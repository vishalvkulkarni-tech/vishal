bdclose all;
% Step 1: Specify ARXML file
arxmlFile = 'ThrottlePositionControlComposition.arxml';

% Step 2: Create an AUTOSAR importer object
arImporter = arxml.importer(arxmlFile);

compositionNames = arImporter.getComponentNames('Composition');
compositionNamesOnly = cellfun(@(x) regexp(x, '[^/]*$', 'match', 'once'), compositionNames, 'UniformOutput', false);
% Step 6: Create test model shells for each composition
for i = 1:numel(compositionNames)
    % create composition models
    createCompositionAsModel(arImporter, compositionNames{i});
    % Open the generated model for the composition
    compositionModelName = compositionNamesOnly{i};
    save_system(compositionModelName);

    % Create a test harness for the composition
    disp(['Creating test harness for composition: ', compositionNames{i}]);
    testHarnessName = [compositionNamesOnly{i}, '_TestHarness'];
    sltest.harness.create(compositionModelName, 'Name', testHarnessName, 'SaveExternally', true);
    close_system(compositionModelName, false);  % Close the composition model without saving
end

% Step 3: Extract all software component names
swcNames = arImporter.getComponentNames;
swcNamesOnly = cellfun(@(x) regexp(x, '[^/]*$', 'match', 'once'), swcNames, 'UniformOutput', false);
% Step 4: Create test model shells for each software component
for i = 1:numel(swcNames)
    % create model shells
    % disp(['Creating shell model for component: ', swcNames{i}]);
    % createComponentAsModel(arImporter,swcNames{i},'ModelPeriodicRunnablesAs','AtomicSubsystem');
    componentModelName = swcNamesOnly{i};
    % createComponentAsModel(arImporter, swcNames{i});
    % Open the generated model for the software component
    open_system(componentModelName);
    % Create a test harness for the component
    disp(['Creating test harness for component: ', swcNames{i}]);
    testHarnessName = [swcNamesOnly{i}, '_TestHarness'];
    sltest.harness.create(componentModelName,'Name', testHarnessName, 'SaveExternally', true);
    load_system(testHarnessName)
    close_system(testHarnessName, false);  % Close the component model without saving
    close_system(componentModelName);
end
disp('Test model shells created for all components and compositions.');
