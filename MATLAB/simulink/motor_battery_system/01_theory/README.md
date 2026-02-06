# Theory Documentation Index

## Complete Electric Vehicle Motor Control Theory

This directory contains comprehensive theoretical documentation and practical algorithms for electric vehicle motor control systems, battery management, and system integration.

---

## 📚 Theory Documents

### 1. [Motor Theory](01_motor_theory.md)
- PMSM fundamentals and electromagnetic principles
- Motor equations and torque production
- Electrical and mechanical characteristics
- Motor types and topologies

### 2. [Battery Theory](02_battery_theory.md)
- Electrochemistry fundamentals
- Battery models (Thevenin, equivalent circuit)
- State estimation (SOC, SOH, SOE)
- Thermal behavior and aging

### 3. [Control Theory](03_control_theory.md)
- Field-Oriented Control (FOC)
- Space Vector Modulation (SVM)
- Coordinate transformations (Clarke, Park)
- PI/PID controller tuning
- Sensorless control methods
- Direct Torque Control (DTC)

### 4. [Thermal Theory](04_thermal_theory.md)
- Heat generation mechanisms
- Thermal modeling and networks
- Cooling systems design
- Thermal management strategies

### 5. [System Integration](05_system_integration.md)
- Overall system architecture
- Component selection and sizing
- Power flow analysis
- System-level optimization

### 6. [FOC Practical Guide](06_FOC_practical_guide.md)
- Step-by-step FOC implementation
- Practical tips and troubleshooting
- Real-world examples
- Common pitfalls and solutions

### 7. [SOC Estimation Guide](07_SOC_estimation_guide.md)
- Coulomb counting method
- Kalman filter approaches (EKF, UKF)
- OCV-based estimation
- Hybrid methods
- Calibration procedures

### 8. [Power Electronics Control](08_power_electronics_control.md) ⭐ **NEW**
#### Inverter Control
- Three-phase VSI topology and switching states
- Space vector representation
- Dead-time management and compensation
- Shoot-through protection

#### PWM Modulation Strategies
- Sinusoidal PWM (SPWM)
- Space Vector Modulation (SVM) with complete sector determination
- Discontinuous PWM (DPWM)
- Overmodulation techniques
- DC bus utilization optimization

#### Current and Voltage Sensing
- Shunt resistor sensing (low-side, high-side)
- Hall effect current sensors
- Single-shunt current reconstruction algorithm
- DC bus voltage sensing and filtering
- ADC considerations and sampling strategies
- Noise rejection and signal conditioning

#### Thermal Management
- Power loss calculations (conduction, switching, gate drive)
- Thermal modeling and equivalent circuits
- Heatsink design methodology
- Active thermal management algorithms
- Temperature-based derating
- Predictive thermal control
- Cooling system control (fan, pump)

#### **8 Production-Ready Algorithms**:
1. Space Vector Modulation (SVM)
2. Single-Shunt Current Reconstruction
3. Dead-Time Compensation
4. Adaptive PWM Frequency Control
5. Thermal Model & Prediction
6. Current Sensor Calibration
7. DC-Link Ripple Compensation
8. Comprehensive Thermal Management System

### 9. [System Integration Interfaces](09_system_integration_interfaces.md) ⭐ **NEW**

#### BMS Interface
- Power limits calculation (thermal, voltage, current, SOC-based)
- SOC estimation (Coulomb counting, Extended Kalman Filter)
- BMS-MCU data structures and communication protocols
- Fault codes and handling procedures
- Power derating strategies

#### Drivetrain Interface
- Drivetrain architectures (single motor, dual motor, in-wheel)
- Torque request processing and pedal mapping
- Speed-dependent torque limits
- Traction control integration and wheel slip control
- Torque vectoring for dual/quad motor systems
- Load transfer compensation
- Drivetrain-MCU data exchange

#### Regenerative Braking System
- Energy recovery theory and efficiency
- Braking force distribution (front/rear axle)
- Regenerative braking strategies:
  - Fixed regen
  - Adaptive regen (SOC-based)
  - Blended braking (optimal)
- Brake pedal feel and blending algorithms
- One-pedal driving implementation
- ABS integration and cooperative control

#### Communication Protocols
- CAN bus architecture and message structure
- CAN-FD for high-bandwidth applications
- Message priority and arbitration
- Data encoding and scaling (fixed-point)
- Timeout monitoring and fault detection
- CRC validation and sequence counting

#### Power Flow Management
- Power flow states and transitions
- Power arbitration hierarchy
- Energy flow optimization
- Efficiency map-based control
- Multi-motor power distribution
- DC-link voltage management

#### **5 Production-Ready Algorithms**:
1. BMS Power Limit Calculator
2. Torque Request Arbiter
3. Regenerative Braking Controller
4. Torque Vectoring Controller
5. Communication State Machine

#### Safety and Fault Handling
- Fault classification (critical, warning, informational)
- Fault response actions and configuration
- Safe state transitions
- Recovery sequences

---

## 🎯 Quick Navigation by Topic

### For Motor Control Engineers
- Start with: [Motor Theory](01_motor_theory.md) → [Control Theory](03_control_theory.md) → [FOC Practical Guide](06_FOC_practical_guide.md) → [Power Electronics Control](08_power_electronics_control.md)

### For Battery System Engineers
- Start with: [Battery Theory](02_battery_theory.md) → [SOC Estimation Guide](07_SOC_estimation_guide.md) → [System Integration Interfaces](09_system_integration_interfaces.md)

### For System Integrators
- Start with: [System Integration](05_system_integration.md) → [System Integration Interfaces](09_system_integration_interfaces.md) → [Thermal Theory](04_thermal_theory.md)

### For Embedded Software Engineers
- Focus on: [Power Electronics Control](08_power_electronics_control.md) → [System Integration Interfaces](09_system_integration_interfaces.md) → [FOC Practical Guide](06_FOC_practical_guide.md)

---

## 🔧 Algorithm Implementations

All documents include **production-ready MATLAB/Simulink algorithms** with:
- ✅ Complete mathematical derivations
- ✅ Real-time implementation considerations
- ✅ Numerical stability and error handling
- ✅ Fault tolerance and safety features
- ✅ Practical tuning guidelines
- ✅ Hardware requirements

### Total Algorithms Provided: **13+**
- 8 Power Electronics Control algorithms
- 5 System Integration algorithms
- Plus numerous sub-algorithms in other documents

---

## 📊 Key Features

### Theoretical Depth
- Rigorous mathematical foundations
- Physics-based modeling
- State-of-the-art control methods
- Industry-standard approaches

### Practical Implementation
- Step-by-step procedures
- Real-world constraints and considerations
- Hardware selection guidelines
- Calibration and tuning methods

### Safety and Reliability
- Fault detection and handling
- Redundancy strategies
- Safe state transitions
- Industry standards compliance (ISO 26262, IEC 61508)

### Performance Optimization
- Efficiency maximization
- Energy recovery optimization
- Thermal management
- Multi-objective optimization

---

## 🔗 Related Documentation

- **Models**: See `../02_models/` for Simulink implementations
- **Scripts**: See `../03_scripts/` for initialization and utilities
- **Test Cases**: See `../04_test_cases/` for validation scenarios
- **Data**: See `../05_data/` for motor and battery parameters

---

## 📖 Usage Guidelines

### For Learning
1. Read theory documents in sequence (01 → 09)
2. Work through practical examples
3. Implement algorithms in test environment
4. Validate against provided test cases

### For Development
1. Select relevant algorithms for your application
2. Adapt parameters to your specific hardware
3. Integrate into your control architecture
4. Validate through simulation and testing
5. Tune for optimal performance

### For Reference
- Use search function to find specific topics
- Refer to algorithm implementations for production code
- Check references for deeper understanding
- Consult safety sections for critical systems

---

## 🆕 Recent Additions

### February 2026
- **Power Electronics Control** (Document 08)
  - Complete inverter control theory
  - 8 production-ready algorithms
  - Comprehensive thermal management
  
- **System Integration Interfaces** (Document 09)
  - BMS interface with power limits
  - Drivetrain control and torque vectoring
  - Regenerative braking strategies
  - Communication protocols and fault handling

---

## 📝 Document Conventions

- **Equations**: LaTeX/KaTeX format for mathematical expressions
- **Code**: MATLAB syntax with detailed comments
- **Diagrams**: ASCII art for simple diagrams, references for complex ones
- **Units**: SI units unless otherwise specified
- **Variables**: Descriptive names following industry conventions

---

## 🤝 Contributing

When adding new theory documents:
1. Follow existing structure and formatting
2. Include both theory and practical algorithms
3. Provide complete code examples
4. Add references to standards and papers
5. Update this index file

---

## 📚 References

All documents include comprehensive references to:
- Academic papers and textbooks
- Industry standards (ISO, IEC, SAE)
- Application notes from manufacturers
- Open-source projects and tools

---

## ⚠️ Important Notes

- All algorithms are provided as educational resources and starting points
- Validate thoroughly before using in production systems
- Follow safety standards for automotive and industrial applications
- Consider legal and regulatory requirements in your jurisdiction
- Test extensively in simulation before hardware implementation

---

**Last Updated**: February 4, 2026
**Total Pages**: 500+ (across all documents)
**Code Examples**: 50+ complete implementations
**Equations**: 200+ mathematical formulas
**Diagrams**: 100+ illustrations

For questions or suggestions, refer to the main project README.
