function createSimpleAdditionModel()
% createSimpleAdditionModel - Creates a simple Simulink model with 2 constants and addition
%
% This creates a basic model: Param1 + Param2 = Output
% The model will be used as a template for dynamic GUI generation

    modelName = 'SimpleAdditionModel';
    
    % Close model if already open
    if bdIsLoaded(modelName)
        close_system(modelName, 0);
    end
    
    % Create new model
    new_system(modelName);
    open_system(modelName);
    
    % Add Constant blocks
    add_block('simulink/Sources/Constant', [modelName '/Param1'], ...
        'Value', '10', ...
        'OutDataTypeStr', 'double', ...
        'SampleTime', '-1', ...
        'Position', [50, 50, 100, 80]);
    
    add_block('simulink/Sources/Constant', [modelName '/Param2'], ...
        'Value', '20', ...
        'OutDataTypeStr', 'double', ...
        'SampleTime', '-1', ...
        'Position', [50, 150, 100, 180]);
    
    % Add Addition block
    add_block('simulink/Math Operations/Add', [modelName '/Add'], ...
        'Inputs', '++', ...
        'Position', [200, 95, 230, 125]);
    
    % Add Output block (Outport)
    add_block('simulink/Sinks/Out1', [modelName '/Output'], ...
        'Position', [350, 103, 380, 117]);
    
    % Connect blocks
    add_line(modelName, 'Param1/1', 'Add/1', 'autorouting', 'on');
    add_line(modelName, 'Param2/1', 'Add/2', 'autorouting', 'on');
    add_line(modelName, 'Add/1', 'Output/1', 'autorouting', 'on');
    
    % Configure solver settings for code generation
    set_param(modelName, 'SolverType', 'Fixed-step');
    set_param(modelName, 'FixedStep', '0.01');
    set_param(modelName, 'StopTime', '1');
    
    % Save model
    save_system(modelName);
    
    fprintf('Model "%s" created successfully!\n', modelName);
    fprintf('Location: %s\n', which(modelName));
end
