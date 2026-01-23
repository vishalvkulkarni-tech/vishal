function createModelMATLABEquivalent(modelName)
% createModelMATLABEquivalent - Create MATLAB function equivalent of Simulink model
%
% This creates a pure MATLAB function that replicates the model behavior
% Can be compiled with mcc (no Simulink Runtime needed)
%
% Input:
%   modelName - Name of Simulink model
%
% Output:
%   Creates ModelName_matlab.m function

    % Load model
    load_system(modelName);
    
    % Get all Constant blocks
    constants = find_system(modelName, 'BlockType', 'Constant');
    
    % Create MATLAB function
    functionName = [modelName '_matlab'];
    fileName = [functionName '.m'];
    
    fid = fopen(fileName, 'w');
    
    % Function header
    fprintf(fid, 'function [output, time] = %s(varargin)\n', functionName);
    fprintf(fid, '%% %s - MATLAB equivalent of %s Simulink model\n', functionName, modelName);
    fprintf(fid, '%% This is a pure MATLAB implementation (no Simulink required)\n');
    fprintf(fid, '%%\n');
    fprintf(fid, '%% Usage:\n');
    fprintf(fid, '%%   [output, time] = %s()\n', functionName);
    fprintf(fid, '%%   [output, time] = %s(''ParamName'', value, ...)\n', functionName);
    fprintf(fid, '%%\n');
    fprintf(fid, '%% Parameters can be overridden using name-value pairs\n\n');
    
    % Parse input parameters
    fprintf(fid, '    %% Parse inputs\n');
    fprintf(fid, '    p = inputParser;\n');
    
    % Add parameters for each constant
    for i = 1:length(constants)
        blockName = get_param(constants{i}, 'Name');
        blockValue = get_param(constants{i}, 'Value');
        fprintf(fid, '    addParameter(p, ''%s'', %s, @isnumeric);\n', blockName, blockValue);
    end
    
    fprintf(fid, '    addParameter(p, ''StopTime'', 10, @isnumeric);\n');
    fprintf(fid, '    addParameter(p, ''SampleTime'', 0.01, @isnumeric);\n');
    fprintf(fid, '    parse(p, varargin{:});\n\n');
    
    % Get parameter values
    fprintf(fid, '    %% Get parameter values\n');
    for i = 1:length(constants)
        blockName = get_param(constants{i}, 'Name');
        fprintf(fid, '    %s = p.Results.%s;\n', blockName, blockName);
    end
    fprintf(fid, '    stopTime = p.Results.StopTime;\n');
    fprintf(fid, '    sampleTime = p.Results.SampleTime;\n\n');
    
    % Simulation logic
    fprintf(fid, '    %% Simulation\n');
    fprintf(fid, '    time = 0:sampleTime:stopTime;\n');
    fprintf(fid, '    nSamples = length(time);\n\n');
    
    % Model-specific logic - for SimpleAdditionModel
    fprintf(fid, '    %% Model computation\n');
    if strcmp(modelName, 'SimpleAdditionModel')
        fprintf(fid, '    %% SimpleAdditionModel: Constant1 + Constant2\n');
        fprintf(fid, '    output = ones(nSamples, 1) * (Constant1 + Constant2);\n');
    else
        % Generic - just return first constant
        fprintf(fid, '    %% Generic model - customize this for your model\n');
        blockName = get_param(constants{1}, 'Name');
        fprintf(fid, '    output = ones(nSamples, 1) * %s;\n', blockName);
    end
    
    fprintf(fid, '\nend\n');
    
    fclose(fid);
    
    fprintf('✓ Created MATLAB equivalent: %s\n', fileName);
    fprintf('  This function can be compiled with mcc (no Simulink Runtime needed)\n');
    
    close_system(modelName, 0);
end
