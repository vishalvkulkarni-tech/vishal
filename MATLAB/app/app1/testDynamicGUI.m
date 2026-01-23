% Demo script to test the Dynamic Model GUI system

% Step 1: Create the simple addition model
fprintf('Creating Simple Addition Model...\n');
createSimpleAdditionModel();

% Step 2: Parse model parameters
fprintf('\nParsing model parameters...\n');
parser = ModelParameterParser('SimpleAdditionModel');
params = parser.getParameters();
parser.printParameters();

% Step 3: Launch the GUI
fprintf('\nLaunching Dynamic GUI...\n');
fprintf('The GUI will open in a new window.\n');
fprintf('You can modify parameters and run simulations.\n\n');

% Launch the app
guiApp = DynamicModelGUI('SimpleAdditionModel');

fprintf('Demo complete! The GUI is now running.\n');
fprintf('Try modifying Param1_Value and Param2_Value, then click "Run Simulation".\n');
