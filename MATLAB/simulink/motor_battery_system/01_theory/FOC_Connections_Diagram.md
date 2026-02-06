# FOC System - Complete Connection Diagram for Simscape Implementation

## Overview
This diagram shows ALL connections for a Field-Oriented Control system that works with different motor types (SPMSM, IPMSM). Use this as a blueprint for Simscape.

---

## 🔷 MAIN SYSTEM ARCHITECTURE

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                         FOC CONTROL SYSTEM                                   │
│                                                                              │
│  ┌──────────────┐         ┌──────────────┐         ┌──────────────┐        │
│  │   COMMAND    │────────>│   CONTROL    │────────>│   INVERTER   │        │
│  │   INPUTS     │         │   LOOPS      │         │   & PWM      │        │
│  └──────────────┘         └──────────────┘         └──────┬───────┘        │
│                                  ▲                         │                │
│                                  │                         │                │
│                                  │                         ▼                │
│                           ┌──────┴───────┐         ┌──────────────┐        │
│                           │  FEEDBACK    │         │    MOTOR     │        │
│                           │  TRANSFORMS  │<────────│   (PMSM)     │        │
│                           └──────────────┘         └──────────────┘        │
└─────────────────────────────────────────────────────────────────────────────┘
```

---

## 📊 DETAILED BLOCK-LEVEL CONNECTIONS

### 1️⃣ INPUT LAYER - COMMAND SIGNALS

```
┌─────────────────────────────────────────────────────────────────┐
│                     INPUT SIGNALS                                │
└─────────────────────────────────────────────────────────────────┘

INPUT #1: Speed_Ref [rpm or rad/s]
    │
    └──────> [Speed PI Controller]

INPUT #2: Torque_Ref [N·m] (optional - can bypass speed loop)
    │
    └──────> [Torque-to-iq Converter]

INPUT #3: id_Ref [A] (usually 0 for SPMSM, varies for IPMSM)
    │
    └──────> [d-axis PI Controller]
```

---

### 2️⃣ SPEED CONTROL LOOP (Outer Loop)

```
┌────────────────────────────────────────────────────────────────────┐
│                      SPEED CONTROL LOOP                             │
└────────────────────────────────────────────────────────────────────┘

Speed_Ref ────>(+)───> [PI Controller] ───> Torque_Ref
                │         │                      │
                │         │ Parameters:          │
                │         │ • Kp_speed           │
                │         │ • Ki_speed           │
                │         │ • Anti-windup        │
                (-)       │                      │
                │         └──────────────────────┘
                │
           Speed_Measured
                ▲
                │
           [Speed Sensor or Estimator]
                ▲
                │
        From: Rotor Position (θ derivative)

CONNECTIONS:
• IN:  Speed_Ref (external)
• IN:  Speed_Measured (from motor feedback)
• OUT: Torque_Ref → goes to Torque-to-iq block
```

---

### 3️⃣ TORQUE TO iq CONVERSION

```
┌────────────────────────────────────────────────────────────────────┐
│                   TORQUE-TO-iq CONVERTER                            │
└────────────────────────────────────────────────────────────────────┘

For SPMSM:
                     Torque_Ref
    iq_ref = ──────────────────────────
             (3/2) × p × λm

For IPMSM (with field weakening):
    ┌─────────────────────────────────────┐
    │  [MTPA/FW Strategy Block]           │
    │                                     │
    │  IN:  Torque_Ref                   │
    │  IN:  Speed_Measured                │
    │  IN:  Motor_Type (SPMSM/IPMSM)     │
    │  IN:  Parameters (Ld, Lq, λm, p)   │
    │                                     │
    │  OUT: iq_ref                        │
    │  OUT: id_ref (adjusted)             │
    └─────────────────────────────────────┘

CONNECTIONS:
• IN:  Torque_Ref (from speed PI or external)
• IN:  Motor_Type selector
• IN:  Motor parameters (p, λm, Ld, Lq)
• IN:  Speed_Measured (for field weakening decision)
• OUT: iq_ref → to q-axis PI controller
• OUT: id_ref → to d-axis PI controller
```

---

### 4️⃣ CURRENT MEASUREMENT & CLARKE TRANSFORM

```
┌────────────────────────────────────────────────────────────────────┐
│              CURRENT SENSING & CLARKE TRANSFORM                     │
└────────────────────────────────────────────────────────────────────┘

         MOTOR 3-PHASE CURRENTS
                │
    ┌───────────┼───────────┐
    │           │           │
   ia          ib          ic
    │           │           │
    └───────────┴───────────┘
                │
         [Current Sensors]
                │
         (optional: Low-pass filter)
                │
    ┌───────────┴───────────┐
    │  CLARKE TRANSFORM      │
    │                        │
    │  iα = ia               │
    │  iβ = (ia + 2×ib)/√3   │
    │                        │
    │  (or use ic if needed) │
    └────────────────────────┘
                │
         ┌──────┴──────┐
         │             │
        iα            iβ
         │             │
         └─────────────┘
                │
         To: PARK TRANSFORM

CONNECTIONS:
• IN:  ia (from phase A current sensor)
• IN:  ib (from phase B current sensor)
• IN:  ic (optional - can calculate from ia+ib)
• OUT: iα (alpha current)
• OUT: iβ (beta current)
```

---

### 5️⃣ ROTOR POSITION SENSING

```
┌────────────────────────────────────────────────────────────────────┐
│                  ROTOR POSITION SENSING                             │
└────────────────────────────────────────────────────────────────────┘

Option A: ENCODER/RESOLVER
    ┌──────────────────┐
    │  Motor Shaft     │
    │  Position Sensor │
    │  (Encoder)       │
    └────────┬─────────┘
             │
        θ_mechanical
             │
    ┌────────┴─────────┐
    │  θ_electrical =  │
    │  p × θ_mech      │  (p = pole pairs)
    └────────┬─────────┘
             │
        θ_electrical
             │
    ┌────────┴─────────┐     ┌──────────────┐
    │   cos(θ)         │     │  Derivative  │
    │   sin(θ)         │     │  dθ/dt       │
    └──────────────────┘     └──────┬───────┘
             │                       │
             │                  Speed_Measured
             │                       │
             └───────────────────────┴──────> To controllers

Option B: SENSORLESS (Observer)
    ┌──────────────────────────────┐
    │  BACK-EMF Observer or        │
    │  PLL/Sliding Mode Observer   │
    │                              │
    │  IN:  iα, iβ                 │
    │  IN:  Vα, Vβ                 │
    │  IN:  Motor parameters       │
    │                              │
    │  OUT: θ_estimated            │
    │  OUT: Speed_estimated        │
    └──────────────────────────────┘

CONNECTIONS:
• IN:  Motor position (mechanical angle)
• IN:  Pole pairs (p)
• OUT: θ (electrical angle) → to Park/Inverse Park
• OUT: cos(θ) → to Park/Inverse Park
• OUT: sin(θ) → to Park/Inverse Park
• OUT: Speed_Measured → to Speed PI
```

---

### 6️⃣ PARK TRANSFORM (αβ → dq)

```
┌────────────────────────────────────────────────────────────────────┐
│                    PARK TRANSFORM (αβ → dq)                         │
└────────────────────────────────────────────────────────────────────┘

    iα ────┐
           ├────> [PARK TRANSFORM] ────┐
    iβ ────┘              ▲             ├───> id_measured
                          │             │
    cos(θ) ──────────────┤             └───> iq_measured
    sin(θ) ──────────────┘

    EQUATIONS:
    ┌────────────────────────────────────┐
    │ id =  iα × cos(θ) + iβ × sin(θ)   │
    │ iq = -iα × sin(θ) + iβ × cos(θ)   │
    └────────────────────────────────────┘

CONNECTIONS:
• IN:  iα (from Clarke)
• IN:  iβ (from Clarke)
• IN:  cos(θ) (from position sensor)
• IN:  sin(θ) (from position sensor)
• OUT: id_measured → to d-axis PI controller
• OUT: iq_measured → to q-axis PI controller
```

---

### 7️⃣ dq CURRENT CONTROLLERS (Inner Loop - FAST)

```
┌────────────────────────────────────────────────────────────────────┐
│                  d-AXIS PI CONTROLLER                               │
└────────────────────────────────────────────────────────────────────┘

id_ref ────>(+)───> [PI Controller] ───> Vd_ref
             │         │                    │
             │         │ Parameters:        │
             │         │ • Kp_d = ωBW × Ld  │
             │         │ • Ki_d = ωBW × Rs  │
             │         │ • Anti-windup      │
             │         │ • Output limit     │
             (-)       │                    │
             │         └────────────────────┘
             │
        id_measured
             ▲
             │
        From: PARK TRANSFORM

┌────────────────────────────────────────────────────────────────────┐
│                  q-AXIS PI CONTROLLER                               │
└────────────────────────────────────────────────────────────────────┘

iq_ref ────>(+)───> [PI Controller] ───> Vq_ref
             │         │                    │
             │         │ Parameters:        │
             │         │ • Kp_q = ωBW × Lq  │
             │         │ • Ki_q = ωBW × Rs  │
             │         │ • Anti-windup      │
             │         │ • Output limit     │
             (-)       │                    │
             │         └────────────────────┘
             │
        iq_measured
             ▲
             │
        From: PARK TRANSFORM

DECOUPLING (Optional but recommended):
    ┌────────────────────────────────────────┐
    │  Vd_comp = -ωe × Lq × iq               │
    │  Vq_comp =  ωe × Ld × id + ωe × λm     │
    │                                        │
    │  Vd_final = Vd_ref + Vd_comp           │
    │  Vq_final = Vq_ref + Vq_comp           │
    └────────────────────────────────────────┘
    where ωe = electrical speed = dθ/dt

CONNECTIONS:
• IN:  id_ref (from torque converter or constant)
• IN:  id_measured (from Park transform)
• IN:  iq_ref (from torque converter)
• IN:  iq_measured (from Park transform)
• IN:  Motor parameters (Ld, Lq, Rs)
• IN:  ωe (electrical speed for decoupling)
• OUT: Vd_ref → to Inverse Park
• OUT: Vq_ref → to Inverse Park
```

---

### 8️⃣ INVERSE PARK TRANSFORM (dq → αβ)

```
┌────────────────────────────────────────────────────────────────────┐
│               INVERSE PARK TRANSFORM (dq → αβ)                      │
└────────────────────────────────────────────────────────────────────┘

    Vd_ref ────┐
               ├────> [INV PARK] ────┐
    Vq_ref ────┘           ▲         ├───> Vα
                           │         │
    cos(θ) ────────────────┤         └───> Vβ
    sin(θ) ────────────────┘

    EQUATIONS:
    ┌─────────────────────────────────────┐
    │ Vα = Vd × cos(θ) - Vq × sin(θ)     │
    │ Vβ = Vd × sin(θ) + Vq × cos(θ)     │
    └─────────────────────────────────────┘

CONNECTIONS:
• IN:  Vd_ref (from d-axis PI)
• IN:  Vq_ref (from q-axis PI)
• IN:  cos(θ) (from position sensor)
• IN:  sin(θ) (from position sensor)
• OUT: Vα → to Inverse Clarke
• OUT: Vβ → to Inverse Clarke
```

---

### 9️⃣ INVERSE CLARKE TRANSFORM (αβ → abc)

```
┌────────────────────────────────────────────────────────────────────┐
│            INVERSE CLARKE TRANSFORM (αβ → abc)                      │
└────────────────────────────────────────────────────────────────────┘

         Vα ────┐
                ├────> [INV CLARKE] ────┬───> Va
         Vβ ────┘                        ├───> Vb
                                         └───> Vc

    EQUATIONS:
    ┌─────────────────────────────────────────┐
    │ Va = Vα                                 │
    │ Vb = -0.5 × Vα + (√3/2) × Vβ           │
    │ Vc = -0.5 × Vα - (√3/2) × Vβ           │
    └─────────────────────────────────────────┘

CONNECTIONS:
• IN:  Vα (from Inverse Park)
• IN:  Vβ (from Inverse Park)
• OUT: Va → to SVM/PWM
• OUT: Vb → to SVM/PWM
• OUT: Vc → to SVM/PWM
```

---

### 🔟 SPACE VECTOR MODULATION (SVM) / PWM

```
┌────────────────────────────────────────────────────────────────────┐
│              SPACE VECTOR MODULATION (SVM)                          │
└────────────────────────────────────────────────────────────────────┘

    Va ────┐
    Vb ────┼────> [SVM Algorithm] ────┬───> Duty_A [0-1]
    Vc ────┘           │               ├───> Duty_B [0-1]
                       │               └───> Duty_C [0-1]
                  Vdc_bus (IN)              │
                                            │
                                            ▼
                              ┌─────────────────────────┐
                              │   PWM GENERATOR         │
                              │                         │
                              │  IN: Duty_A, B, C      │
                              │  IN: fsw (e.g. 10kHz)  │
                              │                         │
                              │  OUT: Gate signals      │
                              │       • Sa_high         │
                              │       • Sa_low          │
                              │       • Sb_high         │
                              │       • Sb_low          │
                              │       • Sc_high         │
                              │       • Sc_low          │
                              └─────────────────────────┘
                                            │
                                            ▼
                                     INVERTER GATES

SVM SECTORS (for reference):
    ┌────────────────────────────────────┐
    │  Sector I:   0° ≤ θ < 60°         │
    │  Sector II:  60° ≤ θ < 120°       │
    │  Sector III: 120° ≤ θ < 180°      │
    │  Sector IV:  180° ≤ θ < 240°      │
    │  Sector V:   240° ≤ θ < 300°      │
    │  Sector VI:  300° ≤ θ < 360°      │
    └────────────────────────────────────┘

DEAD TIME COMPENSATION (optional):
    Add compensation for IGBT/MOSFET turn-on/off delays

CONNECTIONS:
• IN:  Va, Vb, Vc (from Inverse Clarke)
• IN:  Vdc_bus (DC bus voltage measurement)
• IN:  fsw (switching frequency parameter)
• OUT: PWM_A_high, PWM_A_low (to inverter phase A)
• OUT: PWM_B_high, PWM_B_low (to inverter phase B)
• OUT: PWM_C_high, PWM_C_low (to inverter phase C)
```

---

### 1️⃣1️⃣ THREE-PHASE INVERTER

```
┌────────────────────────────────────────────────────────────────────┐
│                  THREE-PHASE INVERTER                               │
└────────────────────────────────────────────────────────────────────┘

                    Vdc_bus (+)
                         │
         ┌───────────────┼───────────────┐
         │               │               │
       [Sa_H]          [Sb_H]          [Sc_H]    ← High-side switches
         │               │               │
         ├───────────────┼───────────────┼─────> To Motor
         │      A        │      B        │    C
       [Sa_L]          [Sb_L]          [Sc_L]    ← Low-side switches
         │               │               │
         └───────────────┴───────────────┘
                         │
                    GND/DC- (-)

Each leg (A, B, C):
    ┌──────────────────────────────────────┐
    │  HIGH-SIDE SWITCH (Sa_H)             │
    │  • IGBT or MOSFET                    │
    │  • Gate driver                       │
    │  • Shoot-through protection          │
    │                                      │
    │  LOW-SIDE SWITCH (Sa_L)              │
    │  • IGBT or MOSFET                    │
    │  • Gate driver                       │
    │  • Complementary to high-side        │
    │  • Dead time: 1-2 μs                 │
    └──────────────────────────────────────┘

CONNECTIONS:
• IN:  Vdc_bus (DC power supply)
• IN:  PWM_A_high, PWM_A_low (from PWM block)
• IN:  PWM_B_high, PWM_B_low (from PWM block)
• IN:  PWM_C_high, PWM_C_low (from PWM block)
• OUT: Phase_A_voltage → to motor
• OUT: Phase_B_voltage → to motor
• OUT: Phase_C_voltage → to motor
```

---

### 1️⃣2️⃣ MOTOR (PMSM) - SIMSCAPE MODEL

```
┌────────────────────────────────────────────────────────────────────┐
│              PMSM MOTOR (Simscape Component)                        │
└────────────────────────────────────────────────────────────────────┘

        ELECTRICAL CONNECTIONS:
        ┌────────────────────┐
        │      PMSM          │
        │                    │
    ───>│ Phase A            │
    ───>│ Phase B            │
    ───>│ Phase C            │
        │                    │
        │ Neutral (optional) │
        └─────────┬──────────┘
                  │
        MECHANICAL OUTPUT:
                  │
                  ▼
        ┌─────────────────────┐
        │  Rotational Shaft   │
        │  • Torque output    │
        │  • Angular position │
        │  • Angular velocity │
        └─────────────────────┘
                  │
                  ▼
        To: Load (inertia, friction)

MOTOR PARAMETERS (User-selectable):
    ┌─────────────────────────────────────────┐
    │  Motor Type:                            │
    │  ○ SPMSM (Ld = Lq)                     │
    │  ○ IPMSM (Ld ≠ Lq)                     │
    │                                         │
    │  Electrical:                            │
    │  • Rs (stator resistance)               │
    │  • Ld (d-axis inductance)               │
    │  • Lq (q-axis inductance)               │
    │  • λm (flux linkage)                    │
    │  • p (pole pairs)                       │
    │                                         │
    │  Mechanical:                            │
    │  • J (rotor inertia)                    │
    │  • B (viscous damping)                  │
    │  • T_friction (Coulomb friction)        │
    └─────────────────────────────────────────┘

SENSOR TAPS (Feedback):
    • Position sensor → θ_rotor
    • Phase currents → ia, ib, ic
    • (optional) Back-EMF → ea, eb, ec

CONNECTIONS:
• IN:  Phase A voltage (from inverter)
• IN:  Phase B voltage (from inverter)
• IN:  Phase C voltage (from inverter)
• IN:  Load torque (mechanical connection)
• OUT: Rotor position θ → to position sensing
• OUT: Phase currents ia, ib, ic → to Clarke transform
• OUT: Mechanical torque → to load
• OUT: Speed → to speed sensor
```

---

### 1️⃣3️⃣ MECHANICAL LOAD

```
┌────────────────────────────────────────────────────────────────────┐
│                    MECHANICAL LOAD                                  │
└────────────────────────────────────────────────────────────────────┘

    Motor Shaft ────> [Inertia] ────> [Friction] ────> [External Load]
                          │               │                  │
                       J_load          B_visc           T_load_ext
                                                             │
                                                 (Can be constant,
                                                  step, ramp, etc.)

LOAD MODELS:
    ┌────────────────────────────────────────┐
    │  Simple:                               │
    │  • Constant torque                     │
    │  • Step torque                         │
    │                                        │
    │  Advanced:                             │
    │  • Speed-dependent (T = k×ω²)          │
    │  • Pump/fan load                       │
    │  • Vehicle dynamics                    │
    └────────────────────────────────────────┘

CONNECTIONS:
• IN:  Motor torque (from PMSM)
• IN:  External load torque (user-defined)
• OUT: Net acceleration → affects rotor speed
• OUT: Speed → back to motor
```

---

## 🔗 COMPLETE SIGNAL FLOW SUMMARY

```
┌──────────────────────────────────────────────────────────────────────────┐
│                    COMPLETE FOC SIGNAL FLOW                               │
└──────────────────────────────────────────────────────────────────────────┘

1. COMMAND PATH (Top-down):
   Speed_Ref → [Speed PI] → Torque_Ref → [Torque-to-iq] → iq_ref
                                                          → id_ref

2. CONTROL PATH (Reference to voltage):
   iq_ref ──┐
   id_ref ──┼─> [dq PI Controllers] → Vd_ref, Vq_ref
   iq_meas ─┤
   id_meas ─┘

3. COORDINATE TRANSFORM (dq → abc):
   Vd_ref, Vq_ref + θ → [Inv Park] → Vα, Vβ → [Inv Clarke] → Va, Vb, Vc

4. POWER CONVERSION:
   Va, Vb, Vc → [SVM] → Duty_A,B,C → [PWM] → Gate_signals → [Inverter] → Motor

5. FEEDBACK PATH (Bottom-up):
   Motor → ia, ib, ic → [Clarke] → iα, iβ + θ → [Park] → id, iq
   Motor → θ_rotor → [×p] → θ_elec → sin/cos → to transforms
   Motor → θ_rotor → [d/dt] → Speed → to speed PI

6. POSITION SENSOR PATH:
   Motor_shaft → [Encoder] → θ_mech → [×p] → θ_elec → [trig] → sin(θ), cos(θ)
                                           → [d/dt] → ω_mech → Speed_measured
```

---

## 🎯 CRITICAL CONNECTIONS CHECKLIST

When building in Simscape, ensure these connections:

### ✅ Electrical Connections
- [ ] DC bus voltage → Inverter
- [ ] Inverter phase outputs (A, B, C) → Motor phases
- [ ] Motor current sensors → Clarke transform
- [ ] Motor neutral (if used)

### ✅ Mechanical Connections
- [ ] Motor shaft → Position sensor
- [ ] Motor shaft → Load inertia
- [ ] Load torque → Motor shaft (opposing)

### ✅ Control Signal Paths
- [ ] Speed reference → Speed PI
- [ ] Speed PI output → Torque converter
- [ ] Torque converter → iq_ref, id_ref
- [ ] iq_ref, id_ref → Current PI controllers
- [ ] Current PI outputs → Inverse Park
- [ ] Inverse Park → Inverse Clarke
- [ ] Inverse Clarke → SVM
- [ ] SVM → PWM generator
- [ ] PWM → Inverter gates

### ✅ Feedback Signals
- [ ] Phase currents → Clarke → Park
- [ ] Park outputs (id, iq) → Current PI inputs
- [ ] Rotor angle → Park transform
- [ ] Rotor angle → Inverse Park transform
- [ ] Rotor speed → Speed PI feedback
- [ ] DC bus voltage → SVM (for normalization)

### ✅ Parameter Propagation
- [ ] Motor parameters (Rs, Ld, Lq, λm, p) → Multiple blocks
- [ ] PI gains → Controller blocks
- [ ] Switching frequency → PWM
- [ ] Sample time consistency across blocks

---

## 📐 BLOCK DIAGRAM WITH PORT LABELS

```
┌─────────────────────────────────────────────────────────────────────┐
│                   ANNOTATED BLOCK DIAGRAM                            │
└─────────────────────────────────────────────────────────────────────┘

                           ┌─────────────┐
         Speed_Ref ───────>│  Speed_PI   │
                           │             │───> Torque_Ref
         Speed_fb ─────(-)─>│ Kp, Ki      │
            ▲               └─────────────┘
            │                      │
            │               ┌──────▼──────────┐
            │               │ Torque_to_iq    │
            │               │ (MTPA/FW logic) │
            │               └──┬───────────┬──┘
            │                  │           │
            │               iq_ref      id_ref
            │                  │           │
            │         ┌────────▼───┐   ┌──▼────────┐
            │         │   q_PI     │   │   d_PI    │
            │         │            │   │           │
            │         │ Kp_q, Ki_q │   │ Kp_d, Ki_d│
         iq_fb ───(-)─>│            │   │           │<─(-)─── id_fb
            │         └────────┬───┘   └──┬────────┘
            │                  │           │
            │               Vq_ref      Vd_ref
            │                  │           │
            │               ┌──▼───────────▼──┐
         θ_elec ───────────>│  Inverse_Park   │
            │               │                 │
            │         sin,cos│                 │
            │               └──┬───────────┬──┘
            │                  │           │
            │                 Vα          Vβ
            │                  │           │
            │               ┌──▼───────────▼──┐
            │               │ Inverse_Clarke  │
            │               └──┬──────┬───┬───┘
            │                  │      │   │
            │                 Va     Vb  Vc
            │                  │      │   │
            │               ┌──▼──────▼───▼───┐
            │      Vdc ────>│      SVM        │
            │               └──┬──────┬───┬───┘
            │                  │      │   │
            │              Duty_A  Duty_B Duty_C
            │                  │      │   │
            │               ┌──▼──────▼───▼───┐
            │               │   PWM (10kHz)   │
            │               └──┬──────┬───┬───┘
            │                  │      │   │
            │            Gate_A  Gate_B Gate_C
            │                  │      │   │
            │               ┌──▼──────▼───▼───┐
            │      Vdc ────>│   INVERTER      │
            │               └──┬──────┬───┬───┘
            │                  │      │   │
            │                 Ua     Ub  Uc (Motor voltages)
            │                  │      │   │
            │               ┌──▼──────▼───▼───┐
            │               │     PMSM        │◄─── T_load
            │               │                 │
            │               │  Rs, Ld, Lq,   │
            │               │  λm, p, J       │
            │               └──┬──────┬───┬───┘
            │                  │      │   │
            │                 ia     ib  ic
            │                  │      │   │
            │               ┌──▼──────▼───▼───┐
            │               │    Clarke       │
            │               └──┬──────────┬───┘
            │                  │          │
            │                 iα         iβ
            │                  │          │
            │               ┌──▼──────────▼───┐
            │        θ ────>│     Park        │
            │               │                 │
            │         sin,cos│                 │
            │               └──┬──────────┬───┘
            │                  │          │
            └──────────────── id         iq
                              (back to current controllers)
                 
         POSITION SENSOR:
            Motor_shaft ──> [Encoder] ──> θ_mech ──> [×p] ──> θ_elec
                                              │
                                              └──> [d/dt] ──> Speed_fb
```

---

## 🔧 PARAMETER FLOW DIAGRAM

```
┌─────────────────────────────────────────────────────────────────────┐
│              WHERE EACH PARAMETER IS USED                            │
└─────────────────────────────────────────────────────────────────────┘

MOTOR PARAMETERS:
    Rs ──────────┬───> d_PI (Ki_d = ωBW × Rs)
                 └───> q_PI (Ki_q = ωBW × Rs)
    
    Ld ──────────┬───> d_PI (Kp_d = ωBW × Ld)
                 └───> Decoupling term
    
    Lq ──────────┬───> q_PI (Kp_q = ωBW × Lq)
                 └───> Decoupling term
    
    λm ──────────┬───> Torque_to_iq converter
                 ├───> Decoupling term
                 └───> Motor block
    
    p ───────────┬───> Torque_to_iq converter
                 ├───> θ_mech to θ_elec conversion
                 └───> Motor block
    
    J ───────────┬───> Speed_PI (Kp = ωBW_speed × J)
                 └───> Motor block

CONTROL PARAMETERS:
    fsw ─────────────> PWM block
    
    ωBW_current ─────> Current PI gains
    
    ωBW_speed ───────> Speed PI gains
    
    Vdc_bus ─────────┬─> Inverter
                     └─> SVM (normalization)

TIMING:
    Ts_current ─────> Current loop sample time
    
    Ts_speed ───────> Speed loop sample time (slower)
    
    Ts_PWM ─────────> PWM update rate
```

---

## 🎨 RECOMMENDED SIMSCAPE LIBRARY BLOCKS

```
┌─────────────────────────────────────────────────────────────────────┐
│              SIMSCAPE BLOCKS TO USE                                  │
└─────────────────────────────────────────────────────────────────────┘

1. Motor:
   • Simscape > Electrical > Specialized Power Systems
     > Machines > Permanent Magnet Synchronous Machine
   OR
   • Simscape > Electrical > Electromechanical > PM Synchronous Motor

2. Inverter:
   • Universal Bridge (with 6 switches)
   OR
   • Three-Phase Bridge
   • Configure: IGBT/Diode or MOSFET

3. Current Sensors:
   • Current Sensor (×3 for 3-phase)

4. Voltage Sensor:
   • Voltage Sensor (for DC bus)

5. Position Sensor:
   • Ideal Rotational Motion Sensor
   OR
   • Resolver/Encoder block

6. Controllers (in Simulink):
   • PID Controller (configure as PI)
   • Gain blocks
   • Math operations (sin, cos, multiply, add)

7. Transforms:
   • Use embedded MATLAB function or
   • Pre-built Park/Clarke blocks from library

8. PWM:
   • PWM Generator (Simscape Electrical)

9. Load:
   • Simscape > Mechanical > Rotational > Inertia
   • Simscape > Mechanical > Rotational > Rotational Damper
   • Torque Source (for external load)

10. Power Supply:
    • DC Voltage Source
    • Capacitor (for DC link)
```

---

## 💡 TIPS FOR SIMSCAPE IMPLEMENTATION

### Connection Order:
1. **Start with motor** - Place PMSM block
2. **Add mechanical load** - Connect inertia and load torque
3. **Add position sensor** - Tap motor shaft
4. **Add inverter** - Connect to motor phases
5. **Add DC source** - Connect to inverter
6. **Add current sensors** - On motor phases
7. **Build control** - Start with current loop, then speed loop
8. **Connect transforms** - Clarke → Park → PI → Inv Park → Inv Clarke
9. **Add PWM** - Connect to inverter gates
10. **Close all loops** - Verify all feedback connections

### Solver Settings:
- Use **ode23tb** or **ode15s** (stiff solvers)
- Max step size: **1e-6** (for 10 kHz PWM)
- Relative tolerance: **1e-4**

### Scopes to Add:
- Speed (reference vs measured)
- Torque
- id, iq currents
- Phase currents ia, ib, ic
- Motor position θ
- DC bus voltage/current
- PWM duty cycles

### Debugging Signals:
- Clarke outputs (iα, iβ)
- Park outputs (id, iq)
- PI outputs (Vd, Vq)
- Inverse transforms
- SVM sector

---

## 📊 EXAMPLE PARAMETER SET (Copy-Paste Ready)

```matlab
%% MOTOR PARAMETERS (1.5 kW PMSM Example)
Rs = 0.285;           % Ohm - stator resistance
Ld = 0.85e-3;         % H - d-axis inductance
Lq = 0.85e-3;         % H - q-axis inductance (SPMSM: Ld=Lq)
lambda_m = 0.1827;    % Wb - flux linkage
p = 4;                % pole pairs
J = 0.0001;           % kg·m² - rotor inertia
B = 0.0001;           % N·m·s - viscous friction
V_rated = 300;        % V - rated voltage (line-line RMS)
I_rated = 5;          % A - rated current
omega_rated = 3000;   % rpm - rated speed

%% CONTROL PARAMETERS
% Current loop (inner, fast)
omega_BW_current = 2*pi*1000;  % rad/s (1000 Hz bandwidth)
Kp_d = omega_BW_current * Ld;
Ki_d = omega_BW_current * Rs;
Kp_q = omega_BW_current * Lq;
Ki_q = omega_BW_current * Rs;

% Speed loop (outer, slower)
omega_BW_speed = 2*pi*50;      % rad/s (50 Hz bandwidth)
Kp_speed = omega_BW_speed * J;
Ki_speed = omega_BW_speed * 0.1;

%% PWM & INVERTER
fsw = 10e3;           % Hz - switching frequency
Ts_PWM = 1/fsw;       % s - PWM period
Vdc = 400;            % V - DC bus voltage
deadtime = 1e-6;      % s - dead time (1 μs)

%% SAMPLE TIMES
Ts_current = 100e-6;  % s - current loop (100 μs)
Ts_speed = 1e-3;      % s - speed loop (1 ms)

%% MOTOR TYPE SELECTION
motor_type = 'SPMSM'; % 'SPMSM' or 'IPMSM'
if strcmp(motor_type, 'SPMSM')
    id_ref = 0;       % Always zero for SPMSM
else
    % For IPMSM, id_ref varies with field weakening
end
```

---

## ✨ FINAL NOTES

This diagram provides **ALL** connections needed to implement FOC for:
- **SPMSM** (Surface-mounted permanent magnet)
- **IPMSM** (Interior permanent magnet)

### Key Differences for Different Motor Types:

**SPMSM (Ld = Lq):**
- `id_ref = 0` always
- Torque = (3/2) × p × λm × iq
- Simpler control

**IPMSM (Ld ≠ Lq):**
- `id_ref` varies (MTPA or field weakening)
- Additional reluctance torque
- Need trajectory planning for id vs speed

### Next Steps:
1. Use this diagram to build in Simscape
2. Start with SPMSM (simpler)
3. Test each subsystem independently
4. Integrate step-by-step
5. Tune PI controllers after basic operation

Good luck with your Simscape implementation! 🚀
```
