%% Battery Cell Parameters - Panasonic NCR18650B
% Lithium Nickel Cobalt Aluminum Oxide (NCA) Chemistry
% 18650 Format - High Energy Density Cell
% Used in Tesla Model S/X (older generations)

clear battery_NCR thermal_NCR pack_NCR

%% Cell Identification
battery_NCR.name = 'Panasonic NCR18650B';
battery_NCR.chemistry = 'NCA';
battery_NCR.form_factor = '18650';
battery_NCR.manufacturer = 'Panasonic';

%% Basic Electrical Specifications
battery_NCR.Q_nom = 3.35;           % High capacity [Ah]
battery_NCR.V_nom = 3.60;           % Nominal voltage [V]
battery_NCR.V_max = 4.20;           % Maximum voltage [V]
battery_NCR.V_min = 2.50;           % Minimum voltage [V]
battery_NCR.E_nom = battery_NCR.Q_nom * battery_NCR.V_nom;

%% Current Limits (Energy-optimized, not power)
battery_NCR.I_max_charge_cont = 1.6;       % Conservative 0.5C [A]
battery_NCR.I_max_charge_peak = 3.35;      % 1C peak [A]
battery_NCR.I_max_discharge_cont = 6.7;    % 2C continuous [A]
battery_NCR.I_max_discharge_peak = 13.4;   % 4C peak [A]

%% State of Charge
battery_NCR.SOC_init = 0.80;
battery_NCR.SOC_max = 1.00;
battery_NCR.SOC_min = 0.00;

%% OCV Characterization (NCA chemistry - flatter curve)
battery_NCR.SOC_lut = [0.00, 0.05, 0.10, 0.15, 0.20, 0.25, 0.30, 0.35, 0.40, 0.45, ...
                       0.50, 0.55, 0.60, 0.65, 0.70, 0.75, 0.80, 0.85, 0.90, 0.95, 1.00];

battery_NCR.OCV_lut = [2.50, 3.12, 3.28, 3.38, 3.45, 3.51, 3.56, 3.60, 3.64, 3.67, ...
                       3.70, 3.73, 3.76, 3.79, 3.83, 3.87, 3.92, 3.98, 4.06, 4.13, 4.20];

%% Internal Resistance (Higher than power cells)
battery_NCR.R0_ref = 0.035;         % Higher for energy cell [Ohm]
battery_NCR.R0_SOC_lut = battery_NCR.SOC_lut;
battery_NCR.R0_SOC_mult = [1.40, 1.32, 1.25, 1.19, 1.14, 1.10, 1.07, 1.05, 1.03, 1.02, ...
                           1.00, 1.00, 1.01, 1.02, 1.03, 1.05, 1.08, 1.13, 1.20, 1.28, 1.38];

battery_NCR.R0_T_ref = 25;
battery_NCR.R0_Ea = 3800;

battery_NCR.R1_ref = 0.020;
battery_NCR.C1_ref = 550;
battery_NCR.tau1 = battery_NCR.R1_ref * battery_NCR.C1_ref;

battery_NCR.R2_ref = 0.025;
battery_NCR.C2_ref = 9000;
battery_NCR.tau2 = battery_NCR.R2_ref * battery_NCR.C2_ref;

battery_NCR.R_total = battery_NCR.R0_ref + battery_NCR.R1_ref + battery_NCR.R2_ref;

%% Thermal Parameters
thermal_NCR.mass = 0.0475;          % Slightly heavier
thermal_NCR.volume = 1.66e-5;
thermal_NCR.Cp = 980;
thermal_NCR.C_th = thermal_NCR.mass * thermal_NCR.Cp;
thermal_NCR.R_th_radial = 11.0;     % Lower heat dissipation
thermal_NCR.R_th_axial = 5.5;
thermal_NCR.R_th = thermal_NCR.R_th_radial;

thermal_NCR.T_init = 25;
thermal_NCR.T_amb = 25;
thermal_NCR.T_charge_max = 45;
thermal_NCR.T_charge_min = 0;
thermal_NCR.T_discharge_max = 60;
thermal_NCR.T_discharge_min = -20;
thermal_NCR.dOCV_dT = -0.0006;

%% Capacity Temperature Dependence
battery_NCR.T_lut = [-20, -10, 0, 10, 25, 40, 60];
battery_NCR.Q_T_mult = [0.60, 0.72, 0.83, 0.92, 1.00, 1.04, 1.06];

%% Degradation (Excellent calendar life, good cycle life)
battery_NCR.aging.k_cal = 3.2e-10;  % Very good calendar aging
battery_NCR.aging.Ea_cal = 26000;
battery_NCR.aging.z_cal = 0.5;
battery_NCR.aging.k_cyc = 1.8e-5;
battery_NCR.aging.Ea_cyc = 19000;
battery_NCR.aging.z_cyc = 0.58;

battery_NCR.SOH_capacity = 1.00;
battery_NCR.SOH_resistance = 1.00;
battery_NCR.eta_coulombic = 0.999;  % Very high efficiency

%% Pack Configuration (Optimized for range)
pack_NCR.N_series = 96;
pack_NCR.N_parallel = 74;           % Many parallel for high energy
pack_NCR.N_total = pack_NCR.N_series * pack_NCR.N_parallel;

pack_NCR.V_nom = pack_NCR.N_series * battery_NCR.V_nom;
pack_NCR.V_max = pack_NCR.N_series * battery_NCR.V_max;
pack_NCR.V_min = pack_NCR.N_series * battery_NCR.V_min;
pack_NCR.Q_nom = pack_NCR.N_parallel * battery_NCR.Q_nom;
pack_NCR.E_nom = pack_NCR.V_nom * pack_NCR.Q_nom;

pack_NCR.I_max_charge_cont = pack_NCR.N_parallel * battery_NCR.I_max_charge_cont;
pack_NCR.I_max_discharge_cont = pack_NCR.N_parallel * battery_NCR.I_max_discharge_cont;
pack_NCR.P_max_charge = pack_NCR.V_nom * pack_NCR.I_max_charge_cont;
pack_NCR.P_max_discharge = pack_NCR.V_nom * pack_NCR.I_max_discharge_cont;

%% Display Summary
fprintf('\n========================================\n');
fprintf('Battery Cell Parameters Loaded\n');
fprintf('========================================\n');
fprintf('Cell: %s\n', battery_NCR.name);
fprintf('Type: HIGH ENERGY cell\n');
fprintf('Note: Used in Tesla Model S/X\n');
fprintf('----------------------------------------\n');
fprintf('Cell Specifications:\n');
fprintf('  Capacity: %.2f Ah ⚡\n', battery_NCR.Q_nom);
fprintf('  Energy: %.2f Wh\n', battery_NCR.E_nom);
fprintf('  Voltage: %.2f - %.2f V\n', battery_NCR.V_min, battery_NCR.V_max);
fprintf('  Max Discharge: %.1f A (%.0fC)\n', battery_NCR.I_max_discharge_cont, battery_NCR.I_max_discharge_cont/battery_NCR.Q_nom);
fprintf('  Internal Resistance: %.1f mOhm\n', battery_NCR.R_total*1000);
fprintf('  Energy Density: Very High\n');
fprintf('----------------------------------------\n');
fprintf('Pack Config: %dS%dP (%d cells)\n', pack_NCR.N_series, pack_NCR.N_parallel, pack_NCR.N_total);
fprintf('  Pack Voltage: %.1f V\n', pack_NCR.V_nom);
fprintf('  Pack Capacity: %.1f Ah\n', pack_NCR.Q_nom);
fprintf('  Pack Energy: %.1f kWh 🔋\n', pack_NCR.E_nom/1000);
fprintf('  Pack Mass: %.1f kg (cells only)\n', thermal_NCR.mass * pack_NCR.N_total);
fprintf('  Range: ~400 km (example EV)\n');
fprintf('========================================\n\n');
