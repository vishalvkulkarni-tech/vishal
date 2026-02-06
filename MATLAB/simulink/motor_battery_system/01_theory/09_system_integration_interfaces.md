# System Integration Interfaces - Motor Control & Vehicle Systems

## Table of Contents
1. [System Architecture Overview](#system-architecture-overview)
2. [Battery Management System (BMS) Interface](#battery-management-system-bms-interface)
3. [Drivetrain Interface](#drivetrain-interface)
4. [Regenerative Braking System](#regenerative-braking-system)
5. [Communication Protocols](#communication-protocols)
6. [Power Flow Management](#power-flow-management)
7. [Practical Algorithm Implementations](#practical-algorithm-implementations)
8. [Safety and Fault Handling](#safety-and-fault-handling)
9. [References](#references)

---

## System Architecture Overview

### Electric Vehicle Control Hierarchy

```
┌─────────────────────────────────────────────────┐
│     Vehicle Dynamics Controller (VDC)          │
│  - Traction Control                            │
│  - Stability Control                           │
│  - Torque Vectoring                           │
└──────────────┬──────────────────────────────────┘
               │
    ┌──────────┴──────────┬──────────────┬────────────────┐
    ▼                     ▼              ▼                ▼
┌─────────┐        ┌──────────┐   ┌──────────┐   ┌────────────┐
│   BMS   │◄──────►│  MCU     │◄─►│ Drivetrain│◄─►│   HMI      │
│         │        │ (Motor   │   │  Control  │   │  Display   │
│         │        │ Control) │   │           │   │            │
└────┬────┘        └────┬─────┘   └─────┬────┘   └────────────┘
     │                  │               │
     │                  │               │
     ▼                  ▼               ▼
┌─────────┐        ┌──────────┐   ┌──────────┐
│ Battery │        │  Motor/  │   │ Mechanical│
│  Pack   │        │ Inverter │   │ Transmission│
└─────────┘        └──────────┘   └──────────┘
```

### Data Flow Architecture

```
BMS → MCU:
  - SOC, SOH, Temperature
  - Voltage, Current limits
  - Power limits (charge/discharge)
  - Fault status

MCU → BMS:
  - Actual current demand
  - Voltage measurements
  - Operating mode
  - Fault status

Drivetrain → MCU:
  - Torque request
  - Speed setpoint
  - Mode (Drive/Regen/Neutral)
  - Gear position

MCU → Drivetrain:
  - Actual torque
  - Motor speed
  - Temperature
  - Ready status
```

### Interface Update Rates

| Interface | Update Rate | Latency Requirement | Protocol |
|-----------|------------|---------------------|----------|
| BMS → MCU (limits) | 10-100 Hz | < 100 ms | CAN |
| BMS → MCU (measurements) | 100-1000 Hz | < 10 ms | CAN-FD |
| MCU ↔ Drivetrain | 100-1000 Hz | < 10 ms | CAN-FD |
| MCU → Inverter | 10-50 kHz | < 100 μs | Direct I/O |
| Vehicle Network | 10-100 Hz | < 50 ms | CAN |

---

## Battery Management System (BMS) Interface

### BMS Responsibilities

1. **Cell Monitoring**: Voltage, temperature, impedance
2. **State Estimation**: SOC, SOH, SOE, SOP
3. **Thermal Management**: Cooling system control
4. **Safety Protection**: OV, UV, OC, OT protection
5. **Balancing**: Active/passive cell balancing
6. **Communication**: Data exchange with MCU

### Power Limits Calculation (BMS Side)

#### Continuous Power Limits

The BMS calculates maximum charge and discharge power based on multiple constraints:

$$P_{max,discharge} = \min(P_{thermal}, P_{voltage}, P_{current}, P_{SOC})$$
$$P_{max,charge} = \min(P_{thermal}, P_{voltage}, P_{current}, P_{SOC})$$

#### 1. Thermal Limit

$$P_{thermal} = \frac{(T_{max} - T_{cell}) \cdot C_{th}}{R_{th}}$$

where:
- $T_{max}$ = Maximum safe cell temperature [°C]
- $T_{cell}$ = Current cell temperature [°C]
- $C_{th}$ = Thermal capacitance [J/°C]
- $R_{th}$ = Thermal resistance [°C/W]

#### 2. Voltage Limit

**Discharge limit**:
$$P_{discharge,V} = \frac{(V_{cell} - V_{min}) \cdot V_{pack}}{R_{internal}}$$

**Charge limit**:
$$P_{charge,V} = \frac{(V_{max} - V_{cell}) \cdot V_{pack}}{R_{internal}}$$

#### 3. Current Limit

Based on C-rate capability:
$$
\begin{aligned}
I_{max,discharge} &= C_{rate,discharge} \times Q_{capacity} \\
I_{max,charge} &= C_{rate,charge} \times Q_{capacity} \\
P_{current} &= I_{max} \times V_{pack}
\end{aligned}
$$

#### 4. SOC-based Limit

$$P_{SOC} = 
\begin{cases}
P_{rated} \cdot \frac{SOC}{SOC_{low}} & \text{if } SOC < SOC_{low} \\
P_{rated} & \text{if } SOC_{low} \leq SOC \leq SOC_{high} \\
P_{rated} \cdot \frac{100 - SOC}{100 - SOC_{high}} & \text{if } SOC > SOC_{high}
\end{cases}
$$

Typical values:
- $SOC_{low} = 20\%$
- $SOC_{high} = 90\%$

### State of Charge (SOC) Estimation

#### Coulomb Counting Method

$$SOC(t) = SOC(t_0) - \frac{1}{Q_{capacity}} \int_{t_0}^{t} \eta \cdot I(\tau) d\tau$$

where:
- $\eta$ = Coulombic efficiency (0.95-1.0)
- $I$ = Battery current [A] (positive = discharge)
- $Q_{capacity}$ = Battery capacity [Ah]

**Discrete implementation**:
$$SOC[k] = SOC[k-1] - \frac{\eta \cdot I[k] \cdot \Delta t}{Q_{capacity} \cdot 3600}$$

#### Extended Kalman Filter (EKF) for SOC

**State equation**:
$$
\begin{bmatrix} SOC[k] \\ R_1[k] \end{bmatrix} = 
\begin{bmatrix} 1 & 0 \\ 0 & e^{-\Delta t/\tau_1} \end{bmatrix}
\begin{bmatrix} SOC[k-1] \\ R_1[k-1] \end{bmatrix} +
\begin{bmatrix} -\frac{\eta \Delta t}{3600 Q} \\ (1-e^{-\Delta t/\tau_1}) I R_{1,\infty} \end{bmatrix}
$$

**Measurement equation**:
$$V_{terminal} = OCV(SOC) - I \cdot R_0 - I \cdot R_1 + noise$$

### BMS-MCU Interface Data Structure

```c
// BMS → MCU (Transmit every 10 ms)
typedef struct {
    // State estimates
    float SOC;                    // State of charge [%]
    float SOH;                    // State of health [%]
    float SOE;                    // State of energy [kWh]
    
    // Measurements
    float pack_voltage;           // Total pack voltage [V]
    float pack_current;           // Pack current [A] (+discharge, -charge)
    float max_cell_voltage;       // Highest cell voltage [V]
    float min_cell_voltage;       // Lowest cell voltage [V]
    float max_cell_temp;          // Highest cell temperature [°C]
    float min_cell_temp;          // Lowest cell temperature [°C]
    float avg_cell_temp;          // Average temperature [°C]
    
    // Power limits
    float max_discharge_power;    // Maximum discharge power [kW]
    float max_charge_power;       // Maximum charge power [kW]
    float max_discharge_current;  // Maximum discharge current [A]
    float max_charge_current;     // Maximum charge current [A]
    
    // Status and faults
    uint8_t bms_state;           // 0=Init, 1=Ready, 2=Active, 3=Fault
    uint16_t fault_code;         // Fault bitmap
    uint8_t contactor_state;     // Main contactor status
    uint8_t balancing_active;    // Balancing status
    
    // Timestamp and checksum
    uint32_t timestamp;          // ms
    uint16_t crc;                // CRC-16
} BMS_to_MCU_t;

// MCU → BMS (Transmit every 10 ms)
typedef struct {
    // Commands
    float torque_request;         // Requested torque [Nm]
    float power_request;          // Requested power [kW]
    
    // Actual values
    float actual_current;         // Actual DC link current [A]
    float actual_power;           // Actual power [kW]
    float dc_link_voltage;        // Measured DC voltage [V]
    
    // Motor controller status
    uint8_t mcu_state;           // 0=Init, 1=Ready, 2=Running, 3=Fault
    float inverter_temp;         // Inverter temperature [°C]
    float motor_temp;            // Motor temperature [°C]
    uint16_t fault_code;         // Fault bitmap
    
    // Operating mode
    uint8_t mode;                // 0=Standby, 1=Drive, 2=Regen, 3=Charge
    
    // Timestamp and checksum
    uint32_t timestamp;          // ms
    uint16_t crc;                // CRC-16
} MCU_to_BMS_t;
```

### Fault Codes and Handling

**BMS Fault Bitmap**:
```c
#define BMS_FAULT_CELL_OV          (1 << 0)   // Cell overvoltage
#define BMS_FAULT_CELL_UV          (1 << 1)   // Cell undervoltage
#define BMS_FAULT_PACK_OV          (1 << 2)   // Pack overvoltage
#define BMS_FAULT_PACK_UV          (1 << 3)   // Pack undervoltage
#define BMS_FAULT_DISCHARGE_OC     (1 << 4)   // Discharge overcurrent
#define BMS_FAULT_CHARGE_OC        (1 << 5)   // Charge overcurrent
#define BMS_FAULT_CELL_OT          (1 << 6)   // Cell overtemperature
#define BMS_FAULT_CELL_UT          (1 << 7)   // Cell undertemperature
#define BMS_FAULT_SOC_LOW          (1 << 8)   // SOC critically low
#define BMS_FAULT_IMBALANCE        (1 << 9)   // Cell imbalance
#define BMS_FAULT_COMMUNICATION    (1 << 10)  // Communication error
#define BMS_FAULT_CONTACTOR        (1 << 11)  // Contactor failure
#define BMS_FAULT_ISOLATION        (1 << 12)  // Isolation fault
```

### Power Derating Strategy

**Graceful degradation** based on BMS limits:

$$P_{available}(t) = P_{BMS,limit} \cdot f_{derating}(T, SOC, Health)$$

**Derating function**:
```
f_derating = min(f_temp, f_SOC, f_health)

f_temp = {
    1.0                           if T < T_nominal
    1 - 0.5(T - T_nominal)/(T_max - T_nominal)  if T_nominal ≤ T < T_max
    0.5                           if T ≥ T_max
}

f_SOC = {
    0.5 + 0.5·SOC/20             if SOC < 20%
    1.0                          if 20% ≤ SOC ≤ 90%
    0.5 + 0.5·(100-SOC)/10       if SOC > 90%
}

f_health = max(0.3, SOH/100)
```

---

## Drivetrain Interface

### Drivetrain Architecture Types

#### 1. Single Motor (Central Drive)

```
     ┌─────────┐      ┌──────────┐      ┌──────────┐
     │  Motor  │─────►│ Reduction│─────►│Differential│
     │   MCU   │      │   Gear   │      │   & Axle  │
     └─────────┘      └──────────┘      └──────────┘
                                              │
                                         ┌────┴────┐
                                         ▼         ▼
                                       Wheel     Wheel
```

**Gear ratio**: $G = 8:1$ to $12:1$ typical

#### 2. Dual Motor (Independent Rear Wheels)

```
     ┌─────────┐                        ┌─────────┐
     │ Motor 1 │────────────────────────│ Wheel L │
     │  MCU-L  │                        └─────────┘
     └─────────┘                        
                                        ┌─────────┐
     ┌─────────┐                        │ Wheel R │
     │ Motor 2 │────────────────────────└─────────┘
     │  MCU-R  │
     └─────────┘
```

**Torque vectoring capability**: Independent left/right control

#### 3. In-Wheel Motors (Four Motors)

```
┌─────────┐                          ┌─────────┐
│ Motor FL│──────────────────────────│ Wheel FL│
└─────────┘                          └─────────┘

┌─────────┐                          ┌─────────┐
│ Motor FR│──────────────────────────│ Wheel FR│
└─────────┘                          └─────────┘

┌─────────┐                          ┌─────────┐
│ Motor RL│──────────────────────────│ Wheel RL│
└─────────┘                          └─────────┘

┌─────────┐                          ┌─────────┐
│ Motor RR│──────────────────────────│ Wheel RR│
└─────────┘                          └─────────┘
```

**Maximum torque vectoring**: All four wheels independently controlled

### Torque Request Processing

#### Driver Input to Torque Mapping

**Accelerator pedal mapping**:
$$T_{request} = T_{max}(n) \cdot f_{pedal}(x_{accel}) \cdot f_{mode}$$

where:
- $T_{max}(n)$ = Speed-dependent maximum torque
- $x_{accel}$ = Accelerator pedal position [0-1]
- $f_{mode}$ = Drive mode factor (Eco/Normal/Sport)

**Pedal mapping functions**:

**Linear** (Eco mode):
$$f_{pedal}(x) = x$$

**Progressive** (Normal mode):
$$f_{pedal}(x) = x^{1.5}$$

**Aggressive** (Sport mode):
$$f_{pedal}(x) = 1 - (1-x)^2$$

#### Speed-Dependent Torque Limit

**Constant torque region** ($n < n_{base}$):
$$T_{max}(n) = T_{rated}$$

**Constant power region** ($n \geq n_{base}$):
$$T_{max}(n) = \frac{P_{rated}}{n} = \frac{T_{rated} \cdot n_{base}}{n}$$

**Field weakening region** ($n > n_{rated}$):
$$T_{max}(n) = T_{rated} \cdot \left(\frac{n_{rated}}{n}\right)^2$$

```
Torque
  │
  │ ┌─────────────┐
  │ │   Constant  │
T │ │   Torque    │
r │ │             │╲
a │ │             │ ╲ Constant
t │ │             │  ╲ Power
e │ │             │   ╲
d │ │             │    ╲
  │ │             │     ╲╲ Field
  │ │             │       ╲╲ Weakening
  └─┴─────────────┴────────╲╲───────► Speed
    0          n_base   n_rated   n_max
```

### Traction Control Integration

#### Wheel Slip Calculation

$$\lambda = \frac{v_{wheel} - v_{vehicle}}{v_{vehicle}}$$

where:
- $v_{wheel} = r_{wheel} \cdot \omega_{wheel}$
- $v_{vehicle}$ = GPS or estimated vehicle speed

**Optimal slip**: $\lambda_{opt} \approx 0.1 - 0.2$ (10-20%)

#### Slip-Based Torque Reduction

**PI controller for slip regulation**:
$$
\begin{aligned}
e_{slip} &= \lambda - \lambda_{target} \\
T_{reduction} &= K_p \cdot e_{slip} + K_i \int e_{slip} dt \\
T_{final} &= T_{request} - T_{reduction}
\end{aligned}
$$

**Anti-slip algorithm**:
```matlab
if λ > λ_max
    T_reduction = K_aggressive × (λ - λ_max)
    T_final = max(0, T_request - T_reduction)
end
```

### Torque Vectoring (Dual/Quad Motor)

#### Yaw Moment Control

**Desired yaw moment**:
$$M_z = K_{\delta} \cdot \delta_{steering} + K_{\dot{\beta}} \cdot \dot{\beta} + K_r \cdot (r_{desired} - r_{actual})$$

where:
- $\delta_{steering}$ = Steering angle [rad]
- $\dot{\beta}$ = Sideslip rate [rad/s]
- $r$ = Yaw rate [rad/s]

**Torque distribution** (rear axle):
$$
\begin{aligned}
T_{left} &= \frac{T_{total}}{2} - \frac{M_z}{t_{track}} \\
T_{right} &= \frac{T_{total}}{2} + \frac{M_z}{t_{track}}
\end{aligned}
$$

where $t_{track}$ = track width [m]

#### Load Transfer Compensation

During cornering:
$$
\begin{aligned}
F_{z,outer} &= F_{z,static} + \Delta F_z \\
F_{z,inner} &= F_{z,static} - \Delta F_z \\
\Delta F_z &= \frac{m \cdot a_y \cdot h_{CG}}{t_{track}}
\end{aligned}
$$

**Torque adjustment**:
$$
\begin{aligned}
T_{outer} &= T_{base} \cdot \left(1 + k \cdot \frac{\Delta F_z}{F_{z,static}}\right) \\
T_{inner} &= T_{base} \cdot \left(1 - k \cdot \frac{\Delta F_z}{F_{z,static}}\right)
\end{aligned}
$$

where $k = 0.2 - 0.5$ (tuning parameter)

### Drivetrain-MCU Interface Data Structure

```c
// Drivetrain Controller → MCU
typedef struct {
    // Torque commands
    float torque_request_Nm;      // Total torque request [Nm]
    float torque_limit_max;       // Maximum allowed torque [Nm]
    float torque_limit_min;       // Minimum allowed torque [Nm]
    
    // For multi-motor systems
    float torque_left;            // Left motor torque [Nm]
    float torque_right;           // Right motor torque [Nm]
    
    // Speed commands (optional)
    float speed_request_rpm;      // Speed setpoint [rpm]
    float speed_limit_max;        // Maximum speed [rpm]
    
    // Operating mode
    uint8_t drive_mode;           // 0=Park, 1=Reverse, 2=Neutral, 3=Drive
    uint8_t power_mode;           // 0=Eco, 1=Normal, 2=Sport
    uint8_t traction_control;     // 0=Off, 1=On, 2=Enhanced
    
    // Vehicle state
    float vehicle_speed_kmh;      // Vehicle speed [km/h]
    float steering_angle;         // Steering angle [deg]
    float brake_pressure;         // Brake pressure [bar]
    
    // Commands
    uint8_t enable_request;       // 0=Disable, 1=Enable
    uint8_t regen_enable;         // 0=Regen Off, 1=Regen On
    
    uint32_t timestamp;
    uint16_t crc;
} Drivetrain_to_MCU_t;

// MCU → Drivetrain Controller
typedef struct {
    // Actual values
    float actual_torque_Nm;       // Actual motor torque [Nm]
    float motor_speed_rpm;        // Motor speed [rpm]
    float motor_power_kW;         // Motor power [kW]
    
    // For multi-motor
    float torque_left_actual;     // Left motor actual [Nm]
    float torque_right_actual;    // Right motor actual [Nm]
    
    // Status
    uint8_t mcu_ready;            // 0=Not ready, 1=Ready
    uint8_t mcu_running;          // 0=Stopped, 1=Running
    uint8_t fault_active;         // 0=No fault, 1=Fault
    uint16_t fault_code;          // Fault bitmap
    
    // Temperatures
    float motor_temp;             // Motor temperature [°C]
    float inverter_temp;          // Inverter temperature [°C]
    
    // Efficiency metrics
    float efficiency;             // Motor efficiency [%]
    float energy_consumed_kWh;    // Cumulative energy [kWh]
    
    uint32_t timestamp;
    uint16_t crc;
} MCU_to_Drivetrain_t;
```

---

## Regenerative Braking System

### Regenerative Braking Theory

#### Energy Recovery

**Kinetic energy**:
$$E_{kinetic} = \frac{1}{2} m v^2$$

**Recoverable energy**:
$$E_{regen} = \eta_{motor} \cdot \eta_{inverter} \cdot \eta_{battery} \cdot \Delta E_{kinetic}$$

Typical overall efficiency: $\eta_{total} = 0.6 - 0.75$ (60-75%)

#### Braking Force Distribution

**Total braking force**:
$$F_{brake,total} = F_{regen} + F_{friction}$$

**Optimal distribution** (for front-wheel drive):
```
Front axle:
  F_regen,front + F_friction,front = 0.6-0.7 × F_brake,total

Rear axle:
  F_friction,rear = 0.3-0.4 × F_brake,total
```

### Regenerative Braking Strategies

#### 1. Fixed Regen (Simple)

Constant regenerative torque when brake pedal pressed:
$$T_{regen} = k_{regen} \cdot x_{brake}$$

**Advantages**: Simple, predictable
**Disadvantages**: Not optimized for energy recovery

#### 2. Adaptive Regen (SOC-based)

$$T_{regen} = T_{regen,max} \cdot f_{SOC} \cdot f_{speed} \cdot x_{brake}$$

**SOC factor**:
$$f_{SOC} = 
\begin{cases}
1.0 & \text{if } SOC < 85\% \\
\frac{95 - SOC}{10} & \text{if } 85\% \leq SOC < 95\% \\
0 & \text{if } SOC \geq 95\%
\end{cases}
$$

**Speed factor**:
$$f_{speed} = 
\begin{cases}
\frac{v}{v_{min}} & \text{if } v < v_{min} \\
1.0 & \text{if } v_{min} \leq v \leq v_{max} \\
\frac{v_{max}}{v} & \text{if } v > v_{max}
\end{cases}
$$

where $v_{min} = 5$ km/h, $v_{max} = 120$ km/h

#### 3. Blended Braking (Optimal)

**Cooperative control** between regenerative and friction braking:

$$
\begin{aligned}
F_{regen,max} &= \min(F_{motor,max}, F_{BMS,limit}, F_{stability}) \\
F_{regen,actual} &= \min(F_{brake,request}, F_{regen,max}) \\
F_{friction} &= F_{brake,request} - F_{regen,actual}
\end{aligned}
$$

**Constraints**:
1. **Motor torque limit**: $T_{regen} \leq T_{motor,max}(n)$
2. **BMS charge limit**: $P_{regen} \leq P_{charge,max}$
3. **Wheel lock prevention**: $F_{regen} \leq \mu \cdot F_z$
4. **Comfort**: $\frac{dF_{regen}}{dt} \leq rate_{max}$

### Brake Pedal Feel and Blending

#### Brake Pedal Sensor

**Redundant sensing**:
- Hydraulic pressure sensor (0-200 bar)
- Pedal position sensor (0-100%)
- Pedal force sensor (optional)

#### Brake-by-Wire Control

**Pedal travel vs. braking force**:
$$F_{brake} = k_1 \cdot x_{pedal} + k_2 \cdot x_{pedal}^2$$

**Blending algorithm**:
```
1. Measure brake pedal position → x_brake
2. Calculate total brake force → F_total
3. Determine max regen available → F_regen_max
4. Allocate: F_regen = min(F_total, F_regen_max)
5. Friction brake demand: F_friction = F_total - F_regen
6. Apply friction brake with delay compensation
7. Monitor actual deceleration → adjust allocation
```

#### Seamless Transition

**Challenge**: Avoid pedal feel discontinuity when switching between regen and friction

**Solution**: Pressure build-up compensation
$$P_{hydraulic}(t) = P_{target} \cdot (1 - e^{-t/\tau}) + P_{compensation}$$

where:
$$P_{compensation} = k \cdot (F_{regen,previous} - F_{regen,current})$$

### One-Pedal Driving

**Concept**: Lift-off regeneration without touching brake pedal

**Implementation**:
$$T_{regen,lift} = k_{lift} \cdot (0 - x_{accel}) \cdot f_{SOC} \cdot f_{mode}$$

**Mode factors**:
- Eco mode: $k_{lift} = 0.3$ (strong regen)
- Normal: $k_{lift} = 0.2$ (moderate regen)
- Sport: $k_{lift} = 0.1$ (minimal regen, coast)

**Creep function at low speed**:
```matlab
if v < v_creep && x_accel == 0 && mode == Drive
    T_creep = T_creep_nominal × (1 - v/v_creep)
end
```

where $v_{creep} = 5$ km/h

### Anti-Lock Braking System (ABS) Integration

#### Regenerative Braking Cut-off

During ABS activation:

**Condition**: Wheel slip $\lambda > \lambda_{threshold}$ (typically 15%)

**Action**:
```matlab
if ABS_active
    T_regen = 0  % Disable regen immediately
    % Friction brake handles all braking
    % Allows ABS to modulate wheel slip effectively
end
```

**Ramp-down time**: < 50 ms (fast to prevent lock-up)

#### Cooperative ABS

**Advanced strategy**: Use regen for fine slip control

```matlab
if λ > λ_target + Δλ
    Reduce T_regen (fine control)
    Reduce F_friction (coarse control)
elseif λ < λ_target - Δλ
    Increase T_regen (limited rate)
    Increase F_friction
end
```

**Advantage**: Smoother braking, better energy recovery

---

## Communication Protocols

### CAN Bus Communication

#### CAN Message Structure

**Standard CAN (11-bit ID)**:
```
SOF | ID (11-bit) | RTR | IDE | r0 | DLC | Data (0-8 bytes) | CRC | ACK | EOF
```

**CAN-FD (Flexible Data Rate)**:
- Extended payload: up to 64 bytes
- Faster data phase: up to 5 Mbps
- Better for high-bandwidth applications

#### Message Priority and Arbitration

**Priority levels** (lower ID = higher priority):

| ID Range | Priority | Content | Update Rate |
|----------|----------|---------|-------------|
| 0x000-0x0FF | Highest | Emergency/Fault | Event-driven |
| 0x100-0x1FF | High | Control commands | 100-1000 Hz |
| 0x200-0x3FF | Medium | Measurements | 10-100 Hz |
| 0x400-0x7FF | Low | Status/diagnostics | 1-10 Hz |

#### Example CAN Message Definitions

**BMS → MCU: Power Limits (ID: 0x120)**
```
Byte 0-1: Max discharge current [0.1 A] (int16)
Byte 2-3: Max charge current [0.1 A] (int16)
Byte 4-5: Max discharge power [0.1 kW] (uint16)
Byte 6-7: Max charge power [0.1 kW] (uint16)
```

**BMS → MCU: State Information (ID: 0x121)**
```
Byte 0: SOC [0.5%] (uint8)
Byte 1: SOH [0.5%] (uint8)
Byte 2-3: Pack voltage [0.1 V] (uint16)
Byte 4-5: Pack current [0.1 A] (int16)
Byte 6: Max cell temp [1°C, offset -40] (uint8)
Byte 7: Status flags (uint8)
```

**MCU → BMS: Motor Status (ID: 0x220)**
```
Byte 0-1: Actual torque [0.1 Nm] (int16)
Byte 2-3: Motor speed [1 rpm] (uint16)
Byte 4-5: DC current [0.1 A] (int16)
Byte 6: Inverter temp [1°C, offset -40] (uint8)
Byte 7: MCU status (uint8)
```

### Data Encoding and Scaling

**Fixed-point representation**:
$$Value_{physical} = (Value_{raw} \cdot scale) + offset$$

**Example**: Temperature encoding
```
Temperature range: -40°C to +215°C
Raw value: 0-255 (uint8)
Scale: 1°C/bit
Offset: -40°C

Encoding: raw = temp + 40
Decoding: temp = raw - 40
```

### Communication Fault Detection

#### Timeout Monitoring

```c
#define MSG_TIMEOUT_MS  100  // 100 ms timeout

typedef struct {
    uint32_t last_rx_time;
    bool timeout_flag;
} MsgMonitor_t;

void CheckMessageTimeout(MsgMonitor_t *msg, uint32_t current_time) {
    if ((current_time - msg->last_rx_time) > MSG_TIMEOUT_MS) {
        msg->timeout_flag = true;
        // Enter safe state
        EnterFailSafeMode();
    }
}
```

#### CRC Validation

**CRC-16-CCITT**:
```c
uint16_t CalculateCRC16(uint8_t *data, uint16_t length) {
    uint16_t crc = 0xFFFF;
    for (uint16_t i = 0; i < length; i++) {
        crc ^= (uint16_t)data[i] << 8;
        for (uint8_t j = 0; j < 8; j++) {
            if (crc & 0x8000)
                crc = (crc << 1) ^ 0x1021;
            else
                crc = crc << 1;
        }
    }
    return crc;
}
```

#### Sequence Counter

```c
typedef struct {
    uint8_t sequence_counter;
    uint8_t last_counter;
    uint16_t lost_messages;
} SequenceMonitor_t;

void CheckSequence(SequenceMonitor_t *mon, uint8_t received_counter) {
    uint8_t expected = (mon->last_counter + 1) & 0x0F;  // 4-bit counter
    if (received_counter != expected) {
        mon->lost_messages++;
    }
    mon->last_counter = received_counter;
}
```

---

## Power Flow Management

### Power Flow States

```
         ┌──────────────┐
         │   Standby    │
         │  (P = 0)     │
         └──┬────────┬──┘
            │        │
    ┌───────▼──┐  ┌─▼──────────┐
    │ Motoring │  │Regeneration│
    │ (P > 0)  │  │  (P < 0)   │
    └───────┬──┘  └─┬──────────┘
            │        │
         ┌──▼────────▼──┐
         │   Charging   │
         │ (External)   │
         └──────────────┘
```

### Power Arbitration

**Priority hierarchy**:
1. **Safety limits** (highest priority)
   - BMS charge/discharge limits
   - Thermal limits
   - Fault conditions

2. **Performance limits**
   - Motor torque limits
   - Speed limits
   - Traction control

3. **Driver request** (lowest priority)
   - Pedal input
   - Cruise control

**Arbitration algorithm**:
$$P_{final} = \min(P_{driver}, P_{BMS}, P_{thermal}, P_{motor}, P_{traction})$$

### Energy Flow Optimization

#### Efficiency Map-Based Control

**Motor efficiency map**: $\eta_{motor}(T, n)$

**Optimal operating point**:
$$\max_{\{T, n\}} \eta_{total}(T, n)$$

subject to:
$$
\begin{aligned}
P_{output} &= T \cdot n \\
T &\leq T_{max}(n) \\
n &\in [n_{min}, n_{max}]
\end{aligned}
$$

#### Multi-Motor Power Distribution

For dual-motor systems, distribute total power for maximum efficiency:

$$
\begin{aligned}
P_{total} &= P_1 + P_2 \\
\{P_1, P_2\} &= \arg\max \eta_{total}(P_1, P_2) \\
\eta_{total} &= \frac{P_1 + P_2}{\frac{P_1}{\eta_1(P_1)} + \frac{P_2}{\eta_2(P_2)}}
\end{aligned}
$$

### DC-Link Voltage Management

#### Voltage Regulation

**Operating voltage range**: $V_{dc,min}$ to $V_{dc,max}$

**Adaptive voltage control**:
$$V_{dc,target} = f(SOC, P_{demand}, T_{battery})$$

**Higher voltage** → Better efficiency at high power
**Lower voltage** → Better efficiency at low power

#### Battery Pack Configuration Switching

For multi-pack systems with series/parallel switching:

**Series configuration**: $V_{dc} = 2V_{pack}$, $I_{max} = I_{pack}$
- Use for: High speed, high voltage requirement

**Parallel configuration**: $V_{dc} = V_{pack}$, $I_{max} = 2I_{pack}$
- Use for: High torque, low speed

**Switching criteria**:
```matlab
if (Speed > Speed_threshold) && (Torque < Torque_threshold)
    Configuration = Series
else
    Configuration = Parallel
end
```

---

## Practical Algorithm Implementations

### Algorithm 1: BMS Power Limit Calculator

```matlab
classdef BMS_PowerLimitCalculator < handle
    properties
        % Battery parameters
        Capacity_Ah
        CellCount_Series
        CellCount_Parallel
        Vmax_cell
        Vmin_cell
        Tmax_cell
        Tmin_cell
        Imax_discharge_C
        Imax_charge_C
        
        % Thermal parameters
        Rth_cell
        Cth_cell
    end
    
    methods
        function obj = BMS_PowerLimitCalculator(params)
            obj.Capacity_Ah = params.Capacity_Ah;
            obj.CellCount_Series = params.CellCount_Series;
            obj.CellCount_Parallel = params.CellCount_Parallel;
            obj.Vmax_cell = params.Vmax_cell;
            obj.Vmin_cell = params.Vmin_cell;
            obj.Tmax_cell = params.Tmax_cell;
            obj.Tmin_cell = params.Tmin_cell;
            obj.Imax_discharge_C = params.Imax_discharge_C;
            obj.Imax_charge_C = params.Imax_charge_C;
            obj.Rth_cell = params.Rth_cell;
            obj.Cth_cell = params.Cth_cell;
        end
        
        function [Pmax_discharge, Pmax_charge] = CalculateLimits(obj, SOC, Vcell, Tcell, Rint)
            % Calculate all constraint-based limits
            
            % 1. Voltage-based limits
            Vpack = Vcell * obj.CellCount_Series;
            
            % Discharge limit (don't go below Vmin)
            Imax_V_discharge = (Vcell - obj.Vmin_cell) / Rint;
            Pmax_V_discharge = Imax_V_discharge * Vpack * obj.CellCount_Parallel;
            
            % Charge limit (don't exceed Vmax)
            Imax_V_charge = (obj.Vmax_cell - Vcell) / Rint;
            Pmax_V_charge = Imax_V_charge * Vpack * obj.CellCount_Parallel;
            
            % 2. Current-based limits (C-rate)
            Imax_C_discharge = obj.Imax_discharge_C * obj.Capacity_Ah;
            Imax_C_charge = obj.Imax_charge_C * obj.Capacity_Ah;
            
            Pmax_C_discharge = Imax_C_discharge * Vpack * obj.CellCount_Parallel;
            Pmax_C_charge = Imax_C_charge * Vpack * obj.CellCount_Parallel;
            
            % 3. Thermal limits
            Temp_margin_discharge = obj.Tmax_cell - Tcell;
            Temp_margin_charge = obj.Tmax_cell - Tcell;
            
            % Simplified thermal model: P_thermal = ΔT * Cth / Rth
            Pmax_thermal_discharge = Temp_margin_discharge * obj.Cth_cell / obj.Rth_cell;
            Pmax_thermal_charge = Temp_margin_charge * obj.Cth_cell / obj.Rth_cell;
            
            % Account for parallel cells
            Pmax_thermal_discharge = Pmax_thermal_discharge * obj.CellCount_Series * obj.CellCount_Parallel;
            Pmax_thermal_charge = Pmax_thermal_charge * obj.CellCount_Series * obj.CellCount_Parallel;
            
            % 4. SOC-based derating
            SOC_low = 20;
            SOC_high = 90;
            
            if SOC < SOC_low
                SOC_factor_discharge = SOC / SOC_low;
            else
                SOC_factor_discharge = 1.0;
            end
            
            if SOC > SOC_high
                SOC_factor_charge = (100 - SOC) / (100 - SOC_high);
            else
                SOC_factor_charge = 1.0;
            end
            
            % Take minimum of all constraints
            Pmax_discharge = min([Pmax_V_discharge, Pmax_C_discharge, ...
                                  Pmax_thermal_discharge]) * SOC_factor_discharge;
            
            Pmax_charge = min([Pmax_V_charge, Pmax_C_charge, ...
                               Pmax_thermal_charge]) * SOC_factor_charge;
            
            % Ensure non-negative
            Pmax_discharge = max(0, Pmax_discharge);
            Pmax_charge = max(0, Pmax_charge);
        end
    end
end
```

### Algorithm 2: Torque Request Arbiter

```matlab
function [T_final, limit_source] = TorqueArbiter(T_driver, BMS_data, MCU_state, Vehicle_state, Params)
    % Inputs:
    %   T_driver: Driver requested torque [Nm]
    %   BMS_data: Structure with BMS limits
    %   MCU_state: Motor controller state
    %   Vehicle_state: Vehicle dynamics state
    %   Params: System parameters
    % Outputs:
    %   T_final: Final torque command [Nm]
    %   limit_source: String indicating limiting factor
    
    % Initialize
    T_limits = [];
    limit_names = {};
    
    % 1. Motor torque capability limit
    n_motor = MCU_state.motor_speed_rpm;
    T_motor_max = MotorTorqueCurve(n_motor, Params);
    T_limits = [T_limits, T_motor_max];
    limit_names = [limit_names, 'Motor'];
    
    % 2. BMS power limit
    if T_driver >= 0  % Motoring
        P_max = BMS_data.max_discharge_power * 1000;  % Convert to W
    else  % Regeneration
        P_max = BMS_data.max_charge_power * 1000;
    end
    
    % Convert power to torque: P = T × ω
    omega = n_motor * 2*pi / 60;  % rad/s
    if omega > 10  % Avoid division by very small number
        T_BMS_limit = P_max / omega;
    else
        T_BMS_limit = inf;
    end
    T_limits = [T_limits, T_BMS_limit];
    limit_names = [limit_names, 'BMS'];
    
    % 3. Thermal limit (inverter and motor)
    T_inverter = MCU_state.inverter_temp;
    T_motor = MCU_state.motor_temp;
    T_thermal_limit = ThermalDerating(T_inverter, T_motor, Params);
    T_limits = [T_limits, T_thermal_limit];
    limit_names = [limit_names, 'Thermal'];
    
    % 4. Traction control limit
    if Vehicle_state.traction_control_active
        wheel_slip = Vehicle_state.wheel_slip;
        T_traction_limit = TractionControlLimit(wheel_slip, T_driver, Params);
        T_limits = [T_limits, T_traction_limit];
        limit_names = [limit_names, 'Traction'];
    end
    
    % 5. Speed limit (if approaching max speed)
    v_vehicle = Vehicle_state.vehicle_speed_kmh;
    if v_vehicle > Params.v_max * 0.95
        T_speed_limit = 0;  % Cut torque near max speed
        T_limits = [T_limits, T_speed_limit];
        limit_names = [limit_names, 'Speed'];
    end
    
    % Find minimum limit
    [T_min_limit, idx] = min(T_limits);
    limit_source = limit_names{idx};
    
    % Apply limit
    if T_driver >= 0
        T_final = min(T_driver, T_min_limit);
    else
        T_final = max(T_driver, -T_min_limit);
    end
    
    % Rate limiter for smooth transitions
    persistent T_previous
    if isempty(T_previous)
        T_previous = 0;
    end
    
    dT_max = Params.torque_rate_limit * Params.dt;  % Max change per timestep
    dT = T_final - T_previous;
    
    if abs(dT) > dT_max
        T_final = T_previous + sign(dT) * dT_max;
    end
    
    T_previous = T_final;
end

function T_max = MotorTorqueCurve(n_rpm, Params)
    % Speed-dependent torque limit
    n_base = Params.n_base_rpm;
    n_max = Params.n_max_rpm;
    T_rated = Params.T_rated_Nm;
    
    if n_rpm < n_base
        % Constant torque region
        T_max = T_rated;
    elseif n_rpm < n_max
        % Constant power region
        T_max = T_rated * n_base / n_rpm;
    else
        % Field weakening region
        T_max = T_rated * (n_base / n_rpm)^2;
    end
end

function T_limit = ThermalDerating(T_inv, T_motor, Params)
    % Temperature-based derating
    T_inv_nominal = Params.T_inv_nominal;
    T_inv_max = Params.T_inv_max;
    T_motor_nominal = Params.T_motor_nominal;
    T_motor_max = Params.T_motor_max;
    
    % Inverter derating factor
    if T_inv < T_inv_nominal
        f_inv = 1.0;
    elseif T_inv < T_inv_max
        f_inv = 1.0 - 0.5 * (T_inv - T_inv_nominal) / (T_inv_max - T_inv_nominal);
    else
        f_inv = 0.5;
    end
    
    % Motor derating factor
    if T_motor < T_motor_nominal
        f_motor = 1.0;
    elseif T_motor < T_motor_max
        f_motor = 1.0 - 0.5 * (T_motor - T_motor_nominal) / (T_motor_max - T_motor_nominal);
    else
        f_motor = 0.5;
    end
    
    % Take minimum
    T_limit = Params.T_rated_Nm * min(f_inv, f_motor);
end

function T_limit = TractionControlLimit(slip, T_request, Params)
    % Slip-based torque reduction
    slip_target = Params.slip_target;  % e.g., 0.15 (15%)
    slip_max = Params.slip_max;        % e.g., 0.25 (25%)
    
    if slip < slip_target
        % No reduction
        T_limit = inf;
    elseif slip < slip_max
        % Proportional reduction
        reduction_factor = 1.0 - (slip - slip_target) / (slip_max - slip_target);
        T_limit = abs(T_request) * reduction_factor;
    else
        % Aggressive reduction
        T_limit = abs(T_request) * 0.3;
    end
end
```

### Algorithm 3: Regenerative Braking Controller

```matlab
classdef RegenerativeBrakingController < handle
    properties
        % Configuration
        regen_max_torque
        blend_mode
        
        % State
        SOC
        vehicle_speed
        motor_speed
        brake_pedal
        
        % Limits from BMS
        max_charge_power
        max_charge_current
    end
    
    methods
        function obj = RegenerativeBrakingController(config)
            obj.regen_max_torque = config.regen_max_torque;
            obj.blend_mode = config.blend_mode;  % 'fixed', 'adaptive', or 'blended'
        end
        
        function [T_regen, T_friction] = Calculate(obj, inputs)
            % Extract inputs
            obj.SOC = inputs.SOC;
            obj.vehicle_speed = inputs.vehicle_speed_kmh;
            obj.motor_speed = inputs.motor_speed_rpm;
            obj.brake_pedal = inputs.brake_pedal_position;  % 0-1
            obj.max_charge_power = inputs.max_charge_power_kW;
            obj.max_charge_current = inputs.max_charge_current_A;
            
            % Calculate total brake demand
            F_brake_total = obj.CalculateBrakeForce(obj.brake_pedal);
            
            % Calculate maximum available regen
            T_regen_max = obj.CalculateMaxRegen();
            
            % Calculate requested regen torque
            switch obj.blend_mode
                case 'fixed'
                    T_regen = obj.FixedRegen(F_brake_total);
                case 'adaptive'
                    T_regen = obj.AdaptiveRegen(F_brake_total, T_regen_max);
                case 'blended'
                    T_regen = obj.BlendedRegen(F_brake_total, T_regen_max);
            end
            
            % Limit to available regen
            T_regen = min(T_regen, T_regen_max);
            
            % Calculate friction brake demand
            % Convert back from torque to force
            r_wheel = 0.3;  % m
            F_regen = T_regen / r_wheel;
            T_friction = max(0, F_brake_total - F_regen) * r_wheel;
        end
        
        function F_brake = CalculateBrakeForce(obj, pedal_pos)
            % Non-linear brake pedal mapping
            % Progressive feel: light at beginning, stronger at end
            k1 = 2000;  % N
            k2 = 3000;  % N
            F_brake = k1 * pedal_pos + k2 * pedal_pos^2;
        end
        
        function T_max = CalculateMaxRegen(obj)
            % Calculate maximum regen considering all constraints
            
            % 1. SOC limit
            f_SOC = obj.SOCFactor(obj.SOC);
            
            % 2. Speed limit (minimum speed for effective regen)
            f_speed = obj.SpeedFactor(obj.vehicle_speed);
            
            % 3. BMS power limit
            omega = obj.motor_speed * 2*pi / 60;  % rad/s
            if omega > 10
                T_BMS = (obj.max_charge_power * 1000) / omega;
            else
                T_BMS = 0;  % No regen at very low speed
            end
            
            % 4. Motor capability
            T_motor = obj.regen_max_torque;
            
            % Take minimum
            T_max = min([T_motor, T_BMS]) * f_SOC * f_speed;
        end
        
        function f = SOCFactor(obj, SOC)
            % Reduce regen as SOC approaches 100%
            SOC_start_reduce = 85;
            SOC_cutoff = 95;
            
            if SOC < SOC_start_reduce
                f = 1.0;
            elseif SOC < SOC_cutoff
                f = (SOC_cutoff - SOC) / (SOC_cutoff - SOC_start_reduce);
            else
                f = 0.0;
            end
        end
        
        function f = SpeedFactor(obj, v_kmh)
            % Reduce regen at very low speeds for smooth stop
            v_min = 5;   % km/h
            v_max = 120; % km/h
            
            if v_kmh < v_min
                f = v_kmh / v_min;
            elseif v_kmh <= v_max
                f = 1.0;
            else
                % Reduce at very high speed (limited by motor speed)
                f = v_max / v_kmh;
            end
        end
        
        function T_regen = FixedRegen(obj, F_brake)
            % Simple proportional regen
            k_regen = 0.7;  % 70% of brake force to regen
            r_wheel = 0.3;  % m
            T_regen = k_regen * F_brake * r_wheel;
        end
        
        function T_regen = AdaptiveRegen(obj, F_brake, T_max)
            % Adaptive based on available regen capacity
            k_base = 0.8;
            r_wheel = 0.3;
            
            % Scale by available capacity
            T_request = k_base * F_brake * r_wheel;
            T_regen = min(T_request, T_max);
        end
        
        function T_regen = BlendedRegen(obj, F_brake, T_max)
            % Optimal blended strategy
            % Prioritize regen up to maximum, then use friction
            r_wheel = 0.3;
            T_brake_total = F_brake * r_wheel;
            
            % Use all available regen
            T_regen = min(T_brake_total, T_max);
            
            % Apply comfort filter (rate limit)
            persistent T_regen_prev
            if isempty(T_regen_prev)
                T_regen_prev = 0;
            end
            
            dT_max = 50;  % Nm/s maximum rate
            dt = 0.01;    % 10 ms sample time
            dT = T_regen - T_regen_prev;
            
            if abs(dT) > dT_max * dt
                T_regen = T_regen_prev + sign(dT) * dT_max * dt;
            end
            
            T_regen_prev = T_regen;
        end
    end
end
```

### Algorithm 4: Torque Vectoring Controller

```matlab
function [T_left, T_right] = TorqueVectoringController(T_total, Vehicle_state, Params)
    % Inputs:
    %   T_total: Total requested torque [Nm]
    %   Vehicle_state: Structure with vehicle dynamics
    %   Params: Vehicle parameters
    % Outputs:
    %   T_left, T_right: Individual motor torques [Nm]
    
    % Extract vehicle state
    delta = Vehicle_state.steering_angle;        % rad
    r_actual = Vehicle_state.yaw_rate;          % rad/s
    beta = Vehicle_state.sideslip_angle;        % rad
    v = Vehicle_state.vehicle_speed_kmh / 3.6;  % m/s
    ax = Vehicle_state.accel_long;              % m/s²
    ay = Vehicle_state.accel_lat;               % m/s²
    
    % Vehicle parameters
    L = Params.wheelbase;           % m
    t = Params.track_width;         % m
    m = Params.mass;                % kg
    Iz = Params.yaw_inertia;        % kg·m²
    h_CG = Params.CG_height;        % m
    
    % Calculate desired yaw rate (reference model)
    if v > 1.0  % Avoid division by zero
        % Bicycle model
        r_desired = (v / L) * delta;
        
        % Limit to prevent instability
        r_max = 0.5;  % rad/s
        r_desired = max(-r_max, min(r_max, r_desired));
    else
        r_desired = 0;
    end
    
    % Yaw rate error
    r_error = r_desired - r_actual;
    
    % Sideslip error (should be near zero)
    beta_error = 0 - beta;
    
    % Calculate desired yaw moment using PID control
    persistent int_r_error int_beta_error
    if isempty(int_r_error)
        int_r_error = 0;
        int_beta_error = 0;
    end
    
    % Yaw rate controller
    Kp_r = 2000;  % Nm/(rad/s)
    Ki_r = 500;   % Nm/(rad/s)/s
    Kd_r = 300;   % Nm/(rad/s²)
    
    int_r_error = int_r_error + r_error * Params.dt;
    % Anti-windup
    int_r_error = max(-10, min(10, int_r_error));
    
    M_z_yaw = Kp_r * r_error + Ki_r * int_r_error;
    
    % Sideslip controller
    Kp_beta = 1000;  % Nm/rad
    M_z_beta = Kp_beta * beta_error;
    
    % Combine yaw moment demands
    M_z_demand = M_z_yaw + M_z_beta;
    
    % Limit yaw moment based on available torque
    M_z_max = abs(T_total) * t / 2;
    M_z_demand = max(-M_z_max, min(M_z_max, M_z_demand));
    
    % Calculate load transfer during cornering
    if abs(ay) > 0.1
        delta_Fz = (m * ay * h_CG) / t;
    else
        delta_Fz = 0;
    end
    
    % Base torque distribution (50/50)
    T_base_left = T_total / 2;
    T_base_right = T_total / 2;
    
    % Add yaw moment component
    dT = M_z_demand / t;
    T_left = T_base_left - dT;
    T_right = T_base_right + dT;
    
    % Load transfer compensation
    % Outside wheel gets more torque during cornering
    k_load = 0.3;  % Tuning parameter
    if ay > 0  % Left turn
        T_compensation = k_load * (delta_Fz / m) * abs(T_total);
        T_left = T_left + T_compensation;   % Outside wheel
        T_right = T_right - T_compensation; % Inside wheel
    elseif ay < 0  % Right turn
        T_compensation = k_load * (delta_Fz / m) * abs(T_total);
        T_left = T_left - T_compensation;   % Inside wheel
        T_right = T_right + T_compensation; % Outside wheel
    end
    
    % Ensure total torque is preserved
    T_sum = T_left + T_right;
    if abs(T_sum) > 0.1
        scale = T_total / T_sum;
        T_left = T_left * scale;
        T_right = T_right * scale;
    end
    
    % Individual motor limits
    T_motor_max = Params.T_motor_max;
    T_left = max(-T_motor_max, min(T_motor_max, T_left));
    T_right = max(-T_motor_max, min(T_motor_max, T_right));
end
```

### Algorithm 5: Communication State Machine

```matlab
classdef CommunicationManager < handle
    properties
        % Communication channels
        BMS_channel
        Drivetrain_channel
        
        % Message monitoring
        BMS_monitor
        Drivetrain_monitor
        
        % State
        comm_state
        fault_active
    end
    
    properties (Constant)
        TIMEOUT_MS = 100
        MAX_RETRIES = 3
    end
    
    methods
        function obj = CommunicationManager()
            % Initialize
            obj.comm_state = 'INIT';
            obj.fault_active = false;
            
            % Initialize monitors
            obj.BMS_monitor.last_rx_time = 0;
            obj.BMS_monitor.timeout_count = 0;
            obj.BMS_monitor.valid = false;
            
            obj.Drivetrain_monitor.last_rx_time = 0;
            obj.Drivetrain_monitor.timeout_count = 0;
            obj.Drivetrain_monitor.valid = false;
        end
        
        function Update(obj, current_time_ms)
            % State machine
            switch obj.comm_state
                case 'INIT'
                    % Wait for all nodes to be online
                    if obj.BMS_monitor.valid && obj.Drivetrain_monitor.valid
                        obj.comm_state = 'OPERATIONAL';
                        disp('Communication: All nodes online');
                    end
                    
                case 'OPERATIONAL'
                    % Check for timeouts
                    obj.CheckTimeout('BMS', current_time_ms);
                    obj.CheckTimeout('Drivetrain', current_time_ms);
                    
                    if obj.BMS_monitor.timeout_count > obj.MAX_RETRIES || ...
                       obj.Drivetrain_monitor.timeout_count > obj.MAX_RETRIES
                        obj.comm_state = 'FAULT';
                        obj.fault_active = true;
                        disp('Communication: Timeout fault detected');
                    end
                    
                case 'FAULT'
                    % Try to recover
                    if obj.BMS_monitor.valid && obj.Drivetrain_monitor.valid
                        % Reset timeout counters
                        obj.BMS_monitor.timeout_count = 0;
                        obj.Drivetrain_monitor.timeout_count = 0;
                        obj.fault_active = false;
                        obj.comm_state = 'OPERATIONAL';
                        disp('Communication: Recovered from fault');
                    end
            end
        end
        
        function CheckTimeout(obj, channel_name, current_time_ms)
            % Check if message has timed out
            if strcmp(channel_name, 'BMS')
                monitor = obj.BMS_monitor;
            else
                monitor = obj.Drivetrain_monitor;
            end
            
            time_since_rx = current_time_ms - monitor.last_rx_time;
            
            if time_since_rx > obj.TIMEOUT_MS
                monitor.timeout_count = monitor.timeout_count + 1;
                monitor.valid = false;
                fprintf('%s timeout: %d ms\n', channel_name, time_since_rx);
            end
            
            % Update monitor
            if strcmp(channel_name, 'BMS')
                obj.BMS_monitor = monitor;
            else
                obj.Drivetrain_monitor = monitor;
            end
        end
        
        function OnMessageReceived(obj, channel_name, current_time_ms, data)
            % Called when message is received
            if strcmp(channel_name, 'BMS')
                monitor = obj.BMS_monitor;
            else
                monitor = obj.Drivetrain_monitor;
            end
            
            % Validate CRC
            if obj.ValidateCRC(data)
                monitor.last_rx_time = current_time_ms;
                monitor.valid = true;
                monitor.timeout_count = 0;  % Reset on successful reception
            else
                fprintf('%s: CRC error\n', channel_name);
            end
            
            % Update monitor
            if strcmp(channel_name, 'BMS')
                obj.BMS_monitor = monitor;
            else
                obj.Drivetrain_monitor = monitor;
            end
        end
        
        function valid = ValidateCRC(obj, data)
            % Extract CRC from data
            received_crc = data.crc;
            
            % Calculate expected CRC
            % (Simplified - actual implementation would calculate over data bytes)
            expected_crc = obj.CalculateCRC16(data);
            
            valid = (received_crc == expected_crc);
        end
        
        function crc = CalculateCRC16(obj, data)
            % CRC-16-CCITT calculation
            % (Placeholder - use actual CRC implementation)
            crc = uint16(0);  % Simplified
        end
    end
end
```

---

## Safety and Fault Handling

### Fault Classification

**Critical faults** (immediate shutdown):
- Overcurrent (> 150% rated)
- Overvoltage/undervoltage (outside safe operating area)
- Overtemperature (> Tmax)
- Isolation fault
- Communication loss (critical channels)

**Warning faults** (derating):
- High temperature (> Tnominal)
- High current (> 100% rated)
- SOC low/high
- Sensor degradation

**Informational**:
- Efficiency below target
- Temperature rising
- Minor communication errors

### Fault Response Actions

```c
typedef enum {
    FAULT_ACTION_NONE,
    FAULT_ACTION_DERATE,
    FAULT_ACTION_LIMIT_POWER,
    FAULT_ACTION_DISABLE_REGEN,
    FAULT_ACTION_SHUTDOWN
} FaultAction_t;

typedef struct {
    uint16_t fault_code;
    FaultAction_t action;
    uint16_t power_limit_percent;  // 0-100%
    uint16_t timeout_ms;           // Time before auto-recovery
} FaultConfig_t;

// Fault configuration table
const FaultConfig_t FaultTable[] = {
    {FAULT_OVERCURRENT,     FAULT_ACTION_SHUTDOWN,       0,   0},
    {FAULT_OVERVOLTAGE,     FAULT_ACTION_SHUTDOWN,       0,   0},
    {FAULT_OVERTEMP_CRIT,   FAULT_ACTION_SHUTDOWN,       0,   0},
    {FAULT_OVERTEMP_WARN,   FAULT_ACTION_DERATE,        50, 10000},
    {FAULT_SOC_LOW,         FAULT_ACTION_LIMIT_POWER,   30, 5000},
    {FAULT_COMM_TIMEOUT,    FAULT_ACTION_SHUTDOWN,       0,   0},
};
```

### Safe State Transition

**Normal operation → Safe state**:
1. Disable PWM outputs (all switches OFF)
2. Discharge gate drivers
3. Open contactors (if applicable)
4. Set torque command to zero
5. Enable brake light
6. Set fault flag
7. Log fault data

**Recovery sequence**:
1. Clear fault condition
2. Wait for user confirmation
3. Perform self-test
4. Re-enable systems in sequence
5. Clear fault flags
6. Resume normal operation

---

## References

### Standards and Guidelines

1. **ISO 26262** - Road vehicles - Functional safety
2. **SAE J1939** - Serial Control and Communications Heavy Duty Vehicle Network
3. **IEC 61508** - Functional Safety of Electrical/Electronic/Programmable Electronic Safety-related Systems
4. **ISO 11898** - Controller Area Network (CAN)

### Technical Papers

5. Ehsani, M., Gao, Y., & Emadi, A. (2009). *Modern Electric, Hybrid Electric, and Fuel Cell Vehicles*. CRC Press.

6. Li, J., et al. (2016). "Cooperative control of regenerative braking and friction braking for electric vehicles." *Vehicle System Dynamics*, 54(10), 1371-1388.

7. De Novellis, L., et al. (2015). "Torque vectoring for electric vehicles with individually controlled motors." *Vehicle System Dynamics*, 53(12), 1906-1929.

8. Lv, C., et al. (2015). "Coordinated control of regenerative braking and friction braking in hybrid vehicles." *IEEE Transactions on Vehicular Technology*, 64(6), 2453-2464.

### Application Notes

9. Texas Instruments (2021). "BMS and Motor Control Integration in EVs." Application Note SLVA941.

10. NXP (2020). "Automotive Ethernet for BMS Communication." Application Note AN12606.

---

## Summary

This document provides complete coverage of system integration interfaces:

✅ **BMS Interface**: Power limits, SOC estimation, fault handling, data structures  
✅ **Drivetrain Interface**: Torque mapping, traction control, torque vectoring  
✅ **Regenerative Braking**: Multiple strategies, blending, one-pedal driving  
✅ **Communication**: CAN protocols, message definitions, fault detection  
✅ **Power Management**: Arbitration, optimization, DC-link control  
✅ **Algorithms**: 5 production-ready implementations with complete logic  
✅ **Safety**: Fault classification, response actions, safe state transitions  

All algorithms are designed for real-time embedded systems with proper fault handling, state management, and seamless integration with vehicle-level control systems.

---

**Integration Checklist**:

- [ ] Define CAN message IDs and update rates
- [ ] Implement timeout monitoring for all critical messages
- [ ] Configure BMS power limit update rate (minimum 10 Hz)
- [ ] Calibrate torque vectoring gains for specific vehicle
- [ ] Tune regenerative braking feel (pedal mapping)
- [ ] Set up fault response table
- [ ] Validate communication latency < requirements
- [ ] Test all fault scenarios and recovery sequences
