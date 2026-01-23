function outputs = SimpleAdditionModel_run(inputs)
% Run SimpleAdditionModel simulation
%   inputs - struct with parameter values
%   outputs - simulation results

    modelName = 'SimpleAdditionModel';
    
    % Apply inputs if provided
    if nargin > 0 && isstruct(inputs)
        fields = fieldnames(inputs);
        for i = 1:length(fields)
            try
                blockPath = [modelName '/' fields{i}];
                set_param(blockPath, 'Value', num2str(inputs.(fields{i})));
            catch
                warning('Could not set %s', fields{i});
            end
        end
    end
    
    % Run simulation
    simOut = sim(modelName);
    
    % Extract outputs
    if nargout > 0
        outputs = simOut.yout;
    end
end
