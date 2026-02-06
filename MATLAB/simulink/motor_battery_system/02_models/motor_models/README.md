# Motor Models

This directory contains Simscape models for various electric motor types.

## Available Models

### PMSM (Permanent Magnet Synchronous Motor)
- `PMSM_basic.slx` - Simple PMSM model with open-loop control
- `PMSM_FOC.slx` - PMSM with Field-Oriented Control
- `PMSM_FOC_sensorless.slx` - Sensorless control using back-EMF observer
- `PMSM_thermal.slx` - PMSM with thermal coupling
- `IPMSM_MTPA.slx` - Interior PMSM with Maximum Torque Per Ampere control
- `PMSM_field_weakening.slx` - FOC with field weakening for high-speed operation

### BLDC (Brushless DC Motor)
- `BLDC_basic.slx` - BLDC with Hall sensor commutation
- `BLDC_trapezoidal_control.slx` - Six-step commutation control

### Induction Motor
- `IM_basic.slx` - Induction motor with V/f control
- `IM_FOC.slx` - Vector control for induction motor
- `IM_DTC.slx` - Direct Torque Control implementation

## Model Complexity Levels

### Level 1: Learning Models
- Ideal components
- No losses
- Simple control
- **Use for**: Understanding basic principles

### Level 2: Engineering Models
- Realistic electrical parameters
- Copper and iron losses
- PI controllers with proper tuning
- **Use for**: Control design and validation

### Level 3: High-Fidelity Models
- Full thermal coupling
- Saturation effects
- Detailed loss modeling
- **Use for**: Performance prediction, HIL preparation

## Quick Start

1. **Load motor parameters**:
   ```matlab
   run('../../05_data/motor_parameters/PMSM_example.m')
   ```

2. **Open model**:
   ```matlab
   open_system('PMSM_FOC.slx')
   ```

3. **Run simulation**:
   ```matlab
   sim('PMSM_FOC.slx')
   ```

4. **Plot results**:
   ```matlab
   run('../../06_utilities/plotting/plot_motor_results.m')
   ```

## Parameter Requirements

Each motor model requires a parameter structure. See examples in `05_data/motor_parameters/`.

### PMSM Parameters
```matlab
motor.Rs = 0.285;           % Stator resistance [Ohm]
motor.Ld = 0.00085;         % d-axis inductance [H]
motor.Lq = 0.00085;         % q-axis inductance [H]
motor.lambda_m = 0.1827;    % PM flux linkage [Wb]
motor.p = 4;                % Pole pairs
motor.J = 0.0001;           % Inertia [kg.m^2]
motor.B = 0.0001;           % Friction [N.m.s/rad]
motor.V_rated = 48;         % Rated voltage [V]
motor.I_rated = 10;         % Rated current [A]
motor.T_rated = 1.5;        % Rated torque [Nm]
motor.n_rated = 3000;       % Rated speed [rpm]
```

## Control Parameters

### Current Controller (PI)
```matlab
ctrl.Ki_d = 50;     % d-axis integral gain
ctrl.Kp_d = 0.5;    % d-axis proportional gain
ctrl.Ki_q = 50;     % q-axis integral gain
ctrl.Kp_q = 0.5;    % q-axis proportional gain
ctrl.BW_i = 1000;   % Current loop bandwidth [rad/s]
```

### Speed Controller (PI)
```matlab
ctrl.Ki_w = 0.1;    % Speed integral gain
ctrl.Kp_w = 0.01;   % Speed proportional gain
ctrl.BW_w = 100;    % Speed loop bandwidth [rad/s]
```

## Simulation Settings

### Fixed-Step
- **Solver**: ode4 (Runge-Kutta)
- **Step size**: 1e-6 to 1e-5 s (for power electronics switching)
- **Use for**: Code generation, HIL

### Variable-Step
- **Solver**: ode23t or ode15s
- **RelTol**: 1e-3
- **AbsTol**: 1e-6
- **Use for**: Faster simulation during development

## Model Documentation

Each model includes:
- **Annotations**: Explaining key subsystems
- **Scopes**: Pre-configured for key signals
- **Data Inspector**: Signal logging configuration
- **Test harness**: Standard test scenarios

## Validation

Compare simulation results with:
- Analytical calculations
- Manufacturer datasheets
- Experimental measurements

See `04_test_cases/motor_tests/` for validation scripts.

## Troubleshooting

### Simulation runs slow
- Reduce simulation time
- Increase solver step size
- Simplify model (remove thermal effects)
- Use accelerator mode

### Unstable simulation
- Check PI controller gains
- Verify current/voltage limits
- Check solver settings
- Add rate limiters

### Incorrect steady-state
- Verify motor parameters
- Check load torque
- Verify control references
- Check for integration drift

## References

See `01_theory/01_motor_theory.md` for detailed mathematical background.

---

**Next Steps**:
1. Review theory documentation
2. Load example parameters
3. Run basic model
4. Modify parameters for your application
5. Validate against test data
