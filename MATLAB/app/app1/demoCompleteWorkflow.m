%% Complete End-to-End Demo: Model → GUI → DLL → EXE
% This script demonstrates the complete workflow from creating a model
% to generating a standalone executable

%% ========================================================================
%% PART 1: Create Model and Test with GUI
%% ========================================================================

fprintf('\n╔════════════════════════════════════════════════════════╗\n');
fprintf('║  PART 1: Model Creation & GUI Testing                ║\n');
fprintf('╚════════════════════════════════════════════════════════╝\n\n');

% Step 1: Create the model
fprintf('Step 1: Creating Simulink model...\n');
createSimpleAdditionModel();

% Step 2: Test parameter parsing
fprintf('\nStep 2: Parsing model parameters...\n');
parser = ModelParameterParser('SimpleAdditionModel');
params = parser.getParameters();
fprintf('Found %d parameters\n', length(params));

% Step 3: Launch GUI (interactive)
fprintf('\nStep 3: Launching GUI for testing...\n');
fprintf('▶ Try modifying parameters and running simulation\n');
fprintf('▶ Close the GUI window when done to continue...\n\n');

guiApp = DynamicModelGUI('SimpleAdditionModel');
waitfor(guiApp.UIFigure);  % Wait for user to close GUI

%% ========================================================================
%% PART 2: Automated DLL Compilation
%% ========================================================================

fprintf('\n╔════════════════════════════════════════════════════════╗\n');
fprintf('║  PART 2: Automated DLL Compilation                   ║\n');
fprintf('╚════════════════════════════════════════════════════════╝\n\n');

% Check prerequisites
fprintf('Checking prerequisites...\n');

% Check MEX compiler
try
    cc = mex.getCompilerConfigurations('C', 'Selected');
    if isempty(cc)
        fprintf('⚠ No MEX compiler configured.\n');
        fprintf('  Run: mex -setup\n');
        fprintf('  Then restart this demo.\n');
        return;
    else
        fprintf('✓ MEX compiler: %s\n', cc.Name);
    end
catch
    fprintf('⚠ MEX compiler not available.\n');
    fprintf('  Run: mex -setup\n');
    return;
end

% Check for Simulink Coder
if ~license('test', 'Simulink_Coder') && ~license('test', 'Real-Time_Workshop')
    fprintf('⚠ Simulink Coder not available.\n');
    fprintf('  DLL compilation requires Simulink Coder.\n');
    fprintf('  Skipping DLL compilation...\n');
    skipDLL = true;
else
    fprintf('✓ Simulink Coder available\n');
    skipDLL = false;
end

if ~skipDLL
    fprintf('\nCompiling model to DLL...\n');
    fprintf('(This will take 1-2 minutes)\n\n');
    
    try
        [dllPath, headerPath] = autoCompileModelToDLL('SimpleAdditionModel');
        
        fprintf('\n✓ DLL compilation successful!\n');
        fprintf('  DLL: %s\n', dllPath);
        
        % Test the DLL
        fprintf('\nTesting DLL...\n');
        test_SimpleAdditionModel_dll;
        
    catch ME
        fprintf('✗ DLL compilation failed: %s\n', ME.message);
        fprintf('  You can still use the GUI with sim() instead of DLL\n');
    end
end

%% ========================================================================
%% PART 3: Compilation Instructions for Standalone EXE
%% ========================================================================

fprintf('\n╔════════════════════════════════════════════════════════╗\n');
fprintf('║  PART 3: Create Standalone EXE (Manual Step)         ║\n');
fprintf('╚════════════════════════════════════════════════════════╝\n\n');

fprintf('To create a standalone executable:\n\n');

fprintf('METHOD 1: Using GUI with DLL (No MATLAB license needed for execution)\n');
fprintf('-------------------------------------------------------------------\n');
if ~skipDLL
    fprintf('cd(''%s'')\n', pwd);
    fprintf('mcc -m DynamicModelGUI.m ...\n');
    fprintf('    -a ModelParameterParser.m ...\n');
    fprintf('    -a SimpleAdditionModel_dll.%s ...\n', mexext);
    fprintf('    -a SimpleAdditionModel.h\n\n');
else
    fprintf('(Requires Simulink Coder - not available)\n\n');
end

fprintf('METHOD 2: Using GUI with Simulink Compiler\n');
fprintf('-------------------------------------------\n');
fprintf('cd(''%s'')\n', pwd);
fprintf('mcc -m DynamicModelGUI.m ...\n');
fprintf('    -a ModelParameterParser.m ...\n');
fprintf('    -a SimpleAdditionModel.slx\n');
fprintf('(Requires Simulink Compiler)\n\n');

fprintf('After compilation:\n');
fprintf('  1. Install MATLAB Runtime on target machine (free)\n');
fprintf('  2. Run DynamicModelGUI.exe\n');
fprintf('  3. No MATLAB license needed!\n\n');

%% ========================================================================
%% Summary
%% ========================================================================

fprintf('╔════════════════════════════════════════════════════════╗\n');
fprintf('║  Demo Complete!                                       ║\n');
fprintf('╚════════════════════════════════════════════════════════╝\n\n');

fprintf('What you have now:\n');
fprintf('  ✓ Simulink model: SimpleAdditionModel.slx\n');
fprintf('  ✓ Parameter parser: ModelParameterParser.m\n');
fprintf('  ✓ Dynamic GUI: DynamicModelGUI.m\n');

if ~skipDLL
    fprintf('  ✓ Compiled DLL: SimpleAdditionModel_dll.%s\n', mexext);
    fprintf('  ✓ DLL wrapper: SimpleAdditionModel_wrapper.m\n');
    fprintf('  ✓ DLL test: test_SimpleAdditionModel_dll.m\n');
end

fprintf('\nNext steps:\n');
fprintf('  1. Test with your own Simulink models\n');
fprintf('  2. Extend ModelParameterParser for more block types\n');
fprintf('  3. Create standalone EXE using mcc (see above)\n');
fprintf('  4. Deploy without MATLAB license!\n\n');

fprintf('Questions? See README.md and README_Deployment.md\n\n');
