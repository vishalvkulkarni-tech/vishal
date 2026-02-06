# FOC System - Visual Mermaid Diagrams

This file contains interactive Mermaid diagrams for the FOC control system. View this in VS Code or any Mermaid-compatible viewer.

---

## 📊 COMPLETE FOC SYSTEM - HIGH LEVEL

```mermaid
flowchart TB
    %% Input Layer
    SpeedRef[Speed Reference<br/>ω_ref]
    TorqueRef[Torque Reference<br/>T_ref]
    
    %% Speed Controller
    SpeedPI[Speed PI Controller<br/>Kp_speed, Ki_speed]
    
    %% Torque to Current Conversion
    TorqueConv[Torque to iq Converter<br/>MTPA / Field Weakening]
    
    %% Current References
    iqRef[iq_ref]
    idRef[id_ref = 0 for SPMSM]
    
    %% Current Controllers
    qPI[q-axis PI Controller<br/>Kp_q, Ki_q]
    dPI[d-axis PI Controller<br/>Kp_d, Ki_d]
    
    %% Coordinate Transforms
    InvPark[Inverse Park Transform<br/>dq → αβ]
    InvClarke[Inverse Clarke Transform<br/>αβ → abc]
    Clarke[Clarke Transform<br/>abc → αβ]
    Park[Park Transform<br/>αβ → dq]
    
    %% PWM & Inverter
    SVM[Space Vector Modulation<br/>SVM]
    PWM[PWM Generator<br/>10 kHz]
    Inverter[3-Phase Inverter<br/>6 IGBTs]
    
    %% Motor & Load
    Motor[PMSM Motor<br/>Rs, Ld, Lq, λm, p]
    Load[Mechanical Load<br/>J, B, T_load]
    
    %% Sensors
    CurrentSensor[Current Sensors<br/>ia, ib, ic]
    PosSensor[Position Sensor<br/>Encoder]
    SpeedCalc[Speed Calculation<br/>dθ/dt]
    AngleConv[Angle Conversion<br/>θ_elec = p × θ_mech]
    TrigCalc[Trig Functions<br/>sin θ, cos θ]
    
    %% Forward Path
    SpeedRef --> SpeedPI
    TorqueRef --> TorqueConv
    SpeedPI --> TorqueConv
    
    TorqueConv --> iqRef
    TorqueConv --> idRef
    
    iqRef --> qPI
    idRef --> dPI
    
    qPI --> |Vq_ref| InvPark
    dPI --> |Vd_ref| InvPark
    
    TrigCalc --> |sin θ, cos θ| InvPark
    InvPark --> |Vα, Vβ| InvClarke
    InvClarke --> |Va, Vb, Vc| SVM
    SVM --> PWM
    PWM --> |Gate Signals| Inverter
    Inverter --> |3-Phase AC| Motor
    Motor --> Load
    
    %% Feedback Path - Current
    Motor --> CurrentSensor
    CurrentSensor --> |ia, ib, ic| Clarke
    Clarke --> |iα, iβ| Park
    TrigCalc --> |sin θ, cos θ| Park
    Park --> |id| dPI
    Park --> |iq| qPI
    
    %% Feedback Path - Position/Speed
    Motor --> PosSensor
    PosSensor --> |θ_mech| AngleConv
    AngleConv --> |θ_elec| TrigCalc
    AngleConv --> SpeedCalc
    SpeedCalc --> |ω_meas| SpeedPI
    
    %% Styling
    classDef inputClass fill:#e1f5ff,stroke:#01579b,stroke-width:2px
    classDef controlClass fill:#fff9c4,stroke:#f57f17,stroke-width:2px
    classDef transformClass fill:#f3e5f5,stroke:#4a148c,stroke-width:2px
    classDef powerClass fill:#ffebee,stroke:#b71c1c,stroke-width:2px
    classDef motorClass fill:#e8f5e9,stroke:#1b5e20,stroke-width:3px
    classDef sensorClass fill:#e0f2f1,stroke:#004d40,stroke-width:2px
    
    class SpeedRef,TorqueRef,iqRef,idRef inputClass
    class SpeedPI,qPI,dPI,TorqueConv controlClass
    class Clarke,Park,InvPark,InvClarke,TrigCalc,AngleConv transformClass
    class SVM,PWM,Inverter powerClass
    class Motor,Load motorClass
    class CurrentSensor,PosSensor,SpeedCalc sensorClass
```

---

## 🔄 DETAILED CONTROL LOOPS

### Speed Control Loop (Outer Loop)

```mermaid
flowchart LR
    SpeedRef[ω_ref<br/>Speed Reference] --> Sum1((+))
    Sum1 --> PI[PI Controller<br/>Kp_speed<br/>Ki_speed]
    PI --> TorqueRef[T_ref<br/>Torque Command]
    SpeedMeas[ω_measured<br/>from motor] --> Neg((-))
    Neg --> Sum1
    
    classDef inputClass fill:#e1f5ff,stroke:#01579b,stroke-width:2px
    classDef controlClass fill:#fff9c4,stroke:#f57f17,stroke-width:2px
    classDef feedbackClass fill:#e0f2f1,stroke:#004d40,stroke-width:2px
    
    class SpeedRef,TorqueRef inputClass
    class PI controlClass
    class SpeedMeas,Neg feedbackClass
```

### Current Control Loop (Inner Loop - d-axis)

```mermaid
flowchart LR
    idRef[id_ref<br/>usually 0] --> Sum1((+))
    Sum1 --> PI[d-axis PI<br/>Kp_d = ωBW × Ld<br/>Ki_d = ωBW × Rs]
    PI --> Vd[Vd_ref<br/>d-axis Voltage]
    idMeas[id_measured<br/>from Park] --> Neg((-))
    Neg --> Sum1
    
    classDef inputClass fill:#e1f5ff,stroke:#01579b,stroke-width:2px
    classDef controlClass fill:#fff9c4,stroke:#f57f17,stroke-width:2px
    classDef feedbackClass fill:#e0f2f1,stroke:#004d40,stroke-width:2px
    
    class idRef,Vd inputClass
    class PI controlClass
    class idMeas,Neg feedbackClass
```

### Current Control Loop (Inner Loop - q-axis)

```mermaid
flowchart LR
    iqRef[iq_ref<br/>from torque] --> Sum1((+))
    Sum1 --> PI[q-axis PI<br/>Kp_q = ωBW × Lq<br/>Ki_q = ωBW × Rs]
    PI --> Vq[Vq_ref<br/>q-axis Voltage]
    iqMeas[iq_measured<br/>from Park] --> Neg((-))
    Neg --> Sum1
    
    classDef inputClass fill:#e1f5ff,stroke:#01579b,stroke-width:2px
    classDef controlClass fill:#fff9c4,stroke:#f57f17,stroke-width:2px
    classDef feedbackClass fill:#e0f2f1,stroke:#004d40,stroke-width:2px
    
    class iqRef,Vq inputClass
    class PI controlClass
    class iqMeas,Neg feedbackClass
```

---

## 🔀 COORDINATE TRANSFORMATIONS

### Forward Path: dq → abc

```mermaid
flowchart TB
    Vd[Vd_ref<br/>d-axis voltage] --> InvPark[Inverse Park Transform<br/>Vα = Vd cos θ - Vq sin θ<br/>Vβ = Vd sin θ + Vq cos θ]
    Vq[Vq_ref<br/>q-axis voltage] --> InvPark
    Theta[θ electrical<br/>sin θ, cos θ] --> InvPark
    
    InvPark --> Valpha[Vα]
    InvPark --> Vbeta[Vβ]
    
    Valpha --> InvClarke[Inverse Clarke Transform<br/>Va = Vα<br/>Vb = -0.5Vα + √3/2 Vβ<br/>Vc = -0.5Vα - √3/2 Vβ]
    Vbeta --> InvClarke
    
    InvClarke --> Va[Va<br/>Phase A voltage]
    InvClarke --> Vb[Vb<br/>Phase B voltage]
    InvClarke --> Vc[Vc<br/>Phase C voltage]
    
    classDef dqClass fill:#f3e5f5,stroke:#4a148c,stroke-width:2px
    classDef abClass fill:#fff9c4,stroke:#f57f17,stroke-width:2px
    classDef angleClass fill:#e0f2f1,stroke:#004d40,stroke-width:2px
    
    class Vd,Vq dqClass
    class Valpha,Vbeta abClass
    class Va,Vb,Vc abClass
    class Theta angleClass
```

### Feedback Path: abc → dq

```mermaid
flowchart TB
    ia[ia<br/>Phase A current] --> Clarke[Clarke Transform<br/>iα = ia<br/>iβ = ia + 2ib / √3]
    ib[ib<br/>Phase B current] --> Clarke
    ic[ic<br/>Phase C current] -.-> Clarke
    
    Clarke --> ialpha[iα]
    Clarke --> ibeta[iβ]
    
    ialpha --> Park[Park Transform<br/>id = iα cos θ + iβ sin θ<br/>iq = -iα sin θ + iβ cos θ]
    ibeta --> Park
    Theta[θ electrical<br/>sin θ, cos θ] --> Park
    
    Park --> id[id<br/>d-axis current<br/>flux component]
    Park --> iq[iq<br/>q-axis current<br/>torque component]
    
    classDef abcClass fill:#ffebee,stroke:#b71c1c,stroke-width:2px
    classDef alphabetaClass fill:#fff9c4,stroke:#f57f17,stroke-width:2px
    classDef dqClass fill:#f3e5f5,stroke:#4a148c,stroke-width:2px
    classDef angleClass fill:#e0f2f1,stroke:#004d40,stroke-width:2px
    
    class ia,ib,ic abcClass
    class ialpha,ibeta alphabetaClass
    class id,iq dqClass
    class Theta angleClass
```

---

## ⚡ POWER STAGE

### Inverter and Motor

```mermaid
flowchart TB
    subgraph PWM_Block[PWM Generation]
        Va[Va] --> SVM[Space Vector<br/>Modulation]
        Vb[Vb] --> SVM
        Vc[Vc] --> SVM
        Vdc[Vdc bus] --> SVM
        
        SVM --> PWM[PWM Generator<br/>fsw = 10 kHz]
        PWM --> GA[Gate A<br/>high/low]
        PWM --> GB[Gate B<br/>high/low]
        PWM --> GC[Gate C<br/>high/low]
    end
    
    subgraph Inverter_Block[3-Phase Inverter]
        VdcBus[Vdc Bus<br/>+400V] --> SA[Switch A]
        VdcBus --> SB[Switch B]
        VdcBus --> SC[Switch C]
        
        GA --> SA
        GB --> SB
        GC --> SC
        
        SA --> PhaseA[Phase A]
        SB --> PhaseB[Phase B]
        SC --> PhaseC[Phase C]
        
        PhaseA --> GND[GND]
        PhaseB --> GND
        PhaseC --> GND
    end
    
    subgraph Motor_Block[PMSM Motor]
        PhaseA --> MotorA[Winding A]
        PhaseB --> MotorB[Winding B]
        PhaseC --> MotorC[Winding C]
        
        MotorA --> Rotor[Rotor<br/>Permanent Magnets]
        MotorB --> Rotor
        MotorC --> Rotor
        
        Rotor --> Shaft[Mechanical<br/>Shaft Output]
    end
    
    Shaft --> LoadTorque[Load<br/>Torque]
    
    classDef voltageClass fill:#fff9c4,stroke:#f57f17,stroke-width:2px
    classDef powerClass fill:#ffebee,stroke:#b71c1c,stroke-width:2px
    classDef motorClass fill:#e8f5e9,stroke:#1b5e20,stroke-width:3px
    
    class Va,Vb,Vc,GA,GB,GC voltageClass
    class VdcBus,SA,SB,SC,PhaseA,PhaseB,PhaseC powerClass
    class MotorA,MotorB,MotorC,Rotor,Shaft motorClass
```

---

## 📐 POSITION & SPEED SENSING

```mermaid
flowchart TB
    Shaft[Motor Shaft<br/>θ_mechanical] --> Encoder[Encoder/Resolver<br/>Position Sensor]
    
    Encoder --> ThetaMech[θ_mech<br/>Mechanical Angle]
    
    ThetaMech --> Mult[× p<br/>pole pairs]
    Mult --> ThetaElec[θ_elec<br/>Electrical Angle<br/>0 to 2π]
    
    ThetaElec --> Trig[Trigonometric<br/>Functions]
    Trig --> SinTheta[sin θ]
    Trig --> CosTheta[cos θ]
    
    ThetaElec --> Deriv[Derivative<br/>dθ/dt]
    Deriv --> OmegaElec[ω_elec<br/>Electrical Speed]
    
    OmegaElec --> DivP[÷ p<br/>pole pairs]
    DivP --> OmegaMech[ω_mech<br/>Mechanical Speed<br/>rad/s or RPM]
    
    SinTheta -.-> Park[To Park<br/>Transform]
    CosTheta -.-> Park
    SinTheta -.-> InvPark[To Inverse Park<br/>Transform]
    CosTheta -.-> InvPark
    OmegaMech -.-> SpeedPI[To Speed<br/>Controller]
    
    classDef sensorClass fill:#e0f2f1,stroke:#004d40,stroke-width:2px
    classDef angleClass fill:#f3e5f5,stroke:#4a148c,stroke-width:2px
    classDef speedClass fill:#fff9c4,stroke:#f57f17,stroke-width:2px
    
    class Shaft,Encoder sensorClass
    class ThetaMech,ThetaElec,SinTheta,CosTheta angleClass
    class OmegaElec,OmegaMech speedClass
```

---

## 🎯 TORQUE GENERATION (Motor Physics)

### SPMSM (Surface Mounted)

```mermaid
flowchart LR
    subgraph Control
        iqRef[iq_ref<br/>Torque Command] 
        idRef[id_ref = 0<br/>No Flux Weakening]
    end
    
    subgraph Motor_Equations
        Torque[Torque Equation<br/>Te = 3/2 × p × λm × iq]
        iqRef --> Torque
        
        Params[Motor Parameters<br/>p = pole pairs<br/>λm = flux linkage]
        Params -.-> Torque
    end
    
    Torque --> Output[Te<br/>Electromagnetic<br/>Torque]
    
    classDef inputClass fill:#e1f5ff,stroke:#01579b,stroke-width:2px
    classDef calcClass fill:#fff9c4,stroke:#f57f17,stroke-width:2px
    classDef outputClass fill:#e8f5e9,stroke:#1b5e20,stroke-width:2px
    
    class iqRef,idRef inputClass
    class Torque,Params calcClass
    class Output outputClass
```

### IPMSM (Interior Mounted with Reluctance)

```mermaid
flowchart LR
    subgraph Control
        iqRef[iq_ref<br/>Torque Component] 
        idRef[id_ref<br/>Flux Component<br/>varies with speed]
    end
    
    subgraph Motor_Equations
        MagTorque[Magnet Torque<br/>3/2 × p × λm × iq]
        RelTorque[Reluctance Torque<br/>3/2 × p × Ld-Lq × id × iq]
        
        iqRef --> MagTorque
        iqRef --> RelTorque
        idRef --> RelTorque
        
        MagTorque --> Sum((+))
        RelTorque --> Sum
        
        Params[Motor Parameters<br/>p, λm, Ld, Lq]
        Params -.-> MagTorque
        Params -.-> RelTorque
    end
    
    Sum --> Output[Te = Magnet + Reluctance<br/>Total Electromagnetic<br/>Torque]
    
    classDef inputClass fill:#e1f5ff,stroke:#01579b,stroke-width:2px
    classDef calcClass fill:#fff9c4,stroke:#f57f17,stroke-width:2px
    classDef outputClass fill:#e8f5e9,stroke:#1b5e20,stroke-width:2px
    
    class iqRef,idRef inputClass
    class MagTorque,RelTorque,Sum,Params calcClass
    class Output outputClass
```

---

## 🔧 PARAMETER FLOW

```mermaid
flowchart TB
    subgraph Motor_Parameters[Motor Nameplate]
        Rs[Rs<br/>Resistance]
        Ld[Ld<br/>d-axis Inductance]
        Lq[Lq<br/>q-axis Inductance]
        Lambda[λm<br/>Flux Linkage]
        Poles[p<br/>Pole Pairs]
        Inertia[J<br/>Rotor Inertia]
    end
    
    subgraph Control_Tuning[Control Parameters]
        BW_Current[ωBW_current<br/>Current Loop Bandwidth<br/>~1000 rad/s]
        BW_Speed[ωBW_speed<br/>Speed Loop Bandwidth<br/>~50 rad/s]
    end
    
    Rs --> KiD[Ki_d = ωBW × Rs]
    Rs --> KiQ[Ki_q = ωBW × Rs]
    Ld --> KpD[Kp_d = ωBW × Ld]
    Lq --> KpQ[Kp_q = ωBW × Lq]
    BW_Current --> KiD
    BW_Current --> KiQ
    BW_Current --> KpD
    BW_Current --> KpQ
    
    Inertia --> KpSpeed[Kp_speed = ωBW_speed × J]
    BW_Speed --> KpSpeed
    BW_Speed --> KiSpeed[Ki_speed = ωBW_speed × 0.1]
    
    Lambda --> TorqueCalc[Torque to iq<br/>Conversion]
    Poles --> TorqueCalc
    Poles --> AngleConv[θ_elec = p × θ_mech]
    
    KpD --> dPI[d-axis PI<br/>Controller]
    KiD --> dPI
    KpQ --> qPI[q-axis PI<br/>Controller]
    KiQ --> qPI
    KpSpeed --> SpeedPI[Speed PI<br/>Controller]
    KiSpeed --> SpeedPI
    
    classDef paramClass fill:#e1f5ff,stroke:#01579b,stroke-width:2px
    classDef tuningClass fill:#fff9c4,stroke:#f57f17,stroke-width:2px
    classDef controlClass fill:#f3e5f5,stroke:#4a148c,stroke-width:2px
    
    class Rs,Ld,Lq,Lambda,Poles,Inertia paramClass
    class BW_Current,BW_Speed tuningClass
    class KiD,KiQ,KpD,KpQ,KpSpeed,KiSpeed,dPI,qPI,SpeedPI controlClass
```

---

## 📊 COMPLETE SYSTEM STATE FLOW

```mermaid
stateDiagram-v2
    [*] --> Initialization
    
    Initialization --> CurrentSensing : System Start
    
    state CurrentSensing {
        [*] --> MeasureABC
        MeasureABC --> ClarkeTransform
        ClarkeTransform --> ParkTransform
        ParkTransform --> [*]
    }
    
    CurrentSensing --> PositionSensing
    
    state PositionSensing {
        [*] --> ReadEncoder
        ReadEncoder --> ConvertAngle
        ConvertAngle --> CalcSpeed
        CalcSpeed --> ComputeTrig
        ComputeTrig --> [*]
    }
    
    PositionSensing --> Control
    
    state Control {
        [*] --> SpeedLoop
        SpeedLoop --> TorqueReference
        TorqueReference --> CurrentReferences
        CurrentReferences --> dqControllers
        dqControllers --> [*]
    }
    
    Control --> VoltageGeneration
    
    state VoltageGeneration {
        [*] --> InversePark
        InversePark --> InverseClarke
        InverseClarke --> SVM
        SVM --> PWMGeneration
        PWMGeneration --> [*]
    }
    
    VoltageGeneration --> MotorDrive
    
    state MotorDrive {
        [*] --> InverterSwitching
        InverterSwitching --> MotorExcitation
        MotorExcitation --> TorqueProduction
        TorqueProduction --> MechanicalOutput
        MechanicalOutput --> [*]
    }
    
    MotorDrive --> CurrentSensing : Feedback Loop (100μs)
    MotorDrive --> PositionSensing : Feedback Loop
```

---

## 🎨 LEGEND

```mermaid
flowchart LR
    Input[Input Signals<br/>Commands]
    Control[Control<br/>Algorithms]
    Transform[Coordinate<br/>Transforms]
    Power[Power<br/>Electronics]
    Motor[Motor &<br/>Load]
    Sensor[Sensors &<br/>Feedback]
    
    classDef inputClass fill:#e1f5ff,stroke:#01579b,stroke-width:2px
    classDef controlClass fill:#fff9c4,stroke:#f57f17,stroke-width:2px
    classDef transformClass fill:#f3e5f5,stroke:#4a148c,stroke-width:2px
    classDef powerClass fill:#ffebee,stroke:#b71c1c,stroke-width:2px
    classDef motorClass fill:#e8f5e9,stroke:#1b5e20,stroke-width:3px
    classDef sensorClass fill:#e0f2f1,stroke:#004d40,stroke-width:2px
    
    class Input inputClass
    class Control controlClass
    class Transform transformClass
    class Power powerClass
    class Motor motorClass
    class Sensor sensorClass
```

---

## 📝 How to View These Diagrams

### In VS Code:
1. Install **Markdown Preview Mermaid Support** extension
2. Right-click this file → "Open Preview"
3. Diagrams will render automatically

### In GitHub:
- Mermaid is natively supported - just view the markdown file

### Export Options:
- VS Code: Export preview to HTML/PDF
- Online: Copy diagram code to https://mermaid.live
- Or use the accompanying HTML file for interactive view

---

## 🔗 Cross-Reference

- **Theory**: See [06_FOC_practical_guide.md](06_FOC_practical_guide.md) for detailed explanations
- **Connections**: See [FOC_Connections_Diagram.md](FOC_Connections_Diagram.md) for text-based connection details
- **Interactive**: See [FOC_Interactive_Diagram.html](FOC_Interactive_Diagram.html) for web-based visualization
