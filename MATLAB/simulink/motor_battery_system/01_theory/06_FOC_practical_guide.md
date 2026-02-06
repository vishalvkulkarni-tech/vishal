# FOC Control - Practical Implementation Guide

## What is Field-Oriented Control (FOC)?

Field-Oriented Control is like giving your motor "superpowers" by controlling it in a special reference frame where complex AC becomes simple DC control.

### The Big Picture Analogy

Imagine you're trying to push a swing:
- **Bad way**: Push randomly in different directions (3-phase AC control)
- **Good way**: Always push in the direction of motion at the right time (FOC)

FOC does this for motors - it aligns control with the motor's natural physics.

---

## The Three Reference Frames

### 1. ABC Frame (Physical Reality)
```
     Phase A
        |
        |
   C ---|--- B
   
Three wires carrying sinusoidal currents
120° apart in phase
```

**Reality**: Your motor has 3 wires (A, B, C) with messy sine waves.

### 2. αβ Frame (Clarke Transform)
```
     β (imaginary)
     |
     |
     |_____ α (real)
     
Two perpendicular axes
Still rotating in space
```

**First simplification**: Convert 3 wires to 2 perpendicular axes.
- Still time-varying (rotating)
- But easier math (2D instead of 3D)

**Clarke Transform Formula**:
```
[iα]   [  1      -1/2      -1/2   ] [ia]
[iβ] = [  0    √3/2     -√3/2   ] [ib]
                                    [ic]
```

### 3. dq Frame (Park Transform)
```
     q (torque)
     |
     |
     |_____ d (flux)
     
Rotates WITH the rotor
DC values in steady state!
```

**The Magic**: Rotate with the motor's rotor angle θ.
- d-axis: aligned with rotor flux (like pointing North)
- q-axis: perpendicular (like pointing East)
- **Currents become DC values!**

**Park Transform Formula**:
```
[id]   [  cos(θ)   sin(θ) ] [iα]
[iq] = [ -sin(θ)   cos(θ) ] [iβ]
```

---

## Why This Works: The Physics

### Surface-Mounted PMSM (SPMSM)

In the dq frame, torque production becomes beautifully simple:

```
Te = (3/2) × p × λm × iq
```

Where:
- `Te` = electromagnetic torque
- `p` = pole pairs
- `λm` = permanent magnet flux
- `iq` = q-axis current

**Key insight**: 
- `id` doesn't produce torque → set it to zero!
- `iq` directly controls torque → use PI controller!

### Interior PMSM (IPMSM)

Slightly more complex:
```
Te = (3/2) × p × [λm × iq + (Ld - Lq) × id × iq]
         \_____________/   \_____________________/
         Magnet torque      Reluctance torque
```

**Strategy**:
- Below base speed: `id = 0` (Maximum Torque Per Ampere - MTPA)
- Above base speed: `id < 0` (field weakening)

---

## FOC Control Loop Architecture

```
Speed      ┌───────┐  Torque   ┌────────┐  iq_ref   ┌──────┐  Vq
Ref ──>─┬──┤  PI   ├──> Ref ───┤ Torque ├──────────┤  PI  ├──> ref
        │  │ Speed │            │ to iq  │           │  iq  │
        │  └───────┘            └────────┘           └──────┘
        │                                                |
    Measured                                            |
     Speed                                              |
        ↑                                               ↓
        │                                          ┌─────────┐
        │                                          │ Inverse │
        │                                          │  Park   │
        │                                          └─────────┘
        │                                               |
        │                                               ↓
        │                                           Vα, Vβ
        │                                               |
        │                                               ↓
        │                                          ┌─────────┐
        │                                          │ Inverse │
        │                                          │ Clarke  │
        │                                          └─────────┘
        │                                               |
        │                                               ↓
        │                                           Va, Vb, Vc
        │                                               |
        │                                               ↓
        │                                          ┌─────────┐
        │                                          │   SVM   │
        │                                          │  (PWM)  │
        │                                          └─────────┘
        │                                               |
    ┌───┴────┐                                         ↓
    │ Motor  │ <─────────────────────────────── Inverter
    │ PMSM   │
    └────────┘
        │
        ↓
    ia, ib, ic
        │
        ↓
    ┌─────────┐
    │ Clarke  │
    └─────────┘
        │
        ↓
    iα, iβ
        │
        ↓
    ┌─────────┐   θ (rotor angle)
    │  Park   │ <─────────
    └─────────┘
        │
        ↓
    id, iq (measured)
```

---

## Step-by-Step Implementation

### Step 1: Measure 3-Phase Currents
```matlab
ia = measured_current_A;
ib = measured_current_B;
ic = -(ia + ib);  % Can calculate from KCL
```

### Step 2: Clarke Transform (abc → αβ)
```matlab
i_alpha = ia;
i_beta = (ia + 2*ib) / sqrt(3);
```

### Step 3: Get Rotor Position
```matlab
theta = rotor_angle;  % From encoder or estimator
```

### Step 4: Park Transform (αβ → dq)
```matlab
cos_theta = cos(theta);
sin_theta = sin(theta);

id = i_alpha * cos_theta + i_beta * sin_theta;
iq = -i_alpha * sin_theta + i_beta * cos_theta;
```

### Step 5: PI Controllers in dq Frame
```matlab
% d-axis (flux) - typically set to zero for SPMSM
id_ref = 0;
ed = id_ref - id;
Vd_ref = Kp_d * ed + Ki_d * integral(ed);

% q-axis (torque)
iq_ref = torque_command / (1.5 * p * lambda_m);
eq = iq_ref - iq;
Vq_ref = Kp_q * eq + Ki_q * integral(eq);
```

**PI Tuning**:
```matlab
% For current loop (fast, ~1 kHz bandwidth)
omega_BW = 2*pi*1000;  % 1000 Hz
Kp_d = omega_BW * Ld;
Ki_d = omega_BW * Rs;

Kp_q = omega_BW * Lq;
Ki_q = omega_BW * Rs;
```

### Step 6: Inverse Park (dq → αβ)
```matlab
V_alpha = Vd_ref * cos_theta - Vq_ref * sin_theta;
V_beta = Vd_ref * sin_theta + Vq_ref * cos_theta;
```

### Step 7: Inverse Clarke (αβ → abc)
```matlab
Va = V_alpha;
Vb = -0.5 * V_alpha + (sqrt(3)/2) * V_beta;
Vc = -0.5 * V_alpha - (sqrt(3)/2) * V_beta;
```

### Step 8: Space Vector Modulation (SVM)
Convert voltage references to PWM duty cycles.

---

## Common Mistakes and Fixes

### ❌ Mistake 1: Wrong Angle
**Problem**: Using electrical angle instead of rotor angle (or vice versa).

**Fix**: 
```matlab
theta_electrical = p * theta_rotor;  % p = pole pairs
% Use theta_electrical in Park transform!
```

### ❌ Mistake 2: Clarke Transform Normalization
**Problem**: Different Clarke transform variants (amplitude-invariant vs power-invariant).

**Fix**: Be consistent! Most FOC uses amplitude-invariant:
```matlab
% Amplitude-invariant (matches peak values)
i_alpha = ia;
i_beta = (ia + 2*ib) / sqrt(3);
```

### ❌ Mistake 3: id ≠ 0 for SPMSM
**Problem**: Not setting `id_ref = 0` wastes current and increases losses.

**Fix**: For SPMSM (Ld = Lq), always use `id_ref = 0`.

### ❌ Mistake 4: PI Controller Windup
**Problem**: Integrator winds up during saturation.

**Fix**: Add anti-windup:
```matlab
% Clamp output
Vq_ref_limited = min(max(Vq_ref, -V_max), V_max);

% Back-calculate integrator
if Vq_ref ~= Vq_ref_limited
    integrator = integrator - Ki * (Vq_ref - Vq_ref_limited) * dt;
end
```

---

## Testing Your FOC Implementation

### Test 1: Open-Loop V/f (Before FOC)
```matlab
% Ramp frequency slowly
f = 0:0.1:50;  % Hz
V = V_rated * (f / f_rated);  % Volts
% Should spin smoothly
```

### Test 2: Locked Rotor (d-axis alignment)
```matlab
id_ref = 1;  % 1A
iq_ref = 0;
theta = 0;   % Fixed angle
% Motor should lock at theta = 0
```

### Test 3: Torque Step Response
```matlab
iq_ref = 0 -> 2A step
% Should see instant torque response
% Measure settling time < 5 ms
```

### Test 4: Speed Regulation
```matlab
speed_ref = 1000 rpm
load_torque = 0 -> 0.5*T_rated step
% Speed should recover in < 100 ms
```

---

## Practical Parameter Values (Example)

For a **1.5 kW PMSM**:
```matlab
% Motor
Rs = 0.285 Ω
Ld = Lq = 0.85 mH
λm = 0.1827 Wb
p = 4 pole pairs
J = 0.0001 kg·m²

% Current Loop (1000 rad/s bandwidth)
ωBW_current = 1000;
Kp_d = ωBW_current * Ld = 0.85
Ki_d = ωBW_current * Rs = 285

% Speed Loop (50 rad/s bandwidth)
ωBW_speed = 50;
Kp_speed = ωBW_speed * J = 0.005
Ki_speed = ωBW_speed * 0.1 = 5

% PWM
fsw = 10 kHz
Ts = 100 μs
```

---

## Debugging Checklist

- [ ] Measured currents sum to zero? (ia + ib + ic ≈ 0)
- [ ] Clarke transform output makes sense? (√(iα² + iβ²) = √(3/2) × ia_peak)
- [ ] Rotor angle incrementing correctly? (0 to 2π)
- [ ] Park transform gives DC in steady state?
- [ ] id ≈ 0 for SPMSM?
- [ ] iq proportional to torque command?
- [ ] No integrator windup?
- [ ] SVM duty cycles between 0-100%?

---

## Next Steps

1. **Start simple**: Implement in Simulink with ideal blocks
2. **Add reality**: Real PWM, dead time, current sensors
3. **Optimize**: Field weakening, MTPA optimization
4. **Advanced**: Sensorless (observer-based FOC)

**See**: `01_theory/03_control_theory.md` for mathematical details!
