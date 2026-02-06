# Test Cases Overview

This directory contains test scenarios for validating motor, battery, and integrated system models.

## Directory Structure

```
04_test_cases/
├── motor_tests/          # Motor control validation tests
├── battery_tests/        # Battery behavior tests
├── control_tests/        # Control algorithm verification
└── system_tests/         # Integrated system tests
```

## Motor Tests

### Basic Tests
- `test_motor_no_load.m` - No-load operation, check losses
- `test_motor_rated_load.m` - Rated operating point validation
- `test_motor_overload.m` - Short-term overload capability

### Dynamic Response
- `test_speed_step_response.m` - Speed controller step response
- `test_torque_step_response.m` - Torque controller step response
- `test_load_disturbance.m` - Load disturbance rejection

### Control Validation
- `test_FOC_basic.m` - Field-Oriented Control validation
- `test_dq_decoupling.m` - Verify dq-axis decoupling
- `test_field_weakening.m` - High-speed operation
- `test_MTPA.m` - Maximum Torque Per Ampere (IPMSM)

### Thermal Tests
- `test_motor_thermal_transient.m` - Thermal time constants
- `test_motor_continuous_rating.m` - Continuous power rating
- `test_motor_derating.m` - Temperature derating curves

## Battery Tests

### Electrical Characterization
- `test_battery_OCV.m` - Open-circuit voltage measurement
- `test_battery_resistance.m` - Internal resistance extraction
- `test_battery_pulse.m` - HPPC (Hybrid Pulse Power Characterization)

### Discharge Profiles
- `test_battery_constant_current.m` - CC discharge at various C-rates
- `test_battery_constant_power.m` - CP discharge
- `test_battery_variable_load.m` - Dynamic power profile

### SOC Estimation
- `test_SOC_coulomb_counting.m` - Coulomb counting accuracy
- `test_SOC_EKF.m` - Extended Kalman Filter performance
- `test_SOC_error_recovery.m` - Error correction capability

### Thermal Tests
- `test_battery_self_heating.m` - Heat generation validation
- `test_battery_cooling.m` - Thermal management effectiveness
- `test_battery_temperature_effects.m` - Parameter variation with T

### Degradation
- `test_battery_cycle_aging.m` - Capacity fade from cycling
- `test_battery_calendar_aging.m` - Storage degradation

## Control Tests

### PI Controller Tuning
- `test_current_controller_bandwidth.m` - Current loop response
- `test_speed_controller_bandwidth.m` - Speed loop response
- `test_controller_stability_margins.m` - Gain/phase margins

### Modulation
- `test_SVM.m` - Space Vector Modulation validation
- `test_PWM.m` - Sinusoidal PWM comparison
- `test_modulation_limits.m` - Overmodulation behavior

### Observers
- `test_sensorless_observer.m` - Position/speed estimation
- `test_flux_observer.m` - Flux estimation accuracy
- `test_observer_startup.m` - Low-speed sensorless operation

## System Tests

### Integrated System
- `test_motor_battery_integration.m` - Complete powertrain
- `test_regenerative_braking.m` - Energy recovery
- `test_drive_cycle_UDDS.m` - Urban driving cycle
- `test_drive_cycle_HWFET.m` - Highway cycle
- `test_drive_cycle_US06.m` - Aggressive driving

### Efficiency Analysis
- `test_efficiency_map.m` - Motor efficiency map generation
- `test_system_efficiency.m` - End-to-end efficiency
- `test_energy_consumption.m` - Energy per kilometer

### Thermal Management
- `test_system_thermal.m` - Coupled thermal analysis
- `test_cooling_strategy.m` - Thermal control validation
- `test_cold_start.m` - Low-temperature operation
- `test_hot_ambient.m` - High-temperature operation

### Fault Scenarios
- `test_sensor_fault.m` - Sensor failure handling
- `test_phase_loss.m` - Single-phase open circuit
- `test_overcurrent.m` - Overcurrent protection
- `test_overvoltage.m` - Overvoltage protection

## Running Tests

### Individual Test
```matlab
cd('04_test_cases/motor_tests')
run('test_speed_step_response.m')
```

### All Tests in Category
```matlab
% (To be implemented)
% run_all_motor_tests
% run_all_battery_tests
% run_all_system_tests
```

### Generate Report
```matlab
% (To be implemented)
% generate_test_report
```

## Test Templates

Each test should follow this structure:

```matlab
%% Test Name and Description
% Brief description of what is being tested
% Expected outcome
% Acceptance criteria

clear; clc;

%% Initialize
run('../../03_scripts/initialization/init_workspace.m');

%% Test Configuration
test.name = 'Test Name';
test.duration = 2.0;  % seconds
% ... test-specific parameters

%% Run Simulation
sim_out = sim('model_name.slx');

%% Analyze Results
% Extract key signals
% Calculate metrics
% Compare with expectations

%% Pass/Fail Criteria
pass = true;
tolerance = 0.05;  % 5%

if abs(actual - expected) / expected > tolerance
    pass = false;
    warning('Test FAILED: Metric outside tolerance');
end

%% Display Results
fprintf('Test: %s\n', test.name);
fprintf('Status: %s\n', string(pass));
fprintf('Expected: %.3f\n', expected);
fprintf('Actual: %.3f\n', actual);
fprintf('Error: %.1f%%\n', abs(actual-expected)/expected*100);

%% Plot Results (optional)
plot_results(sim_out);
```

## Validation Data

Reference data for validation is stored in:
- `05_data/experimental_data/` - Test bench measurements
- `05_data/motor_parameters/` - Datasheet specifications
- `05_data/battery_parameters/` - Cell characterization data

## Acceptance Criteria

### Motor Tests
- Speed tracking error: < 5% steady-state, < 10% transient
- Current tracking error: < 5%
- Efficiency within 3% of datasheet
- Temperature prediction within 5°C

### Battery Tests
- Voltage prediction: < 50 mV error
- SOC estimation: < 3% error
- Temperature prediction: < 3°C error

### System Tests
- Energy consumption: < 10% error vs. experimental
- Efficiency: Within 5% of target
- Thermal limits: Not exceeded under any scenario

## Continuous Integration (Future)

```yaml
# Example CI pipeline structure
test_motor_models:
  - run all motor tests
  - check pass/fail
  - generate coverage report

test_battery_models:
  - run all battery tests
  - validate against data
  - check degradation models

test_system:
  - run drive cycles
  - check efficiency targets
  - validate thermal management
```

---

**Next Steps**:
1. Review test templates
2. Run basic validation tests
3. Create custom tests for your application
4. Document test results
5. Build regression test suite
