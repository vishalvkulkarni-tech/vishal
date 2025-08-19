% Step 1: Specify the ARXML file
arxmlFile = 'ThrottlePositionControlComposition.arxml';

% Step 2: Create an AUTOSAR importer object
arImporter = arxml.importer(arxmlFile);

% Step 3: Extract all software component names
swcNames = getComponents(arImporter);

% Step 4: Generate shell models for all software components
for i = 1:numel(swcNames)
    disp(['Creating shell model for component: ', swcNames{i}]);
    createComponentAsModel(arxmlFile, swcNames{i});
end

% Step 5: Extract all composition names
compositionNames = getCompositions(arImporter);

% Step 6: Generate shell models for all compositions
for i = 1:numel(compositionNames)
    disp(['Creating shell model for composition: ', compositionNames{i}]);
    createCompositionAsModel(arxmlFile, compositionNames{i});
end

disp('All components and compositions have been processed.');
