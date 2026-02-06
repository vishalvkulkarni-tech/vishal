%% Plot Motor Results
% Visualization script for motor simulation results
% Assumes simulation output is in variable 'sim_out' or 'out'

function plot_motor_results(sim_data)
    % Handle different input formats
    if nargin < 1
        if evalin('base', 'exist(''sim_out'', ''var'')')
            sim_data = evalin('base', 'sim_out');
        elseif evalin('base', 'exist(''out'', ''var'')')
            sim_data = evalin('base', 'out');
        else
            error('No simulation data found. Run simulation first.');
        end
    end
    
    % Extract time vector
    t = sim_data.tout;
    
    % Create figure with multiple subplots
    fig = figure('Name', 'Motor Simulation Results', 'Position', [100 100 1200 800]);
    
    %% Subplot 1: Speed Response
    subplot(3, 2, 1);
    try
        speed_rpm = sim_data.logsout.get('speed').Values.Data * 60/(2*pi);  % Convert to RPM
        speed_ref_rpm = sim_data.logsout.get('speed_ref').Values.Data * 60/(2*pi);
        
        plot(t, speed_rpm, 'b-', 'LineWidth', 1.5);
        hold on;
        plot(t, speed_ref_rpm, 'r--', 'LineWidth', 1.5);
        grid on;
        xlabel('Time [s]');
        ylabel('Speed [rpm]');
        title('Speed Response');
        legend('Actual', 'Reference', 'Location', 'best');
    catch
        text(0.5, 0.5, 'Speed data not available', 'HorizontalAlignment', 'center');
    end
    
    %% Subplot 2: Torque
    subplot(3, 2, 2);
    try
        torque = sim_data.logsout.get('torque').Values.Data;
        torque_ref = sim_data.logsout.get('torque_ref').Values.Data;
        
        plot(t, torque, 'b-', 'LineWidth', 1.5);
        hold on;
        plot(t, torque_ref, 'r--', 'LineWidth', 1.5);
        grid on;
        xlabel('Time [s]');
        ylabel('Torque [N.m]');
        title('Electromagnetic Torque');
        legend('Actual', 'Reference', 'Location', 'best');
    catch
        text(0.5, 0.5, 'Torque data not available', 'HorizontalAlignment', 'center');
    end
    
    %% Subplot 3: dq Currents
    subplot(3, 2, 3);
    try
        id = sim_data.logsout.get('id').Values.Data;
        iq = sim_data.logsout.get('iq').Values.Data;
        id_ref = sim_data.logsout.get('id_ref').Values.Data;
        iq_ref = sim_data.logsout.get('iq_ref').Values.Data;
        
        plot(t, id, 'b-', 'LineWidth', 1.5);
        hold on;
        plot(t, id_ref, 'b--', 'LineWidth', 1);
        plot(t, iq, 'r-', 'LineWidth', 1.5);
        plot(t, iq_ref, 'r--', 'LineWidth', 1);
        grid on;
        xlabel('Time [s]');
        ylabel('Current [A]');
        title('dq-axis Currents');
        legend('i_d', 'i_d ref', 'i_q', 'i_q ref', 'Location', 'best');
    catch
        text(0.5, 0.5, 'dq current data not available', 'HorizontalAlignment', 'center');
    end
    
    %% Subplot 4: Three-Phase Currents
    subplot(3, 2, 4);
    try
        ia = sim_data.logsout.get('ia').Values.Data;
        ib = sim_data.logsout.get('ib').Values.Data;
        ic = sim_data.logsout.get('ic').Values.Data;
        
        % Plot only last 50ms for clarity
        t_start = max(0, t(end) - 0.05);
        idx = t >= t_start;
        
        plot(t(idx), ia(idx), 'r-', 'LineWidth', 1.5);
        hold on;
        plot(t(idx), ib(idx), 'g-', 'LineWidth', 1.5);
        plot(t(idx), ic(idx), 'b-', 'LineWidth', 1.5);
        grid on;
        xlabel('Time [s]');
        ylabel('Current [A]');
        title('Three-Phase Currents (Last 50ms)');
        legend('i_a', 'i_b', 'i_c', 'Location', 'best');
    catch
        text(0.5, 0.5, 'Phase current data not available', 'HorizontalAlignment', 'center');
    end
    
    %% Subplot 5: Power
    subplot(3, 2, 5);
    try
        P_mech = sim_data.logsout.get('P_mech').Values.Data / 1000;  % Convert to kW
        P_elec = sim_data.logsout.get('P_elec').Values.Data / 1000;
        
        plot(t, P_mech, 'b-', 'LineWidth', 1.5);
        hold on;
        plot(t, P_elec, 'r-', 'LineWidth', 1.5);
        grid on;
        xlabel('Time [s]');
        ylabel('Power [kW]');
        title('Power');
        legend('Mechanical', 'Electrical', 'Location', 'best');
    catch
        text(0.5, 0.5, 'Power data not available', 'HorizontalAlignment', 'center');
    end
    
    %% Subplot 6: Efficiency or Temperature
    subplot(3, 2, 6);
    try
        % Try efficiency first
        efficiency = sim_data.logsout.get('efficiency').Values.Data * 100;  % Convert to %
        plot(t, efficiency, 'b-', 'LineWidth', 1.5);
        grid on;
        xlabel('Time [s]');
        ylabel('Efficiency [%]');
        title('Motor Efficiency');
        ylim([0 105]);
    catch
        try
            % If efficiency not available, try temperature
            T_winding = sim_data.logsout.get('T_winding').Values.Data;
            plot(t, T_winding, 'r-', 'LineWidth', 1.5);
            grid on;
            xlabel('Time [s]');
            ylabel('Temperature [°C]');
            title('Winding Temperature');
        catch
            text(0.5, 0.5, 'Efficiency/Temperature data not available', 'HorizontalAlignment', 'center');
        end
    end
    
    % Add overall title
    sgtitle('Motor Simulation Results', 'FontSize', 14, 'FontWeight', 'bold');
    
    % Print summary statistics
    fprintf('\n========================================\n');
    fprintf('Motor Simulation Summary\n');
    fprintf('========================================\n');
    fprintf('Simulation Time: %.2f s\n', t(end));
    
    try
        fprintf('Final Speed: %.1f rpm\n', speed_rpm(end));
        fprintf('Speed Reference: %.1f rpm\n', speed_ref_rpm(end));
        fprintf('Speed Error: %.1f rpm (%.1f%%)\n', speed_rpm(end) - speed_ref_rpm(end), ...
            abs(speed_rpm(end) - speed_ref_rpm(end))/speed_ref_rpm(end)*100);
    catch
    end
    
    try
        fprintf('Final Torque: %.3f N.m\n', torque(end));
        fprintf('Peak Torque: %.3f N.m\n', max(abs(torque)));
    catch
    end
    
    try
        fprintf('RMS Phase Current: %.2f A\n', rms(ia));
        fprintf('Peak Phase Current: %.2f A\n', max(abs(ia)));
    catch
    end
    
    try
        fprintf('Average Efficiency: %.1f%%\n', mean(efficiency(efficiency > 0)));
    catch
    end
    
    fprintf('========================================\n\n');
end
