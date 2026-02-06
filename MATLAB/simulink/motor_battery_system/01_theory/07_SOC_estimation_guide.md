# Battery SOC Estimation - Practical Guide

## Why SOC Estimation is Hard

Unlike your phone which can measure battery voltage and assume SOC, electric vehicles face challenges:

1. **High currents** → large voltage drops across internal resistance
2. **Temperature variations** → parameters change
3. **Aging** → capacity decreases over time
4. **Flat OCV curves** (especially LFP) → small voltage differences

---

## Method Comparison

| Method | Accuracy | Complexity | Real-time | Cost |
|--------|----------|------------|-----------|------|
| **Coulomb Counting** | ±5% | Low | Yes | $ |
| **OCV-based** | ±3% | Low | No (needs rest) | $ |
| **Kalman Filter** | ±2% | High | Yes | $$ |
| **Neural Network** | ±1% | Very High | Yes | $$$ |

---

## Method 1: Coulomb Counting (Integration)

### Concept
```
SOC(t) = SOC(0) - ∫[0→t] (I(τ) / Qnom) dτ
```

Where:
- `I(τ)` = current (positive for discharge)
- `Qnom` = nominal capacity [Ah]

### Implementation
```matlab
function SOC = coulomb_counting(I, dt, SOC_init, Q_nom, eta)
    % I: current [A] (positive = discharge)
    % dt: timestep [s]
    % SOC_init: initial SOC [0-1]
    % Q_nom: nominal capacity [Ah]
    % eta: coulombic efficiency [0-1]
    
    persistent SOC_state
    if isempty(SOC_state)
        SOC_state = SOC_init;
    end
    
    % Adjust for efficiency
    if I > 0
        % Discharge
        dSOC = -I * dt / (Q_nom * 3600);
    else
        % Charge (less efficient)
        dSOC = -I * dt / (Q_nom * 3600) * eta;
    end
    
    % Integrate
    SOC_state = SOC_state + dSOC;
    
    % Clamp
    SOC = max(0, min(1, SOC_state));
end
```

### Pros ✓
- Simple to implement
- Fast computation
- Works in real-time

### Cons ✗
- **Accumulates error** over time (drift)
- Requires accurate initial SOC
- Needs precise current measurement
- Doesn't correct itself

### Improvement: Add Capacity Correction
```matlab
% Update capacity based on temperature
Q_available = Q_nom * Q_temp_factor(T);

% Update capacity based on SOH
Q_available = Q_available * SOH;
```

---

## Method 2: Open Circuit Voltage (OCV) Lookup

### Concept

When the battery is at rest (no current), terminal voltage = OCV:
```
V_terminal (at rest) = OCV(SOC)
```

Use a lookup table to find SOC from measured voltage.

### Implementation
```matlab
function SOC = OCV_lookup(V_oc, OCV_table, SOC_table)
    % V_oc: measured open circuit voltage [V]
    % OCV_table: voltage lookup table [V]
    % SOC_table: corresponding SOC values [0-1]
    
    % Interpolate
    SOC = interp1(OCV_table, SOC_table, V_oc, 'linear', 'extrap');
    
    % Clamp
    SOC = max(0, min(1, SOC));
end
```

### How to Get OCV from Terminal Voltage
```matlab
function V_oc = estimate_OCV(V_terminal, I, R0, R1, C1, R2, C2, dt)
    % Compensate for voltage drops
    
    persistent V_R1 V_R2
    if isempty(V_R1)
        V_R1 = 0;
        V_R2 = 0;
    end
    
    % RC dynamics
    tau1 = R1 * C1;
    tau2 = R2 * C2;
    
    V_R1 = V_R1 * exp(-dt/tau1) + I * R1 * (1 - exp(-dt/tau1));
    V_R2 = V_R2 * exp(-dt/tau2) + I * R2 * (1 - exp(-dt/tau2));
    
    % Estimate OCV
    V_oc = V_terminal + I*R0 + V_R1 + V_R2;
end
```

### Pros ✓
- **Self-correcting** (no drift)
- No integration error
- Simple concept

### Cons ✗
- Requires rest period (10-30 min)
- Not real-time
- Poor for flat OCV curves (LFP!)
- Affected by temperature

---

## Method 3: Extended Kalman Filter (EKF)

### Why EKF?

Combine **both methods**:
- Use coulomb counting for dynamics
- Use voltage to correct drift

**The Magic**: EKF weights measurements based on uncertainty!

### Battery Model (State Space)

**State equation**:
```
SOC(k+1) = SOC(k) - (I(k) * dt) / (Q_nom * 3600)
```

**Output equation**:
```
V_terminal(k) = OCV(SOC(k)) - I(k)*R0 - V_R1(k) - V_R2(k)
```

Where RC voltages evolve:
```
V_R1(k+1) = V_R1(k) * exp(-dt/τ1) + I(k) * R1 * (1 - exp(-dt/τ1))
V_R2(k+1) = V_R2(k) * exp(-dt/τ2) + I(k) * R2 * (1 - exp(-dt/τ2))
```

### Simplified EKF Implementation
```matlab
function [SOC_est, P] = EKF_SOC(I, V_meas, dt, params, SOC_prev, P_prev)
    % Unpack parameters
    Q_nom = params.Q_nom;
    R0 = params.R0;
    R1 = params.R1;
    C1 = params.C1;
    R2 = params.R2;
    C2 = params.C2;
    OCV_table = params.OCV_table;
    SOC_table = params.SOC_table;
    
    % Process noise
    Q_process = 1e-6;  % Tuning parameter
    
    % Measurement noise
    R_meas = 1e-3;  % Voltage sensor noise [V²]
    
    %% Prediction Step
    % State prediction
    SOC_pred = SOC_prev - (I * dt) / (Q_nom * 3600);
    
    % Covariance prediction
    P_pred = P_prev + Q_process;
    
    %% Update Step
    % Predicted voltage
    OCV_pred = interp1(SOC_table, OCV_table, SOC_pred);
    V_pred = OCV_pred - I * R0;  % Simplified (neglecting RC for clarity)
    
    % Innovation
    innovation = V_meas - V_pred;
    
    % Jacobian (dV/dSOC)
    dSOC = 0.01;  % Small perturbation
    OCV_plus = interp1(SOC_table, OCV_table, SOC_pred + dSOC);
    OCV_minus = interp1(SOC_table, OCV_table, SOC_pred - dSOC);
    H = (OCV_plus - OCV_minus) / (2 * dSOC);  % ∂V/∂SOC
    
    % Kalman Gain
    S = H * P_pred * H + R_meas;
    K = P_pred * H / S;
    
    % State update
    SOC_est = SOC_pred + K * innovation;
    
    % Covariance update
    P = (1 - K * H) * P_pred;
    
    % Clamp SOC
    SOC_est = max(0, min(1, SOC_est));
end
```

### Tuning the EKF

**Process Noise `Q`** (how much you trust the model):
- Large `Q` → trust measurements more
- Small `Q` → trust model more
- Typical: `1e-6` to `1e-4`

**Measurement Noise `R`** (voltage sensor quality):
- High quality sensor → `R = 1e-4`
- Standard sensor → `R = 1e-3`
- Noisy sensor → `R = 1e-2`

### Pros ✓
- **Best accuracy** (±1-2%)
- Real-time operation
- Self-correcting
- Handles noise well
- Provides confidence (covariance)

### Cons ✗
- Complex implementation
- Requires tuning
- Higher computational cost
- Needs accurate battery model

---

## Practical Tips

### 1. Hybrid Approach
```
Use EKF normally
↓
If voltage error > threshold → reset with OCV lookup
↓
Continue with EKF
```

### 2. Initial SOC Estimation
```matlab
% After vehicle sits overnight
if rest_time > 1800  % 30 minutes
    % Use OCV method
    SOC_init = OCV_lookup(V_terminal);
else
    % Use last known SOC (stored in EEPROM)
    SOC_init = SOC_saved;
end
```

### 3. Temperature Compensation
```matlab
% Adjust OCV lookup for temperature
OCV_at_T = OCV_at_25C + (T - 25) * dOCV_dT;
```

### 4. Handle Flat OCV (LFP Problem!)

For LFP batteries (very flat 3.2-3.3V plateau):

```matlab
if SOC > 0.1 && SOC < 0.9
    % OCV doesn't help much in this range
    % Rely more on coulomb counting
    R_meas = R_meas * 10;  % Reduce measurement trust
end
```

---

## Validation Tests

### Test 1: Constant Current Discharge
```matlab
I = 10 A (constant)
Duration = 1 hour
Expected: SOC drops by I*t/Q_nom = 10*1/3.5 = 28.6%
```

### Test 2: Dynamic Profile (Drive Cycle)
```matlab
Load realistic drive cycle
Compare: SOC_estimated vs SOC_coulomb_counting
Error should be < 3%
```

### Test 3: Error Convergence
```matlab
Start with wrong SOC_init (e.g., 0.8 instead of 0.6)
EKF should converge within 10-20 minutes
```

---

## Example: Complete SOC Estimator

```matlab
function SOC_est = battery_SOC_estimator(I, V, T, dt)
    persistent SOC P V_R1 V_R2 initialized
    
    % Load parameters
    params = get_battery_params();
    
    % Initialize
    if isempty(initialized)
        SOC = 0.8;  % Default or use OCV lookup
        P = 0.01;
        V_R1 = 0;
        V_R2 = 0;
        initialized = true;
    end
    
    % Temperature compensation
    R0 = params.R0 * temp_correction_factor(T);
    
    % Update RC voltages
    tau1 = params.R1 * params.C1;
    tau2 = params.R2 * params.C2;
    V_R1 = V_R1 * exp(-dt/tau1) + I * params.R1 * (1 - exp(-dt/tau1));
    V_R2 = V_R2 * exp(-dt/tau2) + I * params.R2 * (1 - exp(-dt/tau2));
    
    % Run EKF
    [SOC, P] = EKF_SOC(I, V, dt, params, SOC, P);
    
    % Output
    SOC_est = SOC;
end
```

---

## Summary Table

| SOC Range | Best Method | Why |
|-----------|-------------|-----|
| 0-10% | OCV | Critical for "empty" warning |
| 10-90% | EKF | Best real-time accuracy |
| 90-100% | OCV + EKF | Critical for "full" detection |
| LFP (20-80%) | Coulomb + aging model | Flat OCV |

---

## Common Mistakes

❌ **Forgetting coulombic efficiency**
```matlab
// Wrong
SOC = SOC - I*dt/Q;

// Right
if I > 0  % discharge
    SOC = SOC - I*dt/Q;
else  % charge
    SOC = SOC - I*dt/Q * eta;  % eta ≈ 0.98
end
```

❌ **Not resetting on full charge**
```matlab
if (V > V_max) && (I < 0.05*Q_nom) && (dV/dt < 1e-4)
    SOC = 1.0;  % Reset to 100%
end
```

❌ **Ignoring temperature**
```matlab
// OCV changes with temperature!
OCV_corrected = OCV + (T - 25) * (-0.0004);  % -0.4 mV/°C
```

---

**See Also**: `02_battery_theory.md` for model equations!
