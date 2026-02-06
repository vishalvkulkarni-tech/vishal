%% Plot Battery Results
% Visualization script for battery simulation results
% Assumes simulation output is in variable 'sim_out' or 'out'

function plot_battery_results(sim_data)
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
    fig = figure('Name', 'Battery Simulation Results', 'Position', [100 100 1200 800]);
    
    %% Subplot 1: Voltage
    subplot(3, 2, 1);
    try
        V_terminal = sim_data.logsout.get('V_terminal').Values.Data;
        V_OC = sim_data.logsout.get('V_OC').Values.Data;
        
        plot(t, V_terminal, 'b-', 'LineWidth', 1.5);
        hold on;
        plot(t, V_OC, 'r--', 'LineWidth', 1.5);
        grid on;
        xlabel('Time [s]');
        ylabel('Voltage [V]');
        title('Battery Voltage');
        legend('Terminal', 'OCV', 'Location', 'best');
    catch
        text(0.5, 0.5, 'Voltage data not available', 'HorizontalAlignment', 'center');
    end
    
    %% Subplot 2: Current
    subplot(3, 2, 2);
    try
        I = sim_data.logsout.get('I').Values.Data;
        
        plot(t, I, 'b-', 'LineWidth', 1.5);
        grid on;
        xlabel('Time [s]');
        ylabel('Current [A]');
        title('Battery Current (+ = Discharge)');
        
        % Add zero line
        yline(0, 'k--', 'LineWidth', 0.5);
    catch
        text(0.5, 0.5, 'Current data not available', 'HorizontalAlignment', 'center');
    end
    
    %% Subplot 3: State of Charge (SOC)
    subplot(3, 2, 3);
    try
        SOC = sim_data.logsout.get('SOC').Values.Data * 100;  % Convert to %
        
        plot(t, SOC, 'b-', 'LineWidth', 1.5);
        grid on;
        xlabel('Time [s]');
        ylabel('SOC [%]');
        title('State of Charge');
        ylim([0 105]);
        
        % Add safe operating region
        yline(10, 'r--', 'Min SOC', 'LineWidth', 1);
        yline(95, 'r--', 'Max SOC', 'LineWidth', 1);
    catch
        text(0.5, 0.5, 'SOC data not available', 'HorizontalAlignment', 'center');
    end
    
    %% Subplot 4: Power
    subplot(3, 2, 4);
    try
        P = sim_data.logsout.get('P').Values.Data / 1000;  % Convert to kW
        
        plot(t, P, 'b-', 'LineWidth', 1.5);
        grid on;
        xlabel('Time [s]');
        ylabel('Power [kW]');
        title('Battery Power (+ = Discharge)');
        
        % Add zero line
        yline(0, 'k--', 'LineWidth', 0.5);
    catch
        text(0.5, 0.5, 'Power data not available', 'HorizontalAlignment', 'center');
    end
    
    %% Subplot 5: Temperature
    subplot(3, 2, 5);
    try
        T = sim_data.logsout.get('T').Values.Data;
        T_amb = sim_data.logsout.get('T_amb').Values.Data;
        
        plot(t, T, 'b-', 'LineWidth', 1.5);
        hold on;
        plot(t, T_amb, 'k--', 'LineWidth', 1);
        grid on;
        xlabel('Time [s]');
        ylabel('Temperature [°C]');
        title('Battery Temperature');
        legend('Cell', 'Ambient', 'Location', 'best');
        
        % Add temperature limits
        yline(60, 'r--', 'Max Temp', 'LineWidth', 1);
        yline(0, 'b--', 'Min Temp', 'LineWidth', 1);
    catch
        text(0.5, 0.5, 'Temperature data not available', 'HorizontalAlignment', 'center');
    end
    
    %% Subplot 6: Energy
    subplot(3, 2, 6);
    try
        % Calculate cumulative energy
        P_W = sim_data.logsout.get('P').Values.Data;  % Power in W
        E_Wh = cumtrapz(t, P_W) / 3600;  % Energy in Wh
        
        plot(t, E_Wh, 'b-', 'LineWidth', 1.5);
        grid on;
        xlabel('Time [s]');
        ylabel('Energy [Wh]');
        title('Cumulative Energy (+ = Discharged)');
    catch
        try
            % Alternative: Plot SOH if available
            SOH = sim_data.logsout.get('SOH').Values.Data * 100;
            plot(t, SOH, 'g-', 'LineWidth', 1.5);
            grid on;
            xlabel('Time [s]');
            ylabel('SOH [%]');
            title('State of Health');
            ylim([0 105]);
        catch
            text(0.5, 0.5, 'Energy/SOH data not available', 'HorizontalAlignment', 'center');
        end
    end
    
    % Add overall title
    sgtitle('Battery Simulation Results', 'FontSize', 14, 'FontWeight', 'bold');
    
    % Print summary statistics
    fprintf('\n========================================\n');
    fprintf('Battery Simulation Summary\n');
    fprintf('========================================\n');
    fprintf('Simulation Time: %.2f s (%.2f min)\n', t(end), t(end)/60);
    
    try
        fprintf('\nVoltage:\n');
        fprintf('  Initial: %.3f V\n', V_terminal(1));
        fprintf('  Final: %.3f V\n', V_terminal(end));
        fprintf('  Change: %.3f V\n', V_terminal(end) - V_terminal(1));
        fprintf('  Min: %.3f V\n', min(V_terminal));
        fprintf('  Max: %.3f V\n', max(V_terminal));
    catch
    end
    
    try
        fprintf('\nCurrent:\n');
        fprintf('  Average: %.3f A\n', mean(I));
        fprintf('  RMS: %.3f A\n', rms(I));
        fprintf('  Peak: %.3f A\n', max(abs(I)));
    catch
    end
    
    try
        fprintf('\nState of Charge:\n');
        fprintf('  Initial: %.1f%%\n', SOC(1));
        fprintf('  Final: %.1f%%\n', SOC(end));
        fprintf('  Change: %.1f%%\n', SOC(end) - SOC(1));
    catch
    end
    
    try
        fprintf('\nTemperature:\n');
        fprintf('  Initial: %.1f °C\n', T(1));
        fprintf('  Final: %.1f °C\n', T(end));
        fprintf('  Rise: %.1f °C\n', T(end) - T(1));
        fprintf('  Peak: %.1f °C\n', max(T));
    catch
    end
    
    try
        fprintf('\nEnergy:\n');
        fprintf('  Total Discharged: %.2f Wh\n', max(E_Wh));
        fprintf('  Average Power: %.2f W\n', mean(P_W));
    catch
    end
    
    fprintf('========================================\n\n');
end
