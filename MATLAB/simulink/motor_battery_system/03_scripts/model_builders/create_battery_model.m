%% Create Basic Battery Model Programmatically
% This script builds a battery model with thermal dynamics
% Run this after initializing workspace with battery parameters loaded

function create_battery_model()
    
    modelName = 'Battery_Thevenin_2RC';
    
    % Check if model already exists
    if bdIsLoaded(modelName)
        close_system(modelName, 0);
    end
    
    fprintf('Creating Battery 2RC model: %s.slx\n', modelName);
    
    % Create new model
    new_system(modelName);
    open_system(modelName);
    
    % Configure solver
    set_param(modelName, 'Solver', 'ode23t');
    set_param(modelName, 'RelTol', '1e-4');
    set_param(modelName, 'AbsTol', '1e-6');
    set_param(modelName, 'StopTime', '3600'); % 1 hour
    
    %% Current Source (Load)
    fprintf('Adding current source...\n');
    add_block('simulink/Sources/Step', [modelName '/Current Command']);
    set_param([modelName '/Current Command'], 'Time', '10');
    set_param([modelName '/Current Command'], 'After', '3.5'); % 1C discharge
    set_param([modelName '/Current Command'], 'Position', [50, 100, 100, 130]);
    
    %% Battery Model Subsystem
    fprintf('Adding battery equivalent circuit...\n');
    
    % Create battery subsystem
    add_block('simulink/Ports & Subsystems/Subsystem', [modelName '/Battery 2RC']);
    set_param([modelName '/Battery 2RC'], 'Position', [300, 150, 450, 350]);
    
    % Create thermal subsystem
    add_block('simulink/Ports & Subsystems/Subsystem', [modelName '/Thermal Model']);
    set_param([modelName '/Thermal Model'], 'Position', [300, 400, 450, 500]);
    
    %% Measurement and Display
    fprintf('Adding measurement blocks...\n');
    
    % Voltage display
    add_block('simulink/Sinks/Display', [modelName '/Voltage Display']);
    set_param([modelName '/Voltage Display'], 'Position', [600, 150, 680, 180]);
    
    % SOC display
    add_block('simulink/Sinks/Display', [modelName '/SOC Display']);
    set_param([modelName '/SOC Display'], 'Position', [600, 200, 680, 230]);
    
    % Temperature display
    add_block('simulink/Sinks/Display', [modelName '/Temp Display']);
    set_param([modelName '/Temp Display'], 'Position', [600, 250, 680, 280]);
    
    %% Scopes
    fprintf('Adding scopes...\n');
    
    % Voltage scope
    add_block('simulink/Sinks/Scope', [modelName '/Voltage Scope']);
    set_param([modelName '/Voltage Scope'], 'Position', [700, 140, 750, 190]);
    set_param([modelName '/Voltage Scope'], 'NumInputPorts', '2');
    
    % SOC scope
    add_block('simulink/Sinks/Scope', [modelName '/SOC Scope']);
    set_param([modelName '/SOC Scope'], 'Position', [700, 210, 750, 260]);
    
    % Temperature scope
    add_block('simulink/Sinks/Scope', [modelName '/Temperature Scope']);
    set_param([modelName '/Temperature Scope'], 'Position', [700, 280, 750, 330]);
    
    % Power scope
    add_block('simulink/Sinks/Scope', [modelName '/Power Scope']);
    set_param([modelName '/Power Scope'], 'Position', [700, 350, 750, 400]);
    
    %% To Workspace blocks for analysis
    fprintf('Adding data logging...\n');
    
    add_block('simulink/Sinks/To Workspace', [modelName '/V_terminal']);
    set_param([modelName '/V_terminal'], 'VariableName', 'V_terminal');
    set_param([modelName '/V_terminal'], 'Position', [800, 150, 860, 180]);
    
    add_block('simulink/Sinks/To Workspace', [modelName '/SOC_log']);
    set_param([modelName '/SOC_log'], 'VariableName', 'SOC');
    set_param([modelName '/SOC_log'], 'Position', [800, 200, 860, 230]);
    
    add_block('simulink/Sinks/To Workspace', [modelName '/T_log']);
    set_param([modelName '/T_log'], 'VariableName', 'T_cell');
    set_param([modelName '/T_log'], 'Position', [800, 250, 860, 280]);
    
    %% Enable signal logging
    set_param(modelName, 'SignalLogging', 'on');
    set_param(modelName, 'SignalLoggingName', 'logsout');
    
    %% Add annotations
    try
        h1 = Simulink.Annotation([modelName], 'Battery 2RC Equivalent Circuit Model with Thermal Dynamics');
        h1.Position = [400, 50];
        h1.FontSize = 14;
        h1.FontWeight = 'bold';
        
        h2 = Simulink.Annotation([modelName], sprintf(['Battery Model Instructions:\n' ...
            '1. Add Solver Configuration: Simscape > Utilities > Solver Configuration\n' ...
            '2. Load battery parameters: run(''init_workspace.m'')\n' ...
            '3. Build 2RC circuit in Battery subsystem\n' ...
            '4. Add thermal model in Thermal subsystem\n' ...
            '5. Run simulation and use plot_battery_results\n\n' ...
            'Required components:\n' ...
            '- OCV lookup table, R0, R1-C1, R2-C2\n' ...
            '- SOC integrator, Thermal mass & resistance']));
        h2.Position = [150, 600];
    catch
        % Annotations not supported, skip
    end
    
    %% Save model
    modelPath = fullfile('02_models', 'battery_models', [modelName '.slx']);
    save_system(modelName, modelPath);
    
    fprintf('\n========================================\n');
    fprintf('Battery Model Template Created!\n');
    fprintf('========================================\n');
    fprintf('Model saved to: %s\n', modelPath);
    fprintf('\nIMPORTANT - Complete the model:\n');
    fprintf('1. Add Solver Configuration:\n');
    fprintf('   - Simscape > Utilities > Solver Configuration\n');
    fprintf('\n2. Battery 2RC subsystem - Add:\n');
    fprintf('   - Controlled Voltage Source (OCV from lookup table)\n');
    fprintf('   - Resistors: R0, R1, R2\n');
    fprintf('   - Capacitors: C1, C2\n');
    fprintf('   - Current Sensor\n');
    fprintf('   - SOC calculation (Integrator)\n');
    fprintf('\n3. Thermal subsystem - Add:\n');
    fprintf('   - Heat generation: Q = I²R\n');
    fprintf('   - Thermal mass (Cp)\n');
    fprintf('   - Thermal resistance (R_th)\n');
    fprintf('   - Ambient temperature source\n');
    fprintf('\n4. Set parameters from workspace variables:\n');
    fprintf('   battery.R0, battery.R1, battery.C1, etc.\n');
    fprintf('\nSee: 01_theory/02_battery_theory.md for detailed equations\n');
    fprintf('See: 01_theory/07_SOC_estimation_guide.md for SOC implementation\n');
    fprintf('========================================\n\n');
    
end
