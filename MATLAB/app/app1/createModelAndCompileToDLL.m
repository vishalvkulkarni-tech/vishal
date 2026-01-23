function createModelAndCompileToDLL(modelName)
% createModelAndCompileToDLL - Helper script for code generation and DLL creation
%
% This script automates the process of:
% 1. Configuring a Simulink model for code generation
% 2. Generating C code using Simulink Coder
% 3. Compiling the generated code into a DLL
%
% Usage:
%   createModelAndCompileToDLL('SimpleAdditionModel')
%
% Requirements:
%   - Simulink Coder
%   - C/C++ compiler (run 'mex -setup' to configure)

    if nargin < 1
        modelName = 'SimpleAdditionModel';
    end
    
    fprintf('=== Model Code Generation and DLL Compilation ===\n\n');
    
    %% Step 1: Verify model exists
    fprintf('Step 1: Verifying model "%s"...\n', modelName);
    modelPath = which(modelName);
    if isempty(modelPath)
        error('Model "%s" not found on MATLAB path', modelName);
    end
    fprintf('   Found: %s\n', modelPath);
    
    %% Step 2: Load model
    fprintf('\nStep 2: Loading model...\n');
    wasLoaded = bdIsLoaded(modelName);
    if ~wasLoaded
        load_system(modelName);
    end
    
    %% Step 3: Configure model for code generation
    fprintf('\nStep 3: Configuring model for code generation...\n');
    
    % Get configuration set
    configSet = getActiveConfigSet(modelName);
    
    % Set code generation target
    set_param(modelName, 'SystemTargetFile', 'ert.tlc');
    fprintf('   Target: Embedded Coder (ert.tlc)\n');
    
    % Set language to C
    set_param(modelName, 'TargetLang', 'C');
    fprintf('   Language: C\n');
    
    % Set solver for code generation
    set_param(modelName, 'SolverType', 'Fixed-step');
    set_param(modelName, 'Solver', 'FixedStepDiscrete');
    fprintf('   Solver: Fixed-step discrete\n');
    
    % Configure code generation options
    set_param(modelName, 'GenerateReport', 'on');
    set_param(modelName, 'LaunchReport', 'off');
    set_param(modelName, 'CodeInterfacePackaging', 'Nonreusable function');
    
    % Save configuration
    save_system(modelName);
    fprintf('   Configuration saved\n');
    
    %% Step 4: Generate code
    fprintf('\nStep 4: Generating code...\n');
    fprintf('   This may take a minute...\n');
    
    try
        % Build the model
        slbuild(modelName);
        fprintf('   ✓ Code generation successful!\n');
    catch ME
        fprintf('   ✗ Code generation failed: %s\n', ME.message);
        if ~wasLoaded
            close_system(modelName, 0);
        end
        rethrow(ME);
    end
    
    % Find generated code directory
    codeDir = fullfile(pwd, ['slprj/ert/' modelName]);
    if ~exist(codeDir, 'dir')
        codeDir = fullfile(pwd, modelName, '_ert_rtw');
    end
    
    if exist(codeDir, 'dir')
        fprintf('   Generated code location: %s\n', codeDir);
    else
        warning('Cannot locate generated code directory');
    end
    
    %% Step 5: Information about DLL creation
    fprintf('\n=== Next Steps for DLL Creation ===\n');
    fprintf('\nThe C code has been generated. To create a DLL:\n\n');
    
    fprintf('OPTION 1: Using MATLAB MEX (Recommended)\n');
    fprintf('----------------------------------------\n');
    fprintf('1. Navigate to the generated code directory:\n');
    fprintf('   cd(''%s'')\n\n', codeDir);
    fprintf('2. Compile using MEX:\n');
    fprintf('   mex -v -output %s_dll ...\n', modelName);
    fprintf('       %s.c ...\n', modelName);
    fprintf('       rtGetInf.c rtGetNaN.c rt_nonfinite.c\n\n');
    
    fprintf('OPTION 2: Using External Compiler (Visual Studio/MinGW)\n');
    fprintf('-------------------------------------------------------\n');
    fprintf('1. Open command prompt in: %s\n', codeDir);
    fprintf('2. Compile with your C compiler:\n');
    fprintf('   gcc -shared -o %s.dll %s.c rtGetInf.c rtGetNaN.c rt_nonfinite.c\n\n', ...
        modelName, modelName);
    
    fprintf('OPTION 3: Create Simulink S-Function DLL\n');
    fprintf('----------------------------------------\n');
    fprintf('Use legacy_code() tool to wrap generated code\n\n');
    
    %% Step 6: Generate wrapper script
    fprintf('Step 5: Creating wrapper script...\n');
    
    wrapperFile = sprintf('%s_wrapper.m', modelName);
    fid = fopen(wrapperFile, 'w');
    
    fprintf(fid, 'function output = %s_wrapper(input1, input2, stopTime)\n', modelName);
    fprintf(fid, '%% Wrapper function for %s DLL\n', modelName);
    fprintf(fid, '%% This is a template - modify based on your model''s I/O\n\n');
    fprintf(fid, 'if nargin < 3\n');
    fprintf(fid, '    stopTime = 1.0;\n');
    fprintf(fid, 'end\n\n');
    fprintf(fid, '%% Load DLL if not already loaded\n');
    fprintf(fid, 'dllName = ''%s_dll'';\n', modelName);
    fprintf(fid, 'if ~libisloaded(dllName)\n');
    fprintf(fid, '    loadlibrary(dllName, ''%s.h'');\n', modelName);
    fprintf(fid, 'end\n\n');
    fprintf(fid, '%% Initialize model\n');
    fprintf(fid, 'calllib(dllName, ''%s_initialize'');\n\n', modelName);
    fprintf(fid, '%% Run simulation\n');
    fprintf(fid, 'numSteps = floor(stopTime / 0.01); %% Assumes 0.01 step size\n');
    fprintf(fid, 'output = zeros(numSteps, 1);\n\n');
    fprintf(fid, 'for i = 1:numSteps\n');
    fprintf(fid, '    %% Step the model (modify based on your model''s interface)\n');
    fprintf(fid, '    calllib(dllName, ''%s_step'');\n', modelName);
    fprintf(fid, '    %% Get output (you''ll need to modify this)\n');
    fprintf(fid, '    output(i) = input1 + input2; %% Placeholder\n');
    fprintf(fid, 'end\n\n');
    fprintf(fid, '%% Terminate model\n');
    fprintf(fid, 'calllib(dllName, ''%s_terminate'');\n\n', modelName);
    fprintf(fid, 'end\n');
    
    fclose(fid);
    fprintf('   Created: %s\n', wrapperFile);
    
    %% Summary
    fprintf('\n=== Summary ===\n');
    fprintf('✓ Model configured for code generation\n');
    fprintf('✓ C code generated successfully\n');
    fprintf('✓ Wrapper template created\n\n');
    fprintf('Next: Compile the DLL using one of the options above\n');
    fprintf('Then modify DynamicModelGUI.m to use the DLL instead of sim()\n');
    
    % Close model if we opened it
    if ~wasLoaded
        close_system(modelName, 0);
    end
end
