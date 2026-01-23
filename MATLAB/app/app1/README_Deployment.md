# Dynamic Simulink Model GUI with Standalone Deployment

This project enables dynamic GUI generation from Simulink model parameters and standalone deployment without MATLAB license.

## Project Structure

```
MATLAB/+app/
├── createSimpleAdditionModel.m    - Creates sample Simulink model
├── ModelParameterParser.m         - Parses model and extracts parameters
├── DynamicModelGUI.m             - Dynamic GUI application
├── testDynamicGUI.m              - Demo/test script
└── README_Deployment.md          - This file
```

## Features

✅ **Automatic Parameter Discovery**: Reads Simulink models and extracts configurable parameters
✅ **Dynamic GUI Generation**: Creates UI controls based on parameter types (numeric fields, dropdowns, etc.)
✅ **Parameter Types Supported**:
   - Constant blocks: Value, DataType, SampleTime
   - Gain blocks: Gain value
   - Extensible to other block types

✅ **Live Simulation**: Run simulations with modified parameters directly from GUI
✅ **Standalone Deployment Ready**: Can be compiled to EXE with MATLAB Compiler

## Quick Start

### 1. Create and Test the System

```matlab
% Run the demo
app.testDynamicGUI()
```

This will:
1. Create a simple addition model (Param1 + Param2)
2. Parse its parameters
3. Launch the dynamic GUI

### 2. Use the GUI

- **Modify Parameters**: Change values in the parameter fields
- **Run Simulation**: Click "Run Simulation" to execute with current values
- **Save Model**: Click "Save Model" to persist changes to the .slx file
- **Load Model**: Click "Load Model" to select a different Simulink model

## Standalone Deployment (License-Free Execution)

### Prerequisites

1. **MATLAB Compiler** (for creating EXE)
2. **Simulink Coder** (for generating C code from model)
3. **C/C++ Compiler** (MinGW-w64, Visual Studio, etc.)

### Deployment Strategy

There are two approaches to achieve license-free execution:

---

## **Approach 1: Simulink Coder + Generated Code** (RECOMMENDED)

This approach generates standalone C code from your Simulink model that can be called from the compiled MATLAB GUI.

### Step 1: Configure Model for Code Generation

```matlab
% Open your model
modelName = 'SimpleAdditionModel';
load_system(modelName);

% Configure for code generation
set_param(modelName, 'SystemTargetFile', 'ert.tlc');
set_param(modelName, 'TargetLang', 'C');
set_param(modelName, 'CodeInterfacePackaging', 'C++ class');
set_param(modelName, 'GenerateSampleERTMain', 'on');

% Build model
slbuild(modelName);
```

This generates C/C++ code in `slprj/ert/SimpleAdditionModel/` directory.

### Step 2: Create DLL from Generated Code

```matlab
% Navigate to generated code directory
cd(['slprj/ert/' modelName]);

% Compile to DLL (Windows example)
% Adjust compiler flags for your system
mex -v -output modelDLL.dll ...
    SimpleAdditionModel.c ...
    rtGetInf.c ...
    rtGetNaN.c ...
    rt_nonfinite.c ...
    -I. ...
    -DMODEL=SimpleAdditionModel
```

### Step 3: Modify GUI to Call DLL Instead of sim()

Update `DynamicModelGUI.m` to load and call the DLL:

```matlab
% In RunSimulationButtonPushed callback:
% Instead of:
%   simOut = sim(app.ModelName);

% Use:
if ~libisloaded('modelDLL')
    loadlibrary('modelDLL.dll', 'SimpleAdditionModel.h');
end

% Call model step function
output = calllib('modelDLL', 'SimpleAdditionModel_step', input1, input2);
```

### Step 4: Compile GUI to EXE

```matlab
% Create deployment project
mcc -m DynamicModelGUI.m ...
    -a ModelParameterParser.m ...
    -a modelDLL.dll ...
    -o DynamicModelGUI
```

This creates:
- `DynamicModelGUI.exe` - Standalone executable
- `requiredMCRProducts.txt` - List of required MCR components

### Step 5: Distribution

Distribute:
1. `DynamicModelGUI.exe`
2. `modelDLL.dll`
3. **MATLAB Runtime** (free download, ~2GB)
   - Users install from: https://www.mathworks.com/products/compiler/matlab-runtime.html
   - Or include installer with your package

**No MATLAB license required to run!**

---

## **Approach 2: Full App Compilation with Embedded Simulation**

This approach embeds the entire simulation capability in the compiled EXE.

### Step 1: Configure Compilation

```matlab
% Create compiler configuration
cfg = compiler.build.StandaloneApplicationOptions(...
    'DynamicModelGUI.m', ...
    'AdditionalFiles', {'ModelParameterParser.m', 'SimpleAdditionModel.slx'});

% Build
compiler.build.standaloneApplication(cfg);
```

### Step 2: Handle Model Loading in Compiled App

Since `sim()` won't work in compiled code, use Simulink Compiler or Rapid Accelerator:

```matlab
% In RunSimulationButtonPushed, use Rapid Accelerator mode
set_param(app.ModelName, 'SimulationMode', 'rapid-accelerator');
simOut = sim(app.ModelName);
```

### Limitations of Approach 2:
- Requires **Simulink Compiler** (additional toolbox)
- Larger deployment size
- Less flexible than DLL approach

---

## Recommended Workflow

### For Development:
```matlab
% 1. Create/modify model
app.createSimpleAdditionModel();

% 2. Test with GUI
app.testDynamicGUI();

% 3. Modify parameters, run simulations
% (Use GUI interactively)
```

### For Deployment:
```matlab
% 1. Generate code from model
slbuild('SimpleAdditionModel');

% 2. Create DLL from generated code
% (Use mex or external compiler)

% 3. Modify GUI to use DLL

% 4. Compile GUI to EXE
mcc -m DynamicModelGUI.m -a ModelParameterParser.m -a modelDLL.dll
```

## Advanced Features to Add

### 1. Support More Block Types
Extend `ModelParameterParser.m` to handle:
- Switch blocks (threshold)
- Subsystem parameters
- Lookup tables
- State machines

### 2. Configuration Profiles
Save/load parameter sets:
```matlab
% Save current config
params = app.Parser.Parameters;
save('config1.mat', 'params');

% Load config
load('config1.mat');
app.applyParameters(params);
```

### 3. Batch Simulation
Run multiple parameter combinations:
```matlab
% Define parameter sweep
param1Values = 1:10:100;
param2Values = 5:5:50;

% Run batch
results = runBatchSimulation(app, param1Values, param2Values);
```

### 4. Model Validation
Check parameter ranges before simulation:
```matlab
% Add to ModelParameterParser
params(i).MinValue = 0;
params(i).MaxValue = 100;

% Validate in GUI before running
if value < minVal || value > maxVal
    error('Parameter out of range');
end
```

## Troubleshooting

### Issue: "Model not found"
```matlab
% Add model directory to path
addpath('path/to/your/model');
```

### Issue: Code generation fails
```matlab
% Check model configuration
configSet = getActiveConfigSet(modelName);
configSet.getProp('TargetLang')  % Should be 'C'
```

### Issue: DLL loading fails in compiled app
```matlab
% Include DLL in compilation
mcc -m app.m -a myModel.dll -a myModel.h
```

### Issue: Simulation fails in compiled app
- Use Approach 1 (DLL-based) instead of Approach 2
- Ensure all model dependencies are included
- Use Rapid Accelerator mode for Simulink Compiler

## File Size Estimates

- **Model (.slx)**: ~50 KB
- **Generated C code**: ~500 KB - 2 MB
- **Model DLL**: ~100 KB - 1 MB
- **GUI EXE**: ~50-100 MB (with MATLAB Runtime)
- **MATLAB Runtime**: ~2 GB (one-time install)

## License-Free Execution Summary

| Component | License Required? | Notes |
|-----------|------------------|-------|
| Development (MATLAB) | ✅ Yes | Need MATLAB + Simulink |
| Code Generation | ✅ Yes | Need Simulink Coder |
| Compilation | ✅ Yes | Need MATLAB Compiler |
| **Running EXE** | ❌ **NO** | Only need free MATLAB Runtime |
| Distribution | ❌ **NO** | Can distribute freely* |

*Check MathWorks licensing terms for your specific use case

## Next Steps

1. ✅ Test the basic system: `app.testDynamicGUI()`
2. Create your own model with more parameters
3. Test code generation: `slbuild('YourModel')`
4. Create DLL from generated code
5. Modify GUI to use DLL
6. Compile and test standalone EXE

## Questions?

- **Can I use custom Simulink blocks?** Yes, but you'll need to extend `ModelParameterParser` to recognize them
- **Can I deploy to Linux/Mac?** Yes, MATLAB Compiler supports all platforms
- **Can I avoid MATLAB Runtime?** Not easily - it's required for compiled MATLAB apps
- **Can I sell the compiled app?** Check your MATLAB license agreement

## Example Commands Reference

```matlab
% Create model
app.createSimpleAdditionModel()

% Parse parameters
parser = app.ModelParameterParser('SimpleAdditionModel');
params = parser.getParameters();

% Launch GUI
guiApp = app.DynamicModelGUI('SimpleAdditionModel');

% Generate code
slbuild('SimpleAdditionModel');

% Compile to EXE
mcc -m DynamicModelGUI.m -a ModelParameterParser.m
```

---

**Created**: January 2026
**Version**: 1.0
**Author**: Dynamic Model GUI System
