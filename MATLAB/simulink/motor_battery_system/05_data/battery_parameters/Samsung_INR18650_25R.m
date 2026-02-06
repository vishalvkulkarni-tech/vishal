%% Battery Cell Parameters - Samsung INR18650-25R
% Lithium Nickel Manganese Cobalt Oxide (NMC) Chemistry
% 18650 Format - High Power Cell
% Optimized for high discharge rates (20A continuous)

clear battery_25R thermal_25R pack_25R

%% Cell Identification
battery_25R.name = 'Samsung INR18650-25R';
battery_25R.chemistry = 'NMC';
battery_25R.form_factor = '18650';
battery_25R.manufacturer = 'Samsung SDI';

%% Basic Electrical Specifications
battery_25R.Q_nom = 2.5;            % Nominal capacity [Ah]
battery_25R.V_nom = 3.60;           % Nominal voltage [V]
battery_25R.V_max = 4.20;           % Maximum voltage [V]
battery_25R.V_min = 2.50;           % Minimum voltage [V]
battery_25R.E_nom = battery_25R.Q_nom * battery_25R.V_nom;  % Nominal energy [Wh]

%% Current Limits (High Power Cell)
battery_25R.I_max_charge_cont = 4.0;      % Max continuous charge current [A]
battery_25R.I_max_charge_peak = 6.0;      % Max peak charge current [A]
battery_25R.I_max_discharge_cont = 20.0;  % Max continuous discharge (8C!) [A]
battery_25R.I_max_discharge_peak = 25.0;  % Max peak discharge (10C, 5s) [A]

%% State of Charge Initialization
battery_25R.SOC_init = 0.80;
battery_25R.SOC_max = 1.00;
battery_25R.SOC_min = 0.00;

%% OCV Characterization
battery_25R.SOC_lut = [0.00, 0.05, 0.10, 0.15, 0.20, 0.25, 0.30, 0.35, 0.40, 0.45, ...
                       0.50, 0.55, 0.60, 0.65, 0.70, 0.75, 0.80, 0.85, 0.90, 0.95, 1.00];

battery_25R.OCV_lut = [2.50, 3.08, 3.22, 3.32, 3.38, 3.44, 3.49, 3.54, 3.58, 3.61, ...
                       3.64, 3.67, 3.70, 3.74, 3.78, 3.83, 3.89, 3.96, 4.05, 4.12, 4.20];

%% Internal Resistance (Lower than MJ1 - optimized for power)
battery_25R.R0_ref = 0.018;         % Lower R0 for high power [Ohm]
battery_25R.R0_SOC_lut = battery_25R.SOC_lut;
battery_25R.R0_SOC_mult = [1.35, 1.28, 1.22, 1.17, 1.12, 1.09, 1.06, 1.04, 1.02, 1.01, ...
                           1.00, 1.00, 1.00, 1.01, 1.02, 1.04, 1.07, 1.11, 1.16, 1.23, 1.32];

battery_25R.R0_T_ref = 25;
battery_25R.R0_Ea = 3200;           % Slightly lower temperature sensitivity

battery_25R.R1_ref = 0.012;
battery_25R.C1_ref = 700;
battery_25R.tau1 = battery_25R.R1_ref * battery_25R.C1_ref;

battery_25R.R2_ref = 0.016;
battery_25R.C2_ref = 7000;
battery_25R.tau2 = battery_25R.R2_ref * battery_25R.C2_ref;

battery_25R.R_total = battery_25R.R0_ref + battery_25R.R1_ref + battery_25R.R2_ref;

%% Thermal Parameters
thermal_25R.mass = 0.045;
thermal_25R.volume = 1.66e-5;
thermal_25R.Cp = 1050;              % Slightly higher Cp
thermal_25R.C_th = thermal_25R.mass * thermal_25R.Cp;
thermal_25R.R_th_radial = 9.0;      % Better heat dissipation
thermal_25R.R_th_axial = 4.5;
thermal_25R.R_th = thermal_25R.R_th_radial;

thermal_25R.T_init = 25;
thermal_25R.T_amb = 25;
thermal_25R.T_charge_max = 50;      % Higher temp tolerance
thermal_25R.T_charge_min = 0;
thermal_25R.T_discharge_max = 75;   % Can handle higher temps
thermal_25R.T_discharge_min = -20;
thermal_25R.dOCV_dT = -0.0004;

%% Capacity Temperature Dependence
battery_25R.T_lut = [-20, -10, 0, 10, 25, 40, 60];
battery_25R.Q_T_mult = [0.70, 0.78, 0.87, 0.94, 1.00, 1.02, 1.03];

%% Degradation (Better cycle life due to power optimization)
battery_25R.aging.k_cal = 3.8e-10;
battery_25R.aging.Ea_cal = 23000;
battery_25R.aging.z_cal = 0.5;
battery_25R.aging.k_cyc = 1.5e-5;   % Better cycle life
battery_25R.aging.Ea_cyc = 17000;
battery_25R.aging.z_cyc = 0.50;

battery_25R.SOH_capacity = 1.00;
battery_25R.SOH_resistance = 1.00;
battery_25R.eta_coulombic = 0.998;

%% Pack Configuration Example (EV with high power requirement)
pack_25R.N_series = 108;            % Higher voltage for performance
pack_25R.N_parallel = 3;            % More parallel for high current
pack_25R.N_total = pack_25R.N_series * pack_25R.N_parallel;

pack_25R.V_nom = pack_25R.N_series * battery_25R.V_nom;
pack_25R.V_max = pack_25R.N_series * battery_25R.V_max;
pack_25R.V_min = pack_25R.N_series * battery_25R.V_min;
pack_25R.Q_nom = pack_25R.N_parallel * battery_25R.Q_nom;
pack_25R.E_nom = pack_25R.V_nom * pack_25R.Q_nom;

pack_25R.I_max_charge_cont = pack_25R.N_parallel * battery_25R.I_max_charge_cont;
pack_25R.I_max_discharge_cont = pack_25R.N_parallel * battery_25R.I_max_discharge_cont;
pack_25R.P_max_charge = pack_25R.V_nom * pack_25R.I_max_charge_cont;
pack_25R.P_max_discharge = pack_25R.V_nom * pack_25R.I_max_discharge_cont;

%% Display Summary
fprintf('\n========================================\n');
fprintf('Battery Cell Parameters Loaded\n');
fprintf('========================================\n');
fprintf('Cell: %s\n', battery_25R.name);
fprintf('Type: HIGH POWER cell\n');
fprintf('----------------------------------------\n');
fprintf('Cell Specifications:\n');
fprintf('  Capacity: %.1f Ah\n', battery_25R.Q_nom);
fprintf('  Voltage: %.2f - %.2f V (nom: %.2f V)\n', battery_25R.V_min, battery_25R.V_max, battery_25R.V_nom);
fprintf('  Max Discharge: %.0f A (%.0fC) ⚡\n', battery_25R.I_max_discharge_cont, battery_25R.I_max_discharge_cont/battery_25R.Q_nom);
fprintf('  Internal Resistance: %.1f mOhm\n', battery_25R.R_total*1000);
fprintf('  Power Density: Very High\n');
fprintf('----------------------------------------\n');
fprintf('Pack Config: %dS%dP (%d cells)\n', pack_25R.N_series, pack_25R.N_parallel, pack_25R.N_total);
fprintf('  Pack Voltage: %.1f V\n', pack_25R.V_nom);
fprintf('  Pack Capacity: %.1f Ah\n', pack_25R.Q_nom);
fprintf('  Pack Energy: %.2f kWh\n', pack_25R.E_nom/1000);
fprintf('  Peak Power: %.0f kW discharge! 🚀\n', pack_25R.P_max_discharge/1000);
fprintf('========================================\n\n');
