%% PMSM Motor Parameters - Example Configuration
% Surface-Mounted Permanent Magnet Synchronous Motor
% Small automotive/industrial motor (approx. 1.5 kW @ 3000 rpm)

clear motor ctrl

%% Basic Motor Parameters
motor.name = 'PMSM_Example_1.5kW';
motor.type = 'SPMSM';  % Surface-mounted PMSM

%% Electrical Parameters
motor.Rs = 0.285;           % Stator resistance [Ohm]
motor.Ld = 0.00085;         % d-axis inductance [H]
motor.Lq = 0.00085;         % q-axis inductance [H] (same as Ld for SPMSM)
motor.lambda_m = 0.1827;    % PM flux linkage [Wb]
motor.p = 4;                % Number of pole pairs

%% Mechanical Parameters
motor.J = 0.0001;           % Rotor inertia [kg.m^2]
motor.B = 0.0001;           % Viscous friction coefficient [N.m.s/rad]

%% Rated Operating Point
motor.V_rated = 48;         % Rated voltage (line-to-line RMS) [V]
motor.I_rated = 10;         % Rated current (phase RMS) [A]
motor.T_rated = 1.5;        % Rated torque [N.m]
motor.n_rated = 3000;       % Rated speed [rpm]
motor.omega_rated = motor.n_rated * 2*pi/60;  % Rated speed [rad/s]
motor.P_rated = motor.T_rated * motor.omega_rated;  % Rated power [W]

%% Maximum Operating Limits
motor.I_max = 20;           % Maximum current (peak) [A]
motor.V_max = 55;           % Maximum voltage [V]
motor.T_max = 3.0;          % Maximum torque [N.m]
motor.n_max = 6000;         % Maximum speed [rpm]
motor.omega_max = motor.n_max * 2*pi/60;  % Maximum speed [rad/s]

%% Loss Parameters

% Copper losses: P_cu = 3/2 * (id^2 + iq^2) * Rs
motor.alpha_Cu = 0.00393;   % Temperature coefficient of copper [1/K]
motor.T_ref = 25;           % Reference temperature [°C]

% Iron losses (simplified Steinmetz equation)
% P_fe = k_h * f * B^2 + k_e * f^2 * B^2
motor.k_h = 0.01;           % Hysteresis loss coefficient
motor.k_e = 0.0005;         % Eddy current loss coefficient
motor.core_volume = 0.0005; % Core volume [m^3]

% Mechanical losses
motor.k_friction = 0.0001;  % Friction coefficient [N.m.s/rad]
motor.k_windage = 1e-8;     % Windage coefficient [N.m.s^3/rad^3]

%% Thermal Parameters
motor.thermal.mass_winding = 0.5;    % Winding mass [kg]
motor.thermal.mass_core = 1.5;       % Core mass [kg]
motor.thermal.mass_rotor = 0.8;      % Rotor mass [kg]
motor.thermal.Cp_copper = 385;       % Specific heat of copper [J/kg/K]
motor.thermal.Cp_iron = 450;         % Specific heat of iron [J/kg/K]
motor.thermal.Cp_rotor = 450;        % Specific heat of rotor [J/kg/K]

% Thermal resistances
motor.thermal.R_winding_to_core = 2;     % [K/W]
motor.thermal.R_core_to_housing = 1;     % [K/W]
motor.thermal.R_rotor_to_airgap = 5;     % [K/W]
motor.thermal.R_housing_to_amb = 3;      % [K/W]

% Temperature limits
motor.thermal.T_winding_max = 155;   % Max winding temperature (Class F) [°C]
motor.thermal.T_magnet_max = 120;    % Max magnet temperature [°C]
motor.thermal.T_amb = 25;            % Ambient temperature [°C]

%% Back-EMF Constant and Torque Constant
motor.ke = motor.lambda_m * motor.p;     % Back-EMF constant [V.s/rad]
motor.kt = 3/2 * motor.p * motor.lambda_m;  % Torque constant [N.m/A]

%% Base Speed and Field Weakening Region
motor.omega_base = motor.V_rated / (sqrt(3) * motor.ke);  % Base speed [rad/s]
motor.n_base = motor.omega_base * 60/(2*pi);              % Base speed [rpm]

%% Control Parameters

%% Current Controller (PI) Design
% Desired current loop bandwidth
ctrl.BW_current = 1000;     % Current loop bandwidth [rad/s] (159 Hz)

% PI gains for d-axis
ctrl.Kp_d = ctrl.BW_current * motor.Ld;
ctrl.Ki_d = ctrl.BW_current * motor.Rs;

% PI gains for q-axis (same for SPMSM)
ctrl.Kp_q = ctrl.BW_current * motor.Lq;
ctrl.Ki_q = ctrl.BW_current * motor.Rs;

% Current controller limits
ctrl.V_d_max = motor.V_max / sqrt(3);  % Max d-axis voltage [V]
ctrl.V_q_max = motor.V_max / sqrt(3);  % Max q-axis voltage [V]

%% Speed Controller (PI) Design
% Desired speed loop bandwidth (10x slower than current loop)
ctrl.BW_speed = 50;         % Speed loop bandwidth [rad/s] (8 Hz)

% PI gains for speed
ctrl.Kp_speed = ctrl.BW_speed * motor.J;
ctrl.Ki_speed = 0.1 * ctrl.Kp_speed;  % Adjusted for good transient response

% Speed controller limits
ctrl.T_max = motor.T_max;
ctrl.I_q_max = 2 * motor.T_max / (3 * motor.p * motor.lambda_m);

%% Control Strategy Selection
ctrl.strategy = 'id_zero';  % Options: 'id_zero', 'MTPA', 'field_weakening'

% For id=0 control
ctrl.id_ref = 0;            % d-axis current reference [A]

%% Space Vector Modulation (SVM) Parameters
ctrl.Ts_PWM = 100e-6;       % PWM switching period [s] (10 kHz)
ctrl.fs_PWM = 1/ctrl.Ts_PWM;  % PWM switching frequency [Hz]
ctrl.dead_time = 2e-6;      % Dead time [s]

%% Simulation Parameters
sim.Ts_ctrl = 100e-6;       % Control sample time [s] (same as PWM)
sim.Ts_fast = 1e-6;         % Fast dynamics sample time [s]
sim.Ts_slow = 1e-3;         % Slow dynamics sample time [s]
sim.t_end = 2.0;            % Simulation end time [s]

%% DC Link Parameters
dclink.V_DC = 60;           % DC link voltage [V]
dclink.C_DC = 470e-6;       % DC link capacitance [F]

%% Display Summary
fprintf('\n========================================\n');
fprintf('PMSM Motor Parameters Loaded\n');
fprintf('========================================\n');
fprintf('Motor: %s\n', motor.name);
fprintf('Rated Power: %.2f kW\n', motor.P_rated/1000);
fprintf('Rated Torque: %.2f N.m\n', motor.T_rated);
fprintf('Rated Speed: %d rpm (%.1f rad/s)\n', motor.n_rated, motor.omega_rated);
fprintf('Base Speed: %d rpm (%.1f rad/s)\n', motor.n_base, motor.omega_base);
fprintf('Max Speed: %d rpm (%.1f rad/s)\n', motor.n_max, motor.omega_max);
fprintf('Torque Constant: %.4f N.m/A\n', motor.kt);
fprintf('Back-EMF Constant: %.4f V.s/rad\n', motor.ke);
fprintf('Pole Pairs: %d\n', motor.p);
fprintf('Phase Resistance: %.3f Ohm\n', motor.Rs);
fprintf('Phase Inductance: %.3f mH\n', motor.Ld*1000);
fprintf('Flux Linkage: %.4f Wb\n', motor.lambda_m);
fprintf('----------------------------------------\n');
fprintf('Current Loop Bandwidth: %.0f rad/s (%.1f Hz)\n', ctrl.BW_current, ctrl.BW_current/(2*pi));
fprintf('Speed Loop Bandwidth: %.0f rad/s (%.1f Hz)\n', ctrl.BW_speed, ctrl.BW_speed/(2*pi));
fprintf('PWM Frequency: %.0f kHz\n', ctrl.fs_PWM/1000);
fprintf('========================================\n\n');
