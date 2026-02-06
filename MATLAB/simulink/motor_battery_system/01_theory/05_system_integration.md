# System Integration Theory

## Table of Contents
1. [Introduction](#introduction)
2. [System Architecture](#system-architecture)
3. [Power Flow Management](#power-flow-management)
4. [Energy Management Strategies](#energy-management-strategies)
5. [Drive Cycles and Load Profiles](#drive-cycles-and-load-profiles)
6. [System-Level Performance Metrics](#system-level-performance-metrics)
7. [Multi-Domain Coupling](#multi-domain-coupling)
8. [References](#references)

---

## Introduction

System integration combines motor, battery, power electronics, and thermal management into a cohesive electric powertrain. This requires understanding interactions between subsystems and optimizing overall performance.

### Key Integration Challenges

- **Power matching**: Battery capability vs. motor requirements
- **Voltage compatibility**: Operating voltage ranges
- **Thermal coupling**: Heat from motor and power electronics affects battery
- **Control coordination**: Harmonizing motor control, BMS, and thermal management
- **Dynamic response**: Transient power demands vs. battery limitations

---

## System Architecture

### Basic Electric Powertrain

```
Battery Pack → DC Link → Inverter → Motor → Load
      ↓                                ↓
    BMS                           Controller
      ↓                                ↓
Thermal Management ←──────────────────┘
```

### Power Electronics Interface

**DC-DC Converter** (optional):
- **Boost converter**: Increase battery voltage for motor
- **Buck converter**: Reduce voltage for auxiliaries
- **Bidirectional**: Support regenerative braking

Voltage relationship:
$$
V_{motor} = D \cdot V_{battery} / (1-D)
$$

where $D$ = duty cycle

**Inverter**:
- Three-phase bridge (6 switches)
- Maximum line-to-line voltage: $V_{LL,max} = \frac{V_{DC}}{\sqrt{3}}$ (SVM)
- DC link capacitor for ripple current absorption

### Voltage Matching

**Motor base speed**:
$$
\omega_{base} = \frac{V_{max}}{\lambda_m}
$$

**Battery pack voltage**:
$$
V_{pack} = N_s \cdot V_{cell}
$$

where $N_s$ = number of cells in series

**Design consideration**:
- Motor requires sufficient voltage for peak speed
- Battery must deliver within safe voltage range
- Margin for voltage drop under load

Example:
- Motor requirement: 400 V at peak speed
- Battery nominal: 360 V (96 cells × 3.75 V)
- Battery voltage range: 288 V (discharged) to 403 V (fully charged)
- DC link capacitor smooths variations

### Current and Power Sizing

**Motor peak power**:
$$
P_{motor,peak} = T_{peak} \cdot \omega_{max}
$$

**Battery pack power**:
$$
P_{battery,max} = V_{pack} \cdot I_{max}
$$

**Capacity sizing**:
$$
E_{battery} = N_s \cdot N_p \cdot Q_{cell} \cdot V_{nom}
$$

where:
- $N_s$ = cells in series
- $N_p$ = cells in parallel
- $Q_{cell}$ = cell capacity [Ah]

**C-rate consideration**:
$$
C_{rate} = \frac{I_{discharge}}{Q_{cell} \cdot N_p}
$$

---

## Power Flow Management

### Operating Modes

#### 1. Motoring (Acceleration)

Power flow: Battery → Inverter → Motor

Energy balance:
$$
P_{battery} = P_{motor} + P_{inverter,loss} + P_{cable,loss}
$$

Motor power:
$$
P_{motor} = T_e \omega_m + P_{Cu} + P_{Fe} + P_{mech}
$$

Efficiency chain:
$$
\eta_{total} = \eta_{battery} \cdot \eta_{inverter} \cdot \eta_{motor}
$$

#### 2. Regenerative Braking

Power flow: Motor (generator) → Inverter → Battery

Regeneration efficiency:
$$
\eta_{regen} = \eta_{motor,gen} \cdot \eta_{inverter,rec} \cdot \eta_{battery,charge}
$$

Typical: 60-80% overall

**Regeneration limits**:
- Battery SOC: Cannot charge if SOC > 95%
- Battery power: Limited by charge C-rate
- Battery temperature: Reduced at temperature extremes
- Motor speed: Limited by back-EMF and voltage

**Blended braking**:
$$
F_{brake,total} = F_{brake,regen} + F_{brake,friction}
$$

Regeneration percentage:
$$
\alpha_{regen} = \frac{E_{recovered}}{E_{kinetic}}
$$

#### 3. Stationary (Idle/Auxiliaries)

Power consumption:
$$
P_{aux} = P_{BMS} + P_{cooling} + P_{electronics} + P_{other}
$$

Typical: 50-500 W depending on thermal management

### DC Link Dynamics

**Voltage equation**:
$$
C_{DC} \frac{dV_{DC}}{dt} = I_{battery} - I_{motor,avg}
$$

**Capacitor sizing**:
$$
C_{DC} = \frac{\Delta I \cdot T_{sw}}{\Delta V_{DC}}
$$

where:
- $T_{sw}$ = switching period [s]
- $\Delta V_{DC}$ = allowable ripple voltage [V]

Typical: 100-1000 µF for automotive applications

### Current Ripple

**Battery current ripple**:
$$
\Delta I_{battery} = \frac{V_{DC} D(1-D)}{L f_{sw}}
$$

High-frequency ripple accelerates battery degradation. Mitigation:
- LC filter between battery and inverter
- Interleaved switching
- High switching frequency

---

## Energy Management Strategies

### State Machine Control

Define system states based on operating conditions:

**State transitions**:
```
IDLE → START → DRIVE → REGEN → STOP → IDLE
```

Each state has specific power limits and control objectives.

### Equivalent Consumption Minimization Strategy (ECMS)

For hybrid systems, minimize equivalent fuel consumption:

$$
\min J = \dot{m}_{fuel} + s(SOC) \cdot \frac{P_{battery}}{\eta_{battery} Q_{fuel}}
$$

where:
- $s(SOC)$ = equivalence factor (function of SOC)
- $Q_{fuel}$ = fuel energy content

For pure electric:
$$
\min J = s(SOC) \cdot P_{battery}
$$

Adjust $s(SOC)$ to maintain SOC within target window.

### Dynamic Programming

Optimize over entire drive cycle:

$$
J = \sum_{k=0}^{N} L(x_k, u_k, k) + V(x_N)
$$

where:
- $L$ = stage cost (energy consumption)
- $V$ = terminal cost (final SOC penalty)
- $x$ = state (SOC, speed, etc.)
- $u$ = control (torque split, power distribution)

Bellman equation:
$$
J^*(x_k, k) = \min_u [L(x_k, u_k, k) + J^*(x_{k+1}, k+1)]
$$

### Real-Time Energy Management

**Model Predictive Control (MPC)**:

Prediction model:
$$
\begin{aligned}
SOC(k+1) &= SOC(k) - \frac{\eta I(k) \Delta t}{Q} \\
T_{battery}(k+1) &= f(T_{battery}(k), I(k), T_{amb})
\end{aligned}
$$

Cost function:
$$
J = \sum_{k=0}^{N_p} [w_1 (P_{demand} - P_{available})^2 + w_2 (T - T_{ref})^2 + w_3 (SOC - SOC_{target})^2]
$$

Constraints:
- Power limits: $P_{min} \leq P \leq P_{max}$
- SOC limits: $SOC_{min} \leq SOC \leq SOC_{max}$
- Temperature limits: $T_{min} \leq T \leq T_{max}$

### Power Limit Calculation

**Battery discharge power limit**:
$$
P_{dch,max} = \min\left(P_{continuous}, \frac{V_{pack} - V_{min}}{R_{int}} V_{pack}, P_{thermal}\right)
$$

**Battery charge power limit**:
$$
P_{chg,max} = \min\left(P_{continuous,chg}, \frac{V_{max} - V_{pack}}{R_{int}} V_{pack}, P_{thermal}, P_{SOC}\right)
$$

where:
- $P_{continuous}$ = continuous power rating
- $P_{thermal}$ = thermally limited power
- $P_{SOC}$ = SOC-dependent limit (reduced at high SOC)

---

## Drive Cycles and Load Profiles

### Standard Drive Cycles

#### Urban Driving: UDDS (Urban Dynamometer Driving Schedule)
- Duration: 1369 s
- Distance: 11.99 km
- Max speed: 91.2 km/h
- Average speed: 31.5 km/h
- Characteristics: Frequent stops, low speed

#### Highway: HWFET (Highway Fuel Economy Test)
- Duration: 765 s
- Distance: 16.5 km
- Max speed: 96.6 km/h
- Average speed: 77.7 km/h
- Characteristics: Steady state, fewer stops

#### Aggressive: US06
- Duration: 596 s
- Distance: 12.8 km
- Max speed: 129.2 km/h
- Average speed: 77.9 km/h
- Characteristics: High acceleration, high speed

#### Combined: WLTC (Worldwide harmonized Light vehicles Test Cycle)
- Duration: 1800 s
- Distance: 23.3 km
- Max speed: 131.3 km/h
- Phases: Low, Medium, High, Extra-High

### Vehicle Dynamics

**Traction force**:
$$
F_{traction} = F_{rolling} + F_{aero} + F_{grade} + F_{accel}
$$

**Rolling resistance**:
$$
F_{rolling} = \mu_{rr} m g \cos(\alpha)
$$

where $\mu_{rr} = 0.01-0.015$ for car tires

**Aerodynamic drag**:
$$
F_{aero} = \frac{1}{2} \rho C_d A v^2
$$

where:
- $\rho = 1.225$ kg/m³ (air density)
- $C_d = 0.25-0.35$ (drag coefficient)
- $A$ = frontal area [m²]

**Grade resistance**:
$$
F_{grade} = m g \sin(\alpha)
$$

**Acceleration force**:
$$
F_{accel} = m_{eff} a
$$

where $m_{eff} = m (1 + k_{rot})$, and $k_{rot} = 0.04-0.08$ (rotational inertia factor)

**Required motor torque**:
$$
T_{motor} = \frac{F_{traction} \cdot r_{wheel}}{\eta_{trans} \cdot G}
$$

where:
- $r_{wheel}$ = wheel radius [m]
- $G$ = gear ratio
- $\eta_{trans}$ = transmission efficiency

### Energy Consumption Analysis

**Energy required per cycle**:
$$
E_{cycle} = \int_0^{T_{cycle}} P(t) dt = \int_0^{T_{cycle}} F_{traction}(t) \cdot v(t) dt
$$

**Specific energy consumption**:
$$
E_{specific} = \frac{E_{cycle}}{d_{cycle}} \quad [\text{Wh/km}]
$$

**Range estimation**:
$$
Range = \frac{E_{battery,usable}}{E_{specific}}
$$

---

## System-Level Performance Metrics

### Efficiency

**Overall drivetrain efficiency**:
$$
\eta_{drivetrain} = \frac{P_{wheel}}{P_{battery}}
$$

**Component efficiency map**:
- Motor: $\eta_{motor}(T, \omega)$
- Inverter: $\eta_{inverter}(P, \omega)$
- Battery: $\eta_{battery}(I, SOC, T)$

### Energy Consumption

**Specific energy consumption** (Wh/km or Wh/mile):
$$
SEC = \frac{\int P_{battery} dt}{distance}
$$

**Equivalent MPG** (Miles Per Gallon equivalent):
$$
MPGe = \frac{33.7 \text{ kWh}}{E_{100mi} \text{ [kWh]}} \times 100
$$

### Range

**Usable battery energy**:
$$
E_{usable} = E_{total} \times (SOC_{max} - SOC_{min})
$$

Typical: 10-90% SOC window (80% usable)

**Range**:
$$
Range = \frac{E_{usable}}{SEC}
$$

### Thermal Performance

**Temperature rise per cycle**:
$$
\Delta T = \frac{\int P_{loss} dt}{m c_p}
$$

**Cooling requirement**:
$$
\dot{Q}_{cooling,req} = \frac{P_{loss,avg}}{1 - T_{amb}/T_{target}}
$$

### Degradation Rate

**Cycle life**:
$$
L_{cycle} = f(DOD, C_{rate}, T_{avg}, SOC_{avg})
$$

**Capacity fade per year**:
$$
\Delta Q_{year} = k_{cal}(T, SOC) + k_{cyc}(DOD, C_{rate}) \cdot \frac{km_{year}}{km_{per\\_cycle}}
$$

---

## Multi-Domain Coupling

### Electro-Thermal Coupling

**Motor**:
1. Electrical domain: $I, V \rightarrow P_{loss}$
2. Thermal domain: $P_{loss} \rightarrow T$
3. Feedback: $T \rightarrow R_s(T) \rightarrow I, V$

**Battery**:
1. Electrical: $I, SOC \rightarrow V, P_{loss}$
2. Thermal: $P_{loss} \rightarrow T$
3. Feedback: $T \rightarrow R(T), OCV(T)$

### Thermal Cross-Coupling

Heat from motor and inverter affects battery:

**Shared thermal environment**:
$$
T_{battery} = f(Q_{battery}, Q_{motor}, Q_{inverter}, T_{amb}, \dot{m}_{coolant})
$$

Coolant temperature rise:
$$
T_{coolant,out} = T_{coolant,in} + \frac{Q_{total}}{\dot{m} c_p}
$$

### Mechanical-Electrical Coupling

**Back-EMF limitation**:
$$
V_{bemf} = k_e \omega_{mech}
$$

Must satisfy: $V_{bemf} < V_{DC,available}$

**Torque ripple**:
- Electrical: Harmonics in current
- Mechanical: Vibration, noise

### Control Hierarchy

**Supervisory controller**:
- Energy management
- Mode selection
- Thermal management

**Motor controller**:
- Torque/speed control (10-100 ms)

**BMS**:
- SOC/SOH estimation
- Cell balancing
- Protection (1-10 ms)

**Low-level control**:
- Current regulation (10-100 µs)
- PWM generation (µs)

---

## System Optimization

### Multi-Objective Optimization

Objective function:
$$
\min [w_1 E_{consumption} + w_2 T_{max} + w_3 Cost + w_4 (-Performance)]
$$

Design variables:
- Battery capacity: $E_{battery}$
- Motor power: $P_{motor}$
- Gear ratio: $G$
- Cooling system sizing

Constraints:
- Performance: $0-100$ km/h time, top speed, gradeability
- Thermal: $T_{max} < T_{limit}$
- Packaging: Volume, weight limits
- Cost: Budget constraint

### Co-Simulation Approach

Integrate multiple domain models:
1. **Simulink**: System-level control, integration
2. **Simscape Electrical**: Motor, battery, inverter
3. **Simscape Fluids**: Cooling system
4. **Simscape Driveline**: Mechanical transmission
5. **FEA tools**: Detailed thermal analysis (offline)

---

## Validation and Testing

### Component-Level Testing

- **Motor**: Dynamometer testing (torque-speed curve, efficiency map)
- **Battery**: Cell characterization (OCV, resistance, thermal)
- **Inverter**: Efficiency, switching losses

### Subsystem Testing

- **Motor + Inverter**: Combined efficiency
- **Battery pack**: Thermal uniformity, balancing

### System-Level Testing

- **Test bench**: Motor dynamometer + battery simulator
- **Vehicle**: Chassis dynamometer with drive cycles
- **Track testing**: Real-world validation

### Hardware-in-the-Loop (HIL)

- Real controller + simulated plant
- Real-time simulation (1 ms time step)
- Test fault scenarios safely

---

## References

1. Ehsani, M., et al. (2018). *Modern Electric, Hybrid Electric, and Fuel Cell Vehicles*. CRC Press.
2. Larminie, J., & Lowry, J. (2012). *Electric Vehicle Technology Explained*. Wiley.
3. Guzzella, L., & Sciarretta, A. (2013). *Vehicle Propulsion Systems*. Springer.
4. Schouten, N. J., et al. (2002). "Energy management strategies for parallel hybrid vehicles using fuzzy logic." *Control Engineering Practice*, 10(9), 1093-1098.
5. Hu, X., et al. (2017). "Charging, power management, and battery degradation mitigation in plug-in hybrid electric vehicles: A unified cost-optimal approach." *Mechanical Systems and Signal Processing*, 87, 4-16.

---

**Previous**: [Thermal Theory](04_thermal_theory.md)
**Back to**: [Main README](../README.md)
