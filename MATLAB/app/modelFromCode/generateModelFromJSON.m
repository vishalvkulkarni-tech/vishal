function generateModelFromJSON(jsonFile)
% GENERATEMODELFROMJSON - Create Simulink/Stateflow model from JSON analysis
%
% This script reads a JSON file created by the Python parser and generates
% appropriate Simulink or Stateflow models
%
% Usage: 
%   generateModelFromJSON()  % Interactive - prompts for JSON file
%   generateModelFromJSON('path/to/code_analysis.json')  % Direct path
%
% Author: Auto-generated
% Date: 2026-01-23

    if nargin < 1
        % Interactive mode - browse for JSON file
        [filename, filepath] = uigetfile('*.json', 'Select JSON analysis file', ...
                                         fullfile(pwd, 'GeneratedModels', 'code_analysis.json'));
        if filename == 0
            disp('Operation cancelled by user.');
            return;
        end
        jsonFile = fullfile(filepath, filename);
    end
    
    if ~exist(jsonFile, 'file')
        error('JSON file not found: %s', jsonFile);
    end
    
    fprintf('\n========================================\n');
    fprintf('Reading JSON analysis from: %s\n', jsonFile);
    fprintf('========================================\n\n');
    
    % Read JSON file
    try
        fid = fopen(jsonFile, 'r', 'n', 'UTF-8');
        jsonText = fread(fid, '*char')';
        fclose(fid);
        parsedData = jsondecode(jsonText);
    catch ME
        error('Failed to read JSON file: %s', ME.message);
    end
    
    % Display summary
    displaySummary(parsedData);
    
    % Create output folder
    outputFolder = fullfile(pwd, 'GeneratedModels');
    if ~exist(outputFolder, 'dir')
        mkdir(outputFolder);
    end
    
    % Generate model name
    modelName = ['Model_' datestr(now, 'yyyymmdd_HHMMSS')];
    
    % Determine model type
    if isfield(parsedData, 'modelStructure')
        modelType = parsedData.modelStructure.recommendedModelType;
    else
        modelType = 'simulink';
    end
    
    fprintf('\n>>> Generating %s model: %s\n\n', upper(modelType), modelName);
    
    % Generate model with retry logic
    maxRetries = 3;
    success = false;
    
    for attempt = 1:maxRetries
        fprintf('--- Attempt %d of %d ---\n', attempt, maxRetries);
        
        try
            createModel(modelName, modelType, parsedData, outputFolder, attempt);
            success = true;
            break;
        catch ME
            fprintf('Attempt %d failed: %s\n', attempt, ME.message);
            
            if attempt < maxRetries
                fprintf('Retrying with simplified approach...\n\n');
                pause(0.5);
            else
                error('All attempts failed. Last error: %s', ME.message);
            end
        end
    end
    
    if success
        fprintf('\n========================================\n');
        fprintf('SUCCESS! Model generated: %s\n', modelName);
        fprintf('Location: %s\n', outputFolder);
        fprintf('========================================\n');
    end
end

function displaySummary(parsedData)
    % Display analysis summary
    
    fprintf('Analysis Summary:\n');
    fprintf('  Files analyzed: %d\n', parsedData.summary.totalFiles);
    
    if isfield(parsedData.summary, 'modelConstants')
        fprintf('  Model constants: %d\n', parsedData.summary.modelConstants);
    end
    
    fprintf('  Outputs: %d\n', parsedData.summary.outputs);
    fprintf('  Connections: %d\n', parsedData.summary.connections);
    
    if isfield(parsedData.summary, 'detectedOperation')
        fprintf('\n>>> DETECTED OPERATION: %s <<<\n', upper(parsedData.summary.detectedOperation));
    end
    
    if isfield(parsedData, 'relevantConstants')
        fprintf('\nConstants found:\n');
        for i = 1:length(parsedData.relevantConstants)
            c = parsedData.relevantConstants(i);
            if isfield(c, 'numericValue')
                fprintf('  %s = %g\n', c.name, c.numericValue);
            end
        end
    end
end

function createModel(modelName, modelType, parsedData, outputFolder, attempt)
    % Create the Simulink model
    
    fprintf('\nCreating model...\n');
    
    % Close if already open
    if bdIsLoaded(modelName)
        close_system(modelName, 0);
    end
    
    % Create new model
    new_system(modelName);
    open_system(modelName);
    
    % Set model properties
    set_param(modelName, 'Solver', 'FixedStepDiscrete');
    set_param(modelName, 'FixedStep', '0.1');
    
    % Add blocks based on model type
    switch modelType
        case 'simulink'
            addSimulinkBlocks(modelName, parsedData, attempt);
        case 'stateflow'
            addStateflowChart(modelName, parsedData);
        case 'combined'
            addStateflowChart(modelName, parsedData);
            addSimulinkBlocks(modelName, parsedData, attempt);
    end
    
    % Auto-arrange
    try
        Simulink.BlockDiagram.arrangeSystem(modelName);
    catch
        % Ignore arrange errors
    end
    
    % Save model
    modelPath = fullfile(outputFolder, modelName);
    save_system(modelName, modelPath);
    
    fprintf('Model saved: %s.slx\n', modelPath);
end

function addSimulinkBlocks(modelName, parsedData, attempt)
    % Add Simulink blocks based on JSON data
    
    fprintf('  Adding Simulink blocks...\n');
    
    xPos = 50;
    yPos = 100;
    spacing = 200;
    blockHeight = 60;
    
    % Get operation type
    operationType = 'unknown';
    if isfield(parsedData, 'summary') && isfield(parsedData.summary, 'detectedOperation')
        operationType = parsedData.summary.detectedOperation;
    end
    
    numConstants = parsedData.summary.constants + parsedData.summary.defines;
    numInputs = parsedData.summary.inputs;
    numOutputs = max(1, parsedData.summary.outputs);
    
    fprintf('  Structure: %d constants, %d inputs, %d outputs\n', ...
            numConstants, numInputs, numOutputs);
    fprintf('  Operation: %s\n', operationType);
    
    % Add constant blocks from relevantConstants
    if isfield(parsedData, 'relevantConstants') && ~isempty(parsedData.relevantConstants)
        fprintf('  Creating constant blocks...\n');
        
        constCount = 0;
        for i = 1:min(5, length(parsedData.relevantConstants))
            constData = parsedData.relevantConstants(i);
            constName = sanitizeBlockName(constData.name, i);
            
            % Get numeric value
            if isfield(constData, 'numericValue')
                constValue = constData.numericValue;
            else
                try
                    constValue = str2double(constData.value);
                    if isnan(constValue)
                        constValue = 0;
                    end
                catch
                    constValue = 0;
                end
            end
            
            fprintf('    Constant: %s = %g\n', constName, constValue);
            
            add_block('simulink/Sources/Constant', [modelName '/' constName], ...
                      'Value', num2str(constValue), ...
                      'Position', [xPos, yPos + constCount*blockHeight, ...
                                  xPos+60, yPos + constCount*blockHeight + 30]);
            constCount = constCount + 1;
        end
        
        yPos = 100;
        xPos = xPos + spacing;
    end
    
    % Add operation block if detected
    if ~strcmp(operationType, 'unknown')
        fprintf('  Creating %s block...\n', operationType);
        
        switch operationType
            case 'addition'
                add_block('simulink/Math Operations/Add', [modelName '/Add'], ...
                          'Position', [xPos, yPos+30, xPos+60, yPos+90]);
                fprintf('  >>> Add block created! <<<\n');
                
            case 'subtraction'
                add_block('simulink/Math Operations/Subtract', [modelName '/Subtract'], ...
                          'Position', [xPos, yPos+30, xPos+60, yPos+90]);
                
            case 'multiplication'
                add_block('simulink/Math Operations/Product', [modelName '/Multiply'], ...
                          'Position', [xPos, yPos+30, xPos+60, yPos+90]);
                
            case 'division'
                add_block('simulink/Math Operations/Divide', [modelName '/Divide'], ...
                          'Position', [xPos, yPos+30, xPos+60, yPos+90]);
        end
        
        xPos = xPos + spacing;
    end
    
    % Add output port(s)
    fprintf('  Adding output port(s)...\n');
    for i = 1:min(numOutputs, 3)
        outputName = sprintf('Out%d', i);
        add_block('simulink/Sinks/Out1', [modelName '/' outputName], ...
                  'Position', [xPos, yPos + (i-1)*blockHeight, ...
                              xPos+30, yPos + (i-1)*blockHeight + 30]);
    end
    
    fprintf('  Blocks created successfully!\n');
end

function addStateflowChart(modelName, parsedData)
    % Add Stateflow chart
    
    fprintf('  Adding Stateflow chart...\n');
    
    add_block('sflib/Chart', [modelName '/StateflowChart'], ...
              'Position', [100, 100, 400, 300]);
    
    % Get chart and add states
    rt = sfroot;
    chart = rt.find('-isa', 'Stateflow.Chart', '-and', 'Path', [modelName '/StateflowChart']);
    
    if ~isempty(chart)
        for i = 1:3
            state = Stateflow.State(chart);
            state.Name = sprintf('State%d', i);
            state.Position = [50 + (i-1)*120, 50, 100, 80];
        end
    end
end

function cleanName = sanitizeBlockName(name, index)
    % Sanitize block name for Simulink
    
    % Remove invalid characters
    cleanName = regexprep(name, '[^a-zA-Z0-9_]', '_');
    
    % Ensure starts with letter
    if ~isempty(cleanName) && ~isletter(cleanName(1))
        cleanName = ['Block_' cleanName];
    end
    
    % Ensure not empty
    if isempty(cleanName)
        cleanName = sprintf('Block_%d', index);
    end
    
    % Limit length
    if length(cleanName) > 63
        cleanName = cleanName(1:63);
    end
    
    % Avoid reserved names
    reservedNames = {'Input', 'Output', 'In1', 'Out1', 'Subsystem'};
    if ismember(cleanName, reservedNames)
        cleanName = ['User_' cleanName];
    end
end
