function BUILD_AND_PACKAGE()
% BUILD_AND_PACKAGE - ONE COMMAND to create complete distribution package
%
% This function does EVERYTHING:
%   1. Browse for Simulink model
%   2. Compile model to DLL
%   3. Compile GUI to EXE
%   4. Create distribution package with all files
%
% Usage:
%   Just run: BUILD_AND_PACKAGE
%
% No arguments needed! Just run it and follow the prompts.

    fprintf('\n');
    fprintf('╔════════════════════════════════════════════════════════════╗\n');
    fprintf('║   ONE-COMMAND BUILD & PACKAGE                             ║\n');
    fprintf('║   Creates complete distribution for end users             ║\n');
    fprintf('╚════════════════════════════════════════════════════════════╝\n\n');
    
    %% Step 1: Browse for model
    fprintf('Step 1: Select your Simulink model...\n');
    
    [file, path] = uigetfile('*.slx', 'Select Simulink Model to Package');
    if isequal(file, 0)
        fprintf('   Cancelled by user.\n');
        return;
    end
    
    % Add model path
    addpath(path);
    
    % Get model name (without extension)
    [~, modelName, ~] = fileparts(file);
    fprintf('   ✓ Selected: %s\n', modelName);
    
    %% Step 2: Check prerequisites
    fprintf('\nStep 2: Checking prerequisites...\n');
    
    % Check MEX compiler
    try
        cc = mex.getCompilerConfigurations('C', 'Selected');
        if isempty(cc)
            error('No MEX compiler configured. Run: mex -setup');
        end
        fprintf('   ✓ MEX compiler: %s\n', cc.Name);
    catch
        error('MEX compiler required. Run: mex -setup');
    end
    
    % Check Simulink Coder
    if ~license('test', 'Simulink_Coder') && ~license('test', 'Real-Time_Workshop')
        error('Simulink Coder license required for code generation');
    end
    fprintf('   ✓ Simulink Coder available\n');
    
    % Check MATLAB Compiler
    if ~license('test', 'Compiler')
        error('MATLAB Compiler license required for EXE creation');
    end
    fprintf('   ✓ MATLAB Compiler available\n');
    
    %% Step 3: Create MATLAB equivalent of model
    fprintf('\n╔════════════════════════════════════════════════════════════╗\n');
    fprintf('║   Step 3: Creating MATLAB Function from Model             ║\n');
    fprintf('╚════════════════════════════════════════════════════════════╝\n\n');
    
    % Generate MATLAB equivalent
    matlabFunctionFile = [modelName '_matlab.m'];
    if ~exist(matlabFunctionFile, 'file')
        fprintf('   Generating MATLAB equivalent...\n');
        createModelMATLABEquivalent(modelName);
    else
        fprintf('   ✓ MATLAB function exists: %s\n', matlabFunctionFile);
    end
    
    %% Step 4: Create output folder
    fprintf('\n╔════════════════════════════════════════════════════════════╗\n');
    fprintf('║   Step 4: Creating Output Directory                       ║\n');
    fprintf('╚════════════════════════════════════════════════════════════╝\n\n');
    
    timestamp = datestr(now, 'yyyymmdd_HHMMSS');
    outputFolder = sprintf('Distribution_%s_%s', modelName, timestamp);
    mkdir(outputFolder);
    fprintf('   ✓ Created: %s\n', outputFolder);
    
    %% Step 5: Compile GUI to EXE
    fprintf('\n╔════════════════════════════════════════════════════════════╗\n');
    fprintf('║   Step 5: Compiling GUI + Model to EXE                    ║\n');
    fprintf('║   (This takes 5-10 minutes - please be patient!)          ║\n');
    fprintf('╚════════════════════════════════════════════════════════════╝\n\n');
    
    exeName = 'DynamicModelGUI';
    
    fprintf('   Building standalone EXE with:\n');
    fprintf('     - DynamicModelGUI.m (GUI)\n');
    fprintf('     - ModelParameterParser.m (Parser)\n');
    fprintf('     - %s (MATLAB function - no Simulink needed!)\n\n', matlabFunctionFile);
    
    try
        % Build the EXE with MATLAB function (not .slx - no Simulink Runtime needed!)
        % -o takes just the name, -d specifies the output directory
        mcc('-m', 'DynamicModelGUI.m', ...
            '-a', 'ModelParameterParser.m', ...
            '-a', matlabFunctionFile, ...
            '-o', exeName, ...
            '-d', outputFolder, ...
            '-v');
        
        fprintf('\n   ✓ EXE compilation successful!\n');
        fprintf('     EXE: %s\n', fullfile(outputFolder, [exeName '.exe']));
        
    catch ME
        fprintf('   ✗ EXE compilation failed: %s\n', ME.message);
        error('Cannot create distribution without EXE');
    end
    
    %% Step 6: Copy runtime requirements
    fprintf('\n╔════════════════════════════════════════════════════════════╗\n');
    fprintf('║   Step 6: Copying Runtime Requirements                    ║\n');
    fprintf('╚════════════════════════════════════════════════════════════╝\n\n');
    
    % Copy requiredMCRProducts.txt if it exists
    if exist('requiredMCRProducts.txt', 'file')
        copyfile('requiredMCRProducts.txt', fullfile(outputFolder, 'requiredMCRProducts.txt'));
        fprintf('   ✓ Copied requiredMCRProducts.txt\n');
    end
    
    %% Step 7: Create documentation
    fprintf('\n╔════════════════════════════════════════════════════════════╗\n');
    fprintf('║   Step 7: Creating User Documentation                     ║\n');
    fprintf('╚════════════════════════════════════════════════════════════╝\n\n');
    
    % Create simple README
    readmePath = fullfile(outputFolder, 'README.txt');
    fid = fopen(readmePath, 'w');
    fprintf(fid, '========================================\n');
    fprintf(fid, 'Dynamic Model GUI - %s\n', modelName);
    fprintf(fid, '========================================\n\n');
    fprintf(fid, 'INSTALLATION:\n');
    fprintf(fid, '1. Install MATLAB Runtime R2024b (FREE, no license needed)\n');
    fprintf(fid, '   Download: https://www.mathworks.com/products/compiler/matlab-runtime.html\n\n');
    fprintf(fid, 'USAGE:\n');
    fprintf(fid, '1. Double-click DynamicModelGUI.exe\n');
    fprintf(fid, '2. Modify parameters in the GUI\n');
    fprintf(fid, '3. Click "Run Simulation"\n');
    fprintf(fid, '4. View results\n\n');
    fprintf(fid, 'FILES:\n');
    fprintf(fid, '- DynamicModelGUI.exe : Main application (contains GUI + Model)\n');
    fprintf(fid, '- README.txt : This file\n\n');
    fprintf(fid, 'REQUIREMENTS:\n');
    fprintf(fid, '- Windows 10/11 (64-bit)\n');
    fprintf(fid, '- MATLAB Runtime R2024b (FREE)\n');
    fprintf(fid, '- NO MATLAB license required!\n');
    fclose(fid);
    fprintf('   ✓ Created README.txt\n');
    
    %% Step 8: Create ZIP
    fprintf('\n╔════════════════════════════════════════════════════════════╗\n');
    fprintf('║   Step 8: Creating ZIP Archive                            ║\n');
    fprintf('╚════════════════════════════════════════════════════════════╝\n\n');
    
    zipFile = [outputFolder '.zip'];
    zip(zipFile, outputFolder);
    zipInfo = dir(zipFile);
    fprintf('   ✓ Created: %s (%.1f MB)\n', zipFile, zipInfo.bytes/1024/1024);
    
    %% Final Summary
    fprintf('\n');
    fprintf('╔════════════════════════════════════════════════════════════╗\n');
    fprintf('║   SUCCESS! Distribution Ready!                            ║\n');
    fprintf('╚════════════════════════════════════════════════════════════╝\n\n');
    
    fprintf('📦 Your Distribution Package:\n');
    fprintf('   📁 Folder: %s\n', outputFolder);
    fprintf('   📦 ZIP:    %s\n\n', zipFile);
    
    fprintf('📄 Package Contents:\n');
    fprintf('   ✓ DynamicModelGUI.exe - Standalone app with embedded model\n');
    fprintf('   ✓ README.txt - Installation & usage instructions\n\n');
    
    fprintf('🎁 To Share with End Users:\n');
    fprintf('   1. Send them: %s\n', zipFile);
    fprintf('   2. They install MATLAB Runtime R2024b (FREE, one-time)\n');
    fprintf('      https://www.mathworks.com/products/compiler/matlab-runtime.html\n');
    fprintf('   3. They extract ZIP and run DynamicModelGUI.exe\n\n');
    
    fprintf('💡 What End Users Need:\n');
    fprintf('   ✓ Windows 10/11 (64-bit)\n');
    fprintf('   ✓ MATLAB Runtime R2024b - FREE download, no license!\n');
    fprintf('   ✗ They do NOT need MATLAB installed\n');
    fprintf('   ✗ They do NOT need any MATLAB license\n\n');
    
    fprintf('═══════════════════════════════════════════════════════════\n');
    fprintf('✓ All files in: %s\n', outputFolder);
    fprintf('✓ Share file:   %s\n', zipFile);
    fprintf('═══════════════════════════════════════════════════════════\n\n');
    
    % Open the output folder
    if ispc
        winopen(outputFolder);
    end
    
end
