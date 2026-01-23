%% QUICK START GUIDE
% Copy-paste these commands to get started quickly

%% ========================================================================
%% 1. ONE-TIME SETUP
%% ========================================================================

% Navigate to app1 folder
cd('C:\Users\z004f2se\OneDrive - Siemens AG\Vishal\Personal\vishal\MATLAB\app\app1')

% Add to MATLAB path
addpath(pwd)
savepath  % Optional: makes it permanent

%% ========================================================================
%% 2. QUICKEST START (30 seconds)
%% ========================================================================

% Run the basic demo
testDynamicGUI

% This will:
%   - Create SimpleAdditionModel.slx
%   - Parse parameters
%   - Launch GUI
%   - You can modify values and run simulations

%% ========================================================================
%% 3. FULL DEMO WITH DLL (3-5 minutes)
%% ========================================================================

% Prerequisites: MEX compiler configured
% Run: mex -setup  (first time only)

% Run complete workflow
demoCompleteWorkflow

% This will:
%   - Create model
%   - Test GUI (you interact, then close)
%   - Compile to DLL
%   - Show deployment instructions

%% ========================================================================
%% 4. STEP-BY-STEP (If you want control)
%% ========================================================================

% Step 1: Create model
createSimpleAdditionModel

% Step 2: Test parser
parser = ModelParameterParser('SimpleAdditionModel');
params = parser.getParameters();
parser.printParameters()

% Step 3: Launch GUI
guiApp = DynamicModelGUI('SimpleAdditionModel');

% Step 4: Compile to DLL (requires Simulink Coder)
[dllPath, headerPath] = autoCompileModelToDLL('SimpleAdditionModel');

% Step 5: Test DLL
test_SimpleAdditionModel_dll

%% ========================================================================
%% 5. USE WITH YOUR OWN MODEL
%% ========================================================================

% Make sure your model is on the path
addpath('path/to/your/model')

% Launch GUI with your model
guiApp = DynamicModelGUI('YourModelName');

% Or compile your model to DLL
[dll, hdr] = autoCompileModelToDLL('YourModelName');

%% ========================================================================
%% 6. CREATE STANDALONE EXE (Requires MATLAB Compiler)
%% ========================================================================

% After creating DLL, run in command window or terminal:
% mcc -m DynamicModelGUI.m -a ModelParameterParser.m -a SimpleAdditionModel_dll.mexw64

%% ========================================================================
%% TROUBLESHOOTING
%% ========================================================================

% If "function not found":
addpath('C:\Users\z004f2se\OneDrive - Siemens AG\Vishal\Personal\vishal\MATLAB\app\app1')

% If "MEX compiler not configured":
mex -setup

% If "model not found":
addpath('path/to/model/folder')

%% ========================================================================
%% WHAT TO RUN FIRST?
%% ========================================================================

% ► Absolute beginner? Run this:
testDynamicGUI

% ► Want to see everything? Run this:
demoCompleteWorkflow

% ► Have your own model? Run this:
DynamicModelGUI('YourModelName')

%% ========================================================================
%% QUICK REFERENCE
%% ========================================================================

% Function                          | Purpose
% ----------------------------------|------------------------------------------
% testDynamicGUI                    | Quick test (start here!)
% demoCompleteWorkflow             | Full demo with DLL
% createSimpleAdditionModel        | Create demo model
% ModelParameterParser             | Class to parse models
% DynamicModelGUI                  | Main GUI class
% autoCompileModelToDLL            | Automated DLL compilation
% createModelAndCompileToDLL       | Manual code generation

%% ========================================================================
