classdef ModelParameterParser
    % ModelParameterParser - Parses Simulink models and extracts configurable parameters
    %
    % This class reads a Simulink model and extracts parameters from blocks
    % that can be configured through a GUI. Currently supports:
    %   - Constant blocks: Value, DataType, SampleTime
    %   - Future: Gain blocks, Switch blocks, etc.
    %
    % Usage:
    %   parser = ModelParameterParser('SimpleAdditionModel');
    %   params = parser.getParameters();
    
    properties
        ModelName           % Name of the Simulink model
        ModelPath           % Full path to model file
        Parameters          % Structure array of extracted parameters
    end
    
    methods
        function obj = ModelParameterParser(modelNameOrPath)
            % Constructor - Initialize parser with model name or full path
            if contains(modelNameOrPath, filesep) || endsWith(modelNameOrPath, '.slx') || endsWith(modelNameOrPath, '.mdl')
                % Full path provided
                obj.ModelPath = modelNameOrPath;
                [~, obj.ModelName, ~] = fileparts(modelNameOrPath);
            else
                % Just name provided
                obj.ModelName = modelNameOrPath;
                obj.ModelPath = which(modelNameOrPath);
                if isempty(obj.ModelPath)
                    obj.ModelPath = [modelNameOrPath '.slx'];
                end
            end
        end
        
        function params = getParameters(obj)
            % getParameters - Extract all configurable parameters from model
            % In deployed mode, returns hardcoded parameter definitions
            
            % Check if running in deployed mode or Simulink not available
            if isdeployed || ~license('test', 'Simulink')
                % Return hardcoded parameters for SimpleAdditionModel
                params = getHardcodedParameters(obj);
                return;
            end
            
            % Development mode - extract from actual model
            params = extractFromModel(obj);
        end
        
        function params = getHardcodedParameters(obj)
            % Hardcoded parameter definitions for deployment
            % These match the MATLAB function parameters
            
            if strcmp(obj.ModelName, 'SimpleAdditionModel')
                params = struct([]);
                params(1).BlockName = 'Param1';
                params(1).ParameterName = 'Param1_Value';
                params(1).ParameterType = 'numeric';
                params(1).CurrentValue = 10;
                params(1).DataType = 'double';
                params(1).SampleTime = '-1';
                params(1).BlockType = 'Constant';
                
                params(2).BlockName = 'Param2';
                params(2).ParameterName = 'Param2_Value';
                params(2).ParameterType = 'numeric';
                params(2).CurrentValue = 20;
                params(2).DataType = 'double';
                params(2).SampleTime = '-1';
                params(2).BlockType = 'Constant';
            else
                % Generic model - empty parameters
                params = struct([]);
            end
        end
        
        function params = extractFromModel(obj)
            % Extract parameters from actual Simulink model (development mode only)
            
            params = [];
            paramIdx = 1;
            
            try
                % Load model if needed
                wasLoaded = true;
                try
                    % Try to check if model is loaded
                    bdIsLoaded(obj.ModelName);
                catch
                    % bdIsLoaded not available or model not loaded
                    wasLoaded = false;
                end
                
                if ~wasLoaded
                    load_system(obj.ModelPath);
                end
                
                % Find all Constant blocks
                constantBlocks = find_system(obj.ModelName, ...
                    'BlockType', 'Constant');
                
                for i = 1:length(constantBlocks)
                    blockPath = constantBlocks{i};
                    
                    % Get block name (without model prefix)
                    blockName = get_param(blockPath, 'Name');
                    
                    % Extract Value parameter
                    params(paramIdx).BlockPath = blockPath;
                    params(paramIdx).BlockName = blockName;
                    params(paramIdx).BlockType = 'Constant';
                    params(paramIdx).ParameterName = [blockName '_Value'];
                    params(paramIdx).ParameterType = 'numeric';
                    params(paramIdx).CurrentValue = get_param(blockPath, 'Value');
                    params(paramIdx).DataType = get_param(blockPath, 'OutDataTypeStr');
                    params(paramIdx).SampleTime = get_param(blockPath, 'SampleTime');
                    params(paramIdx).Description = 'Constant value';
                    paramIdx = paramIdx + 1;
                    
                    % Extract DataType parameter
                    params(paramIdx).BlockPath = blockPath;
                    params(paramIdx).BlockName = blockName;
                    params(paramIdx).BlockType = 'Constant';
                    params(paramIdx).ParameterName = [blockName '_DataType'];
                    params(paramIdx).ParameterType = 'dropdown';
                    params(paramIdx).CurrentValue = get_param(blockPath, 'OutDataTypeStr');
                    params(paramIdx).DropdownOptions = {'double', 'single', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'boolean'};
                    params(paramIdx).Description = 'Output data type';
                    paramIdx = paramIdx + 1;
                    
                    % Extract SampleTime parameter
                    params(paramIdx).BlockPath = blockPath;
                    params(paramIdx).BlockName = blockName;
                    params(paramIdx).BlockType = 'Constant';
                    params(paramIdx).ParameterName = [blockName '_SampleTime'];
                    params(paramIdx).ParameterType = 'numeric';
                    params(paramIdx).CurrentValue = get_param(blockPath, 'SampleTime');
                    params(paramIdx).Description = 'Sample time (-1 for inherited)';
                    paramIdx = paramIdx + 1;
                end
                
                % Find all Gain blocks
                gainBlocks = find_system(obj.ModelName, ...
                    'BlockType', 'Gain');
                
                for i = 1:length(gainBlocks)
                    blockPath = gainBlocks{i};
                    blockName = get_param(blockPath, 'Name');
                    
                    % Extract Gain value
                    params(paramIdx).BlockPath = blockPath;
                    params(paramIdx).BlockName = blockName;
                    params(paramIdx).BlockType = 'Gain';
                    params(paramIdx).ParameterName = [blockName '_Gain'];
                    params(paramIdx).ParameterType = 'numeric';
                    params(paramIdx).CurrentValue = get_param(blockPath, 'Gain');
                    params(paramIdx).Description = 'Gain value';
                    paramIdx = paramIdx + 1;
                end
                
            catch ME
                if ~wasLoaded
                    close_system(obj.ModelName, 0);
                end
                rethrow(ME);
            end
            
            % Model handling removed - not needed in deployed mode
            
            obj.Parameters = params;
        end
        
        function setParameter(obj, paramName, newValue)
            % setParameter - Update a parameter value in the model
            % Not available in deployed mode
            
            if isdeployed
                warning('setParameter not available in deployed mode');
                return;
            end
            
            % Find parameter
            idx = find(strcmp({obj.Parameters.ParameterName}, paramName), 1);
            if isempty(idx)
                error('Parameter "%s" not found', paramName);
            end
            
            param = obj.Parameters(idx);
            
            % Load model if needed
            wasLoaded = false;
            try
                bdIsLoaded(obj.ModelName);
                wasLoaded = true;
            catch
                wasLoaded = false;
            end
            
            if ~wasLoaded
                load_system(obj.ModelName);
            end
            
            try
                % Extract the actual block parameter name from ParameterName
                % e.g., 'Param1_Value' -> 'Value'
                parts = strsplit(paramName, '_');
                blockParam = parts{end};
                
                % Map our parameter names to actual block parameters
                switch blockParam
                    case 'Value'
                        set_param(param.BlockPath, 'Value', num2str(newValue));
                    case 'DataType'
                        set_param(param.BlockPath, 'OutDataTypeStr', newValue);
                    case 'SampleTime'
                        set_param(param.BlockPath, 'SampleTime', num2str(newValue));
                    case 'Gain'
                        set_param(param.BlockPath, 'Gain', num2str(newValue));
                    otherwise
                        warning('Unknown parameter type: %s', blockParam);
                end
                
                % Update our cached value
                obj.Parameters(idx).CurrentValue = num2str(newValue);
                
            catch ME
                if ~wasLoaded
                    close_system(obj.ModelName, 0);
                end
                rethrow(ME);
            end
            
            % Don't close model - leave it open for simulation
        end
        
        function printParameters(obj)
            % printParameters - Display all parameters in a readable format
            
            if isempty(obj.Parameters)
                fprintf('No parameters extracted. Call getParameters() first.\n');
                return;
            end
            
            fprintf('\n=== Model Parameters for %s ===\n\n', obj.ModelName);
            
            for i = 1:length(obj.Parameters)
                p = obj.Parameters(i);
                fprintf('%d. %s\n', i, p.ParameterName);
                fprintf('   Block: %s (%s)\n', p.BlockName, p.BlockType);
                fprintf('   Type: %s\n', p.ParameterType);
                fprintf('   Current Value: %s\n', p.CurrentValue);
                fprintf('   Description: %s\n', p.Description);
                if strcmp(p.ParameterType, 'dropdown')
                    fprintf('   Options: %s\n', strjoin(p.DropdownOptions, ', '));
                end
                fprintf('\n');
            end
        end
    end
end
