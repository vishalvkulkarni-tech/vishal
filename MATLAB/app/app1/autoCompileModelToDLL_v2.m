function [dllPath, headerPath] = autoCompileModelToDLL_v2(modelName, varargin)
% autoCompileModelToDLL_v2 - Simplified model preparation (no MEX to avoid crashes)
%
% This creates a MATLAB wrapper instead of trying to compile MEX DLL
% The wrapper can be compiled to EXE with mcc
%
% Syntax:
%   [wrapperPath, headerPath] = autoCompileModelToDLL_v2(modelName)
%
% Outputs:
%   wrapperPath - MATLAB wrapper function that runs the model
%   headerPath - Generated header file

    %% Parse inputs
    p = inputParser;
    addRequired(p, 'modelName', @ischar);
    addParameter(p, 'OutputDir', pwd, @ischar);
    addParameter(p, 'Verbose', true, @islogical);
    parse(p, modelName, varargin{:});
    
    outputDir = p.Results.OutputDir;
    verbose = p.Results.Verbose;
    
    if verbose
        fprintf('\n=== Automated Model Preparation ===\n\n');
    end
    
    %% Step 1: Verify model exists
    if verbose, fprintf('Step 1: Checking model...\n'); end
    
    modelPath = which(modelName);
    if isempty(modelPath)
        error('Model "%s" not found', modelName);
    end
    if verbose, fprintf('   ✓ Found: %s\n', modelPath); end
    
    %% Step 2: Configure model
    if verbose, fprintf('\nStep 2: Configuring model...\n'); end
    
    wasLoaded = bdIsLoaded(modelName);
    if ~wasLoaded
        load_system(modelName);
    end
    
    try
        set_param(modelName, 'SystemTargetFile', 'ert.tlc');
        set_param(modelName, 'TargetLang', 'C');
        set_param(modelName, 'SolverType', 'Fixed-step');
        set_param(modelName, 'Solver', 'FixedStepDiscrete');
        set_param(modelName, 'FixedStep', '0.01');
        save_system(modelName);
        
        if verbose, fprintf('   ✓ Configured\n'); end
    catch ME
        if ~wasLoaded, close_system(modelName, 0); end
        error('Configuration failed: %s', ME.message);
    end
    
    %% Step 3: Generate code
    if verbose, fprintf('\nStep 3: Generating code...\n'); end
    
    try
        set_param(modelName, 'Description', ['Generated: ' datestr(now)]);
        save_system(modelName);
        evalc('rtwbuild(modelName)');
        if verbose, fprintf('   ✓ Code generated\n'); end
    catch ME
        if ~wasLoaded, close_system(modelName, 0); end
        error('Code generation failed: %s', ME.message);
    end
    
    %% Step 4: Find generated files
    if verbose, fprintf('\nStep 4: Locating files...\n'); end
    
    codeDir = fullfile(pwd, [modelName '_ert_rtw']);
    if ~exist(codeDir, 'dir')
        error('Code directory not found: %s', codeDir);
    end
    
    mainHFile = fullfile(codeDir, [modelName '.h']);
    if ~exist(mainHFile, 'file')
        error('Header file not found: %s', mainHFile);
    end
    
    if verbose, fprintf('   ✓ Code in: %s\n', codeDir); end
    
    %% Step 5: Create MATLAB wrapper
    if verbose, fprintf('\nStep 5: Creating wrapper...\n'); end
    
    if ~exist(outputDir, 'dir')
        mkdir(outputDir);
    end
    
    wrapperFile = fullfile(outputDir, [modelName '_run.m']);
    fid = fopen(wrapperFile, 'w');
    fprintf(fid, 'function outputs = %s_run(inputs)\n', modelName);
    fprintf(fid, '%% Run %s simulation\n', modelName);
    fprintf(fid, '%%   inputs - struct with parameter values\n');
    fprintf(fid, '%%   outputs - simulation results\n\n');
    fprintf(fid, '    modelName = ''%s'';\n', modelName);
    fprintf(fid, '    \n');
    fprintf(fid, '    %% Apply inputs if provided\n');
    fprintf(fid, '    if nargin > 0 && isstruct(inputs)\n');
    fprintf(fid, '        fields = fieldnames(inputs);\n');
    fprintf(fid, '        for i = 1:length(fields)\n');
    fprintf(fid, '            try\n');
    fprintf(fid, '                blockPath = [modelName ''/'' fields{i}];\n');
    fprintf(fid, '                set_param(blockPath, ''Value'', num2str(inputs.(fields{i})));\n');
    fprintf(fid, '            catch\n');
    fprintf(fid, '                warning(''Could not set %%s'', fields{i});\n');
    fprintf(fid, '            end\n');
    fprintf(fid, '        end\n');
    fprintf(fid, '    end\n');
    fprintf(fid, '    \n');
    fprintf(fid, '    %% Run simulation\n');
    fprintf(fid, '    simOut = sim(modelName);\n');
    fprintf(fid, '    \n');
    fprintf(fid, '    %% Extract outputs\n');
    fprintf(fid, '    if nargout > 0\n');
    fprintf(fid, '        outputs = simOut.yout;\n');
    fprintf(fid, '    end\n');
    fprintf(fid, 'end\n');
    fclose(fid);
    
    if verbose, fprintf('   ✓ Wrapper: %s\n', wrapperFile); end
    
    %% Step 6: Copy header
    headerPath = fullfile(outputDir, [modelName '.h']);
    copyfile(mainHFile, headerPath);
    
    if verbose, fprintf('   ✓ Header: %s\n', headerPath); end
    
    %% Cleanup
    if ~wasLoaded
        close_system(modelName, 0);
    end
    
    dllPath = wrapperFile;
    
    if verbose
        fprintf('\n✓ SUCCESS!\n');
        fprintf('   Wrapper: %s\n', dllPath);
        fprintf('   Header: %s\n', headerPath);
    end
end
