# Thermal Modeling Theory

## Table of Contents
1. [Introduction](#introduction)
2. [Heat Transfer Fundamentals](#heat-transfer-fundamentals)
3. [Thermal Network Modeling](#thermal-network-modeling)
4. [Motor Thermal Modeling](#motor-thermal-modeling)
5. [Battery Thermal Modeling](#battery-thermal-modeling)
6. [Cooling Systems](#cooling-systems)
7. [References](#references)

---

## Introduction

Thermal management is critical for electric powertrains to ensure:
- **Performance**: Temperature affects resistance, torque, efficiency
- **Safety**: Prevent thermal runaway and component damage
- **Durability**: High temperatures accelerate degradation
- **Comfort**: Cabin heating/cooling requirements

---

## Heat Transfer Fundamentals

### Three Modes of Heat Transfer

#### 1. Conduction

Heat transfer through solid materials:

**Fourier's Law**:
$$
\dot{Q}_{cond} = -kA\frac{dT}{dx}
$$

For uniform cross-section:
$$
\dot{Q}_{cond} = \frac{k A (T_1 - T_2)}{L}
$$

**Thermal resistance**:
$$
R_{th,cond} = \frac{L}{kA}
$$

where:
- $\dot{Q}$ = heat transfer rate [W]
- $k$ = thermal conductivity [W/m·K]
- $A$ = cross-sectional area [m²]
- $L$ = length [m]
- $T$ = temperature [K or °C]

**Common thermal conductivities**:
- Copper: 400 W/m·K
- Aluminum: 237 W/m·K
- Steel: 50 W/m·K
- Thermal interface material (TIM): 1-10 W/m·K
- Air (gap): 0.026 W/m·K

#### 2. Convection

Heat transfer between solid surface and moving fluid:

**Newton's Law of Cooling**:
$$
\dot{Q}_{conv} = hA(T_s - T_\infty)
$$

**Thermal resistance**:
$$
R_{th,conv} = \frac{1}{hA}
$$

where:
- $h$ = convection heat transfer coefficient [W/m²·K]
- $T_s$ = surface temperature [K]
- $T_\infty$ = fluid bulk temperature [K]

**Typical convection coefficients**:
- Natural air convection: 5-25 W/m²·K
- Forced air convection: 10-200 W/m²·K
- Liquid convection: 50-10,000 W/m²·K
- Boiling water: 2,500-100,000 W/m²·K

**Nusselt number correlations**:

Natural convection (vertical plate):
$$
Nu = 0.59 Ra^{1/4} \quad \text{(laminar)}
$$
$$
Nu = 0.10 Ra^{1/3} \quad \text{(turbulent)}
$$

Forced convection (internal flow):
$$
Nu = 0.023 Re^{0.8} Pr^{0.4} \quad \text{(turbulent)}
$$

where:
- $Nu = \frac{hL}{k}$ = Nusselt number
- $Ra = Gr \cdot Pr$ = Rayleigh number
- $Re = \frac{\rho v L}{\mu}$ = Reynolds number
- $Pr = \frac{\mu c_p}{k}$ = Prandtl number

#### 3. Radiation

Heat transfer via electromagnetic waves:

**Stefan-Boltzmann Law**:
$$
\dot{Q}_{rad} = \varepsilon \sigma A (T_1^4 - T_2^4)
$$

Linearized form for small temperature differences:
$$
\dot{Q}_{rad} = h_r A (T_1 - T_2)
$$

where:
$$
h_r = 4\varepsilon \sigma T_{avg}^3
$$

Constants:
- $\sigma = 5.67 \times 10^{-8}$ W/m²·K⁴ (Stefan-Boltzmann constant)
- $\varepsilon$ = emissivity (0-1)
  - Polished metal: 0.05-0.15
  - Painted surface: 0.9-0.95
  - Black surface: 0.95-0.98

---

## Thermal Network Modeling

### Lumped Capacitance Method

Thermal-electrical analogy:

| Thermal | Electrical | Equation |
|---------|-----------|----------|
| Temperature $T$ | Voltage $V$ | - |
| Heat flow $\dot{Q}$ | Current $I$ | - |
| Thermal resistance $R_{th}$ | Resistance $R$ | $T = \dot{Q} \cdot R_{th}$ |
| Thermal capacitance $C_{th}$ | Capacitance $C$ | $C_{th} \frac{dT}{dt} = \dot{Q}$ |

### Single-Node Model

Energy balance:
$$
C_{th} \frac{dT}{dt} = \dot{Q}_{gen} - \frac{T - T_{amb}}{R_{th}}
$$

**Steady-state solution**:
$$
T_{ss} = T_{amb} + \dot{Q}_{gen} \cdot R_{th}
$$

**Transient solution** (step input):
$$
T(t) = T_{amb} + \dot{Q}_{gen} R_{th} (1 - e^{-t/\tau})
$$

where $\tau = R_{th} C_{th}$ = thermal time constant [s]

### Multi-Node Network

For complex geometries, discretize into multiple nodes:

Node $i$:
$$
C_{th,i} \frac{dT_i}{dt} = \dot{Q}_{gen,i} + \sum_{j} \frac{T_j - T_i}{R_{th,ij}}
$$

**Matrix form**:
$$
\mathbf{C}_{th} \frac{d\mathbf{T}}{dt} = \mathbf{\dot{Q}}_{gen} - \mathbf{G}_{th} \mathbf{T} + \mathbf{G}_{th,amb} T_{amb}
$$

where $\mathbf{G}_{th}$ = thermal conductance matrix [W/K]

---

## Motor Thermal Modeling

### Heat Generation Sources

#### 1. Copper Losses (Stator Windings)

$$
P_{Cu} = 3 I_{rms}^2 R_s(T)
$$

Temperature-dependent resistance:
$$
R_s(T) = R_{s,ref} [1 + \alpha_{Cu}(T - T_{ref})]
$$

where $\alpha_{Cu} = 0.00393$ /K for copper at 20°C

#### 2. Iron Losses (Stator Core)

Hysteresis and eddy current losses:
$$
P_{Fe} = k_h f B_{max}^2 + k_e f^2 B_{max}^2
$$

or empirically:
$$
P_{Fe} = P_{Fe,rated} \left(\frac{f}{f_{rated}}\right)^{1.5} \left(\frac{B}{B_{rated}}\right)^{2}
$$

#### 3. Mechanical Losses

Friction and windage:
$$
P_{mech} = k_{friction} \omega_m + k_{windage} \omega_m^3
$$

#### 4. Rotor Losses (Induction Motor)

$$
P_{rotor} = s \cdot P_{airgap} = s \cdot (P_{in} - P_{Cu,s} - P_{Fe})
$$

where $s$ = slip

### Motor Thermal Network

Typical nodes:
1. **Stator winding** ($T_w$)
2. **Stator core** ($T_c$)
3. **Rotor** ($T_r$)
4. **Housing** ($T_h$)
5. **Ambient** ($T_{amb}$)

**Winding node**:
$$
C_{th,w} \frac{dT_w}{dt} = P_{Cu} - \frac{T_w - T_c}{R_{th,wc}} - \frac{T_w - T_h}{R_{th,wh}}
$$

**Core node**:
$$
C_{th,c} \frac{dT_c}{dt} = P_{Fe} + \frac{T_w - T_c}{R_{th,wc}} - \frac{T_c - T_h}{R_{th,ch}}
$$

**Rotor node**:
$$
C_{th,r} \frac{dT_r}{dt} = P_{rotor} - \frac{T_r - T_c}{R_{th,rc}} - \frac{T_r - T_h}{R_{th,rh}}
$$

**Housing node**:
$$
C_{th,h} \frac{dT_h}{dt} = \frac{T_c - T_h}{R_{th,ch}} + \frac{T_w - T_h}{R_{th,wh}} - \frac{T_h - T_{amb}}{R_{th,conv}}
$$

### Parameter Estimation

**Thermal capacitance**:
$$
C_{th} = m \cdot c_p
$$

Specific heat capacities:
- Copper: 385 J/kg·K
- Iron: 450 J/kg·K
- Aluminum: 900 J/kg·K

**Thermal resistance** (conduction):
$$
R_{th} = \frac{L}{k \cdot A}
$$

**Thermal resistance** (convection):
$$
R_{th,conv} = \frac{1}{h \cdot A_{surface}}
$$

### Thermal Limits

**Insulation classes** (temperature rise above 40°C ambient):
- Class A: 60 K (max 105°C)
- Class E: 75 K (max 120°C)
- Class B: 80 K (max 130°C)
- Class F: 100 K (max 155°C)
- Class H: 125 K (max 180°C)

**Magnet demagnetization**:
- NdFeB magnets: >150-180°C
- Ferrite magnets: >250°C

---

## Battery Thermal Modeling

### Heat Generation

Total heat generation:
$$
\dot{Q}_{total} = \dot{Q}_{irr} + \dot{Q}_{rev}
$$

#### 1. Irreversible Heat (Joule Heating)

$$
\dot{Q}_{irr} = I^2 R_{total} = I(V_{OC} - V_{terminal})
$$

For detailed model:
$$
\dot{Q}_{irr} = I^2 (R_0 + R_1 + R_2 + ...)
$$

#### 2. Reversible Heat (Entropic Heat)

$$
\dot{Q}_{rev} = IT\frac{\partial V_{OC}}{\partial T}
$$

Entropic coefficient $\frac{\partial V_{OC}}{\partial T}$:
- Typically -0.5 to +0.5 mV/K
- Varies with SOC
- Can be endothermic or exothermic

### Battery Cell Thermal Model

#### Lumped Model (Single Node)

$$
mc_p\frac{dT}{dt} = \dot{Q}_{gen} - \frac{T - T_{amb}}{R_{th}}
$$

where:
- $m$ = cell mass [kg]
- $c_p$ = specific heat (800-1200 J/kg·K for Li-ion)
- $R_{th}$ = thermal resistance to ambient [K/W]

#### Distributed Model (Radial)

For cylindrical cells (18650, 21700):

$$
\rho c_p \frac{\partial T}{\partial t} = \frac{1}{r}\frac{\partial}{\partial r}\left(k_r r \frac{\partial T}{\partial r}\right) + \dot{q}_{gen}
$$

Boundary conditions:
- Center: $\frac{\partial T}{\partial r}\Big|_{r=0} = 0$ (symmetry)
- Surface: $-k\frac{\partial T}{\partial r}\Big|_{r=R} = h(T_s - T_\infty)$ (convection)

### Battery Pack Thermal Model

**Cell-to-cell variation**:

Cell $i$:
$$
C_{th,i} \frac{dT_i}{dt} = \dot{Q}_{gen,i} - \sum_j \frac{T_i - T_j}{R_{th,ij}} - \frac{T_i - T_{amb}}{R_{th,i,amb}}
$$

**Interconnected network**:
- Conduction between adjacent cells
- Convection to coolant or air
- Radiation between cells (often neglected)

### Temperature Effects on Battery Parameters

**Internal resistance**:
$$
R(T) = R_{ref} \exp\left[\beta\left(\frac{1}{T} - \frac{1}{T_{ref}}\right)\right]
$$

Typical $\beta = 3000-5000$ K

**Capacity**:
$$
Q(T) = Q_{ref} \left[1 + k_Q (T - T_{ref})\right]
$$

Capacity decreases at low temperature (Li-ion loses ~20-50% capacity at -20°C)

**OCV**:
$$
V_{OC}(SOC,T) = V_{OC,ref}(SOC) + k_T(T - T_{ref})
$$

where $k_T \approx -0.5$ to -1 mV/K

---

## Cooling Systems

### Air Cooling

**Natural convection**:
- Simple, no parasitic power
- Limited cooling capacity (5-15 W/cell max)
- Suitable for low power applications

**Forced air**:
- Fan-driven airflow
- Moderate cooling capacity (10-30 W/cell)
- Lightweight, low cost
- Used in Nissan Leaf

Heat removal:
$$
\dot{Q}_{air} = \dot{m}_{air} c_{p,air} (T_{out} - T_{in})
$$

where:
- $\dot{m}_{air}$ = air mass flow rate [kg/s]
- $c_{p,air}$ = 1005 J/kg·K

### Liquid Cooling

**Cold plates**:
- Cells mounted on cooling plates
- High heat transfer coefficient
- Uniform temperature distribution
- Used in Tesla, BMW, VW

**Immersion cooling**:
- Cells submerged in dielectric fluid
- Very uniform temperature
- Complex sealing requirements

Heat removal:
$$
\dot{Q}_{liquid} = \dot{m}_{liquid} c_{p,liquid} (T_{out} - T_{in})
$$

Coolant properties:
- Water/glycol (50/50): $c_p = 3500$ J/kg·K, $\rho = 1070$ kg/m³
- Oil-based: $c_p = 2000$ J/kg·K

**Effectiveness-NTU method**:

Effectiveness:
$$
\varepsilon = \frac{\dot{Q}_{actual}}{\dot{Q}_{max}}
$$

NTU (Number of Transfer Units):
$$
NTU = \frac{UA}{\dot{m}c_p}
$$

For parallel flow:
$$
\varepsilon = \frac{1 - \exp[-NTU(1+C_r)]}{1 + C_r}
$$

where $C_r = \frac{\dot{m}c_p}_{min}/\frac{\dot{m}c_p}_{max}$

### Phase Change Materials (PCM)

**Principle**: Absorb heat during phase transition (solid→liquid) at constant temperature

Latent heat storage:
$$
Q_{latent} = m_{PCM} \cdot h_{fg}
$$

where:
- $h_{fg}$ = latent heat of fusion [J/kg]
- Typical PCM: paraffin wax, $h_{fg} = 200-250$ kJ/kg, $T_{melt} = 30-50$°C

**Advantages**:
- Isothermal heat absorption
- Passive (no power required)
- Peak shaving capability

**Disadvantages**:
- Low thermal conductivity (need fins or additives)
- Limited reusability after melting
- Added weight and volume

### Heat Pipes

**Principle**: Two-phase heat transfer (evaporation-condensation cycle)

Effective thermal conductivity:
$$
k_{eff} = 10,000 - 100,000 \text{ W/m·K}
$$

Much higher than solid copper!

**Applications**:
- High heat flux areas
- Long-distance heat transfer
- Thermal spreading

---

## Thermal Management Control

### Temperature Control Strategies

#### 1. On/Off Control

Simple thermostat:
$$
\text{Cooling} = \begin{cases}
\text{ON} & \text{if } T > T_{set} + \Delta T \\
\text{OFF} & \text{if } T < T_{set} - \Delta T
\end{cases}
$$

#### 2. PID Control

$$
u(t) = K_p e(t) + K_i \int e(t) dt + K_d \frac{de(t)}{dt}
$$

where $e = T_{set} - T$

#### 3. Model Predictive Control (MPC)

Predict future temperatures and optimize cooling power:

$$
\min_{u} \sum_{k=0}^{N} [q(T(k) - T_{ref})^2 + r u(k)^2]
$$

subject to:
- Temperature limits: $T_{min} \leq T \leq T_{max}$
- Cooling power limits: $0 \leq u \leq u_{max}$
- Temperature gradient limits: $|\Delta T| \leq \Delta T_{max}$

### Preconditioning

**Battery preheating** (cold weather):
- Resistive heaters
- Reverse heat pump
- Use battery internal resistance

**Battery precooling** (hot weather or before fast charge):
- Activate cooling before high power demand
- Reduce peak temperature

### Parasitic Power Consideration

Cooling system power consumption:

**Fan power**:
$$
P_{fan} = \frac{\Delta p \cdot \dot{V}}{\eta_{fan}}
$$

**Pump power**:
$$
P_{pump} = \frac{\Delta p \cdot \dot{V}}{\eta_{pump}}
$$

**Optimization**:
Minimize total power:
$$
P_{total} = P_{battery} + P_{cooling}
$$

---

## Thermal Simulation in Simscape

### Thermal Domain Blocks

**Basic elements**:
- Thermal Mass: $C_{th}$
- Thermal Resistance: $R_{th}$
- Thermal Reference: Ambient temperature
- Heat Flow Source: $\dot{Q}$

**Convective blocks**:
- Convective Heat Transfer
- Forced Convection
- Natural Convection

### Coupled Electro-Thermal Simulation

1. **Electrical domain**: Calculate current, voltage, losses
2. **Thermal domain**: Calculate heat generation, temperature
3. **Feedback**: Update electrical parameters based on temperature

Example workflow:
```
Current → Losses → Heat Generation → Temperature → Resistance → Voltage → Current
```

### Solver Settings

- **Solver**: ode15s (stiff) or ode23t
- **Relative tolerance**: 1e-3 to 1e-4
- **Absolute tolerance**: 1e-6
- **Max step size**: Auto (or 1/10 of smallest time constant)

---

## Thermal Testing and Validation

### Experimental Methods

**Thermocouple placement**:
- Winding hotspot
- Core temperature
- Surface temperature
- Coolant inlet/outlet

**Infrared thermography**:
- Non-contact measurement
- Surface temperature mapping
- Identify hot spots

**Calorimetry**:
- Measure total heat dissipation
- Validate loss models

### Thermal Transient Testing

**Step response**:
1. Apply constant load
2. Measure temperature rise
3. Fit to exponential: $T(t) = T_{ss}(1 - e^{-t/\tau})$
4. Extract $R_{th}$ and $C_{th}$

**Frequency response**:
1. Apply sinusoidal power input
2. Measure temperature amplitude and phase
3. Construct Bode plot of thermal impedance

---

## References

1. Incropera, F. P., et al. (2011). *Fundamentals of Heat and Mass Transfer*. Wiley.
2. Mellor, P. H., et al. (1991). "Lumped parameter thermal model for electrical machines of TEFC design." *IEE Proceedings B*, 138(5), 205-218.
3. Pesaran, A. A. (2001). "Battery thermal management in EVs and HEVs: Issues and solutions." *Advanced Automotive Battery Conference*.
4. Bandhauer, T. M., et al. (2011). "A critical review of thermal issues in lithium-ion batteries." *Journal of the Electrochemical Society*, 158(3), R1-R25.
5. Kim, J., et al. (2019). "Review on battery thermal management system for electric vehicles." *Applied Thermal Engineering*, 149, 192-212.

---

**Previous**: [Control Theory](03_control_theory.md)
**Next**: [System Integration](05_system_integration.md)
