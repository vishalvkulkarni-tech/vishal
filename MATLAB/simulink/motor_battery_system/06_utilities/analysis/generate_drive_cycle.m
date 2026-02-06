%% Drive Cycle Generator and Analyzer
% Generates standard drive cycles and custom profiles
% Analyzes power, energy, and efficiency requirements

function drive_cycle = generate_drive_cycle(cycle_name, vehicle_params)
    
    if nargin < 2
        % Default vehicle parameters
        vehicle_params = get_default_vehicle_params();
    end
    
    switch upper(cycle_name)
        case 'UDDS'
            drive_cycle = generate_UDDS();
        case 'HWFET'
            drive_cycle = generate_HWFET();
        case 'US06'
            drive_cycle = generate_US06();
        case 'WLTC'
            drive_cycle = generate_WLTC_Class3();
        case 'NEDC'
            drive_cycle = generate_NEDC();
        case 'CONSTANT'
            drive_cycle = generate_constant_speed(60, 600); % 60 km/h for 600s
        case 'AGGRESSIVE'
            drive_cycle = generate_aggressive_cycle();
        otherwise
            error('Unknown cycle: %s. Options: UDDS, HWFET, US06, WLTC, NEDC, CONSTANT, AGGRESSIVE', cycle_name);
    end
    
    % Add vehicle dynamics calculations
    drive_cycle = add_vehicle_dynamics(drive_cycle, vehicle_params);
    
    % Display summary
    display_cycle_summary(drive_cycle);
    
end

%% UDDS - Urban Dynamometer Driving Schedule (City)
function cycle = generate_UDDS()
    % Simplified UDDS profile (representative segments)
    t = [0:1:1369]'; % 1369 seconds
    v_kph = zeros(size(t));
    
    % Segment 1: Acceleration to 32 km/h
    v_kph(1:20) = linspace(0, 32, 20);
    % Segment 2: Cruise
    v_kph(21:50) = 32;
    % Segment 3: Deceleration
    v_kph(51:65) = linspace(32, 0, 15);
    % Segment 4: Stop
    v_kph(66:85) = 0;
    % Segment 5: Acceleration to 56 km/h
    v_kph(86:135) = linspace(0, 56, 50);
    % Repeat pattern with variations...
    
    % For full accuracy, load from file
    % Here's a representative approximation
    for i = 1:10
        idx_start = 136 + (i-1)*120;
        idx_end = min(idx_start + 119, length(v_kph));
        if idx_start > length(v_kph), break; end
        segment = generate_segment_pattern(120);
        v_kph(idx_start:idx_end) = segment(1:(idx_end-idx_start+1));
    end
    
    cycle.name = 'UDDS';
    cycle.time = t;
    cycle.velocity_kph = v_kph;
    cycle.velocity_mps = v_kph / 3.6;
    cycle.type = 'Urban/City';
    cycle.duration = max(t);
    cycle.distance_km = trapz(t, v_kph) / 3600;
    cycle.avg_speed_kph = mean(v_kph(v_kph > 0));
    cycle.max_speed_kph = max(v_kph);
end

%% HWFET - Highway Fuel Economy Test
function cycle = generate_HWFET()
    t = [0:1:765]'; % 765 seconds
    v_kph = zeros(size(t));
    
    % Start with acceleration
    v_kph(1:30) = linspace(0, 80, 30);
    % Highway cruise with variations
    v_kph(31:200) = 80 + 5*sin(2*pi*(31:200)/100)';
    v_kph(201:350) = 95;
    v_kph(351:500) = 80;
    v_kph(501:650) = 90 + 7*sin(2*pi*(501:650)/80)';
    v_kph(651:735) = linspace(90, 60, 85);
    v_kph(736:765) = linspace(60, 0, 30);
    
    cycle.name = 'HWFET';
    cycle.time = t;
    cycle.velocity_kph = v_kph;
    cycle.velocity_mps = v_kph / 3.6;
    cycle.type = 'Highway';
    cycle.duration = max(t);
    cycle.distance_km = trapz(t, v_kph) / 3600;
    cycle.avg_speed_kph = mean(v_kph(v_kph > 0));
    cycle.max_speed_kph = max(v_kph);
end

%% US06 - Aggressive/High Speed
function cycle = generate_US06()
    t = [0:1:596]'; % 596 seconds
    v_kph = zeros(size(t));
    
    % Aggressive profile
    v_kph(1:40) = linspace(0, 100, 40);
    v_kph(41:150) = 100 + 20*sin(2*pi*(41:150)/60)';
    v_kph(151:180) = linspace(120, 60, 30);
    v_kph(181:210) = linspace(60, 130, 30);
    v_kph(211:350) = 115 + 15*sin(2*pi*(211:350)/80)';
    v_kph(351:450) = linspace(130, 40, 100);
    v_kph(451:500) = 40;
    v_kph(501:566) = linspace(40, 110, 66);
    v_kph(567:596) = linspace(110, 0, 30);
    
    cycle.name = 'US06';
    cycle.time = t;
    cycle.velocity_kph = v_kph;
    cycle.velocity_mps = v_kph / 3.6;
    cycle.type = 'Aggressive/High Speed';
    cycle.duration = max(t);
    cycle.distance_km = trapz(t, v_kph) / 3600;
    cycle.avg_speed_kph = mean(v_kph(v_kph > 0));
    cycle.max_speed_kph = max(v_kph);
end

%% WLTC Class 3 (Worldwide Harmonized Light Vehicle Test Cycle)
function cycle = generate_WLTC_Class3()
    t = [0:1:1800]'; % 1800 seconds
    v_kph = zeros(size(t));
    
    % Low phase
    v_kph(1:589) = generate_wltc_low();
    % Medium phase
    v_kph(590:1022) = generate_wltc_medium();
    % High phase
    v_kph(1023:1477) = generate_wltc_high();
    % Extra high phase
    v_kph(1478:1800) = generate_wltc_extra_high();
    
    cycle.name = 'WLTC Class 3';
    cycle.time = t;
    cycle.velocity_kph = v_kph;
    cycle.velocity_mps = v_kph / 3.6;
    cycle.type = 'Worldwide Harmonized';
    cycle.duration = max(t);
    cycle.distance_km = trapz(t, v_kph) / 3600;
    cycle.avg_speed_kph = mean(v_kph(v_kph > 0));
    cycle.max_speed_kph = max(v_kph);
end

%% Helper: WLTC phases
function v = generate_wltc_low()
    v = 20*ones(589, 1) + 10*sin(linspace(0, 8*pi, 589))';
    v = max(v, 0);
end

function v = generate_wltc_medium()
    v = 50*ones(433, 1) + 15*sin(linspace(0, 10*pi, 433))';
    v = max(v, 0);
end

function v = generate_wltc_high()
    v = 80*ones(455, 1) + 20*sin(linspace(0, 12*pi, 455))';
    v = max(v, 0);
end

function v = generate_wltc_extra_high()
    v = linspace(100, 130, 323)' + 10*sin(linspace(0, 6*pi, 323))';
end

%% NEDC (New European Driving Cycle)
function cycle = generate_NEDC()
    t = [0:1:1180]';
    v_kph = zeros(size(t));
    
    % ECE-15 urban (4 repetitions)
    ece_cycle = [0, 15, 15, 0, 0, 32, 32, 0]';
    
    % EUDC extra-urban
    eudc = [0, 50, 50, 70, 70, 100, 100, 120, 120, 80, 50, 0]';
    
    % Simplified representation
    v_kph(1:300) = repmat(ece_cycle, 37, 1);
    v_kph(301:1180) = repmat(eudc, 73, 1);
    v_kph = v_kph(1:1180);
    
    cycle.name = 'NEDC';
    cycle.time = t;
    cycle.velocity_kph = v_kph;
    cycle.velocity_mps = v_kph / 3.6;
    cycle.type = 'European';
    cycle.duration = max(t);
    cycle.distance_km = trapz(t, v_kph) / 3600;
    cycle.avg_speed_kph = mean(v_kph(v_kph > 0));
    cycle.max_speed_kph = max(v_kph);
end

%% Generate constant speed profile
function cycle = generate_constant_speed(speed_kph, duration)
    t = [0:1:duration]';
    v_kph = speed_kph * ones(size(t));
    
    cycle.name = sprintf('Constant %.0f km/h', speed_kph);
    cycle.time = t;
    cycle.velocity_kph = v_kph;
    cycle.velocity_mps = v_kph / 3.6;
    cycle.type = 'Constant Speed';
    cycle.duration = max(t);
    cycle.distance_km = trapz(t, v_kph) / 3600;
    cycle.avg_speed_kph = speed_kph;
    cycle.max_speed_kph = speed_kph;
end

%% Generate aggressive test cycle
function cycle = generate_aggressive_cycle()
    t = [0:1:300]';
    v_kph = zeros(size(t));
    
    % Hard acceleration
    v_kph(1:10) = linspace(0, 100, 10);
    v_kph(11:30) = 100;
    % Hard braking
    v_kph(31:40) = linspace(100, 0, 10);
    v_kph(41:50) = 0;
    % Repeat
    v_kph(51:250) = repmat(v_kph(1:50), 4, 1);
    v_kph(251:300) = linspace(0, 120, 50);
    
    cycle.name = 'Aggressive Test';
    cycle.time = t;
    cycle.velocity_kph = v_kph;
    cycle.velocity_mps = v_kph / 3.6;
    cycle.type = 'Performance Test';
    cycle.duration = max(t);
    cycle.distance_km = trapz(t, v_kph) / 3600;
    cycle.avg_speed_kph = mean(v_kph(v_kph > 0));
    cycle.max_speed_kph = max(v_kph);
end

%% Add vehicle dynamics
function cycle = add_vehicle_dynamics(cycle, vehicle)
    dt = 1; % 1 second timestep
    
    % Calculate acceleration
    cycle.accel_mps2 = [0; diff(cycle.velocity_mps)] / dt;
    
    % Forces
    cycle.F_roll = vehicle.C_roll * vehicle.mass * 9.81 * ones(size(cycle.time));
    cycle.F_aero = 0.5 * vehicle.rho_air * vehicle.C_drag * vehicle.A_front * cycle.velocity_mps.^2;
    cycle.F_grade = vehicle.mass * 9.81 * sin(atan(vehicle.grade));
    cycle.F_accel = vehicle.mass * cycle.accel_mps2;
    cycle.F_total = cycle.F_roll + cycle.F_aero + cycle.F_grade + cycle.F_accel;
    
    % Power (at wheels)
    cycle.P_wheel = cycle.F_total .* cycle.velocity_mps;
    cycle.P_motor = cycle.P_wheel / vehicle.eta_drivetrain;
    
    % Energy
    cycle.E_total_Wh = trapz(cycle.time, max(cycle.P_motor, 0)) / 3600;
    cycle.E_regen_Wh = -trapz(cycle.time, min(cycle.P_motor, 0)) / 3600 * vehicle.eta_regen;
    cycle.E_net_Wh = cycle.E_total_Wh - cycle.E_regen_Wh;
    
    % Peak power
    cycle.P_max_kW = max(cycle.P_motor) / 1000;
    cycle.P_min_kW = min(cycle.P_motor) / 1000;
end

%% Default vehicle parameters
function params = get_default_vehicle_params()
    params.mass = 1500;             % kg
    params.C_roll = 0.010;          % Rolling resistance
    params.C_drag = 0.28;           % Drag coefficient
    params.A_front = 2.3;           % Frontal area [m^2]
    params.rho_air = 1.225;         % Air density [kg/m^3]
    params.grade = 0.00;            % Road grade
    params.eta_drivetrain = 0.90;   % Drivetrain efficiency
    params.eta_regen = 0.70;        % Regen efficiency
end

%% Display summary
function display_cycle_summary(cycle)
    fprintf('\n========================================\n');
    fprintf('Drive Cycle: %s\n', cycle.name);
    fprintf('========================================\n');
    fprintf('Type: %s\n', cycle.type);
    fprintf('Duration: %.0f s (%.1f min)\n', cycle.duration, cycle.duration/60);
    fprintf('Distance: %.2f km\n', cycle.distance_km);
    fprintf('Avg Speed: %.1f km/h\n', cycle.avg_speed_kph);
    fprintf('Max Speed: %.1f km/h\n', cycle.max_speed_kph);
    fprintf('Max Accel: %.2f m/s²\n', max(cycle.accel_mps2));
    fprintf('Max Decel: %.2f m/s²\n', min(cycle.accel_mps2));
    fprintf('----------------------------------------\n');
    fprintf('Energy Requirements:\n');
    fprintf('  Total Energy: %.2f Wh\n', cycle.E_total_Wh);
    fprintf('  Regen Energy: %.2f Wh\n', cycle.E_regen_Wh);
    fprintf('  Net Energy: %.2f Wh\n', cycle.E_net_Wh);
    fprintf('  Efficiency: %.1f Wh/km\n', cycle.E_net_Wh/cycle.distance_km);
    fprintf('  Peak Power: %.1f kW (motor)\n', cycle.P_max_kW);
    fprintf('  Regen Power: %.1f kW (motor)\n', cycle.P_min_kW);
    fprintf('========================================\n\n');
end

%% Helper for segment patterns
function segment = generate_segment_pattern(length)
    segment = 40*abs(sin(linspace(0, 2*pi, length))) + 10*randn(1, length);
    segment = max(segment, 0);
    segment = min(segment, 80);
end
