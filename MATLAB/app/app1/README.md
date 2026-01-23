# Dynamic Model GUI System - Quick Start Guide

## 🎯 What You Get

A complete system that:
1. ✅ Reads any Simulink model and extracts parameters automatically
2. ✅ Creates a GUI dynamically with controls for each parameter
3. ✅ Runs simulations with modified parameters
4. ✅ Can be compiled to a standalone EXE (no MATLAB license needed to run)

## 📁 Files Created

| File | Description |
|------|-------------|
| `createSimpleAdditionModel.m` | Creates demo model (Param1 + Param2) |
| `ModelParameterParser.m` | Class that reads models and extracts parameters |
| `DynamicModelGUI.m` | Main GUI application |
| `testDynamicGUI.m` | Demo script to test everything |
| `createModelAndCompileToDLL.m` | Helper for code generation |
| `README_Deployment.md` | Full deployment documentation |

## 🚀 Getting Started (3 Steps)

### Prerequisites

```matlab
% Add the app1 folder to your MATLAB path
addpath('path/to/your/MATLAB/app/app1');
```

### Step 1: Test the System

```matlab
% Run this in MATLAB
testDynamicGUI
```

This will:
- Create a simple Simulink model
- Parse its parameters
- Launch the GUI

### Step 2: Try the GUI

In the GUI window:
1. Change `Param1_Value` to `100`
2. Change `Param2_Value` to `50`
3. Click **"Run Simulation"**
4. See the result: 150!

### Step 3: Try Your Own Model

```matlab
% Load any Simulink model
guiApp = DynamicModelGUI('YourModelName');
```

## 🔧 What Parameters Are Supported?

Currently extracts:
- ✅ **Constant blocks**: Value, DataType, SampleTime
- ✅ **Gain blocks**: Gain value
- 🔄 **Extensible**: Easy to add more block types

## 📦 Standalone Deployment (No License Needed)

### ⚡ **FULLY AUTOMATED DLL Creation**

```matlab
% One command to generate C code AND compile to DLL!
[dllPath, headerPath] = autoCompileModelToDLL('SimpleAdditionModel');
```

This automatically:
- ✅ Configures model for code generation
- ✅ Generates C code with Simulink Coder
- ✅ Compiles DLL using MEX
- ✅ Creates wrapper function for easy DLL usage
- ✅ Creates test script

### Quick Path to EXE:

**Option A: Fully Automated (Recommended)**
```matlab
% 1. One command creates DLL automatically
[dll, hdr] = autoCompileModelToDLL('SimpleAdditionModel');

% 2. Test the DLL
test_SimpleAdditionModel_dll

% 3. Compile GUI to EXE
mcc -m DynamicModelGUI.m -a ModelParameterParser.m -a SimpleAdditionModel_dll.mexw64
```

**Option B: Manual Steps**
```matlab
% 1. Generate code only (you compile DLL manually)
createModelAndCompileToDLL('SimpleAdditionModel')

% 2. Follow instructions to compile DLL
% 3. Compile GUI
mcc -m DynamicModelGUI.m -a ModelParameterParser.m
```

**Distribute:**
   - `DynamicModelGUI.exe`
   - `YourModel_dll.mexw64` (the compiled DLL)
   - MATLAB Runtime (free, 2GB download)
   
**Users don't need MATLAB license!**

See [README_Deployment.md](README_Deployment.md) for full details.

## 🎓 How It Works

```
┌─────────────┐
│ Simulink    │
│ Model (.slx)│
└──────┬──────┘
       │
       ▼
┌─────────────────────┐
│ ModelParameterParser│  ← Reads model, extracts parameters
└──────┬──────────────┘
       │
       ▼
┌─────────────────┐
│ DynamicModelGUI │  ← Creates UI controls dynamically
└──────┬──────────┘
       │
       ▼
┌──────────────┐
│ Run sim() or │  ← Simulates with modified parameters
│ Call DLL     │
└──────────────┘
```

## 🔍 Example: Adding Support for Switch Blocks

Want to extract Switch block threshold parameter? Edit `ModelParameterParser.m`:

```matlab
% In getParameters() method, add:
switchBlocks = find_system(obj.ModelName, 'BlockType', 'Switch');

for i = 1:length(switchBlocks)
    blockPath = switchBlocks{i};
    blockName = get_param(blockPath, 'Name');
    
    params(paramIdx).BlockPath = blockPath;
    params(paramIdx).BlockName = blockName;
    params(paramIdx).ParameterName = [blockName '_Threshold'];
    params(paramIdx).ParameterType = 'numeric';
    params(paramIdx).CurrentValue = get_param(blockPath, 'Threshold');
    params(paramIdx).Description = 'Switch threshold';
    paramIdx = paramIdx + 1;
end
```

## ⚠️ Requirements

### For Development:
- MATLAB (R2020b or later recommended)
- Simulink

### For Deployment:
- MATLAB Compiler (to create EXE)
- Simulink Coder (to generate C code from model)
- C/C++ Compiler (for DLL creation)

### For Running EXE (End Users):
- **Just MATLAB Runtime** (free download, no license)

## 🐛 Common Issues

**"Model not found"**
```matlab
addpath('path/to/your/model');
```

**"Functions not found"**
```matlab
% Make sure the app1 folder is on your MATLAB path
addpath('path/to/your/MATLAB/app/app1');
```

**GUI doesn't show parameters**
- Check that your model has Constant or Gain blocks
- Call `parser.printParameters()` to debug

## 📚 Learn More

- **Full Deployment Guide**: [README_Deployment.md](README_Deployment.md)
- **Test Script**: Run `testDynamicGUI` to see everything in action

## 💡 Next Steps

1. ✅ Run `testDynamicGUI` - **Start here!**
2. Create your own model with parameters
3. Use the GUI to simulate with different values
4. Follow deployment guide to create standalone EXE
5. Extend to support more block types

## ❓ Can This Work?

**Yes!** This approach is used in real-world applications:

✅ **Parameter tuning tools** - Modify and test parameters without touching Simulink  
✅ **HIL testing** - Hardware-in-the-loop with standalone executables  
✅ **Customer deliveries** - Provide simulation tools without MATLAB licenses  
✅ **CI/CD pipelines** - Automated testing with parameter variations  

The key is using **Simulink Coder** to generate C code (DLL) and **MATLAB Compiler** to create the EXE, both of which can run on **MATLAB Runtime** (free).

---

**Ready to start?** Run:
```matlab
testDynamicGUI
```
