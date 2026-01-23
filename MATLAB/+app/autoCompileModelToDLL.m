function [dllPath, headerPath] = autoCompileModelToDLL(modelName, varargin)
% autoCompileModelToDLL - Fully automated model to DLL compilation
%
% This script completely automates:
% 1. Configuring Simulink model for code generation
% 2. Generating C code using Simulink Coder
% 3. Compiling generated code into a DLL using MEX
% 4. Creating wrapper functions for easy DLL usage
%
% Syntax:
%   [dllPath, headerPath] = autoCompileModelToDLL(modelName)
%   [dllPath, headerPath] = autoCompileModelToDLL(modelName, 'OutputDir', dirPath)
%
% Inputs:
%   modelName - Name of Simulink model (without .slx extension)
%   'OutputDir' - Optional output directory for DLL (default: current dir)
%
% Outputs:
%   dllPath - Full path to generated DLL file
%   headerPath - Full path to generated header file
%
% Example:
%   [dll, hdr] = autoCompileModelToDLL('SimpleAdditionModel');
%
% Requirements:
%   - Simulink Coder
%   - MEX compiler configured (run 'mex -setup' first time)

    %% Parse inputs
    p = inputParser;
    addRequired(p, 'modelName', @ischar);
    addParameter(p, 'OutputDir', pwd, @ischar);
    addParameter(p, 'Verbose', true, @islogical);
    parse(p, modelName, varargin{:});
    
    outputDir = p.Results.OutputDir;
    verbose = p.Results.Verbose;
    
    if verbose
        fprintf('\n');
        fprintf('╔════════════════════════════════════════════════════════╗\n');
        fprintf('║   Automated Model → DLL Compilation                  ║\n');
        fprintf('╚════════════════════════════════════════════════════════╝\n\n');
    end
    
    %% Step 1: Verify prerequisites
    if verbose, fprintf('Step 1: Verifying prerequisites...\n'); end
    
    % Check model exists
    modelPath = which(modelName);
    if isempty(modelPath)
        error('Model "%s" not found on MATLAB path', modelName);
    end
    if verbose, fprintf('   ✓ Model found: %s\n', modelPath); end
    
    % Check for MEX compiler
    try
        cc = mex.getCompilerConfigurations('C', 'Selected');
        if isempty(cc)
            error('No MEX compiler configured. Run: mex -setup');
        end
        if verbose, fprintf('   ✓ MEX compiler: %s\n', cc.Name); end
    catch
        error('MEX compiler not configured. Run: mex -setup');
    end
    
    % Check for Simulink Coder
    if ~license('test', 'Simulink_Coder') && ~license('test', 'Real-Time_Workshop')
        warning('Simulink Coder license not available. Code generation may fail.');
    end
    
    %% Step 2: Load and configure model
    if verbose, fprintf('\nStep 2: Configuring model for code generation...\n'); end
    
    wasLoaded = bdIsLoaded(modelName);
    if ~wasLoaded
        load_system(modelName);
    end
    
    try
        % Configure for embedded code generation
        set_param(modelName, 'SystemTargetFile', 'ert.tlc');
        set_param(modelName, 'TargetLang', 'C');
        set_param(modelName, 'GenerateSampleERTMain', 'off');
        set_param(modelName, 'GenerateReport', 'off');
        set_param(modelName, 'LaunchReport', 'off');
        
        % Solver configuration
        set_param(modelName, 'SolverType', 'Fixed-step');
        set_param(modelName, 'Solver', 'FixedStepDiscrete');
        set_param(modelName, 'FixedStep', '0.01');
        
        % Code generation options
        set_param(modelName, 'CodeInterfacePackaging', 'Nonreusable function');
        set_param(modelName, 'GenerateAllocFcn', 'off');
        set_param(modelName, 'IncludeMdlTerminateFcn', 'on');
        set_param(modelName, 'CombineOutputUpdateFcns', 'on');
        set_param(modelName, 'SupportNonFinite', 'on');
        
        % Optimization
        set_param(modelName, 'OptimizationLevel', 'Level2');
        set_param(modelName, 'OptimizationPriority', 'Speed');
        
        save_system(modelName);
        
        if verbose, fprintf('   ✓ Model configured\n'); end
        
    catch ME
        if ~wasLoaded, close_system(modelName, 0); end
        error('Failed to configure model: %s', ME.message);
    end
    
    %% Step 3: Generate code
    if verbose
        fprintf('\nStep 3: Generating C code...\n');
        fprintf('   (This may take 30-60 seconds...)\n');
    end
    
    try
        % Clear any previous build
        slbuild(modelName, 'ClearMex', 'on');
        
        % Generate code
        slbuild(modelName);
        
        if verbose, fprintf('   ✓ Code generation complete\n'); end
        
    catch ME
        if ~wasLoaded, close_system(modelName, 0); end
        error('Code generation failed: %s', ME.message);
    end
    
    %% Step 4: Locate generated files
    if verbose, fprintf('\nStep 4: Locating generated files...\n'); end
    
    % Find code generation directory
    codeDir = fullfile(pwd, 'slprj', 'ert', modelName);
    if ~exist(codeDir, 'dir')
        codeDir = fullfile(pwd, [modelName '_ert_rtw']);
    end
    
    if ~exist(codeDir, 'dir')
        error('Cannot find generated code directory');
    end
    
    if verbose, fprintf('   ✓ Code directory: %s\n', codeDir); end
    
    % Find source files
    mainCFile = fullfile(codeDir, [modelName '.c']);
    mainHFile = fullfile(codeDir, [modelName '.h']);
    
    if ~exist(mainCFile, 'file')
        error('Main C file not found: %s', mainCFile);
    end
    
    % Find all C files to compile
    cFiles = dir(fullfile(codeDir, '*.c'));
    cFilePaths = {};
    for i = 1:length(cFiles)
        cFilePaths{end+1} = fullfile(codeDir, cFiles(i).name);
    end
    
    if verbose
        fprintf('   ✓ Found %d C source files\n', length(cFilePaths));
    end
    
    %% Step 5: Compile to DLL
    if verbose
        fprintf('\nStep 5: Compiling DLL...\n');
        fprintf('   (This may take 30-60 seconds...)\n');
    end
    
    % Create output directory if needed
    if ~exist(outputDir, 'dir')
        mkdir(outputDir);
    end
    
    % DLL output path
    dllName = [modelName '_dll'];
    dllPath = fullfile(outputDir, [dllName '.' mexext]);
    
    % Build MEX command
    mexCmd = {'-v', '-shared'};  % Verbose and shared library
    mexCmd{end+1} = '-output';
    mexCmd{end+1} = fullfile(outputDir, dllName);
    
    % Add all C files
    mexCmd = [mexCmd, cFilePaths];
    
    % Add include directory
    mexCmd{end+1} = ['-I' codeDir];
    
    % Add definitions
    mexCmd{end+1} = ['-DMODEL=' modelName];
    mexCmd{end+1} = '-DMT=0';  % Single-threaded
    
    try
        % Change to code directory for compilation
        oldDir = pwd;
        cd(codeDir);
        
        % Compile
        if verbose
            mex(mexCmd{:});
        else
            evalc('mex(mexCmd{:})');  % Suppress output
        end
        
        cd(oldDir);
        
        if verbose, fprintf('   ✓ DLL compiled successfully\n'); end
        
    catch ME
        cd(oldDir);
        if ~wasLoaded, close_system(modelName, 0); end
        error('MEX compilation failed: %s', ME.message);
    end
    
    %% Step 6: Copy header file
    if verbose, fprintf('\nStep 6: Copying header file...\n'); end
    
    headerPath = fullfile(outputDir, [modelName '.h']);
    copyfile(mainHFile, headerPath);
    
    if verbose, fprintf('   ✓ Header copied: %s\n', headerPath); end
    
    %% Step 7: Create wrapper function
    if verbose, fprintf('\nStep 7: Creating wrapper function...\n'); end
    
    createDLLWrapper(modelName, dllPath, headerPath, outputDir);
    
    if verbose, fprintf('   ✓ Wrapper created\n'); end
    
    %% Step 8: Create test script
    if verbose, fprintf('\nStep 8: Creating test script...\n'); end
    
    createDLLTestScript(modelName, outputDir);
    
    if verbose, fprintf('   ✓ Test script created\n'); end
    
    %% Cleanup
    if ~wasLoaded
        close_system(modelName, 0);
    end
    
    %% Summary
    if verbose
        fprintf('\n');
        fprintf('╔════════════════════════════════════════════════════════╗\n');
        fprintf('║   SUCCESS - DLL Compilation Complete!                ║\n');
        fprintf('╚════════════════════════════════════════════════════════╝\n\n');
        fprintf('Generated files:\n');
        fprintf('  📦 DLL:     %s\n', dllPath);
        fprintf('  📄 Header:  %s\n', headerPath);
        fprintf('  📝 Wrapper: %s\n', fullfile(outputDir, [modelName '_wrapper.m']));
        fprintf('  🧪 Test:    %s\n', fullfile(outputDir, ['test_' modelName '_dll.m']));
        fprintf('\nNext steps:\n');
        fprintf('  1. Test DLL: run %s\n', ['test_' modelName '_dll']);
        fprintf('  2. Use in GUI: Update DynamicModelGUI to call wrapper\n');
        fprintf('  3. Compile GUI: mcc -m DynamicModelGUI.m -a %s\n', dllPath);
        fprintf('\n');
    end
end

%% Helper function to create wrapper
function createDLLWrapper(modelName, dllPath, headerPath, outputDir)
    wrapperFile = fullfile(outputDir, [modelName '_wrapper.m']);
    fid = fopen(wrapperFile, 'w');
    
    fprintf(fid, 'function [output, time] = %s_wrapper(varargin)\n', modelName);
    fprintf(fid, '%% %s_wrapper - Wrapper for %s DLL\n', modelName, modelName);
    fprintf(fid, '%%\n');
    fprintf(fid, '%% This function loads and executes the compiled DLL\n');
    fprintf(fid, '%% Auto-generated by autoCompileModelToDLL\n');
    fprintf(fid, '%%\n');
    fprintf(fid, '%% Usage:\n');
    fprintf(fid, '%%   [output, time] = %s_wrapper()\n', modelName);
    fprintf(fid, '%%   [output, time] = %s_wrapper(''StopTime'', 1.0)\n', modelName);
    fprintf(fid, '%%   [output, time] = %s_wrapper(''StepSize'', 0.01, ''StopTime'', 2.0)\n\n', modelName);
    
    fprintf(fid, '    %% Parse inputs\n');
    fprintf(fid, '    p = inputParser;\n');
    fprintf(fid, '    addParameter(p, ''StopTime'', 1.0, @isnumeric);\n');
    fprintf(fid, '    addParameter(p, ''StepSize'', 0.01, @isnumeric);\n');
    fprintf(fid, '    parse(p, varargin{:});\n\n');
    
    fprintf(fid, '    stopTime = p.Results.StopTime;\n');
    fprintf(fid, '    stepSize = p.Results.StepSize;\n\n');
    
    fprintf(fid, '    %% Load DLL if not already loaded\n');
    fprintf(fid, '    dllName = ''%s'';\n', modelName);
    fprintf(fid, '    dllPath = ''%s'';\n', strrep(dllPath, '\', '\\'));
    fprintf(fid, '    headerPath = ''%s'';\n\n', strrep(headerPath, '\', '\\'));
    
    fprintf(fid, '    if ~libisloaded(dllName)\n');
    fprintf(fid, '        try\n');
    fprintf(fid, '            loadlibrary(dllPath, headerPath);\n');
    fprintf(fid, '            fprintf(''DLL loaded successfully\\n'');\n');
    fprintf(fid, '        catch ME\n');
    fprintf(fid, '            error(''Failed to load DLL: %%s'', ME.message);\n');
    fprintf(fid, '        end\n');
    fprintf(fid, '    end\n\n');
    
    fprintf(fid, '    %% Initialize model\n');
    fprintf(fid, '    calllib(dllName, ''%s_initialize'');\n\n', modelName);
    
    fprintf(fid, '    %% Run simulation\n');
    fprintf(fid, '    numSteps = floor(stopTime / stepSize);\n');
    fprintf(fid, '    time = (0:numSteps-1) * stepSize;\n');
    fprintf(fid, '    output = zeros(numSteps, 1);\n\n');
    
    fprintf(fid, '    for i = 1:numSteps\n');
    fprintf(fid, '        %% Step the model\n');
    fprintf(fid, '        calllib(dllName, ''%s_step'');\n', modelName);
    fprintf(fid, '        \n');
    fprintf(fid, '        %% TODO: Extract output values\n');
    fprintf(fid, '        %% You need to access the model''s output structure\n');
    fprintf(fid, '        %% Example: output(i) = calllib(dllName, ''get_output'');\n');
    fprintf(fid, '        output(i) = i * stepSize; %% Placeholder\n');
    fprintf(fid, '    end\n\n');
    
    fprintf(fid, '    %% Terminate model\n');
    fprintf(fid, '    calllib(dllName, ''%s_terminate'');\n\n', modelName);
    
    fprintf(fid, 'end\n');
    fclose(fid);
end

%% Helper function to create test script
function createDLLTestScript(modelName, outputDir)
    testFile = fullfile(outputDir, ['test_' modelName '_dll.m']);
    fid = fopen(testFile, 'w');
    
    fprintf(fid, '%% Test script for %s DLL\n', modelName);
    fprintf(fid, '%% Auto-generated by autoCompileModelToDLL\n\n');
    
    fprintf(fid, 'fprintf(''Testing %s DLL...\\n'');\n\n', modelName);
    
    fprintf(fid, '%% Test 1: Basic execution\n');
    fprintf(fid, 'try\n');
    fprintf(fid, '    [output, time] = %s_wrapper();\n', modelName);
    fprintf(fid, '    fprintf(''✓ DLL executed successfully\\n'');\n');
    fprintf(fid, '    fprintf(''  Simulation time: %%.2f seconds\\n'', time(end));\n');
    fprintf(fid, '    fprintf(''  Output samples: %%d\\n'', length(output));\n');
    fprintf(fid, 'catch ME\n');
    fprintf(fid, '    fprintf(''✗ DLL execution failed: %%s\\n'', ME.message);\n');
    fprintf(fid, 'end\n\n');
    
    fprintf(fid, '%% Test 2: Plot results\n');
    fprintf(fid, 'figure(''Name'', ''%s DLL Test'');\n', modelName);
    fprintf(fid, 'plot(time, output);\n');
    fprintf(fid, 'grid on;\n');
    fprintf(fid, 'xlabel(''Time (s)'');\n');
    fprintf(fid, 'ylabel(''Output'');\n');
    fprintf(fid, 'title(''%s DLL Simulation Output'');\n\n', modelName);
    
    fprintf(fid, 'fprintf(''Test complete!\\n'');\n');
    
    fclose(fid);
end
