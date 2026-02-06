# Motor Control Theory

## Table of Contents
1. [Introduction](#introduction)
2. [Field-Oriented Control (FOC)](#field-oriented-control-foc)
3. [Space Vector Modulation (SVM)](#space-vector-modulation-svm)
4. [Sensorless Control](#sensorless-control)
5. [Direct Torque Control (DTC)](#direct-torque-control-dtc)
6. [Advanced Control Strategies](#advanced-control-strategies)
7. [References](#references)

---

## Introduction

Motor control algorithms determine how electrical power is delivered to achieve desired torque, speed, and efficiency. Modern control strategies decouple torque and flux control, enabling precise, dynamic response similar to DC motors.

### Control Hierarchy

```
Torque/Speed Command
        ↓
    Controller
        ↓
    Modulator (PWM/SVM)
        ↓
    Inverter (Power Electronics)
        ↓
    Motor
```

---

## Field-Oriented Control (FOC)

### Overview

Field-Oriented Control (also called Vector Control) transforms three-phase AC quantities into a two-axis (dq) rotating reference frame, enabling independent control of torque and flux.

**Key Advantages**:
- Independent torque and flux control
- Fast dynamic response
- High efficiency
- Smooth torque across speed range

### Control Structure

```
Speed Reference → Speed      → Torque    → Current  → SVM → Inverter
                  Controller    Command    Controller
                      ↑                        ↑
                  Speed Feedback         Current Feedback (dq)
```

### Coordinate Transformations

#### 1. Clarke Transformation (abc → αβ)

Transforms three-phase quantities to two-phase stationary reference frame:

$$
\begin{bmatrix} i_\alpha \\ i_\beta \end{bmatrix} = 
\frac{2}{3} \begin{bmatrix} 
1 & -\frac{1}{2} & -\frac{1}{2} \\
0 & \frac{\sqrt{3}}{2} & -\frac{\sqrt{3}}{2}
\end{bmatrix}
\begin{bmatrix} i_a \\ i_b \\ i_c \end{bmatrix}
$$

Amplitude-invariant form (power-invariant uses $\sqrt{2/3}$ coefficient):
$$
\begin{aligned}
i_\alpha &= i_a \\
i_\beta &= \frac{1}{\sqrt{3}}(i_a + 2i_b)
\end{aligned}
$$

Simplified (assuming $i_a + i_b + i_c = 0$):
$$
\begin{aligned}
i_\alpha &= i_a \\
i_\beta &= \frac{1}{\sqrt{3}}(i_a + 2i_b) = \frac{2}{\sqrt{3}}\left(i_b + \frac{i_a}{2}\right)
\end{aligned}
$$

#### 2. Park Transformation (αβ → dq)

Transforms to rotating reference frame aligned with rotor flux:

$$
\begin{bmatrix} i_d \\ i_q \end{bmatrix} = 
\begin{bmatrix} 
\cos\theta_e & \sin\theta_e \\
-\sin\theta_e & \cos\theta_e
\end{bmatrix}
\begin{bmatrix} i_\alpha \\ i_\beta \end{bmatrix}
$$

where $\theta_e$ = electrical rotor angle [rad]

#### 3. Inverse Park Transformation (dq → αβ)

$$
\begin{bmatrix} v_\alpha \\ v_\beta \end{bmatrix} = 
\begin{bmatrix} 
\cos\theta_e & -\sin\theta_e \\
\sin\theta_e & \cos\theta_e
\end{bmatrix}
\begin{bmatrix} v_d \\ v_q \end{bmatrix}
$$

#### 4. Inverse Clarke Transformation (αβ → abc)

$$
\begin{bmatrix} v_a \\ v_b \\ v_c \end{bmatrix} = 
\begin{bmatrix} 
1 & 0 \\
-\frac{1}{2} & \frac{\sqrt{3}}{2} \\
-\frac{1}{2} & -\frac{\sqrt{3}}{2}
\end{bmatrix}
\begin{bmatrix} v_\alpha \\ v_\beta \end{bmatrix}
$$

### Current Control Loops

#### PI Controller Design

**d-axis current controller**:
$$
v_d = K_{p,d}(i_d^* - i_d) + K_{i,d}\int(i_d^* - i_d)dt - \omega_e L_q i_q
$$

**q-axis current controller**:
$$
v_q = K_{p,q}(i_q^* - i_q) + K_{i,q}\int(i_q^* - i_q)dt + \omega_e L_d i_d + \omega_e \lambda_m
$$

The terms $-\omega_e L_q i_q$ and $+\omega_e L_d i_d + \omega_e \lambda_m$ are **feedforward decoupling** terms.

#### PI Gain Calculation

For plant transfer function $G(s) = \frac{1}{R_s + sL_d}$:

Desired closed-loop bandwidth $\omega_{BW}$:

$$
\begin{aligned}
K_p &= \omega_{BW} L_d \\
K_i &= \omega_{BW} R_s
\end{aligned}
$$

Typical bandwidth: 500-2000 rad/s (80-320 Hz)

### Speed Control Loop

**PI speed controller**:
$$
T_e^* = K_{p,\omega}(\omega_m^* - \omega_m) + K_{i,\omega}\int(\omega_m^* - \omega_m)dt
$$

Convert torque command to q-axis current:
$$
i_q^* = \frac{2T_e^*}{3p\lambda_m}
$$

Speed loop bandwidth: 10-50 Hz (much slower than current loop)

### Control Strategies

#### 1. $i_d = 0$ Control (Maximum Torque per Ampere for SPMSM)

- Set $i_d^* = 0$
- Torque proportional to $i_q$: $T_e = \frac{3}{2}p\lambda_m i_q$
- Minimizes copper losses
- Valid below base speed

#### 2. Maximum Torque per Ampere (MTPA) for IPMSM

Optimal current angle to maximize torque for given current magnitude:

$$
i_d^* = \frac{\lambda_m - \sqrt{\lambda_m^2 + 8(L_q-L_d)^2(i_q^*)^2}}{4(L_q-L_d)}
$$

#### 3. Field Weakening

Above base speed, reduce d-axis current (negative) to weaken flux:

Voltage limit ellipse:
$$
(L_d i_d + \lambda_m)^2 + (L_q i_q)^2 \leq \left(\frac{V_{max}}{\omega_e}\right)^2
$$

Current limit circle:
$$
i_d^2 + i_q^2 \leq I_{max}^2
$$

**Field weakening algorithm**:
1. Calculate required $i_d$ to satisfy voltage constraint
2. Maximize $i_q$ within current limit
3. Reduce torque as speed increases

---

## Space Vector Modulation (SVM)

### Voltage Source Inverter (VSI)

Three-leg inverter with 8 possible switching states:

| State | $S_a$ | $S_b$ | $S_c$ | Vector |
|-------|-------|-------|-------|--------|
| 0     | 0     | 0     | 0     | $V_0$ (zero) |
| 1     | 1     | 0     | 0     | $V_1$ |
| 2     | 1     | 1     | 0     | $V_2$ |
| 3     | 0     | 1     | 0     | $V_3$ |
| 4     | 0     | 1     | 1     | $V_4$ |
| 5     | 0     | 0     | 1     | $V_5$ |
| 6     | 1     | 0     | 1     | $V_6$ |
| 7     | 1     | 1     | 1     | $V_7$ (zero) |

### Space Vector Representation

Voltage space vectors:
$$
\vec{V}_k = V_{DC} \cdot e^{j(k-1)\pi/3}, \quad k = 1,2,3,4,5,6
$$

Reference voltage vector:
$$
\vec{V}_{ref} = V_\alpha + j V_\beta = V_m e^{j\theta}
$$

### SVM Algorithm

1. **Determine sector** (1-6) based on angle $\theta$

2. **Calculate duty cycles**:

For sector 1 ($0° \leq \theta < 60°$):
$$
\begin{aligned}
T_1 &= T_s \frac{V_m}{V_{DC}} \sin\left(\frac{\pi}{3} - \theta\right) \\
T_2 &= T_s \frac{V_m}{V_{DC}} \sin(\theta) \\
T_0 &= T_s - T_1 - T_2
\end{aligned}
$$

where:
- $T_s$ = switching period [s]
- $T_1, T_2$ = active vector times [s]
- $T_0$ = zero vector time [s]

3. **Switching sequence**:

Symmetric sequence to minimize switching:
$$
V_0 \to V_1 \to V_2 \to V_7 \to V_2 \to V_1 \to V_0
$$

### SVM vs. Sinusoidal PWM

- **Maximum voltage**: SVM achieves $V_{max} = \frac{V_{DC}}{\sqrt{3}}$ (15% higher than SPWM)
- **Harmonic performance**: SVM has better THD
- **DC bus utilization**: SVM achieves 90.7% vs. 78.5% for SPWM

---

## Sensorless Control

### Motivation

Eliminate position sensor (encoder/resolver) for:
- Cost reduction
- Increased reliability
- Reduced wiring complexity

### Challenges

- No position feedback at standstill and low speed
- Requires estimation algorithms
- Parameter sensitivity

### Methods

#### 1. Back-EMF Based Methods (High Speed)

**Principle**: Estimate rotor position from back-EMF in stator voltage equations.

Back-EMF in αβ frame:
$$
\begin{aligned}
e_\alpha &= \omega_e \lambda_m \sin(\theta_e) \\
e_\beta &= -\omega_e \lambda_m \cos(\theta_e)
\end{aligned}
$$

From motor equations:
$$
\begin{aligned}
e_\alpha &= v_\alpha - R_s i_\alpha - L_s \frac{di_\alpha}{dt} \\
e_\beta &= v_\beta - R_s i_\beta - L_s \frac{di_\beta}{dt}
\end{aligned}
$$

**Position estimation**:
$$
\hat{\theta}_e = \arctan\left(\frac{e_\alpha}{-e_\beta}\right)
$$

**Speed estimation**:
$$
\hat{\omega}_e = \frac{\sqrt{e_\alpha^2 + e_\beta^2}}{\lambda_m}
$$

**Limitation**: Back-EMF is very small at low speeds.

#### 2. Sliding Mode Observer (SMO)

Design observer with discontinuous control:

$$
\begin{aligned}
\frac{d\hat{i}_\alpha}{dt} &= -\frac{R_s}{L_s}\hat{i}_\alpha + \frac{1}{L_s}v_\alpha - \frac{1}{L_s}k \cdot \text{sign}(\hat{i}_\alpha - i_\alpha) \\
\frac{d\hat{i}_\beta}{dt} &= -\frac{R_s}{L_s}\hat{i}_\beta + \frac{1}{L_s}v_\beta - \frac{1}{L_s}k \cdot \text{sign}(\hat{i}_\beta - i_\beta)
\end{aligned}
$$

The discontinuous term estimates back-EMF:
$$
\begin{aligned}
\hat{e}_\alpha &= k \cdot \text{sign}(\hat{i}_\alpha - i_\alpha) \\
\hat{e}_\beta &= k \cdot \text{sign}(\hat{i}_\beta - i_\beta)
\end{aligned}
$$

Extract position from estimated back-EMF.

#### 3. Extended Kalman Filter (EKF)

**State vector**: $\mathbf{x} = [i_\alpha, i_\beta, \omega_e, \theta_e]^T$

**State equations**:
$$
\begin{aligned}
\frac{di_\alpha}{dt} &= -\frac{R_s}{L_s}i_\alpha + \frac{1}{L_s}v_\alpha - \frac{\omega_e\lambda_m}{L_s}\sin(\theta_e) \\
\frac{di_\beta}{dt} &= -\frac{R_s}{L_s}i_\beta + \frac{1}{L_s}v_\beta + \frac{\omega_e\lambda_m}{L_s}\cos(\theta_e) \\
\frac{d\omega_e}{dt} &= 0 \quad \text{(assume constant)} \\
\frac{d\theta_e}{dt} &= \omega_e
\end{aligned}
$$

**Measurement equations**:
$$
\mathbf{y} = [i_\alpha, i_\beta]^T
$$

EKF recursively estimates position and speed from current measurements.

#### 4. High-Frequency Injection (Low Speed)

Inject high-frequency voltage signal:
$$
v_{hf} = V_{hf} \sin(\omega_{hf} t)
$$

For salient rotor (IPMSM), inductance varies with position:
$$
L(\theta) = L_{avg} + L_{diff}\cos(2\theta_e)
$$

High-frequency current response contains position information:
$$
i_{hf} \propto \frac{1}{L(\theta_e)}
$$

Extract position using demodulation and filtering.

#### 5. Model Reference Adaptive System (MRAS)

**Reference model**: Stator voltage model
**Adaptive model**: Rotor flux model

Minimize error between models to estimate speed:
$$
\hat{\omega}_e = K_p \varepsilon + K_i \int \varepsilon dt
$$

where $\varepsilon$ = error between reference and adaptive models

### Hybrid Sensorless Control

Combine multiple methods:
- **Low speed (0-10% rated)**: High-frequency injection or open-loop
- **Medium speed (10-30% rated)**: Transition/hybrid
- **High speed (>30% rated)**: Back-EMF based observer

---

## Direct Torque Control (DTC)

### Overview

DTC directly controls torque and flux by selecting optimal voltage vectors from a lookup table, without coordinate transformations or modulators.

**Advantages**:
- Simple structure
- Fast torque response
- No coordinate transformations
- No current controllers

**Disadvantages**:
- Variable switching frequency
- Higher torque ripple
- Requires flux estimation

### Control Principle

#### 1. Flux and Torque Estimation

**Stator flux linkage**:
$$
\begin{aligned}
\lambda_\alpha &= \int (v_\alpha - R_s i_\alpha) dt \\
\lambda_\beta &= \int (v_\beta - R_s i_\beta) dt
\end{aligned}
$$

Flux magnitude:
$$
|\lambda_s| = \sqrt{\lambda_\alpha^2 + \lambda_\beta^2}
$$

Flux angle:
$$
\theta_s = \arctan\left(\frac{\lambda_\beta}{\lambda_\alpha}\right)
$$

**Electromagnetic torque**:
$$
T_e = \frac{3}{2} p (\lambda_\alpha i_\beta - \lambda_\beta i_\alpha)
$$

#### 2. Hysteresis Controllers

**Flux hysteresis controller** (2-level):
$$
d_\lambda = \begin{cases}
1 & \text{if } |\lambda_s| < |\lambda_s^*| - h_\lambda \\
0 & \text{if } |\lambda_s| > |\lambda_s^*| + h_\lambda
\end{cases}
$$

**Torque hysteresis controller** (3-level):
$$
d_T = \begin{cases}
1 & \text{if } T_e < T_e^* - h_T \\
0 & \text{if } |T_e - T_e^*| \leq h_T \\
-1 & \text{if } T_e > T_e^* + h_T
\end{cases}
$$

#### 3. Switching Table

Select voltage vector based on $d_\lambda$, $d_T$, and flux sector:

| $d_T$ | $d_\lambda$ | Sector 1 | Sector 2 | Sector 3 | Sector 4 | Sector 5 | Sector 6 |
|-------|-------------|----------|----------|----------|----------|----------|----------|
| 1     | 1           | $V_2$    | $V_3$    | $V_4$    | $V_5$    | $V_6$    | $V_1$    |
| 1     | 0           | $V_3$    | $V_4$    | $V_5$    | $V_6$    | $V_1$    | $V_2$    |
| 0     | 1           | $V_7$    | $V_0$    | $V_7$    | $V_0$    | $V_7$    | $V_0$    |
| 0     | 0           | $V_0$    | $V_7$    | $V_0$    | $V_7$    | $V_0$    | $V_7$    |
| -1    | 1           | $V_6$    | $V_1$    | $V_2$    | $V_3$    | $V_4$    | $V_5$    |
| -1    | 0           | $V_5$    | $V_6$    | $V_1$    | $V_2$    | $V_3$    | $V_4$    |

### DTC-SVM

Combines DTC with space vector modulation:
- Calculate reference voltage from flux and torque errors
- Use SVM for constant switching frequency
- Reduces torque ripple
- Maintains DTC advantages

---

## Advanced Control Strategies

### 1. Model Predictive Control (MPC)

Optimize control over prediction horizon:

**Cost function**:
$$
J = \sum_{k=1}^{N} \left[ w_i (i_d^* - i_d(k))^2 + w_i (i_q^* - i_q(k))^2 + w_u \Delta u(k)^2 \right]
$$

**Constraints**:
- Voltage limits
- Current limits
- Switching frequency limits

Select optimal voltage vector to minimize cost.

**Advantages**:
- Handles constraints naturally
- Multi-objective optimization
- Fast dynamics

### 2. Adaptive Control

Update controller parameters online:

**MIT rule**:
$$
\frac{d\theta}{dt} = -\gamma e \frac{\partial e}{\partial \theta}
$$

where:
- $\theta$ = parameter vector
- $e$ = tracking error
- $\gamma$ = adaptation gain

### 3. Sliding Mode Control

Design sliding surface:
$$
s = \lambda e + \dot{e}
$$

Control law:
$$
u = u_{eq} + u_{sw}
$$

where:
- $u_{eq}$ = equivalent control (maintain on surface)
- $u_{sw}$ = switching control (reach surface)

**Advantages**:
- Robust to parameter uncertainties
- Finite-time convergence

### 4. Fuzzy Logic Control

Rule-based control without precise model:

**Example rule**:
- IF error is "positive large" AND change in error is "negative small" THEN output is "medium"

### 5. Neural Network Control

Learn motor dynamics and optimal control:
- Feed-forward network for inverse dynamics
- Recurrent network for system identification
- Reinforcement learning for optimal policy

---

## Control Implementation Considerations

### Sampling and Execution Times

- **Current loop**: 10-50 kHz (100-20 µs)
- **Speed loop**: 1-5 kHz (1000-200 µs)
- **Position loop**: 100-500 Hz (10-2 ms)

### Anti-Windup

Prevent integrator saturation:

**Conditional integration**:
$$
\int e \, dt = \begin{cases}
\int e \, dt + e \cdot \Delta t & \text{if output not saturated} \\
\text{hold} & \text{if output saturated}
\end{cases}
$$

**Back-calculation**:
$$
\int e \, dt = \int e \, dt + \frac{1}{T_t}(u_{sat} - u) \Delta t
$$

### Current Measurement

- **Shunt resistors**: Low-side, high-side, or in-line
- **Hall effect sensors**: Isolated, higher cost
- **Reconstruction**: Single shunt with special PWM

### Position Sensing

- **Encoders**: Incremental, absolute
- **Resolvers**: Robust, analog output
- **Hall sensors**: Low resolution (6 steps), for BLDC

---

## Simulation and Testing

### Hardware-in-the-Loop (HIL)

Test control algorithms with real-time motor simulation:
1. Controller runs on actual hardware
2. Motor model runs on HIL simulator
3. Interface through analog/digital I/O

### Processor-in-the-Loop (PIL)

Verify code generation and execution:
1. Auto-generate C code from Simulink
2. Compile and deploy to target processor
3. Compare PIL results with simulation

### Rapid Prototyping

- **dSPACE**: MicroLabBox, SCALEXIO
- **OPAL-RT**: OP4510, OP5707
- **National Instruments**: CompactRIO, PXI

---

## References

1. Bose, B. K. (2002). *Modern Power Electronics and AC Drives*. Prentice Hall.
2. Leonhard, W. (2001). *Control of Electrical Drives*. Springer.
3. Vas, P. (1998). *Sensorless Vector and Direct Torque Control*. Oxford University Press.
4. Kazmierkowski, M. P., et al. (2002). *Control in Power Electronics*. Academic Press.
5. Mohan, N. (2014). *Advanced Electric Drives*. Wiley.
6. Holtz, J. (2002). "Sensorless control of induction motor drives." *Proceedings of the IEEE*, 90(8), 1359-1394.
7. Boldea, I., & Nasar, S. A. (1992). *Vector Control of AC Drives*. CRC Press.

---

**Previous**: [Motor Theory](01_motor_theory.md) | [Battery Theory](02_battery_theory.md)
**Next**: [Thermal Theory](04_thermal_theory.md)
