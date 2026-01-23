function START_HERE()
% START_HERE - One-click startup for Dynamic Model GUI system
%
% This function sets up everything and launches the demo
%
% Just run: START_HERE

    fprintf('\n');
    fprintf('╔═══════════════════════════════════════════════════════════╗\n');
    fprintf('║   Dynamic Model GUI System - Startup                     ║\n');
    fprintf('╚═══════════════════════════════════════════════════════════╝\n\n');
    
    %% Step 1: Setup path
    fprintf('Step 1: Setting up MATLAB path...\n');
    currentDir = fileparts(mfilename('fullpath'));
    addpath(currentDir);
    fprintf('   ✓ Added: %s\n', currentDir);
    
    %% Step 2: Check prerequisites
    fprintf('\nStep 2: Checking prerequisites...\n');
    
    % Check Simulink
    if license('test', 'Simulink')
        fprintf('   ✓ Simulink available\n');
    else
        fprintf('   ⚠ Simulink not available - some features may not work\n');
    end
    
    % Check MEX compiler (optional for DLL)
    try
        cc = mex.getCompilerConfigurations('C', 'Selected');
        if ~isempty(cc)
            fprintf('   ✓ MEX compiler: %s\n', cc.Name);
        else
            fprintf('   ⚠ MEX compiler not configured (optional for DLL)\n');
        end
    catch
        fprintf('   ⚠ MEX compiler not available (optional for DLL)\n');
    end
    
    % Check Simulink Coder (optional for DLL)
    if license('test', 'Simulink_Coder') || license('test', 'Real-Time_Workshop')
        fprintf('   ✓ Simulink Coder available\n');
    else
        fprintf('   ⚠ Simulink Coder not available (optional for DLL)\n');
    end
    
    %% Step 3: Display menu
    fprintf('\n');
    fprintf('╔═══════════════════════════════════════════════════════════╗\n');
    fprintf('║   What would you like to do?                             ║\n');
    fprintf('╚═══════════════════════════════════════════════════════════╝\n\n');
    
    fprintf('1. 🚀 BUILD & PACKAGE - Create complete distribution (ONE COMMAND!)\n');
    fprintf('2. Quick Start Demo (30 seconds) - Test the system\n');
    fprintf('3. Full Demo with DLL Compilation (3-5 minutes)\n');
    fprintf('4. Create Model Only\n');
    fprintf('5. Launch GUI with Existing Model\n');
    fprintf('6. View Documentation\n');
    fprintf('7. Exit\n\n');
    
    choice = input('Enter your choice (1-7): ', 's');
    
    fprintf('\n');
    
    switch choice
        case '1'
            % BUILD & PACKAGE - The ultimate one-command solution!
            fprintf('╔═══════════════════════════════════════════════════════════╗\n');
            fprintf('║   BUILD & PACKAGE - Complete Distribution Creator        ║\n');
            fprintf('╚═══════════════════════════════════════════════════════════╝\n\n');
            fprintf('This will:\n');
            fprintf('  1. Browse for your Simulink model\n');
            fprintf('  2. Compile model to DLL\n');
            fprintf('  3. Compile GUI to EXE\n');
            fprintf('  4. Create distribution package\n\n');
            fprintf('Total time: ~5-15 minutes\n\n');
            
            proceed = input('Continue? (y/n): ', 's');
            if strcmpi(proceed, 'y')
                BUILD_AND_PACKAGE
            else
                fprintf('Cancelled.\n');
            end
            
        case '2'
            % Quick demo
            fprintf('Launching quick demo...\n\n');
            testDynamicGUI
            
        case '3'
            % Full demo
            fprintf('Launching full demo with DLL compilation...\n');
            fprintf('Note: This requires MEX compiler and Simulink Coder\n\n');
            demoCompleteWorkflow
            
        case '4'
            % Create model only
            fprintf('Creating SimpleAdditionModel...\n\n');
            createSimpleAdditionModel
            fprintf('\nModel created! Open it with: open_system(''SimpleAdditionModel'')\n\n');
            
        case '5'
            % Launch GUI with existing model
            modelName = input('Enter model name (without .slx): ', 's');
            if ~isempty(modelName)
                fprintf('Launching GUI for %s...\n\n', modelName);
                try
                    DynamicModelGUI(modelName);
                catch ME
                    fprintf('Error: %s\n', ME.message);
                end
            end
            
        case '6'
            % View documentation
            fprintf('Opening documentation files...\n\n');
            fprintf('Available documentation:\n');
            fprintf('  - README.md - Overview and quick start\n');
            fprintf('  - ACTION_ITEMS.md - Detailed action items\n');
            fprintf('  - README_Deployment.md - Deployment guide\n');
            fprintf('  - QUICK_START.m - Quick reference commands\n\n');
            
            % Try to open README
            readmePath = fullfile(currentDir, 'README.md');
            if ispc
                system(['start "" "' readmePath '"']);
            elseif ismac
                system(['open "' readmePath '"']);
            else
                system(['xdg-open "' readmePath '"']);
            end
            
        case '7'
            fprintf('Goodbye!\n\n');
            
        otherwise
            fprintf('Invalid choice. Please run START_HERE again.\n\n');
    end
    
    fprintf('\n');
    fprintf('═══════════════════════════════════════════════════════════\n');
    fprintf('Tip: Type "help START_HERE" for more information\n');
    fprintf('═══════════════════════════════════════════════════════════\n\n');
    
end
