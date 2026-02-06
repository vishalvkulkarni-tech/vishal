# Electric Motor Theory

## Table of Contents
1. [Introduction](#introduction)
2. [Permanent Magnet Synchronous Motor (PMSM)](#pmsm)
3. [Brushless DC Motor (BLDC)](#bldc)
4. [Induction Motor](#induction-motor)
5. [Motor Losses](#motor-losses)
6. [Thermal Modeling](#thermal-modeling)
7. [References](#references)

---

## Introduction

Electric motors convert electrical energy into mechanical energy through electromagnetic interaction. This document covers the mathematical modeling and simulation approaches for the most common motor types used in industrial and automotive applications.

### Motor Classification
- **DC Motors**: Brushed, Brushless (BLDC)
- **AC Motors**: Synchronous (PMSM, Wound Rotor), Asynchronous (Induction)
- **Special Motors**: Switched Reluctance, Stepper

---

## Permanent Magnet Synchronous Motor (PMSM)

### Physical Principles

PMSM uses permanent magnets on the rotor to create the excitation field, eliminating the need for rotor windings. The stator contains three-phase windings that create a rotating magnetic field.

### Mathematical Model

#### 1. Voltage Equations in abc Frame

The three-phase voltage equations are:

$$
\begin{aligned}
v_a &= R_s i_a + \frac{d\lambda_a}{dt} \\
v_b &= R_s i_b + \frac{d\lambda_b}{dt} \\
v_c &= R_s i_c + \frac{d\lambda_c}{dt}
\end{aligned}
$$

where:
- $v_{a,b,c}$ = phase voltages [V]
- $i_{a,b,c}$ = phase currents [A]
- $R_s$ = stator resistance [Ω]
- $\lambda_{a,b,c}$ = flux linkages [Wb]

#### 2. Flux Linkages

$$
\begin{aligned}
\lambda_a &= L_{aa}i_a + L_{ab}i_b + L_{ac}i_c + \lambda_{ma} \\
\lambda_b &= L_{ba}i_a + L_{bb}i_b + L_{bc}i_c + \lambda_{mb} \\
\lambda_c &= L_{ca}i_a + L_{cb}i_b + L_{cc}i_c + \lambda_{mc}
\end{aligned}
$$

where:
- $L_{xx}$ = self and mutual inductances [H]
- $\lambda_{m}$ = permanent magnet flux linkage [Wb]

#### 3. dq0 Transformation (Park Transform)

To simplify analysis, we transform from the stationary abc frame to the rotating dq frame aligned with the rotor:

**Clarke Transformation** (abc → αβ):

$$
\begin{bmatrix} i_\alpha \\ i_\beta \\ i_0 \end{bmatrix} = 
\frac{2}{3} \begin{bmatrix} 
1 & -\frac{1}{2} & -\frac{1}{2} \\
0 & \frac{\sqrt{3}}{2} & -\frac{\sqrt{3}}{2} \\
\frac{1}{2} & \frac{1}{2} & \frac{1}{2}
\end{bmatrix}
\begin{bmatrix} i_a \\ i_b \\ i_c \end{bmatrix}
$$

**Park Transformation** (αβ → dq):

$$
\begin{bmatrix} i_d \\ i_q \end{bmatrix} = 
\begin{bmatrix} 
\cos\theta_e & \sin\theta_e \\
-\sin\theta_e & \cos\theta_e
\end{bmatrix}
\begin{bmatrix} i_\alpha \\ i_\beta \end{bmatrix}
$$

where $\theta_e$ = electrical rotor position [rad]

#### 4. dq Frame Voltage Equations (Simplified Form)

In the synchronous reference frame rotating at electrical speed $\omega_e$:

$$
\begin{aligned}
v_d &= R_s i_d + L_d \frac{di_d}{dt} - \omega_e L_q i_q \\
v_q &= R_s i_q + L_q \frac{di_q}{dt} + \omega_e L_d i_d + \omega_e \lambda_m
\end{aligned}
$$

where:
- $v_d, v_q$ = d-axis and q-axis voltages [V]
- $i_d, i_q$ = d-axis and q-axis currents [A]
- $L_d, L_q$ = d-axis and q-axis inductances [H]
- $\lambda_m$ = permanent magnet flux linkage [Wb]
- $\omega_e$ = electrical angular velocity [rad/s]

**Key Insight**: In steady state with constant speed:
- The d-axis voltage equation shows coupling term $-\omega_e L_q i_q$
- The q-axis voltage equation shows coupling term $+\omega_e L_d i_d$ and back-EMF term $\omega_e \lambda_m$

#### 5. Electromagnetic Torque

The electromagnetic torque produced by the motor is:

$$
T_e = \frac{3}{2} p \left[ \lambda_m i_q + (L_d - L_q) i_d i_q \right]
$$

where:
- $T_e$ = electromagnetic torque [Nm]
- $p$ = number of pole pairs
- $\lambda_m$ = permanent magnet flux linkage [Wb]

**For Surface-mounted PMSM** (SPMSM): $L_d = L_q$, so:

$$
T_e = \frac{3}{2} p \lambda_m i_q
$$

**For Interior PMSM** (IPMSM): $L_d < L_q$, and there's an additional reluctance torque component.

#### 6. Mechanical Dynamics

$$
J \frac{d\omega_m}{dt} = T_e - T_L - B\omega_m
$$

where:
- $J$ = moment of inertia [kg·m²]
- $\omega_m$ = mechanical angular velocity [rad/s]
- $T_L$ = load torque [Nm]
- $B$ = viscous friction coefficient [Nm·s/rad]

**Relationship between electrical and mechanical quantities**:

$$
\begin{aligned}
\omega_e &= p \omega_m \\
\theta_e &= p \theta_m
\end{aligned}
$$

### Motor Types

#### Surface-Mounted PMSM (SPMSM)
- Magnets on rotor surface
- $L_d \approx L_q$ (round rotor, no saliency)
- Torque proportional to $i_q$ only
- Simpler control
- Lower inductance → faster dynamics

#### Interior PMSM (IPMSM)
- Magnets embedded inside rotor
- $L_d < L_q$ (salient rotor)
- Both magnet torque and reluctance torque
- Higher power density
- Field weakening capability
- More complex control

### Torque Production Strategies

#### 1. Maximum Torque per Ampere (MTPA)

Maximize torque for given current magnitude:

For IPMSM, optimal current angle:

$$
\beta = \arctan\left(\frac{\lambda_m + \sqrt{\lambda_m^2 + 8(L_q-L_d)^2 I_s^2}}{4(L_q-L_d)I_s}\right)
$$

where $I_s = \sqrt{i_d^2 + i_q^2}$

For SPMSM: $i_d = 0$, $i_q = I_s$ (id=0 control)

#### 2. Field Weakening

At high speeds, back-EMF limits available voltage. Inject negative d-axis current to weaken the magnetic field:

Voltage constraint:

$$
v_d^2 + v_q^2 \leq V_{max}^2
$$

Current constraint:

$$
i_d^2 + i_q^2 \leq I_{max}^2
$$

---

## Brushless DC Motor (BLDC)

### Physical Principles

BLDC motors are similar to PMSM but designed for trapezoidal back-EMF instead of sinusoidal. They use electronic commutation to replace mechanical brushes.

### Mathematical Model

#### Back-EMF Model

$$
\begin{aligned}
v_a &= R_s i_a + L \frac{di_a}{dt} + e_a \\
v_b &= R_s i_b + L \frac{di_b}{dt} + e_b \\
v_c &= R_s i_c + L \frac{di_c}{dt} + e_c
\end{aligned}
$$

where the back-EMF has trapezoidal waveform:

$$
e_{a,b,c} = k_e \omega_m f(\theta_e)
$$

$f(\theta_e)$ = trapezoidal function with 120° flat regions

#### Torque Equation

$$
T_e = \frac{e_a i_a + e_b i_b + e_c i_c}{\omega_m} = k_t I_{ph}
$$

where:
- $k_t$ = torque constant [Nm/A]
- $I_{ph}$ = phase current [A]

### Six-Step Commutation

BLDC motors use six-step (120° conduction) commutation based on rotor position:

| Step | Phase A | Phase B | Phase C |
|------|---------|---------|---------|
| 1    | +       | -       | Off     |
| 2    | +       | Off     | -       |
| 3    | Off     | +       | -       |
| 4    | -       | +       | Off     |
| 5    | -       | Off     | +       |
| 6    | Off     | -       | +       |

Hall sensors provide position feedback for commutation.

---

## Induction Motor

### Physical Principles

Induction motors have no permanent magnets or electrical rotor connections. Rotor currents are induced by the rotating stator field, creating torque through slip.

### Mathematical Model (in dq frame)

#### Voltage Equations

Stator:
$$
\begin{aligned}
v_{ds} &= R_s i_{ds} + \frac{d\lambda_{ds}}{dt} - \omega_e \lambda_{qs} \\
v_{qs} &= R_s i_{qs} + \frac{d\lambda_{qs}}{dt} + \omega_e \lambda_{ds}
\end{aligned}
$$

Rotor (short-circuited):
$$
\begin{aligned}
0 &= R_r i_{dr} + \frac{d\lambda_{dr}}{dt} - \omega_{slip} \lambda_{qr} \\
0 &= R_r i_{qr} + \frac{d\lambda_{qr}}{dt} + \omega_{slip} \lambda_{dr}
\end{aligned}
$$

where:
- $\omega_{slip} = \omega_e - \omega_m$ = slip frequency [rad/s]
- $R_r$ = rotor resistance [Ω]

#### Flux Linkages

$$
\begin{aligned}
\lambda_{ds} &= L_s i_{ds} + L_m i_{dr} \\
\lambda_{qs} &= L_s i_{qs} + L_m i_{qr} \\
\lambda_{dr} &= L_r i_{dr} + L_m i_{ds} \\
\lambda_{qr} &= L_r i_{qr} + L_m i_{qs}
\end{aligned}
$$

where:
- $L_s = L_{ls} + L_m$ = stator inductance [H]
- $L_r = L_{lr} + L_m$ = rotor inductance [H]
- $L_m$ = magnetizing inductance [H]

#### Torque Equation

$$
T_e = \frac{3}{2} p L_m (i_{qs} i_{dr} - i_{ds} i_{qr})
$$

#### Slip and Speed Relationship

Slip:
$$
s = \frac{\omega_e - \omega_m}{\omega_e} = \frac{\omega_{slip}}{\omega_e}
$$

Synchronous speed:
$$
n_{sync} = \frac{120 f}{P}
$$

where:
- $f$ = supply frequency [Hz]
- $P$ = number of poles

---

## Motor Losses

### 1. Copper Losses (I²R Losses)

Stator copper loss:
$$
P_{Cu,s} = \frac{3}{2}(i_d^2 + i_q^2) R_s
$$

Rotor copper loss (for induction motor):
$$
P_{Cu,r} = \frac{3}{2}(i_{dr}^2 + i_{qr}^2) R_r
$$

### 2. Iron Losses (Core Losses)

Hysteresis loss:
$$
P_h = k_h f B_{max}^n V
$$

Eddy current loss:
$$
P_e = k_e f^2 B_{max}^2 V
$$

Total iron loss (Steinmetz equation):
$$
P_{Fe} = k_h f B_{max}^n + k_e f^2 B_{max}^2
$$

where:
- $f$ = frequency [Hz]
- $B_{max}$ = peak flux density [T]
- $V$ = core volume [m³]
- $k_h, k_e, n$ = material constants

Simplified model in dq frame:
$$
P_{Fe} = \frac{3}{2} R_c (v_d^2 + v_q^2) / \omega_e^2
$$

### 3. Mechanical Losses

Friction loss:
$$
P_{friction} = B \omega_m^2
$$

Windage loss:
$$
P_{windage} = k_w \omega_m^3
$$

### 4. Stray Load Losses

Additional losses due to harmonics, saturation, etc.:
$$
P_{stray} \approx 1-2\% \text{ of rated power}
$$

### Total Loss and Efficiency

$$
\begin{aligned}
P_{loss,total} &= P_{Cu,s} + P_{Cu,r} + P_{Fe} + P_{mech} + P_{stray} \\
\eta &= \frac{P_{out}}{P_{out} + P_{loss,total}} = \frac{T_e \omega_m}{P_{in}}
\end{aligned}
$$

---

## Thermal Modeling

### Lumped Thermal Network

Motor thermal behavior can be modeled using thermal-electrical analogy:

$$
C_{th} \frac{dT}{dt} = P_{loss} - \frac{T - T_{amb}}{R_{th}}
$$

where:
- $C_{th}$ = thermal capacitance [J/K]
- $R_{th}$ = thermal resistance [K/W]
- $T$ = temperature [°C or K]
- $T_{amb}$ = ambient temperature [°C or K]
- $P_{loss}$ = heat generation [W]

### Multi-Node Thermal Network

For more detailed analysis, separate nodes for different components:

**Stator winding**:
$$
C_{th,w} \frac{dT_w}{dt} = P_{Cu,s} - \frac{T_w - T_{core}}{R_{th,wc}} - \frac{T_w - T_{amb}}{R_{th,wa}}
$$

**Stator core**:
$$
C_{th,c} \frac{dT_c}{dt} = P_{Fe} + \frac{T_w - T_{core}}{R_{th,wc}} - \frac{T_c - T_{amb}}{R_{th,ca}}
$$

**Rotor**:
$$
C_{th,r} \frac{dT_r}{dt} = P_{Cu,r} - \frac{T_r - T_{amb}}{R_{th,ra}}
$$

### Temperature-Dependent Parameters

Resistance temperature dependency:
$$
R(T) = R_{ref} [1 + \alpha (T - T_{ref})]
$$

where:
- $\alpha$ = temperature coefficient (0.00393/°C for copper)
- $T_{ref}$ = reference temperature (typically 25°C)

Magnet flux temperature dependency:
$$
\lambda_m(T) = \lambda_{m,ref} [1 + \beta (T - T_{ref})]
$$

where $\beta \approx -0.001$ to $-0.002$ /°C for NdFeB magnets

### Thermal Limits

- **Class A insulation**: 105°C
- **Class B insulation**: 130°C
- **Class F insulation**: 155°C
- **Class H insulation**: 180°C

**Derating**: Reduce continuous current rating as ambient temperature increases

---

## Parameter Identification

### Resistance Measurement

DC test with locked rotor:
$$
R_s = \frac{V_{DC}}{I_{DC}}
$$

### Inductance Measurement

**d-axis inductance**: Align rotor with phase A, inject DC current:
$$
L_d = \frac{\Delta \lambda_d}{\Delta i_d}
$$

**q-axis inductance**: Align rotor 90° from phase A:
$$
L_q = \frac{\Delta \lambda_q}{\Delta i_q}
$$

### Back-EMF Constant

Open-circuit test at known speed:
$$
k_e = \frac{E_{peak}}{\omega_m}
$$

For PMSM:
$$
\lambda_m = \frac{k_e}{p}
$$

### Inertia Measurement

Acceleration test:
$$
J = \frac{T_e - T_L}{\alpha}
$$

where $\alpha = d\omega_m/dt$ = angular acceleration

---

## Simscape Implementation Notes

### Recommended Blocks

1. **PMSM**: Use `Simscape > Electrical > Electromechanical > Permanent Magnet Synchronous Machine`
2. **Solver Configuration**: Fixed-step solver, ode4 (Runge-Kutta), step size 1e-6 to 1e-5 s
3. **Thermal Port**: Enable thermal port for coupled electro-thermal simulation
4. **Saturation**: Consider magnetic saturation for high-fidelity models

### Parameter Estimation

Use MATLAB functions:
- `pmsm.estimator` - Parameter estimation from measurements
- `motor.Calibration` - Automated motor characterization
- `fmincon` - Optimization for parameter fitting

---

## References

1. Krishnan, R. (2010). *Permanent Magnet Synchronous and Brushless DC Motor Drives*. CRC Press.
2. Boldea, I., & Nasar, S. A. (2016). *The Induction Machines Design Handbook*. CRC Press.
3. Mohan, N. (2014). *Advanced Electric Drives: Analysis, Control, and Modeling using MATLAB/Simulink*. Wiley.
4. Vas, P. (1998). *Sensorless Vector and Direct Torque Control*. Oxford University Press.
5. Jahns, T. M., & Soong, W. L. (1996). "Pulsating torque minimization techniques for permanent magnet AC motor drives—a review." *IEEE Transactions on Industrial Electronics*, 43(2), 321-330.
6. Hendershot, J. R., & Miller, T. J. E. (2010). *Design of Brushless Permanent-Magnet Machines*. Motor Design Books LLC.

---

**Next**: [Battery Theory](02_battery_theory.md) | [Control Theory](03_control_theory.md)
