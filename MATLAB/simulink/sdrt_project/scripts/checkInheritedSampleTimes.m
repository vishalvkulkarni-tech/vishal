function checkInheritedSampleTimes(modelName)
% Finds blocks with inherited sample time (-1)

    if ~bdIsLoaded(modelName)
        load_system(modelName);
    end

    fprintf('Checking for inherited sample times...\n');

    blocks = find_system(modelName, ...
        'LookUnderMasks','all', ...
        'FollowLinks','on', ...
        'SampleTime','-1');

    % Remove root model
    blocks = setdiff(blocks, modelName);

    if ~isempty(blocks)
        fprintf('ERROR: Inherited sample time detected in:\n');
        disp(blocks);
        error('Fix inherited sample times before SDRT execution');
    end

    fprintf('✔ No inherited sample times found\n');
end
