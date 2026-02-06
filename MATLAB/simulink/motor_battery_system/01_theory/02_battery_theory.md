# Battery Theory and Modeling

## Table of Contents
1. [Introduction](#introduction)
2. [Battery Electrochemistry](#battery-electrochemistry)
3. [Electrical Models](#electrical-models)
4. [State of Charge (SOC)](#state-of-charge-soc)
5. [State of Health (SOH)](#state-of-health-soh)
6. [Thermal Modeling](#thermal-modeling)
7. [Degradation Mechanisms](#degradation-mechanisms)
8. [References](#references)

---

## Introduction

Batteries are electrochemical energy storage devices that convert chemical energy into electrical energy through redox reactions. This document focuses on lithium-ion batteries, the dominant technology for electric vehicles and energy storage applications.

### Battery Cell Chemistry Types

- **Lithium Nickel Manganese Cobalt Oxide (NMC)**: High energy density, good power capability
- **Lithium Iron Phosphate (LFP)**: Long cycle life, thermal stability, lower energy density
- **Lithium Nickel Cobalt Aluminum Oxide (NCA)**: Very high energy density, used in Tesla vehicles
- **Lithium Titanate (LTO)**: Very long cycle life, fast charging, lower energy density

---

## Battery Electrochemistry

### Basic Principles

A lithium-ion battery consists of:
- **Anode** (negative electrode): Typically graphite (LiC₆)
- **Cathode** (positive electrode): Metal oxide (e.g., LiCoO₂, LiFePO₄)
- **Electrolyte**: Lithium salt in organic solvent
- **Separator**: Prevents short circuits while allowing ion flow

### Electrochemical Reactions

**Discharge** (lithium ions flow from anode to cathode):

Anode:
$$
\text{LiC}_6 \rightarrow \text{C}_6 + \text{Li}^+ + e^-
$$

Cathode (example for LiCoO₂):
$$
\text{Li}_{1-x}\text{CoO}_2 + x\text{Li}^+ + xe^- \rightarrow \text{LiCoO}_2
$$

**Charge** (reverse process)

### Cell Voltage

The cell voltage is determined by the electrochemical potential difference:

$$
V_{cell} = V_{cathode} - V_{anode} - \eta
$$

where $\eta$ = overpotential losses (activation, concentration, ohmic)

### Nernst Equation

Open-circuit voltage (OCV) as a function of concentration:

$$
\text{OCV} = E^0 + \frac{RT}{nF} \ln\left(\frac{a_{oxidized}}{a_{reduced}}\right)
$$

where:
- $E^0$ = standard electrode potential [V]
- $R$ = universal gas constant (8.314 J/mol·K)
- $T$ = absolute temperature [K]
- $n$ = number of electrons transferred
- $F$ = Faraday's constant (96485 C/mol)
- $a$ = activity (approximately concentration)

---

## Electrical Models

### 1. Simple Voltage Source Model

Most basic representation:

$$
V_{terminal} = \text{OCV}(SOC) - I \cdot R_{int}
$$

where:
- $V_{terminal}$ = terminal voltage [V]
- $\text{OCV}$ = open-circuit voltage [V]
- $I$ = current [A] (positive for discharge)
- $R_{int}$ = internal resistance [Ω]

**Advantages**: Simple, fast simulation
**Disadvantages**: No transient response, temperature effects not captured

### 2. Thevenin Equivalent Circuit Model

Single RC pair to capture transient behavior:

$$
V_{terminal} = \text{OCV}(SOC) - V_{RC} - I \cdot R_0
$$

RC voltage dynamics:
$$
\frac{dV_{RC}}{dt} = -\frac{V_{RC}}{R_1 C_1} + \frac{I}{C_1}
$$

Equivalent form:
$$
\frac{dV_{RC}}{dt} = -\frac{1}{\tau_1}V_{RC} + \frac{R_1}{\tau_1}I
$$

where:
- $R_0$ = ohmic resistance [Ω]
- $R_1$ = polarization resistance [Ω]
- $C_1$ = polarization capacitance [F]
- $\tau_1 = R_1 C_1$ = time constant [s]

**Advantages**: Captures voltage relaxation, moderate complexity
**Disadvantages**: Limited accuracy for varying current profiles

### 3. Dual Polarization Model (2RC Model)

Two RC pairs for better transient accuracy:

$$
V_{terminal} = \text{OCV}(SOC) - V_{RC1} - V_{RC2} - I \cdot R_0
$$

RC dynamics:
$$
\begin{aligned}
\frac{dV_{RC1}}{dt} &= -\frac{1}{\tau_1}V_{RC1} + \frac{R_1}{\tau_1}I \\
\frac{dV_{RC2}}{dt} &= -\frac{1}{\tau_2}V_{RC2} + \frac{R_2}{\tau_2}I
\end{aligned}
$$

where:
- RC1: Fast dynamics (seconds) - charge transfer
- RC2: Slow dynamics (minutes) - diffusion

**Advantages**: High accuracy for most applications
**Disadvantages**: More parameters to identify

### 4. PNGV (Partnership for a New Generation of Vehicles) Model

Includes capacitance in parallel with OCV:

$$
V_{terminal} = V_{OC} - V_{RC} - I \cdot R_0
$$

with:
$$
\frac{dV_{OC}}{dt} = \frac{I}{C_0}
$$

### 5. Randles Circuit Model

Includes Warburg impedance for diffusion effects:

$$
Z_{Warburg}(s) = \frac{\sigma}{\sqrt{s}}
$$

More detailed but complex for time-domain simulation.

### Open-Circuit Voltage (OCV) Characterization

OCV is a nonlinear function of SOC. Common representations:

**Polynomial fit**:
$$
\text{OCV}(SOC) = a_0 + a_1 \cdot SOC + a_2 \cdot SOC^2 + ... + a_n \cdot SOC^n
$$

**Lookup table**: Empirical data from low-current discharge test

**Shepherd equation**:
$$
V = E_0 - K \frac{Q}{Q-it} + A \cdot e^{-B \cdot it}
$$

where:
- $E_0$ = battery constant voltage [V]
- $K$ = polarization constant [V/Ah]
- $Q$ = battery capacity [Ah]
- $it$ = discharged capacity [Ah]
- $A, B$ = exponential zone parameters

### Temperature Dependence

All parameters vary with temperature:

$$
\begin{aligned}
R_0(T) &= R_{0,ref} \cdot \exp\left[\alpha_R \left(\frac{1}{T} - \frac{1}{T_{ref}}\right)\right] \\
R_i(T) &= R_{i,ref} \cdot \exp\left[\alpha_R \left(\frac{1}{T} - \frac{1}{T_{ref}}\right)\right] \\
C_i(T) &= C_{i,ref} \cdot \exp\left[\alpha_C \left(\frac{1}{T} - \frac{1}{T_{ref}}\right)\right]
\end{aligned}
$$

OCV also shifts with temperature:
$$
\text{OCV}(SOC, T) = \text{OCV}_{ref}(SOC) + k_T (T - T_{ref})
$$

where $k_T \approx -0.5$ to $-1$ mV/K

---

## State of Charge (SOC)

### Definition

SOC represents the available capacity as a percentage of total capacity:

$$
SOC = \frac{Q_{available}}{Q_{total}} \times 100\%
$$

### 1. Coulomb Counting (Ampere-Hour Integration)

Most common method:

$$
SOC(t) = SOC(t_0) - \frac{1}{Q_{nom}} \int_{t_0}^{t} \eta I(\tau) d\tau
$$

or in discrete time:
$$
SOC(k+1) = SOC(k) - \frac{\eta I(k) \Delta t}{Q_{nom}}
$$

where:
- $\eta$ = coulombic efficiency (≈1 for lithium-ion)
- $Q_{nom}$ = nominal capacity [Ah]
- $I$ = current [A] (positive for discharge)
- $\Delta t$ = sampling time [s]

**Advantages**: Simple, real-time implementation
**Disadvantages**: 
- Requires accurate initial SOC
- Accumulates measurement errors
- Sensitive to capacity changes

### 2. Open-Circuit Voltage (OCV) Method

Use OCV-SOC relationship:

$$
SOC = f^{-1}(\text{OCV})
$$

Requires voltage relaxation period (no current) to measure true OCV.

**Advantages**: No error accumulation
**Disadvantages**: Requires rest period, flat OCV curve reduces accuracy

### 3. Kalman Filter-Based Estimation

Combines coulomb counting with voltage measurements for optimal estimation.

**State equation**:
$$
SOC(k+1) = SOC(k) - \frac{\eta I(k) \Delta t}{Q}
$$

**Measurement equation**:
$$
V(k) = \text{OCV}(SOC(k)) - V_{RC}(k) - I(k) R_0
$$

**Extended Kalman Filter (EKF)** algorithm:

Prediction:
$$
\begin{aligned}
\hat{SOC}_{k|k-1} &= \hat{SOC}_{k-1|k-1} - \frac{\eta I_{k-1} \Delta t}{Q} \\
P_{k|k-1} &= P_{k-1|k-1} + Q_{process}
\end{aligned}
$$

Update:
$$
\begin{aligned}
K_k &= P_{k|k-1} H_k^T (H_k P_{k|k-1} H_k^T + R_{meas})^{-1} \\
\hat{SOC}_{k|k} &= \hat{SOC}_{k|k-1} + K_k (V_k - \hat{V}_k) \\
P_{k|k} &= (I - K_k H_k) P_{k|k-1}
\end{aligned}
$$

where:
- $K$ = Kalman gain
- $H = \frac{\partial V}{\partial SOC}$ = Jacobian matrix
- $P$ = error covariance
- $Q_{process}$ = process noise covariance
- $R_{meas}$ = measurement noise covariance

### 4. Adaptive Methods

**Adaptive EKF**: Updates $Q_{nom}$ online
**Unscented Kalman Filter (UKF)**: Better for highly nonlinear systems
**Particle Filter**: Handles non-Gaussian distributions

---

## State of Health (SOH)

### Definition

SOH quantifies battery degradation:

**Capacity-based**:
$$
SOH_Q = \frac{Q_{current}}{Q_{initial}} \times 100\%
$$

**Resistance-based**:
$$
SOH_R = \frac{R_{initial}}{R_{current}} \times 100\%
$$

**Combined**:
$$
SOH = w_Q \cdot SOH_Q + w_R \cdot SOH_R
$$

### Degradation Indicators

- **Capacity fade**: Loss of active material, loss of lithium inventory
- **Power fade**: Increase in internal resistance
- **Impedance growth**: Increase in charge transfer and diffusion resistance

### SOH Estimation Methods

#### 1. Capacity Measurement

Periodic full charge-discharge cycle:
$$
Q_{current} = \int_{t_{full}}^{t_{empty}} I(t) dt
$$

#### 2. Resistance Tracking

From voltage response to current pulse:
$$
R_0 = \frac{\Delta V}{\Delta I}
$$

#### 3. Incremental Capacity Analysis (ICA)

Plot $dQ/dV$ vs. voltage to identify degradation mechanisms.

#### 4. Electrochemical Impedance Spectroscopy (EIS)

Measure impedance at multiple frequencies:
$$
Z(j\omega) = R_0 + \sum_{i=1}^{n} \frac{R_i}{1 + j\omega R_i C_i}
$$

### End-of-Life (EOL) Criteria

Typical EOL definitions:
- **Automotive**: 80% capacity retention
- **Grid storage**: 70% capacity retention
- **Consumer electronics**: 60% capacity retention

---

## Thermal Modeling

### Heat Generation Mechanisms

Total heat generation:
$$
\dot{Q}_{total} = \dot{Q}_{reversible} + \dot{Q}_{irreversible}
$$

#### 1. Irreversible Heat (Joule Heating)

Ohmic losses:
$$
\dot{Q}_{irr} = I^2 R_{total} = I^2 (R_0 + R_1 + R_2)
$$

#### 2. Reversible Heat (Entropic Heat)

Due to entropy change in electrochemical reactions:
$$
\dot{Q}_{rev} = I T \frac{\partial \text{OCV}}{\partial T}
$$

where $\frac{\partial \text{OCV}}{\partial T}$ = entropic coefficient [V/K]

- Endothermic (heat absorption) during charge if $\frac{\partial \text{OCV}}{\partial T} > 0$
- Exothermic (heat generation) during discharge

Total heat generation:
$$
\dot{Q}_{gen} = I(V_{OC} - V_{terminal}) - I T \frac{\partial \text{OCV}}{\partial T}
$$

Simplified (ignoring reversible heat for conservative design):
$$
\dot{Q}_{gen} \approx I^2 R_{total}
$$

### Lumped Thermal Model

Single-node energy balance:
$$
m c_p \frac{dT}{dt} = \dot{Q}_{gen} - \frac{T - T_{amb}}{R_{th}}
$$

where:
- $m$ = battery mass [kg]
- $c_p$ = specific heat capacity [J/kg·K]
- $R_{th}$ = thermal resistance [K/W]
- $T_{amb}$ = ambient temperature [K]

Thermal resistance from convection:
$$
R_{th} = \frac{1}{h A}
$$

where:
- $h$ = heat transfer coefficient [W/m²·K]
  - Natural convection: 5-25 W/m²·K
  - Forced air: 10-100 W/m²·K
  - Liquid cooling: 50-10000 W/m²·K
- $A$ = surface area [m²]

### Multi-Node Thermal Network

For battery packs, use network of thermal resistances and capacitances:

**Core temperature**:
$$
C_{th,core} \frac{dT_{core}}{dt} = \dot{Q}_{gen} - \frac{T_{core} - T_{surface}}{R_{th,cs}}
$$

**Surface temperature**:
$$
C_{th,surf} \frac{dT_{surf}}{dt} = \frac{T_{core} - T_{surface}}{R_{th,cs}} - \frac{T_{surf} - T_{amb}}{R_{th,conv}}
$$

### Thermal Management Strategies

1. **Air cooling**: Simple, lightweight, limited cooling capacity
2. **Liquid cooling**: High capacity, complex, additional weight
3. **Phase change materials (PCM)**: Passive, isothermal plateau
4. **Heat pipes**: High effective thermal conductivity

### Thermal Limits

Operating temperature ranges:
- **Optimal performance**: 15-35°C
- **Acceptable operation**: -20 to 60°C
- **Thermal runaway**: >130-150°C (varies by chemistry)

Temperature gradients:
- Cell-to-cell: <5°C preferred, <10°C maximum
- Within cell: <5°C

---

## Degradation Mechanisms

### Calendar Aging (Storage Degradation)

Degradation while idle, function of SOC and temperature:

**SEI (Solid Electrolyte Interphase) growth**:
$$
Q_{loss,cal}(t) = \alpha \sqrt{t} \exp\left(-\frac{E_a}{RT}\right) \exp(\beta \cdot SOC)
$$

where:
- $\alpha$ = pre-exponential factor
- $E_a$ = activation energy [J/mol]
- $\beta$ = SOC stress factor

Arrhenius relationship for temperature:
$$
k(T) = k_0 \exp\left(-\frac{E_a}{R}\left(\frac{1}{T} - \frac{1}{T_{ref}}\right)\right)
$$

### Cycle Aging (Usage Degradation)

Degradation from charge-discharge cycles:

**Capacity fade per cycle**:
$$
\Delta Q_{cycle} = f(DOD, C_{rate}, T, SOC_{avg})
$$

**Stress factors**:
- **Depth of Discharge (DOD)**: Higher DOD → faster degradation
- **C-rate**: Higher current → faster degradation
- **Temperature**: Higher temperature → faster degradation
- **Average SOC**: Extreme SOCs (0% or 100%) → faster degradation

### Empirical Degradation Models

**Power law model**:
$$
Q(t) = Q_0 - \alpha t^\beta
$$

**Exponential model**:
$$
Q(t) = Q_0 - A(1 - e^{-Bt})
$$

**Combined calendar-cycle model**:
$$
Q(t, N) = Q_0 - (k_{cal} \sqrt{t} + k_{cyc} N^{z})
$$

where:
- $t$ = time [days]
- $N$ = number of equivalent full cycles
- $z$ = cycle aging exponent (0.5-0.6)

### Mechanistic Models

More detailed physics-based models:

**Loss of Lithium Inventory (LLI)**:
$$
\frac{dLLI}{dt} = k_{SEI} c_{Li^+} \exp\left(-\frac{E_{a,SEI}}{RT}\right)
$$

**Loss of Active Material (LAM)**:
- Particle cracking
- Binder degradation
- Current collector corrosion

**Resistance growth**:
$$
R(t) = R_0 + \Delta R_{SEI}(t) + \Delta R_{CT}(t)
$$

### Mitigation Strategies

1. **Temperature control**: Keep 15-35°C
2. **SOC management**: 
   - Avoid storing at 100% or 0%
   - Optimal storage: 40-60% SOC
3. **Charging optimization**:
   - Reduce charge rate near full SOC
   - Avoid frequent fast charging
4. **Depth of discharge limiting**:
   - Use 20-80% SOC window for daily operation
5. **Voltage/current limiting**:
   - Respect maximum charge voltage
   - Limit discharge power at low SOC

---

## Battery Management System (BMS) Functions

### Core Functions

1. **Monitoring**
   - Cell voltages, current, temperatures
   - SOC, SOH estimation

2. **Protection**
   - Overvoltage/undervoltage
   - Overcurrent
   - Over-temperature/under-temperature
   - Short circuit

3. **Balancing**
   - Passive (resistive dissipation)
   - Active (charge transfer between cells)

4. **Thermal management**
   - Cooling/heating control
   - Temperature gradient minimization

5. **Communication**
   - CAN bus interface
   - Fault diagnostics

### Cell Balancing

**Passive balancing**:
- Dissipate energy from higher voltage cells
- Simple, low cost
- Energy waste, slow

**Active balancing**:
- Transfer charge from high to low cells
- Complex, higher cost
- Energy efficient, faster

---

## Parameter Identification

### Pulse Test Method

1. Apply current pulse at fixed SOC
2. Measure voltage response
3. Extract parameters:
   - $R_0$ from instantaneous voltage drop
   - $R_1, C_1$ from exponential decay fitting

### Electrochemical Impedance Spectroscopy (EIS)

1. Apply AC excitation at multiple frequencies
2. Measure impedance magnitude and phase
3. Fit to equivalent circuit model

### Hybrid Pulse Power Characterization (HPPC)

Standard test for automotive batteries:
1. Discharge pulse (10s at rated current)
2. Rest period (40s)
3. Charge pulse (10s)
4. Repeat at multiple SOC levels

### Parameter Estimation Algorithms

**Least squares fitting**:
$$
\min_{\theta} \sum_{i=1}^{N} [V_{meas}(i) - V_{model}(i, \theta)]^2
$$

**Recursive Least Squares (RLS)**:
Online parameter updates

**Genetic algorithms**, **particle swarm optimization**: Global optimization for nonlinear fitting

---

## Simscape Implementation Notes

### Recommended Blocks

1. **Battery**: Use `Simscape > Electrical > Sources > Battery`
   - Configure as "Tabulated SOC-OCV"
   - Enable thermal port

2. **BMS**: Build custom subsystem with:
   - SOC estimator (coulomb counting + EKF)
   - Voltage/current limiters
   - Thermal management logic

3. **Thermal Network**: Use thermal blocks from `Simscape > Foundation Library > Thermal`

### Simulation Setup

- **Solver**: Variable-step, ode23t or ode15s (stiff)
- **Tolerances**: RelTol 1e-4, AbsTol 1e-6
- **Sample time**: Fast dynamics 0.1-1 ms, BMS logic 10-100 ms

---

## References

1. Plett, G. L. (2015). *Battery Management Systems, Volume I: Battery Modeling*. Artech House.
2. Plett, G. L. (2015). *Battery Management Systems, Volume II: Equivalent-Circuit Methods*. Artech House.
3. Hu, X., et al. (2020). "Battery Lifetime Prognostics." *Joule*, 4(2), 310-346.
4. Waag, W., et al. (2013). "Critical review of the methods for monitoring of lithium-ion batteries in electric and hybrid vehicles." *Journal of Power Sources*, 258, 321-339.
5. Liaw, B. Y., et al. (2014). "Modeling of lithium ion cells—A simple equivalent-circuit model approach." *Solid State Ionics*, 175(1-4), 835-839.
6. Barré, A., et al. (2013). "A review on lithium-ion battery ageing mechanisms and estimations for automotive applications." *Journal of Power Sources*, 241, 680-689.

---

**Next**: [Control Theory](03_control_theory.md) | [Thermal Theory](04_thermal_theory.md)
