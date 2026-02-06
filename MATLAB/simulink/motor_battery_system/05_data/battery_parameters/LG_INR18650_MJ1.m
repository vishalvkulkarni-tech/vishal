%% Battery Cell Parameters - LG INR18650-MJ1
% Lithium Nickel Manganese Cobalt Oxide (NMC) Chemistry
% 18650 Format (18mm diameter, 65mm length)
% High energy density cell for EV applications

clear battery thermal pack

%% Cell Identification
battery.name = 'LG INR18650-MJ1';
battery.chemistry = 'NMC';
battery.form_factor = '18650';
battery.manufacturer = 'LG Chem';

%% Basic Electrical Specifications
battery.Q_nom = 3.5;            % Nominal capacity [Ah]
battery.V_nom = 3.635;          % Nominal voltage [V]
battery.V_max = 4.20;           % Maximum voltage [V]
battery.V_min = 2.50;           % Minimum voltage [V]
battery.E_nom = battery.Q_nom * battery.V_nom;  % Nominal energy [Wh]

%% Current Limits
battery.I_max_charge_cont = 3.5;      % Max continuous charge current (1C) [A]
battery.I_max_charge_peak = 7.0;      % Max peak charge current (2C, 10s) [A]
battery.I_max_discharge_cont = 10.0;  % Max continuous discharge current [A]
battery.I_max_discharge_peak = 15.0;  % Max peak discharge current (5s) [A]

%% State of Charge (SOC) Initialization
battery.SOC_init = 0.80;        % Initial SOC [0-1]
battery.SOC_max = 1.00;         % Maximum usable SOC [0-1]
battery.SOC_min = 0.00;         % Minimum usable SOC [0-1]

%% Open-Circuit Voltage (OCV) Characterization
% Based on low-current discharge test at 25°C
battery.SOC_lut = [0.00, 0.05, 0.10, 0.15, 0.20, 0.25, 0.30, 0.35, 0.40, 0.45, ...
                   0.50, 0.55, 0.60, 0.65, 0.70, 0.75, 0.80, 0.85, 0.90, 0.95, 1.00];

battery.OCV_lut = [2.50, 3.10, 3.25, 3.35, 3.42, 3.48, 3.53, 3.58, 3.62, 3.65, ...
                   3.68, 3.71, 3.74, 3.78, 3.82, 3.87, 3.93, 4.00, 4.08, 4.14, 4.20];  % [V]

%% Internal Resistance Model (2RC Equivalent Circuit)

% Ohmic resistance R0 (instantaneous voltage drop)
% Function of SOC and temperature
battery.R0_ref = 0.025;         % Reference R0 at 25°C, 50% SOC [Ohm]

% SOC dependence of R0 (multiplier)
battery.R0_SOC_lut = battery.SOC_lut;
battery.R0_SOC_mult = [1.30, 1.25, 1.20, 1.15, 1.10, 1.08, 1.05, 1.03, 1.02, 1.01, ...
                       1.00, 1.00, 1.00, 1.01, 1.02, 1.04, 1.07, 1.12, 1.18, 1.25, 1.35];

% Temperature dependence of R0 (Arrhenius)
battery.R0_T_ref = 25;          % Reference temperature [°C]
battery.R0_Ea = 3500;           % Activation energy [K]

% Polarization resistance R1 (fast dynamics, charge transfer)
battery.R1_ref = 0.015;         % [Ohm]
battery.C1_ref = 600;           % [F]
battery.tau1 = battery.R1_ref * battery.C1_ref;  % Time constant [s]

% Polarization resistance R2 (slow dynamics, diffusion)
battery.R2_ref = 0.020;         % [Ohm]
battery.C2_ref = 8000;          % [F]
battery.tau2 = battery.R2_ref * battery.C2_ref;  % Time constant [s]

% Total resistance (for quick calculations)
battery.R_total = battery.R0_ref + battery.R1_ref + battery.R2_ref;  % [Ohm]

%% Thermal Parameters

% Physical properties
thermal.mass = 0.0465;          % Cell mass [kg]
thermal.volume = 1.66e-5;       % Cell volume [m^3]
thermal.Cp = 1000;              % Specific heat capacity [J/kg/K]
thermal.C_th = thermal.mass * thermal.Cp;  % Thermal capacitance [J/K]

% Heat transfer
thermal.R_th_radial = 10.0;     % Radial thermal resistance [K/W]
thermal.R_th_axial = 5.0;       % Axial thermal resistance [K/W]
thermal.R_th = thermal.R_th_radial;  % Dominant thermal resistance [K/W]

% Initial conditions
thermal.T_init = 25;            % Initial temperature [°C]
thermal.T_amb = 25;             % Ambient temperature [°C]

% Operating temperature limits
thermal.T_charge_max = 45;      % Max charge temperature [°C]
thermal.T_charge_min = 0;       % Min charge temperature [°C]
thermal.T_discharge_max = 60;   % Max discharge temperature [°C]
thermal.T_discharge_min = -20;  % Min discharge temperature [°C]
thermal.T_storage_max = 60;     % Max storage temperature [°C]
thermal.T_storage_min = -30;    % Min storage temperature [°C]

% Entropic coefficient (reversible heat)
thermal.dOCV_dT = -0.0005;      % Entropic coefficient [V/K]
% Note: Varies with SOC, this is average value

%% Capacity and Resistance Temperature Dependence

% Capacity vs. Temperature
battery.T_lut = [-20, -10, 0, 10, 25, 40, 60];  % Temperature [°C]
battery.Q_T_mult = [0.65, 0.75, 0.85, 0.93, 1.00, 1.03, 1.05];  % Multiplier

%% Degradation Parameters

% Calendar aging (storage)
battery.aging.k_cal = 4.14e-10; % Calendar aging rate [1/sqrt(day)]
battery.aging.Ea_cal = 24500;   % Activation energy [J/mol]
battery.aging.z_cal = 0.5;      % Calendar aging power law exponent

% Cycle aging
battery.aging.k_cyc = 2.0e-5;   % Cycle aging rate [1/cycle^z]
battery.aging.Ea_cyc = 18000;   % Activation energy [J/mol]
battery.aging.z_cyc = 0.55;     % Cycle aging power law exponent

% SOH initial values
battery.SOH_capacity = 1.00;    % Initial capacity SOH [0-1]
battery.SOH_resistance = 1.00;  % Initial resistance SOH [0-1]

%% Battery Pack Configuration

% Pack topology
pack.N_series = 96;             % Number of cells in series
pack.N_parallel = 2;            % Number of cells in parallel
pack.N_total = pack.N_series * pack.N_parallel;  % Total cells

% Pack electrical parameters
pack.V_nom = pack.N_series * battery.V_nom;      % Nominal pack voltage [V]
pack.V_max = pack.N_series * battery.V_max;      % Maximum pack voltage [V]
pack.V_min = pack.N_series * battery.V_min;      % Minimum pack voltage [V]
pack.Q_nom = pack.N_parallel * battery.Q_nom;    % Nominal pack capacity [Ah]
pack.E_nom = pack.V_nom * pack.Q_nom;            % Nominal pack energy [Wh]

% Pack current limits
pack.I_max_charge_cont = pack.N_parallel * battery.I_max_charge_cont;      % [A]
pack.I_max_discharge_cont = pack.N_parallel * battery.I_max_discharge_cont;  % [A]

% Pack power limits
pack.P_max_charge = pack.V_nom * pack.I_max_charge_cont;        % [W]
pack.P_max_discharge = pack.V_nom * pack.I_max_discharge_cont;  % [W]

% Pack thermal
pack.C_th_total = thermal.C_th * pack.N_total;   % Total thermal capacitance [J/K]

%% BMS Parameters

% Voltage limits
bms.V_cell_max = 4.25;          % Overvoltage threshold [V]
bms.V_cell_min = 2.40;          % Undervoltage threshold [V]
bms.V_pack_max = bms.V_cell_max * pack.N_series;  % [V]
bms.V_pack_min = bms.V_cell_min * pack.N_series;  % [V]

% Current limits (with safety margin)
bms.I_charge_max = 0.9 * pack.I_max_charge_cont;     % [A]
bms.I_discharge_max = 0.9 * pack.I_max_discharge_cont;  % [A]

% Temperature limits
bms.T_cell_max = 55;            % Maximum cell temperature [°C]
bms.T_cell_min = -15;           % Minimum cell temperature [°C]

% SOC operating window
bms.SOC_max_operating = 0.95;   % Upper SOC limit for operation
bms.SOC_min_operating = 0.10;   % Lower SOC limit for operation

% Cell balancing
bms.balance_enable = true;      % Enable cell balancing
bms.balance_threshold = 0.010;  % Voltage difference for balancing [V]
bms.balance_current = 0.1;      % Balancing current [A]

% SOC estimation (EKF parameters)
bms.EKF_Q = 1e-6;               % Process noise covariance
bms.EKF_R = 1e-4;               % Measurement noise covariance
bms.EKF_P0 = 0.01;              % Initial error covariance

%% Coulombic Efficiency
battery.eta_coulombic = 0.998;  % Coulombic efficiency [0-1]
% Slightly less than 1.0 to account for side reactions

%% Display Summary
fprintf('\n========================================\n');
fprintf('Battery Cell Parameters Loaded\n');
fprintf('========================================\n');
fprintf('Cell: %s\n', battery.name);
fprintf('Chemistry: %s\n', battery.chemistry);
fprintf('Form Factor: %s\n', battery.form_factor);
fprintf('----------------------------------------\n');
fprintf('Cell Specifications:\n');
fprintf('  Nominal Capacity: %.2f Ah\n', battery.Q_nom);
fprintf('  Nominal Voltage: %.3f V\n', battery.V_nom);
fprintf('  Nominal Energy: %.2f Wh\n', battery.E_nom);
fprintf('  Voltage Range: %.2f - %.2f V\n', battery.V_min, battery.V_max);
fprintf('  Max Charge Current: %.1f A (%.1fC)\n', battery.I_max_charge_cont, battery.I_max_charge_cont/battery.Q_nom);
fprintf('  Max Discharge Current: %.1f A (%.1fC)\n', battery.I_max_discharge_cont, battery.I_max_discharge_cont/battery.Q_nom);
fprintf('  Internal Resistance: %.1f mOhm\n', battery.R_total*1000);
fprintf('----------------------------------------\n');
fprintf('Pack Configuration: %dS%dP (%d cells total)\n', pack.N_series, pack.N_parallel, pack.N_total);
fprintf('  Pack Voltage: %.1f V (%.1f - %.1f V)\n', pack.V_nom, pack.V_min, pack.V_max);
fprintf('  Pack Capacity: %.1f Ah\n', pack.Q_nom);
fprintf('  Pack Energy: %.2f kWh\n', pack.E_nom/1000);
fprintf('  Pack Power (cont.): %.1f kW charge / %.1f kW discharge\n', pack.P_max_charge/1000, pack.P_max_discharge/1000);
fprintf('  Pack Mass: %.1f kg (cells only)\n', thermal.mass * pack.N_total);
fprintf('----------------------------------------\n');
fprintf('Thermal:\n');
fprintf('  Cell Mass: %.1f g\n', thermal.mass*1000);
fprintf('  Thermal Capacitance: %.1f J/K\n', thermal.C_th);
fprintf('  Thermal Resistance: %.1f K/W\n', thermal.R_th);
fprintf('  Operating Temp: %.0f to %.0f °C (discharge)\n', thermal.T_discharge_min, thermal.T_discharge_max);
fprintf('========================================\n\n');
