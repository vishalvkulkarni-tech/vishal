# Battery Models

This directory contains Simscape models for battery systems with varying levels of complexity.

## Available Models

### Electrical Models
- `battery_simple.slx` - Simple voltage source with internal resistance
- `battery_thevenin_1RC.slx` - Thevenin model with one RC pair
- `battery_thevenin_2RC.slx` - Dual polarization model (recommended for most applications)
- `battery_PNGV.slx` - Partnership for New Generation Vehicles model
- `battery_pack.slx` - Multi-cell pack with series/parallel configuration

### Thermal Models
- `battery_thermal_lumped.slx` - Single-node thermal model
- `battery_thermal_multinode.slx` - Distributed thermal network
- `battery_pack_thermal.slx` - Pack-level thermal analysis with cell-to-cell variation

### State Estimation
- `battery_SOC_coulomb_counting.slx` - Basic coulomb counting
- `battery_SOC_EKF.slx` - Extended Kalman Filter for SOC estimation
- `battery_SOH_estimation.slx` - State of Health tracking

### Complete Systems
- `battery_with_BMS.slx` - Battery with Battery Management System
- `battery_thermal_management.slx` - Battery with active cooling/heating

## Model Complexity Levels

### Level 1: Basic Models
- Constant OCV and resistance
- No temperature effects
- **Use for**: Initial system sizing, quick analysis

### Level 2: Engineering Models
- SOC-dependent OCV and resistance
- Temperature-dependent parameters
- Thermal dynamics
- **Use for**: Control design, performance analysis

### Level 3: High-Fidelity Models
- Multi-RC polarization
- Reversible and irreversible heat
- Degradation tracking
- **Use for**: Detailed design, lifetime prediction

## Quick Start

1. **Load battery parameters**:
   ```matlab
   run('../../05_data/battery_parameters/LG_INR18650_MJ1.m')
   ```

2. **Open model**:
   ```matlab
   open_system('battery_thevenin_2RC.slx')
   ```

3. **Run simulation**:
   ```matlab
   sim('battery_thevenin_2RC.slx')
   ```

4. **Analyze results**:
   ```matlab
   run('../../06_utilities/plotting/plot_battery_results.m')
   ```

## Parameter Requirements

### Basic Parameters
```matlab
battery.Q_nom = 3.5;            % Nominal capacity [Ah]
battery.V_nom = 3.635;          % Nominal voltage [V]
battery.V_max = 4.2;            % Max voltage [V]
battery.V_min = 2.5;            % Min voltage [V]
battery.I_max_charge = 3.5;     % Max charge current [A] (1C)
battery.I_max_discharge = 10;   % Max discharge current [A]
battery.SOC_init = 0.8;         % Initial SOC [0-1]
```

### Electrical Model (2RC)
```matlab
% Open-circuit voltage (OCV) vs SOC lookup table
battery.SOC_lut = [0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0];
battery.OCV_lut = [2.5 3.2 3.4 3.5 3.6 3.65 3.7 3.8 3.95 4.1 4.2];  % [V]

% Resistances (can be SOC and temperature dependent)
battery.R0 = 0.020;             % Ohmic resistance [Ohm]
battery.R1 = 0.010;             % Polarization resistance 1 [Ohm]
battery.C1 = 500;               % Polarization capacitance 1 [F]
battery.R2 = 0.015;             % Polarization resistance 2 [Ohm]
battery.C2 = 5000;              % Polarization capacitance 2 [F]
```

### Thermal Parameters
```matlab
thermal.mass = 0.045;           % Cell mass [kg]
thermal.Cp = 1000;              % Specific heat [J/kg/K]
thermal.R_th = 10;              % Thermal resistance [K/W]
thermal.T_init = 25;            % Initial temperature [°C]
thermal.T_amb = 25;             % Ambient temperature [°C]
```

### Battery Pack Configuration
```matlab
pack.N_series = 96;             % Cells in series
pack.N_parallel = 2;            % Cells in parallel
pack.V_pack = pack.N_series * battery.V_nom;  % Pack voltage [V]
pack.Q_pack = pack.N_parallel * battery.Q_nom;  % Pack capacity [Ah]
pack.E_pack = pack.V_pack * pack.Q_pack;  % Pack energy [Wh]
```

## State of Charge (SOC) Estimation

### Coulomb Counting
```matlab
SOC(t) = SOC(0) - (1/Q_nom) * integral(I*dt)
```

Advantages: Simple, real-time
Disadvantages: Drift, needs initial SOC

### Extended Kalman Filter (EKF)
- Combines coulomb counting with voltage measurement
- Corrects for modeling errors and measurement noise
- Recommended for BMS applications

Parameters:
```matlab
EKF.Q = 1e-6;           % Process noise covariance
EKF.R = 1e-4;           % Measurement noise covariance
EKF.P0 = 0.01;          % Initial error covariance
```

## Thermal Modeling

### Heat Generation
```matlab
Q_gen = I^2 * R_total + I * T * dOCV_dT  % [W]
```

Components:
- Joule heating (always positive)
- Reversible heat (entropic, can be negative)

### Temperature Dynamics
```matlab
m * Cp * dT/dt = Q_gen - (T - T_amb) / R_th
```

## Battery Management System (BMS)

### Protection Functions
- **Overvoltage**: Disconnect if V_cell > V_max
- **Undervoltage**: Disconnect if V_cell < V_min
- **Overcurrent charge**: Limit I_charge < I_max_charge
- **Overcurrent discharge**: Limit I_discharge < I_max_discharge
- **Over-temperature**: Reduce power if T > T_max
- **Under-temperature**: Reduce power if T < T_min

### Cell Balancing
- Passive: Resistor dissipation
- Active: Charge redistribution

### Power Limits
```matlab
P_discharge_max = min([
    V_pack * I_max_discharge,
    (V_pack - V_min * N_series) / R_total * V_pack,
    P_thermal_limit
]);

P_charge_max = min([
    V_pack * I_max_charge,
    (V_max * N_series - V_pack) / R_total * V_pack,
    P_thermal_limit,
    P_SOC_limit
]);
```

## Degradation Modeling

### Capacity Fade
```matlab
Q_current = Q_initial * (1 - k_cal * sqrt(t) - k_cyc * N_cycles^0.5)
```

Factors:
- Calendar aging: Time at temperature and SOC
- Cycle aging: Number and depth of cycles
- Temperature: Arrhenius relationship

### Resistance Growth
```matlab
R(t) = R0 * (1 + k_R * t)
```

## Example Battery Cells

Pre-configured parameters available in `05_data/battery_parameters/`:

- **LG INR18650-MJ1**: 3.5 Ah, NMC chemistry
- **Samsung INR18650-25R**: 2.5 Ah, high power
- **Panasonic NCR18650B**: 3.35 Ah, high energy
- **LiFePO4 26650**: 3.2V nominal, LFP chemistry

## Simulation Settings

### For Electrical Dynamics
- **Solver**: ode23t or ode15s (stiff solvers)
- **RelTol**: 1e-4
- **AbsTol**: 1e-6
- **Step size**: Variable, max 0.1 s

### For Thermal Dynamics
- **Can use larger step**: 1-10 s
- **Thermal time constants**: Minutes to hours
- **Separate fast/slow dynamics**: Use multirate simulation

## Validation

### OCV Characterization
1. Fully charge battery
2. Discharge at C/20 rate
3. Record voltage vs. capacity
4. Convert to SOC

### Pulse Test (HPPC)
1. Discharge to target SOC
2. Rest 1 hour
3. 10s discharge pulse at 1C
4. Rest 40s
5. 10s charge pulse
6. Extract R0, R1, C1 from response

### Thermal Test
1. Apply constant current
2. Monitor temperature rise
3. Fit to exponential: Extract R_th, C_th

## Troubleshooting

### SOC drift
- Check coulombic efficiency (should be ~1.0)
- Verify current sensor calibration
- Use EKF instead of pure coulomb counting

### Voltage mismatch
- Verify OCV curve accuracy
- Check RC parameters (pulse test)
- Consider temperature effects

### Thermal runaway
- Check heat generation calculation
- Verify thermal resistance values
- Add temperature-dependent limits

## Safety Considerations

Always implement:
1. Voltage limits (cell level and pack level)
2. Current limits (charge and discharge)
3. Temperature limits (charge and discharge)
4. SOC window limiting (avoid extremes)
5. Fault detection and isolation

## References

See `01_theory/02_battery_theory.md` for detailed mathematical background.

---

**Next Steps**:
1. Review battery theory
2. Load example cell parameters
3. Run characterization simulation
4. Validate OCV and resistance curves
5. Implement BMS logic
