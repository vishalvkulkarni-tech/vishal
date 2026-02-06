%% Battery Cell Parameters - A123 ANR26650 LiFePO4
% Lithium Iron Phosphate (LFP) Chemistry
% 26650 Format (26mm diameter, 65mm length)
% Excellent safety, long cycle life, lower energy density

clear battery_LFP thermal_LFP pack_LFP

%% Cell Identification
battery_LFP.name = 'A123 ANR26650 (LiFePO4)';
battery_LFP.chemistry = 'LFP';
battery_LFP.form_factor = '26650';
battery_LFP.manufacturer = 'A123 Systems';

%% Basic Electrical Specifications
battery_LFP.Q_nom = 2.5;            % Nominal capacity [Ah]
battery_LFP.V_nom = 3.30;           % Lower nominal voltage [V]
battery_LFP.V_max = 3.60;           % Maximum voltage [V]
battery_LFP.V_min = 2.00;           % Minimum voltage [V]
battery_LFP.E_nom = battery_LFP.Q_nom * battery_LFP.V_nom;

%% Current Limits (Excellent power capability)
battery_LFP.I_max_charge_cont = 10.0;      % High charge rate [A]
battery_LFP.I_max_charge_peak = 25.0;      % Very high peak [A]
battery_LFP.I_max_discharge_cont = 50.0;   % Excellent! 20C [A]
battery_LFP.I_max_discharge_peak = 70.0;   % 28C peak [A]

%% State of Charge
battery_LFP.SOC_init = 0.80;
battery_LFP.SOC_max = 1.00;
battery_LFP.SOC_min = 0.00;

%% OCV Characterization (Very flat OCV curve - characteristic of LFP!)
battery_LFP.SOC_lut = [0.00, 0.05, 0.10, 0.15, 0.20, 0.25, 0.30, 0.35, 0.40, 0.45, ...
                       0.50, 0.55, 0.60, 0.65, 0.70, 0.75, 0.80, 0.85, 0.90, 0.95, 1.00];

% Very flat plateau in middle SOC range - LFP characteristic
battery_LFP.OCV_lut = [2.00, 2.80, 3.10, 3.20, 3.25, 3.28, 3.30, 3.32, 3.33, 3.34, ...
                       3.35, 3.35, 3.36, 3.37, 3.38, 3.40, 3.42, 3.45, 3.50, 3.55, 3.60];

%% Internal Resistance (Very low for excellent power)
battery_LFP.R0_ref = 0.012;         % Very low! [Ohm]
battery_LFP.R0_SOC_lut = battery_LFP.SOC_lut;
battery_LFP.R0_SOC_mult = [1.50, 1.35, 1.22, 1.12, 1.06, 1.02, 1.00, 0.99, 0.98, 0.98, ...
                           0.98, 0.98, 0.98, 0.99, 1.00, 1.02, 1.05, 1.10, 1.18, 1.30, 1.45];

battery_LFP.R0_T_ref = 25;
battery_LFP.R0_Ea = 2800;           % Lower temperature sensitivity

battery_LFP.R1_ref = 0.008;
battery_LFP.C1_ref = 800;
battery_LFP.tau1 = battery_LFP.R1_ref * battery_LFP.C1_ref;

battery_LFP.R2_ref = 0.010;
battery_LFP.C2_ref = 6000;
battery_LFP.tau2 = battery_LFP.R2_ref * battery_LFP.C2_ref;

battery_LFP.R_total = battery_LFP.R0_ref + battery_LFP.R1_ref + battery_LFP.R2_ref;

%% Thermal Parameters
thermal_LFP.mass = 0.072;           % Heavier (larger format)
thermal_LFP.volume = 3.46e-5;       % Larger volume (26650)
thermal_LFP.Cp = 1100;              % Higher Cp
thermal_LFP.C_th = thermal_LFP.mass * thermal_LFP.Cp;
thermal_LFP.R_th_radial = 6.0;      % Better heat dissipation (larger surface)
thermal_LFP.R_th_axial = 3.0;
thermal_LFP.R_th = thermal_LFP.R_th_radial;

thermal_LFP.T_init = 25;
thermal_LFP.T_amb = 25;
thermal_LFP.T_charge_max = 60;      % Excellent thermal stability
thermal_LFP.T_charge_min = -10;     % Can charge at low temp
thermal_LFP.T_discharge_max = 70;   % Very high tolerance
thermal_LFP.T_discharge_min = -30;  % Good low temp performance
thermal_LFP.dOCV_dT = -0.0003;      % Lower temperature dependence

%% Capacity Temperature Dependence (Better than NMC/NCA at low temp)
battery_LFP.T_lut = [-20, -10, 0, 10, 25, 40, 60];
battery_LFP.Q_T_mult = [0.75, 0.85, 0.92, 0.97, 1.00, 1.01, 1.02];

%% Degradation (Excellent cycle life - key advantage of LFP!)
battery_LFP.aging.k_cal = 2.5e-10;  % Excellent calendar aging
battery_LFP.aging.Ea_cal = 22000;
battery_LFP.aging.z_cal = 0.45;
battery_LFP.aging.k_cyc = 8.0e-6;   % Outstanding cycle life!
battery_LFP.aging.Ea_cyc = 15000;
battery_LFP.aging.z_cyc = 0.45;

battery_LFP.SOH_capacity = 1.00;
battery_LFP.SOH_resistance = 1.00;
battery_LFP.eta_coulombic = 0.999;

%% Pack Configuration (Higher voltage needed due to lower cell voltage)
pack_LFP.N_series = 120;            % More cells for same voltage
pack_LFP.N_parallel = 2;
pack_LFP.N_total = pack_LFP.N_series * pack_LFP.N_parallel;

pack_LFP.V_nom = pack_LFP.N_series * battery_LFP.V_nom;
pack_LFP.V_max = pack_LFP.N_series * battery_LFP.V_max;
pack_LFP.V_min = pack_LFP.N_series * battery_LFP.V_min;
pack_LFP.Q_nom = pack_LFP.N_parallel * battery_LFP.Q_nom;
pack_LFP.E_nom = pack_LFP.V_nom * pack_LFP.Q_nom;

pack_LFP.I_max_charge_cont = pack_LFP.N_parallel * battery_LFP.I_max_charge_cont;
pack_LFP.I_max_discharge_cont = pack_LFP.N_parallel * battery_LFP.I_max_discharge_cont;
pack_LFP.P_max_charge = pack_LFP.V_nom * pack_LFP.I_max_charge_cont;
pack_LFP.P_max_discharge = pack_LFP.V_nom * pack_LFP.I_max_discharge_cont;

%% Display Summary
fprintf('\n========================================\n');
fprintf('Battery Cell Parameters Loaded\n');
fprintf('========================================\n');
fprintf('Cell: %s\n', battery_LFP.name);
fprintf('Type: LONG LIFE / SAFE cell\n');
fprintf('----------------------------------------\n');
fprintf('Cell Specifications:\n');
fprintf('  Capacity: %.1f Ah\n', battery_LFP.Q_nom);
fprintf('  Voltage: %.2f - %.2f V (nom: %.2f V)\n', battery_LFP.V_min, battery_LFP.V_max, battery_LFP.V_nom);
fprintf('  Max Discharge: %.0f A (%.0fC!) ⚡\n', battery_LFP.I_max_discharge_cont, battery_LFP.I_max_discharge_cont/battery_LFP.Q_nom);
fprintf('  Internal Resistance: %.1f mOhm (Very Low!)\n', battery_LFP.R_total*1000);
fprintf('  Cycle Life: >3000 cycles to 80%% SOH 🔋\n');
fprintf('  Safety: Excellent (thermal stability)\n');
fprintf('----------------------------------------\n');
fprintf('Advantages:\n');
fprintf('  ✓ Very long cycle life\n');
fprintf('  ✓ Excellent safety (no thermal runaway)\n');
fprintf('  ✓ High power capability\n');
fprintf('  ✓ Good low-temperature performance\n');
fprintf('  ✓ Lower cost per cycle\n');
fprintf('Disadvantages:\n');
fprintf('  ✗ Lower energy density\n');
fprintf('  ✗ Flat OCV (harder SOC estimation)\n');
fprintf('----------------------------------------\n');
fprintf('Pack Config: %dS%dP (%d cells)\n', pack_LFP.N_series, pack_LFP.N_parallel, pack_LFP.N_total);
fprintf('  Pack Voltage: %.1f V\n', pack_LFP.V_nom);
fprintf('  Pack Energy: %.2f kWh\n', pack_LFP.E_nom/1000);
fprintf('  Peak Power: %.0f kW\n', pack_LFP.P_max_discharge/1000);
fprintf('  Expected Life: >3000 deep cycles\n');
fprintf('========================================\n\n');
