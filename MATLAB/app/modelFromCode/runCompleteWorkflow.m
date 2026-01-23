function generateModelFromCode()
% GENERATEMODELFROMCODE - Master script to convert C/C++ code to Simulink model
%
% This script orchestrates the complete workflow:
%   1. Runs Python parser to analyze C/C++ code
%   2. Generates JSON structure
%   3. Creates Simulink/Stateflow model from JSON
%
% Usage: generateModelFromCode()
%
% Requirements:
%   - Python installed and accessible from MATLAB
%   - parse_code_to_json.py in the same folder
%   - generateModelFromJSON.m in the same folder
%
% Author: Auto-generated
% Date: 2026-01-23

    fprintf('\n========================================\n');
    fprintf('C/C++ to Simulink Model Generator\n');
    fprintf('========================================\n\n');
    
    % Get script directory
    scriptDir = fileparts(mfilename('fullpath'));
    pythonScript = fullfile(scriptDir, 'parse_code_to_json.py');
    
    % Check if Python script exists
    if ~exist(pythonScript, 'file')
        error('Python parser script not found: %s', pythonScript);
    end
    
    % Select folder containing C/C++ files
    folderPath = uigetdir(pwd, 'Select folder containing C/C++ code generation files');
    if folderPath == 0
        disp('Operation cancelled by user.');
        return;
    end
    
    fprintf('Selected folder: %s\n\n', folderPath);
    
    % Create output folder
    outputFolder = fullfile(scriptDir, 'GeneratedModels');
    if ~exist(outputFolder, 'dir')
        mkdir(outputFolder);
    end
    
    jsonFile = fullfile(outputFolder, 'code_analysis.json');
    
    % Step 1: Run Python parser
    fprintf('========================================\n');
    fprintf('STEP 1: Parsing C/C++ Code with Python\n');
    fprintf('========================================\n\n');
    
    success = runPythonParser(pythonScript, folderPath, jsonFile);
    
    if ~success
        error('Python parsing failed. Check error messages above.');
    end
    
    % Verify JSON was created
    if ~exist(jsonFile, 'file')
        error('JSON file was not created: %s', jsonFile);
    end
    
    fprintf('\n>>> Python parsing completed successfully!\n');
    fprintf('>>> JSON saved to: %s\n\n', jsonFile);
    
    % Step 2: Generate Simulink model from JSON
    fprintf('\n========================================\n');
    fprintf('STEP 2: Generating Simulink Model\n');
    fprintf('========================================\n\n');
    
    try
        generateModelFromJSON(jsonFile);
        
        fprintf('\n========================================\n');
        fprintf('COMPLETE! Model generated successfully.\n');
        fprintf('========================================\n\n');
        
    catch ME
        fprintf('\n*** ERROR in model generation ***\n');
        fprintf('Error: %s\n', ME.message);
        fprintf('Stack:\n');
        for i = 1:length(ME.stack)
            fprintf('  %s (line %d)\n', ME.stack(i).name, ME.stack(i).line);
        end
        rethrow(ME);
    end
end

function success = runPythonParser(pythonScript, folderPath, jsonFile)
    % Run the Python parser script
    
    success = false;
    
    % Check if Python is available
    [status, pythonVersion] = system('python --version');
    
    if status ~= 0
        % Try python3
        [status, pythonVersion] = system('python3 --version');
        pythonCmd = 'python3';
        
        if status ~= 0
            error('Python is not installed or not in system PATH.\nPlease install Python and try again.');
        end
    else
        pythonCmd = 'python';
    end
    
    fprintf('Using: %s\n\n', strtrim(pythonVersion));
    
    % Build command
    cmd = sprintf('"%s" "%s" "%s"', pythonCmd, pythonScript, folderPath);
    
    fprintf('Running command:\n%s\n\n', cmd);
    
    % Run Python script
    [status, output] = system(cmd);
    
    % Display output
    fprintf('Python output:\n');
    fprintf('%s\n', output);
    
    if status == 0
        success = true;
    else
        fprintf('\n*** Python script failed with exit code: %d ***\n', status);
        success = false;
    end
end
