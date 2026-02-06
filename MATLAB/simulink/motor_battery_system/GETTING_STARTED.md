# Getting Started Guide

## Welcome!

This guide will help you get started with the Electric Motor & Battery System Modeling Framework. Follow these steps to begin developing and simulating motor and battery systems.

---

## Step 1: Prerequisites

### Required Software
- **MATLAB** R2020b or later
- **Simulink**
- **Simscape** (Foundation Library)
- **Simscape Electrical** (for motor and battery models)
- **Control System Toolbox** (for controller design)

### Recommended Toolboxes
- **Simscape Driveline** (for mechanical transmission models)
- **Optimization Toolbox** (for parameter tuning)
- **Parallel Computing Toolbox** (for faster simulation)

### Verify Installation
Run in MATLAB:
```matlab
ver
```
Check that all required products are listed.

---

## Step 2: Initialize Workspace

### Quick Start
1. Navigate to the project directory in MATLAB:
   ```matlab
   cd('c:\Users\z004f2se\OneDrive - Siemens AG\Vishal\Personal\vishal\MATLAB\simulink\motor_battery_system')
   ```

2. Run initialization script:
   ```matlab
   run('03_scripts\initialization\init_workspace.m')
   ```

This will:
- Add all folders to MATLAB path
- Load motor parameters
- Load battery parameters
- Configure simulation settings
- Display available variables

---

## Step 3: Understand the Project Structure

```
motor_battery_system/
├── 01_theory/          ← Start here! Read the theory documents
├── 02_models/          ← Simulink/Simscape models
├── 03_scripts/         ← MATLAB scripts for analysis
├── 04_test_cases/      ← Validation and test scenarios
├── 05_data/            ← Parameters and experimental data
└── 06_utilities/       ← Helper functions
```

---

## Step 4: Learn the Theory (Recommended Path)

### Week 1-2: Motor Fundamentals
Read: [01_theory/01_motor_theory.md](01_theory/01_motor_theory.md)

**Topics to understand**:
- PMSM vs BLDC vs Induction motors
- dq0 transformation (Clarke and Park)
- Torque production
- Motor losses

**Hands-on exercise**:
1. Review the motor parameter file:
   ```matlab
   edit('05_data\motor_parameters\PMSM_example.m')
   ```
2. Understand each parameter's physical meaning
3. Calculate theoretical torque constant and back-EMF

### Week 3-4: Battery Systems
Read: [01_theory/02_battery_theory.md](01_theory/02_battery_theory.md)

**Topics to understand**:
- Equivalent circuit models
- SOC estimation methods
- Thermal behavior
- Degradation mechanisms

**Hands-on exercise**:
1. Review the battery parameter file:
   ```matlab
   edit('05_data\battery_parameters\LG_INR18650_MJ1.m')
   ```
2. Plot OCV vs SOC curve:
   ```matlab
   figure;
   plot(battery.SOC_lut, battery.OCV_lut, 'LineWidth', 2);
   xlabel('State of Charge [0-1]');
   ylabel('Open Circuit Voltage [V]');
   title('OCV Characteristic');
   grid on;
   ```

### Week 5-7: Control Theory
Read: [01_theory/03_control_theory.md](01_theory/03_control_theory.md)

**Topics to understand**:
- Field-Oriented Control (FOC)
- Space Vector Modulation
- PI controller design
- Sensorless control methods

**Hands-on exercise**:
1. Calculate current controller bandwidth
2. Derive PI gains from motor parameters
3. Understand decoupling terms

### Week 8-9: Thermal Management
Read: [01_theory/04_thermal_theory.md](01_theory/04_thermal_theory.md)

**Topics to understand**:
- Heat generation mechanisms
- Thermal network modeling
- Cooling strategies

### Week 10-12: System Integration
Read: [01_theory/05_system_integration.md](01_theory/05_system_integration.md)

**Topics to understand**:
- Power flow management
- Energy management strategies
- Multi-domain coupling

---

## Step 5: Build Your First Model

### Option A: Start with Motor Control

**Goal**: Build a simple PMSM with FOC control

1. **Study the block diagram**:
   - Review FOC structure in theory document
   - Understand transformation blocks (Clarke, Park)
   - Identify current and speed controllers

2. **Create a new model** (or open example):
   ```matlab
   % Later we'll add: open_system('02_models\motor_models\PMSM_FOC.slx')
   ```

3. **Required blocks**:
   - PMSM (from Simscape Electrical)
   - Clarke Transform
   - Park Transform
   - PI Controllers (d-axis, q-axis, speed)
   - Inverse Park/Clarke
   - SVM or PWM modulator
   - Voltage Source Inverter

4. **Set parameters**:
   - Motor: Use `motor` struct from workspace
   - Controllers: Use `ctrl` struct

5. **Add measurement**:
   - Phase currents (abc)
   - Rotor position and speed
   - DC link voltage

6. **Run simulation**:
   ```matlab
   sim_out = sim('PMSM_FOC.slx');
   ```

7. **Analyze results**:
   - Plot speed response
   - Check current waveforms
   - Verify torque tracking

### Option B: Start with Battery Model

**Goal**: Simulate battery discharge with thermal effects

1. **Study equivalent circuit**:
   - Review 2RC model in theory document
   - Understand SOC calculation
   - Identify thermal coupling

2. **Create battery model**:
   ```matlab
   % Later: open_system('02_models\battery_models\battery_thevenin_2RC.slx')
   ```

3. **Required blocks**:
   - Controlled Voltage Source (OCV)
   - Resistor (R0, R1, R2)
   - Capacitor (C1, C2)
   - Integrator (for SOC)
   - Thermal Mass and Resistance

4. **Configure current profile**:
   - Constant current discharge (1C = 3.5A)
   - Or pulse discharge pattern

5. **Monitor**:
   - Terminal voltage
   - SOC
   - Temperature
   - Power/Energy

---

## Step 6: Run Test Cases

### Motor Tests
```matlab
% Navigate to test directory
cd('04_test_cases\motor_tests')

% Run speed step response test
% (script to be created)
% test_motor_speed_step

% Run torque step test
% test_motor_torque_step
```

### Battery Tests
```matlab
% Navigate to test directory
cd('04_test_cases\battery_tests')

% Run discharge profile
% test_battery_discharge

% Run pulse test (HPPC)
% test_battery_pulse
```

---

## Step 7: Customize for Your Application

### Modify Motor Parameters
1. Open parameter file:
   ```matlab
   edit('05_data\motor_parameters\PMSM_example.m')
   ```

2. Update values based on your motor datasheet:
   - Rated power, torque, speed
   - Resistance, inductance
   - Flux linkage, pole pairs

3. Save as new file:
   ```matlab
   % Example: PMSM_custom.m
   ```

4. Load your parameters:
   ```matlab
   run('05_data\motor_parameters\PMSM_custom.m')
   ```

### Modify Battery Parameters
1. Open parameter file:
   ```matlab
   edit('05_data\battery_parameters\LG_INR18650_MJ1.m')
   ```

2. Update for your battery:
   - Capacity, voltage range
   - OCV curve
   - Internal resistance

3. Update pack configuration:
   ```matlab
   pack.N_series = 120;    % Your series count
   pack.N_parallel = 3;     % Your parallel count
   ```

---

## Step 8: Advanced Topics

### Implement Sensorless Control
- Study observer-based methods
- Implement back-EMF observer
- Test at various speeds

### Add Thermal Management
- Design cooling system
- Implement thermal controller
- Optimize cooling power

### System Integration
- Connect motor + battery + inverter
- Implement drive cycle
- Analyze energy consumption

### Optimize Performance
- Tune control parameters
- Implement MTPA or field weakening
- Minimize losses

---

## Common Tasks - Quick Reference

### Load Parameters
```matlab
run('03_scripts\initialization\init_workspace.m')
```

### Simulate a Model
```matlab
sim_out = sim('model_name.slx');
```

### Plot Results
```matlab
% Time series plotting
figure;
plot(sim_out.tout, sim_out.speed);
xlabel('Time [s]');
ylabel('Speed [rad/s]');

% Access logged signals
speed_data = sim_out.logsout.get('speed');
plot(speed_data.Values);
```

### Change Simulation Time
```matlab
set_param('model_name', 'StopTime', '5.0');  % 5 seconds
```

### Export Results
```matlab
% Save to MAT file
save('results_file.mat', 'sim_out');

% Export to Excel
writematrix([sim_out.tout, sim_out.speed], 'results.xlsx');
```

---

## Troubleshooting

### "Undefined variable" error
**Solution**: Run initialization script
```matlab
run('03_scripts\initialization\init_workspace.m')
```

### "Can't find model file"
**Solution**: Check current directory or use full path
```matlab
cd('motor_battery_system')
```

### Simulation runs very slow
**Solutions**:
1. Reduce simulation time
2. Increase solver tolerance
3. Simplify model (remove thermal)
4. Use accelerator mode

### Numerical issues/instability
**Solutions**:
1. Check parameter values (especially small resistances/inductances)
2. Use stiff solver (ode15s or ode23t)
3. Reduce max step size
4. Add current/voltage limiters

---

## Next Steps

1. ✅ Complete theory reading
2. ✅ Run example models
3. ✅ Modify parameters for your application
4. ⬜ Build custom model
5. ⬜ Validate against experimental data
6. ⬜ Optimize performance
7. ⬜ Prepare for hardware testing

---

## Resources

- **Theory Documents**: `01_theory/`
- **Example Models**: `02_models/`
- **Parameters**: `05_data/`
- **MATLAB Help**: Type `doc simscape` in command window
- **Simscape Examples**: Type `sscexplore` in command window

---

## Need Help?

1. Check theory documentation for mathematical background
2. Review model README files for specific guidance
3. Look at example parameter files
4. Search MATLAB documentation: `doc [function_name]`

---

**Happy Modeling!**

Last Updated: February 3, 2026
