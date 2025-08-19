% Step 1: Specify the ARXML file
arxmlFile = 'BasicComposition.arxml';

% Step 2: Create an AUTOSAR importer object
arImporter = autosar.importer(arxmlFile);

% Step 3: Extract all software component (SWC) names
swcNames = getComponents(arImporter);

% Step 4: Loop through each SWC model to configure and generate code
for i = 1:numel(swcNames)
    % Define the model name for the SWC
    modelName = [swcNames{i}, '.slx'];

    % Check if the model exists
    if exist(modelName, 'file') == 2
        % Open the existing model
        disp(['Opening model: ', modelName]);
        open_system(modelName);

        % Configure the model for AUTOSAR code generation
        set_param(modelName, 'SystemTargetFile', 'autosar.tlc'); % Set AUTOSAR target
        set_param(modelName, 'GenerateReport', 'on');            % Enable code generation report

        % Optional: Adjust additional AUTOSAR properties if required
        arProps = autosar.api.getAUTOSARProperties(modelName);
        % Example: Map an SWC to an RTE
        % mapSWCToRTE(arProps, 'MyRunnable', 'RTEPortName');

        % Generate AUTOSAR-compliant C code
        disp(['Generating AUTOSAR-compliant code for: ', swcNames{i}]);
        slbuild(modelName);

        % Close the model without saving
        close_system(modelName, false);
    else
        disp(['Model file not found for SWC: ', swcNames{i}, '. Skipping...']);
    end
end

disp('Code generation completed for all SWCs.');
