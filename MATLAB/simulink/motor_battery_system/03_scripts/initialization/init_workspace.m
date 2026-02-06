%% Initialization Script - Motor and Battery System
% This script initializes the workspace for motor and battery simulations
% Run this script before opening any Simulink models

clear all;
close all;
clc;

fprintf('\n========================================\n');
fprintf('Motor & Battery System Initialization\n');
fprintf('========================================\n\n');

%% Set Path
% Add all subdirectories to MATLAB path
% Get project root (go up two levels from this script location)
scriptPath = mfilename('fullpath');
if isempty(scriptPath)
    % Script was run from command line, use current directory
    projectRoot = pwd;
    % Navigate up to project root if we're in a subdirectory
    if contains(projectRoot, '03_scripts')
        projectRoot = fileparts(fileparts(projectRoot));
    end
else
    projectRoot = fileparts(fileparts(scriptPath));
end

% Change to project root
cd(projectRoot);
addpath(genpath(projectRoot));
fprintf('Project root: %s\n', projectRoot);
fprintf('All subdirectories added to path.\n\n');

%% Load Motor Parameters
fprintf('Loading motor parameters...\n');
run(fullfile(projectRoot, '05_data', 'motor_parameters', 'PMSM_example.m'));
fprintf('Motor parameters loaded successfully.\n\n');

%% Load Battery Parameters
fprintf('Loading battery parameters...\n');
run(fullfile(projectRoot, '05_data', 'battery_parameters', 'LG_INR18650_MJ1.m'));
fprintf('Battery parameters loaded successfully.\n\n');

%% Load Drive Cycle (optional)
% Uncomment to load a standard drive cycle
% fprintf('Loading drive cycle...\n');
% run(fullfile(projectRoot, '05_data', 'drive_cycles', 'UDDS.m'));
% fprintf('Drive cycle loaded successfully.\n\n');

%% Simulation Settings
sim_config.solver = 'ode23t';           % Solver for stiff systems
sim_config.RelTol = 1e-3;               % Relative tolerance
sim_config.AbsTol = 1e-6;               % Absolute tolerance
sim_config.StopTime = '2.0';            % Simulation time [s]

% Fixed-step settings (for code generation)
sim_config.fixed_step = false;          % Use variable step by default
sim_config.FixedStepSize = '1e-5';      % Fixed step size if enabled [s]

fprintf('Simulation configuration:\n');
fprintf('  Solver: %s\n', sim_config.solver);
fprintf('  RelTol: %.0e\n', sim_config.RelTol);
fprintf('  AbsTol: %.0e\n', sim_config.AbsTol);
fprintf('  Stop Time: %s s\n', sim_config.StopTime);
fprintf('\n');

%% Configure Simscape
fprintf('Configuring Simscape...\n');

% Electrical settings
electrical.solver_type = 'Backward Euler';
electrical.use_local_solver = false;

% Thermal settings
thermal.enable = true;
thermal.T_amb_K = thermal.T_amb + 273.15;  % Convert to Kelvin

fprintf('Simscape configuration complete.\n\n');

%% Workspace Variables Summary
fprintf('========================================\n');
fprintf('Workspace Variables Available:\n');
fprintf('========================================\n');
fprintf('motor       - Motor parameters and specifications\n');
fprintf('ctrl        - Control parameters (PI gains, limits)\n');
fprintf('battery     - Battery cell parameters\n');
fprintf('pack        - Battery pack configuration\n');
fprintf('thermal     - Thermal parameters\n');
fprintf('bms         - Battery Management System parameters\n');
fprintf('sim_config  - Simulation configuration\n');
fprintf('dclink      - DC link parameters\n');
fprintf('========================================\n\n');

%% Quick Access Functions
fprintf('Quick Start Commands:\n');
fprintf('========================================\n');
fprintf('Open motor model:    open_system(''PMSM_FOC.slx'')\n');
fprintf('Open battery model:  open_system(''battery_thevenin_2RC.slx'')\n');
fprintf('Run simulation:      sim(''model_name.slx'')\n');
fprintf('Plot results:        plot_motor_results or plot_battery_results\n');
fprintf('========================================\n\n');

fprintf('Initialization complete!\n\n');
