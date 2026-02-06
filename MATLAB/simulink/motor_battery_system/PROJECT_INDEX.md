# Project Index - Quick Reference

## Theory Documents (01_theory/)

| Document | Topics Covered | Key Equations |
|----------|----------------|---------------|
| [01_motor_theory.md](01_theory/01_motor_theory.md) | PMSM, BLDC, Induction motors, dq transformation, losses | Clarke/Park transforms, Torque equations |
| [02_battery_theory.md](01_theory/02_battery_theory.md) | Equivalent circuits, SOC/SOH, thermal, degradation | Thevenin model, Kalman filter |
| [03_control_theory.md](01_theory/03_control_theory.md) | FOC, SVM, sensorless control, DTC | PI controller design, Back-EMF estimation |
| [04_thermal_theory.md](01_theory/04_thermal_theory.md) | Heat transfer, thermal networks, cooling systems | Heat generation, Lumped capacitance |
| [05_system_integration.md](01_theory/05_system_integration.md) | Power flow, energy management, drive cycles | Efficiency, Energy consumption |

## Models (02_models/)

### Motor Models
- **PMSM**: Surface-mounted and Interior PMSMs with FOC
- **BLDC**: Trapezoidal control with Hall sensors
- **Induction Motor**: V/f and FOC control
- **Thermal**: Coupled electro-thermal models

### Battery Models
- **Electrical**: Simple, Thevenin (1RC, 2RC), PNGV
- **Thermal**: Lumped and distributed thermal networks
- **Pack**: Multi-cell configurations
- **BMS**: Complete battery management system

### Control Systems
- **FOC**: Field-Oriented Control implementation
- **Sensorless**: Observer-based position estimation
- **SVM**: Space Vector Modulation
- **Thermal Control**: Active cooling/heating

## Scripts (03_scripts/)

### Initialization
- `init_workspace.m` - Load all parameters and configure workspace

### Analysis
- `calculate_motor_efficiency.m` - Efficiency map generation
- `calculate_battery_SOC.m` - SOC estimation
- `analyze_drive_cycle.m` - Energy consumption analysis

### Optimization
- `optimize_controller_gains.m` - PI tuning
- `optimize_thermal_management.m` - Cooling optimization

## Test Cases (04_test_cases/)

### Motor Tests
- Speed/torque step response
- FOC validation
- Field weakening
- Thermal transients

### Battery Tests
- OCV characterization
- Pulse tests (HPPC)
- SOC estimation accuracy
- Thermal behavior

### System Tests
- Drive cycle simulation (UDDS, HWFET, US06)
- Regenerative braking
- Efficiency mapping
- Fault scenarios

## Data (05_data/)

### Motor Parameters
- `PMSM_example.m` - 1.5 kW PMSM
- Create custom: Copy and modify for your motor

### Battery Parameters
- `LG_INR18650_MJ1.m` - 3.5 Ah NMC cell
- Create custom: Copy and modify for your battery

### Drive Cycles
- UDDS (Urban)
- HWFET (Highway)
- US06 (Aggressive)
- WLTC (Combined)

### Experimental Data
- Motor test bench data
- Battery characterization
- Thermal measurements

## Utilities (06_utilities/)

### Plotting
- `plot_motor_results.m` - Comprehensive motor visualization
- `plot_battery_results.m` - Battery performance plots
- `plot_efficiency_map.m` - Efficiency contour plots

### Data Processing
- `import_test_data.m` - Load experimental data
- `resample_data.m` - Synchronize time series
- `filter_noise.m` - Signal conditioning

### Reporting
- `generate_performance_report.m` - Automated reporting
- `export_to_excel.m` - Data export

## Quick Start Workflows

### Workflow 1: Motor Control Development

```matlab
% 1. Initialize workspace
run('03_scripts/initialization/init_workspace.m');

% 2. Open motor model
% open_system('02_models/motor_models/PMSM_FOC.slx');

% 3. Modify speed reference or load torque in model

% 4. Run simulation
% sim_out = sim('PMSM_FOC.slx');

% 5. Plot results
% plot_motor_results(sim_out);

% 6. Analyze efficiency
% analyze_motor_efficiency(sim_out);
```

### Workflow 2: Battery Pack Design

```matlab
% 1. Initialize
run('03_scripts/initialization/init_workspace.m');

% 2. Modify pack configuration
pack.N_series = 120;  % Your series count
pack.N_parallel = 3;  % Your parallel count

% 3. Recalculate pack parameters
pack.V_nom = pack.N_series * battery.V_nom;
pack.Q_nom = pack.N_parallel * battery.Q_nom;
pack.E_nom = pack.V_nom * pack.Q_nom;

% 4. Open battery pack model
% open_system('02_models/battery_models/battery_pack.slx');

% 5. Run discharge simulation
% sim_out = sim('battery_pack.slx');

% 6. Analyze results
% plot_battery_results(sim_out);
```

### Workflow 3: Complete System Integration

```matlab
% 1. Initialize all subsystems
run('03_scripts/initialization/init_workspace.m');

% 2. Load drive cycle
% run('05_data/drive_cycles/UDDS.m');

% 3. Open integrated model
% open_system('02_models/integrated_systems/motor_battery_system.slx');

% 4. Run drive cycle simulation
% sim_out = sim('motor_battery_system.slx');

% 5. Calculate energy consumption
% energy_per_km = calculate_energy_consumption(sim_out);
% fprintf('Energy consumption: %.2f Wh/km\n', energy_per_km);

% 6. Generate comprehensive report
% generate_performance_report(sim_out);
```

## Key Parameters Reference

### Motor (PMSM Example)
```matlab
Rs = 0.285 Ω
Ld = Lq = 0.85 mH
λm = 0.1827 Wb
p = 4 pole pairs
Rated: 1.5 kW, 3000 rpm
```

### Battery (LG MJ1)
```matlab
Capacity: 3.5 Ah
Voltage: 2.5-4.2 V (nominal 3.635 V)
R0 = 25 mΩ
Max discharge: 10 A (continuous)
Pack example: 96S2P = 349 V, 7 Ah, 2.4 kWh
```

### Controller
```matlab
Current loop BW: 1000 rad/s (159 Hz)
Speed loop BW: 50 rad/s (8 Hz)
PWM frequency: 10 kHz
```

## Common Tasks - Command Reference

| Task | Command |
|------|---------|
| Initialize workspace | `run('03_scripts/initialization/init_workspace.m')` |
| Load motor parameters | `run('05_data/motor_parameters/PMSM_example.m')` |
| Load battery parameters | `run('05_data/battery_parameters/LG_INR18650_MJ1.m')` |
| Plot motor results | `plot_motor_results(sim_out)` |
| Plot battery results | `plot_battery_results(sim_out)` |
| Run test case | `run('04_test_cases/motor_tests/test_name.m')` |

## File Naming Conventions

- **Models**: `component_description.slx` (e.g., `PMSM_FOC.slx`)
- **Scripts**: `action_subject.m` (e.g., `plot_motor_results.m`)
- **Parameters**: `BRAND_MODEL.m` (e.g., `LG_INR18650_MJ1.m`)
- **Tests**: `test_category_name.m` (e.g., `test_speed_step_response.m`)

## Variable Naming Conventions

- **Motor**: `motor.*` (e.g., `motor.Rs`, `motor.lambda_m`)
- **Control**: `ctrl.*` (e.g., `ctrl.Kp_d`, `ctrl.BW_current`)
- **Battery**: `battery.*` (e.g., `battery.Q_nom`, `battery.OCV_lut`)
- **Pack**: `pack.*` (e.g., `pack.N_series`, `pack.V_nom`)
- **Thermal**: `thermal.*` (e.g., `thermal.C_th`, `thermal.R_th`)
- **BMS**: `bms.*` (e.g., `bms.SOC_max_operating`)

## Development Phases

### Phase 1: Foundation (Weeks 1-4)
- ✅ Read theory documentation
- ✅ Understand coordinate transformations
- ✅ Study equivalent circuit models
- ⬜ Run example models

### Phase 2: Component Models (Weeks 5-8)
- ⬜ Build PMSM with FOC
- ⬜ Build battery with thermal model
- ⬜ Validate against datasheets
- ⬜ Parameter identification

### Phase 3: Advanced Control (Weeks 9-12)
- ⬜ Implement sensorless control
- ⬜ Add field weakening
- ⬜ Implement BMS logic
- ⬜ Optimize control parameters

### Phase 4: System Integration (Weeks 13-16)
- ⬜ Integrate motor + battery + inverter
- ⬜ Add thermal management
- ⬜ Implement drive cycles
- ⬜ System-level optimization

### Phase 5: Validation & Deployment (Weeks 17-20)
- ⬜ Compare with experimental data
- ⬜ Refine models
- ⬜ Code generation for HIL
- ⬜ Documentation

## Troubleshooting Guide

| Issue | Likely Cause | Solution |
|-------|--------------|----------|
| Undefined variable error | Workspace not initialized | Run `init_workspace.m` |
| Slow simulation | Small time step | Increase tolerances or use variable-step |
| Oscillating controller | Gains too high | Reduce bandwidth, retune gains |
| Solver error | Stiff system | Use ode15s or ode23t |
| Temperature runaway | Thermal resistance too low | Check thermal parameters |
| SOC drift | Current sensor error | Verify efficiency, use EKF |

## References & Resources

- **MATLAB Documentation**: Type `doc simscape` in command window
- **Simscape Examples**: Type `sscexplore` in command window
- **Theory Background**: See `01_theory/*.md` files
- **Parameter Files**: `05_data/motor_parameters/`, `05_data/battery_parameters/`

---

**Project Status**: Foundation Complete ✅
**Last Updated**: February 3, 2026
**Version**: 1.0.0
