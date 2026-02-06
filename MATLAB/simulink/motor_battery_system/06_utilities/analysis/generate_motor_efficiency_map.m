%% Efficiency Map Generator for Motors
% Creates efficiency contour maps for motors across speed-torque operating space
% Useful for sizing, optimization, and performance analysis

function [efficiency_map, losses_map] = generate_motor_efficiency_map(motor_params, options)
    
    if nargin < 2
        options = struct();
    end
    
    % Default options
    if ~isfield(options, 'N_speed_points'), options.N_speed_points = 50; end
    if ~isfield(options, 'N_torque_points'), options.N_torque_points = 50; end
    if ~isfield(options, 'plot_results'), options.plot_results = true; end
    if ~isfield(options, 'temperature'), options.temperature = 75; end
    
    fprintf('Generating motor efficiency map...\n');
    fprintf('Motor: %s\n', motor_params.name);
    fprintf('Temperature: %.0f°C\n', options.temperature);
    
    %% Operating range
    speed_rpm = linspace(0, motor_params.n_max, options.N_speed_points);
    torque_Nm = linspace(0, motor_params.T_rated * 1.5, options.N_torque_points);
    
    [Speed_grid, Torque_grid] = meshgrid(speed_rpm, torque_Nm);
    
    %% Calculate losses and efficiency
    Efficiency = zeros(size(Speed_grid));
    P_copper = zeros(size(Speed_grid));
    P_iron = zeros(size(Speed_grid));
    P_mech = zeros(size(Speed_grid));
    P_total_loss = zeros(size(Speed_grid));
    
    % Temperature-dependent resistance
    T_ref = 25;
    alpha_cu = 0.00393;
    R_factor = 1 + alpha_cu * (options.temperature - T_ref);
    Rs_temp = motor_params.Rs * R_factor;
    
    fprintf('Calculating %d operating points...\n', numel(Speed_grid));
    
    for i = 1:numel(Speed_grid)
        n_rpm = Speed_grid(i);
        T_req = Torque_grid(i);
        omega_m = n_rpm * 2 * pi / 60;
        
        % Skip zero speed points
        if n_rpm < 1
            Efficiency(i) = 0;
            continue;
        end
        
        % Current required (simplified FOC assumption: Te = 3/2 * p * lambda_m * iq)
        if strcmp(motor_params.type, 'SPMSM')
            iq = T_req / (1.5 * motor_params.p * motor_params.lambda_m);
            id = 0; % No field weakening in this simplified model
        else
            % IPMSM with field weakening
            [id, iq] = calculate_ipmsm_currents(motor_params, T_req, omega_m);
        end
        
        I_rms = sqrt(id^2 + iq^2);
        
        % Check current limit
        if I_rms > motor_params.I_max
            Efficiency(i) = NaN;
            continue;
        end
        
        % Check torque-speed envelope
        if T_req > calculate_max_torque(motor_params, n_rpm)
            Efficiency(i) = NaN;
            continue;
        end
        
        % Copper losses (3-phase)
        P_copper(i) = 3 * Rs_temp * I_rms^2;
        
        % Iron losses (Steinmetz equation simplified)
        k_h = motor_params.k_h;
        k_e = motor_params.k_e;
        k_ex = motor_params.k_ex;
        f_e = motor_params.p * n_rpm / 60;
        B_peak = motor_params.lambda_m / (motor_params.L_d * I_rms + 0.001);
        
        P_iron(i) = k_h * f_e * B_peak^2 + ...
                    k_e * f_e^2 * B_peak^2 + ...
                    k_ex * f_e^1.5 * B_peak^1.5;
        
        % Mechanical losses
        P_mech(i) = motor_params.k_friction * omega_m + ...
                    motor_params.k_windage * omega_m^2;
        
        % Total losses
        P_total_loss(i) = P_copper(i) + P_iron(i) + P_mech(i);
        
        % Output power
        P_out = T_req * omega_m;
        
        % Input power
        P_in = P_out + P_total_loss(i);
        
        % Efficiency
        if P_in > 1 % At least 1W input
            Efficiency(i) = P_out / P_in * 100;
        else
            Efficiency(i) = 0;
        end
    end
    
    %% Package results
    efficiency_map.speed_rpm = speed_rpm;
    efficiency_map.torque_Nm = torque_Nm;
    efficiency_map.Speed_grid = Speed_grid;
    efficiency_map.Torque_grid = Torque_grid;
    efficiency_map.Efficiency = Efficiency;
    efficiency_map.Power_kW = Speed_grid * 2*pi/60 .* Torque_grid / 1000;
    
    losses_map.P_copper = P_copper;
    losses_map.P_iron = P_iron;
    losses_map.P_mech = P_mech;
    losses_map.P_total = P_total_loss;
    
    % Statistics
    efficiency_map.peak_efficiency = max(Efficiency(:));
    [~, idx] = max(Efficiency(:));
    efficiency_map.peak_eff_speed = Speed_grid(idx);
    efficiency_map.peak_eff_torque = Torque_grid(idx);
    
    fprintf('Peak efficiency: %.2f%% at %.0f rpm, %.2f Nm\n', ...
        efficiency_map.peak_efficiency, ...
        efficiency_map.peak_eff_speed, ...
        efficiency_map.peak_eff_torque);
    
    %% Plot if requested
    if options.plot_results
        plot_efficiency_map(efficiency_map, losses_map, motor_params);
    end
    
end

%% Calculate IPMSM currents with field weakening
function [id, iq] = calculate_ipmsm_currents(motor, T_req, omega_m)
    % Simplified field weakening strategy
    lambda_m = motor.lambda_m;
    Ld = motor.L_d;
    Lq = motor.L_q;
    p = motor.p;
    V_max = motor.V_dc / sqrt(3);
    
    % Base speed
    omega_base = V_max / lambda_m;
    
    if omega_m <= omega_base
        % Below base speed: MTPA (Maximum Torque Per Ampere)
        iq = T_req / (1.5 * p * lambda_m);
        id = 0;
    else
        % Above base speed: Field weakening
        iq = T_req / (1.5 * p * lambda_m);
        id = -(lambda_m - sqrt(lambda_m^2 - 4*(Lq-Ld)*Ld*iq^2)) / (2*(Lq-Ld));
        id = min(id, 0); % id is negative for field weakening
    end
end

%% Calculate maximum torque at given speed
function T_max = calculate_max_torque(motor, n_rpm)
    omega_m = n_rpm * 2*pi/60;
    omega_base = motor.omega_base;
    
    if n_rpm <= motor.n_base
        % Constant torque region
        T_max = motor.T_max;
    else
        % Constant power region (field weakening)
        T_max = motor.T_max * motor.n_base / n_rpm;
    end
    
    % Don't exceed rated speed limit
    if n_rpm > motor.n_max
        T_max = 0;
    end
end

%% Plot efficiency map
function plot_efficiency_map(eff_map, loss_map, motor)
    figure('Name', 'Motor Efficiency Map', 'Position', [100, 100, 1400, 800]);
    
    % Efficiency contour
    subplot(2, 3, 1);
    contourf(eff_map.Speed_grid, eff_map.Torque_grid, eff_map.Efficiency, 20);
    hold on;
    contour(eff_map.Speed_grid, eff_map.Torque_grid, eff_map.Efficiency, ...
        [80, 85, 90, 92, 94, 95, 96], 'k', 'LineWidth', 1.5, 'ShowText', 'on');
    colorbar;
    xlabel('Speed [rpm]');
    ylabel('Torque [Nm]');
    title('Efficiency Map [%]');
    grid on;
    
    % Power contours on efficiency
    subplot(2, 3, 2);
    contourf(eff_map.Speed_grid, eff_map.Torque_grid, eff_map.Efficiency, 20);
    hold on;
    contour(eff_map.Speed_grid, eff_map.Torque_grid, eff_map.Power_kW, 10, 'k', 'LineWidth', 1, 'ShowText', 'on');
    colorbar;
    xlabel('Speed [rpm]');
    ylabel('Torque [Nm]');
    title('Power Contours [kW] on Efficiency');
    grid on;
    
    % Total losses
    subplot(2, 3, 3);
    contourf(eff_map.Speed_grid, eff_map.Torque_grid, loss_map.P_total, 20);
    colorbar;
    xlabel('Speed [rpm]');
    ylabel('Torque [Nm]');
    title('Total Losses [W]');
    grid on;
    
    % Copper losses
    subplot(2, 3, 4);
    contourf(eff_map.Speed_grid, eff_map.Torque_grid, loss_map.P_copper, 20);
    colorbar;
    xlabel('Speed [rpm]');
    ylabel('Torque [Nm]');
    title('Copper Losses [W]');
    grid on;
    
    % Iron losses
    subplot(2, 3, 5);
    contourf(eff_map.Speed_grid, eff_map.Torque_grid, loss_map.P_iron, 20);
    colorbar;
    xlabel('Speed [rpm]');
    ylabel('Torque [Nm]');
    title('Iron Losses [W]');
    grid on;
    
    % Loss breakdown at rated point
    subplot(2, 3, 6);
    n_rated_idx = find(eff_map.speed_rpm >= motor.n_rated, 1);
    T_rated_idx = find(eff_map.torque_Nm >= motor.T_rated, 1);
    
    P_cu_rated = loss_map.P_copper(T_rated_idx, n_rated_idx);
    P_fe_rated = loss_map.P_iron(T_rated_idx, n_rated_idx);
    P_mech_rated = loss_map.P_mech(T_rated_idx, n_rated_idx);
    
    bar([P_cu_rated, P_fe_rated, P_mech_rated]);
    set(gca, 'XTickLabel', {'Copper', 'Iron', 'Mechanical'});
    ylabel('Loss [W]');
    title(sprintf('Loss Breakdown at Rated Point\n(%.0f rpm, %.1f Nm)', motor.n_rated, motor.T_rated));
    grid on;
    
    % Overall title
    sgtitle(sprintf('Motor Efficiency Analysis: %s', motor.name), 'FontSize', 14, 'FontWeight', 'bold');
end
