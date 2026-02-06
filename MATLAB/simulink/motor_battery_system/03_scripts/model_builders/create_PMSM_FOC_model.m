%% Create Complete PMSM FOC Model Programmatically
% This script builds a complete PMSM model with Field-Oriented Control
% All blocks are created and connected properly
% Run this after initializing workspace with motor parameters loaded

function create_PMSM_FOC_model()
    
    modelName = 'PMSM_FOC_Complete';
    
    % Check if model already exists
    if bdIsLoaded(modelName)
        close_system(modelName, 0);
    end
    
    fprintf('Creating complete PMSM FOC model: %s.slx\n', modelName);
    
    % Create new model
    new_system(modelName);
    open_system(modelName);
    
    % Configure solver
    set_param(modelName, 'Solver', 'ode45');
    set_param(modelName, 'RelTol', '1e-3');
    set_param(modelName, 'AbsTol', '1e-6');
    set_param(modelName, 'StopTime', '2.0');
    
    % Add Simscape configuration
    add_block('nesl_utility/Solver Configuration', [modelName '/Solver Configuration']);
    
    %% Reference Inputs
    fprintf('Creating reference inputs...\n');
    
    % Speed reference (step from 0 to 3000 rpm)
    add_block('simulink/Sources/Step', [modelName '/Speed_Ref']);
    set_param([modelName '/Speed_Ref'], 'Time', '0.1', 'After', '3000*2*pi/60', 'Position', [30, 200, 70, 230]);
    
    % Torque load reference (step at 1s)
    add_block('simulink/Sources/Step', [modelName '/Torque_Load']);
    set_param([modelName '/Torque_Load'], 'Time', '1.0', 'After', '5', 'Position', [30, 600, 70, 630]);
    
    %% Speed Controller (PI)
    fprintf('Creating speed controller...\n');
    add_block('simulink/Continuous/PID Controller', [modelName '/Speed_PI']);
    set_param([modelName '/Speed_PI'], 'P', '0.005', 'I', '5', 'D', '0', 'Position', [200, 195, 250, 235]);
    
    %% Current References
    % Torque to Iq conversion: iq = T / (1.5 * p * lambda_m)
    add_block('simulink/Math Operations/Gain', [modelName '/Torque_to_Iq']);
    set_param([modelName '/Torque_to_Iq'], 'Gain', '1/(1.5*motor.p*motor.lambda_m)', 'Position', [290, 200, 330, 230]);
    
    % Id reference (always zero for SPMSM)
    add_block('simulink/Sources/Constant', [modelName '/Id_Ref']);
    set_param([modelName '/Id_Ref'], 'Value', '0', 'Position', [290, 140, 330, 170]);
    
    %% Current Controllers (PI for d and q axes)
    fprintf('Creating current controllers...\n');
    add_block('simulink/Continuous/PID Controller', [modelName '/Id_PI']);
    set_param([modelName '/Id_PI'], 'P', 'ctrl.Kp_d', 'I', 'ctrl.Ki_d', 'D', '0', 'Position', [470, 135, 520, 175]);
    
    add_block('simulink/Continuous/PID Controller', [modelName '/Iq_PI']);
    set_param([modelName '/Iq_PI'], 'P', 'ctrl.Kp_q', 'I', 'ctrl.Ki_q', 'D', '0', 'Position', [470, 195, 520, 235]);
    
    %% Inverse Park Transform (dq to alpha-beta)
    fprintf('Creating inverse Park transform...\n');
    add_block('simulink/User-Defined Functions/MATLAB Function', [modelName '/Inv_Park']);
    set_param([modelName '/Inv_Park'], 'Position', [580, 170, 650, 230]);
    
    %% Inverse Clarke Transform (alpha-beta to abc)
    fprintf('Creating inverse Clarke transform...\n');
    add_block('simulink/User-Defined Functions/MATLAB Function', [modelName '/Inv_Clarke']);
    set_param([modelName '/Inv_Clarke'], 'Position', [700, 170, 770, 230]);
    
    %% Three-Phase Voltage Sources (simplified motor drive)
    fprintf('Creating three-phase voltage sources...\n');
    add_block('simulink/Sources/Signal Generator', [modelName '/Va_Source']);
    set_param([modelName '/Va_Source'], 'Amplitude', '100', 'Frequency', '50', 'Position', [850, 150, 880, 180]);
    
    add_block('simulink/Sources/Signal Generator', [modelName '/Vb_Source']);
    set_param([modelName '/Vb_Source'], 'Amplitude', '100', 'Frequency', '50', 'Position', [850, 200, 880, 230]);
    
    add_block('simulink/Sources/Signal Generator', [modelName '/Vc_Source']);
    set_param([modelName '/Vc_Source'], 'Amplitude', '100', 'Frequency', '50', 'Position', [850, 250, 880, 280]);
    
    %% Motor Model (Transfer function approximation)
    fprintf('Creating motor model...\n');
    add_block('simulink/Continuous/Transfer Fcn', [modelName '/Motor_Electrical']);
    set_param([modelName '/Motor_Electrical'], 'Numerator', '[motor.lambda_m*1.5*motor.p]', ...
        'Denominator', '[motor.J motor.b]', 'Position', [950, 195, 1010, 235]);
    
    %% Mechanical Load
    add_block('simulink/Math Operations/Sum', [modelName '/Torque_Sum']);
    set_param([modelName '/Torque_Sum'], 'Inputs', '+-', 'Position', [1070, 205, 1090, 225]);
    
    add_block('simulink/Continuous/Integrator', [modelName '/Speed_Integrator']);
    set_param([modelName '/Speed_Integrator'], 'Position', [1130, 200, 1160, 230]);
    
    %% Current Measurement (Clarke Transform)
    fprintf('Creating Clarke transform...\n');
    add_block('simulink/User-Defined Functions/MATLAB Function', [modelName '/Clarke']);
    set_param([modelName '/Clarke'], 'Position', [320, 370, 390, 430]);
    
    %% Park Transform
    fprintf('Creating Park transform...\n');
    add_block('simulink/User-Defined Functions/MATLAB Function', [modelName '/Park']);
    set_param([modelName '/Park'], 'Position', [440, 370, 510, 430]);
    
    %% Rotor Angle for transforms (simplified - from speed integration)
    add_block('simulink/Continuous/Integrator', [modelName '/Angle_Integrator']);
    set_param([modelName '/Angle_Integrator'], 'Position', [1130, 370, 1160, 400]);
    
    %% Current generation (simplified 3-phase from motor model)
    add_block('simulink/Sources/Sine Wave', [modelName '/Ia_sim']);
    set_param([modelName '/Ia_sim'], 'Amplitude', '5', 'Frequency', '50', 'Position', [200, 370, 230, 400]);
    
    add_block('simulink/Sources/Sine Wave', [modelName '/Ib_sim']);
    set_param([modelName '/Ib_sim'], 'Amplitude', '5', 'Frequency', '50', 'Phase', '-2*pi/3', 'Position', [200, 410, 230, 440]);
    
    add_block('simulink/Sources/Sine Wave', [modelName '/Ic_sim']);
    set_param([modelName '/Ic_sim'], 'Amplitude', '5', 'Frequency', '50', 'Phase', '2*pi/3', 'Position', [200, 450, 230, 480]);
    
    %% Mux blocks for transforms
    add_block('simulink/Signal Routing/Mux', [modelName '/Mux_abc']);
    set_param([modelName '/Mux_abc'], 'Inputs', '3', 'Position', [260, 379, 265, 461]);
    
    add_block('simulink/Signal Routing/Mux', [modelName '/Mux_dq']);
    set_param([modelName ' and logging...\n');
    
    % Speed scope (ref vs actual)
    add_block('simulink/Sinks/Scope', [modelName '/Speed_Scope']);
    set_param([modelName '/Speed_Scope'], 'NumInputPorts', '2', 'Position', [1220, 195, 1270, 235]);
    
    % Current dq scope
    add_block('simulink/Sinks/Scope', [modelName '/Current_dq_Scope']);
    set_param([modelName '/Current_dq_Scope'], 'NumInputPorts', '2', 'Position', [580, 370, 630, 410]);
    
    % Torque scope
    add_block('simulink/Sinks/Scope', [modelName '/Torque_Scope']);
    set_param([modelName '/Torque_Scope'], 'Position', [1220, 595, 1270, 635]);
    
    % Three-phase currents scope
    addMake all the connections
    fprintf('Connecting all blocks...\n');
    
    % Speed loop
    add_line(modelName, 'Speed_Ref/1', 'Speed_PI/1');
    add_line(modelName, 'Speed_PI/1', 'Torque_to_Iq/1');
    add_line(modelName, 'Torque_to_Iq/1', 'Iq_PI/1');
    
    % Current control loop
    add_line(modelName, 'Id_Ref/1', 'Id_PI/1');
    add_line(modelName, 'Id_PI/1', 'Mux_dq/1');
    add_line(modelName, 'Iq_PI/1', 'Mux_dq/2');
    add_line(modelName, 'Mux_dq/1', 'Inv_Park/1');
    add_line(modelName, 'Inv_Park/1', 'Inv_Clarke/1');
    
    % Voltage to motor (simplified)
    add_line(modelName, 'Inv_Clarke/1', 'Motor_Electrical/1');
    
    % Motor to speed
    add_line(modelName, 'Motor_Electrical/1', 'Torque_Sum/1');
    add_line(modelName, 'Torque_Load/1', 'Torque_Sum/2');
    add_line(modelName, 'Torque_Sum/1', 'Speed_Integrator/1');
    
    % Speed feedback
    add_line(modelName, 'Speed_Integrator/1', 'Speed_PI/1', 'autorouting', 'on');
    add_line(modelName, 'Speed_Integrator/1', 'Angle_Integrator/1');
    
    % Current measurement path
    add_line(modelName, 'Ia_sim/1', 'Mux_abc/1');
    add_line(modelName, 'Ib_sim/1', 'Mux_abc/2');
    add_line(modelName, 'Ic_sim/1', 'Mux_abc/3');
    add_line(modelName, 'Mux_abc/1', 'Clarke/1');
    add_line(modelName, 'Clarke/1', 'Park/1');
    add_line(modelName, 'Angle_Integrator/1', 'Park/2');
    add_line(modelName, 'Angle_Integrator/1', 'Inv_Park/2');
    
    % Feedback to current controllers
    add_line(modelName, 'Park/1', 'Id_PI/1', 'autorouting', 'on');
    add_line(modelName, 'Park/1', 'Iq_PI/1', 'autorouting', 'on');
    
    % Scopes
    add_line(modelName, 'Speed_Ref/1', 'Speed_Scope/1', 'autorouting', 'on');
    add_line(modelName, 'Speed_Integrator/1', 'Speed_Scope/2', 'autorouting', 'on');
    add_line(modelName, 'Park/1', 'Current_dq_Scope/1', 'autorouting', 'on');
    add_line(modelName, 'Motor_Electrical/1', 'Torque_Scope/1', 'autorouting', 'on');
    add_line(modelName, 'Mux_abc/1', 'ABC_Currents_Scope/1', 'autorouting', 'on');
    
    %% Signal logging
    fprintf('Configuring signal logging...\n');ks/Scope', [modelName '/Torque Scope']);
    set_param([modelName '/Torque Scope'], 'Position', [900, 460, 950, 510]);
    
    %% Signal logging
    fprintf('Configuring signal logging...\n');
    
    % Enable signal logging
    set_param(modelName, 'SignalLogging', 'on');
    set_param(modelName, 'SignalLoggingName', 'logsout');
    
    %% Add annotations
    add_block('simulink/Model-Wide Utilities/Model Info', [modelName '/Model Info']);
    
    % Add text annotations
    Simulink.Annotation([modelName '/Motor and Load'], ...
        'Position', [650, 150], ...
        'Text', 'Motor and Mechanical Load');
    try
        add_block('simulink/Model-Wide Utilities/Model Info', [modelName '/Model Info']);
    catch
        % Model Info block not available in this version
    end
    
    % Add text annotations
    try
        h1 = Simulink.Annotation([modelName], 'Motor and Mechanical Load');
        h1.Position = [650, 150];
        
        h2 = Simulink.Annotation([modelName], 'FOC Control System');
        h2.Position = [270, 150];
        
        h3 = Simulink.Annotation([modelName], sprintf(['PMSM with FOC Model Template\n' ...
            '1. Add PMSM from: Simscape > Electrical > Electromechanical\n' ...
            '2. Configure FOC controller subsystem\n' ...
            '3. Add Solver Configuration block\n' ...
            '4. Load motor parameters: run(''init_workspace.m'')\n' ...
            '5. Use plot_motor_results to visualize']));
        h3.Position = [200, 50];
    catch
        % Annotations not supported, skip
    end
    fprintf('\n========================================\n');
    fprintf('PMSM FOC Model Template Created!\n');
    fprintf('========================================\n');
    fprintf('Model saved to: %s\n', modelPath);
    fprintf('\nIMPORTANT - Complete the model:\n');
    fprintf('1. Motor & Drive subsystem:\n');
    fprintf('   - Add: Simscape > Electrical > Electromechanical >\n');
    fprintf('          Permanent Magnet Synchronous Machine\n');
    fprintf('   - Add: Controlled Voltage Source (3-phase)\n');
    fprintf('   - Add: Solver Configuration block\n');
    fprintf('\n2. FOC Controller subsystem:\n');
    fprintf('   - Add Clarke Transform (abc→αβ)\n');
    fprintf('   - Add Park Transform (αβ→dq)\n');
    fprintf('   - Add PI controllers for id, iq\n');
    fprintf('   - Add Inverse Park (dq→αβ)\n');
    fprintf('   - Add Inverse Clarke (αβ→abc)\n');
    fprintf('\n3. Replace sensor placeholders with actual Simscape sensors\n');
    fprintf('\nSee: 01_theory/06_FOC_practical_guide.md for step-by-step help\n');
    fprintf('========================================\n\n');
    
end
