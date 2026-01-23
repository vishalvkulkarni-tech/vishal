function createDistributionPackage(modelName, varargin)
% createDistributionPackage - Create complete distribution package for end users
%
% This function automatically creates a distribution-ready package containing:
%   - Compiled EXE
%   - Model DLL
%   - Header files
%   - End user documentation
%   - Installation instructions
%
% Usage:
%   createDistributionPackage('SimpleAdditionModel')
%   createDistributionPackage('MyModel', 'Version', 'v1.0')
%   createDistributionPackage('MyModel', 'OutputDir', 'C:\Releases')
%
% Prerequisites:
%   - Model must be compiled to DLL (run autoCompileModelToDLL first)
%   - GUI must be compiled to EXE (run mcc command first)

    %% Parse inputs
    p = inputParser;
    addRequired(p, 'modelName', @ischar);
    addParameter(p, 'Version', 'v1.0', @ischar);
    addParameter(p, 'OutputDir', pwd, @ischar);
    addParameter(p, 'ExeName', 'DynamicModelGUI.exe', @ischar);
    parse(p, modelName, varargin{:});
    
    version = p.Results.Version;
    outputDir = p.Results.OutputDir;
    exeName = p.Results.ExeName;
    
    %% Display header
    fprintf('\n');
    fprintf('╔════════════════════════════════════════════════════════╗\n');
    fprintf('║   Creating Distribution Package                      ║\n');
    fprintf('╚════════════════════════════════════════════════════════╝\n\n');
    
    %% Step 1: Verify required files exist
    fprintf('Step 1: Verifying required files...\n');
    
    % Check EXE
    if ~exist(exeName, 'file')
        error(['EXE not found: %s\n' ...
               'Run: mcc -m DynamicModelGUI.m -a ModelParameterParser.m -a %s_dll.%s'], ...
               exeName, modelName, mexext);
    end
    fprintf('   ✓ Found EXE: %s\n', exeName);
    
    % Check DLL or wrapper
    dllName = [modelName '_dll.' mexext];
    wrapperName = [modelName '_run.m'];
    
    hasDLL = exist(dllName, 'file');
    hasWrapper = exist(wrapperName, 'file');
    
    if hasDLL
        fprintf('   ✓ Found DLL: %s\n', dllName);
        modelFile = dllName;
    elseif hasWrapper
        fprintf('   ✓ Found wrapper: %s\n', wrapperName);
        modelFile = wrapperName;
    else
        error(['Model file not found: %s or %s\n' ...
               'Run: autoCompileModelToDLL_v2(''%s'')'], dllName, wrapperName, modelName);
    end
    
    % Check header
    headerName = [modelName '.h'];
    if ~exist(headerName, 'file')
        warning('Header file not found: %s (optional)', headerName);
        hasHeader = false;
    else
        fprintf('   ✓ Found Header: %s\n', headerName);
        hasHeader = true;
    end
    
    %% Step 2: Create distribution folder
    fprintf('\nStep 2: Creating distribution folder...\n');
    
    distFolder = fullfile(outputDir, sprintf('DynamicModelGUI_%s_%s', modelName, version));
    if exist(distFolder, 'dir')
        fprintf('   ! Folder exists, will overwrite\n');
        rmdir(distFolder, 's');
    end
    mkdir(distFolder);
    fprintf('   ✓ Created: %s\n', distFolder);
    
    %% Step 3: Copy files
    fprintf('\nStep 3: Copying files...\n');
    
    % Copy EXE
    copyfile(exeName, fullfile(distFolder, exeName));
    exeInfo = dir(exeName);
    fprintf('   ✓ Copied EXE (%s)\n', formatFileSize(exeInfo.bytes));
    
    % Copy model file (DLL or wrapper)
    copyfile(modelFile, fullfile(distFolder, modelFile));
    modelInfo = dir(modelFile);
    fprintf('   ✓ Copied Model file (%s)\n', formatFileSize(modelInfo.bytes));
    
    % Copy header if exists
    if hasHeader
        copyfile(headerName, fullfile(distFolder, headerName));
        fprintf('   ✓ Copied Header\n');
    end
    
    % Copy requiredMCRProducts.txt if exists
    if exist('requiredMCRProducts.txt', 'file')
        copyfile('requiredMCRProducts.txt', fullfile(distFolder, 'requiredMCRProducts.txt'));
        fprintf('   ✓ Copied Runtime requirements\n');
    end
    
    %% Step 4: Create end user documentation
    fprintf('\nStep 4: Creating documentation...\n');
    
    createEndUserReadme(distFolder, modelName);
    fprintf('   ✓ Created README_EndUser.txt\n');
    
    createQuickStart(distFolder);
    fprintf('   ✓ Created QUICK_START.txt\n');
    
    createTroubleshooting(distFolder);
    fprintf('   ✓ Created TROUBLESHOOTING.txt\n');
    
    %% Step 5: Create version info file
    fprintf('\nStep 5: Creating version info...\n');
    
    createVersionInfo(distFolder, modelName, version);
    fprintf('   ✓ Created VERSION_INFO.txt\n');
    
    %% Step 6: Create ZIP archive (optional)
    fprintf('\nStep 6: Creating ZIP archive...\n');
    
    zipName = [distFolder '.zip'];
    zip(zipName, distFolder);
    fprintf('   ✓ Created: %s\n', zipName);
    
    %% Summary
    fprintf('\n');
    fprintf('╔════════════════════════════════════════════════════════╗\n');
    fprintf('║   Distribution Package Created Successfully!         ║\n');
    fprintf('╚════════════════════════════════════════════════════════╝\n\n');
    
    fprintf('Distribution contents:\n');
    fprintf('  📦 Folder: %s\n', distFolder);
    fprintf('  🗜️  ZIP:    %s\n\n', zipName);
    
    fprintf('Share with end users:\n');
    fprintf('  Option 1: Send ZIP file (%s)\n', formatFileSize(getFileSize(zipName)));
    fprintf('  Option 2: Upload folder to cloud and share link\n\n');
    
    fprintf('End users need:\n');
    fprintf('  ✓ Extract ZIP\n');
    fprintf('  ✓ Install MATLAB Runtime (one time, free)\n');
    fprintf('  ✓ Run %s\n\n', exeName);
    
    fprintf('Runtime download link:\n');
    fprintf('  https://www.mathworks.com/products/compiler/matlab-runtime.html\n\n');
    
    % Open folder
    if ispc
        winopen(distFolder);
    end
end

%% Helper Functions

function createEndUserReadme(distFolder, modelName)
    filename = fullfile(distFolder, 'README_EndUser.txt');
    fid = fopen(filename, 'w');
    
    fprintf(fid, '================================================================================\n');
    fprintf(fid, '  DYNAMIC MODEL GUI - End User Guide\n');
    fprintf(fid, '  Model: %s\n', modelName);
    fprintf(fid, '  Date: %s\n', datestr(now, 'yyyy-mm-dd'));
    fprintf(fid, '================================================================================\n\n');
    
    fprintf(fid, 'QUICK START\n');
    fprintf(fid, '-----------\n\n');
    fprintf(fid, '1. Install MATLAB Runtime (one time only)\n');
    fprintf(fid, '   See INSTALLATION section below\n\n');
    fprintf(fid, '2. Double-click DynamicModelGUI.exe\n\n');
    fprintf(fid, '3. Modify parameters and click "Run Simulation"\n\n');
    
    fprintf(fid, 'INSTALLATION\n');
    fprintf(fid, '------------\n\n');
    fprintf(fid, '1. Download MATLAB Runtime:\n');
    fprintf(fid, '   https://www.mathworks.com/products/compiler/matlab-runtime.html\n\n');
    fprintf(fid, '2. Check requiredMCRProducts.txt for exact version needed\n\n');
    fprintf(fid, '3. Install MATLAB Runtime (takes ~10 minutes, ~2 GB)\n\n');
    fprintf(fid, '4. Extract all files to a folder:\n');
    fprintf(fid, '   - DynamicModelGUI.exe\n');
    fprintf(fid, '   - %s_dll.%s\n', modelName, mexext);
    fprintf(fid, '   - %s.h\n', modelName);
    fprintf(fid, '   - Documentation files\n\n');
    
    fprintf(fid, 'USAGE\n');
    fprintf(fid, '-----\n\n');
    fprintf(fid, '1. Launch Application:\n');
    fprintf(fid, '   - Double-click DynamicModelGUI.exe\n');
    fprintf(fid, '   - Wait for GUI to load (~5-10 seconds first time)\n\n');
    
    fprintf(fid, '2. Modify Parameters:\n');
    fprintf(fid, '   - Parameters appear in left panel\n');
    fprintf(fid, '   - Edit values directly in text fields\n');
    fprintf(fid, '   - Select options from dropdowns\n\n');
    
    fprintf(fid, '3. Run Simulation:\n');
    fprintf(fid, '   - Click "Run Simulation" button\n');
    fprintf(fid, '   - View results in results panel\n');
    fprintf(fid, '   - Plots will appear in separate window\n\n');
    
    fprintf(fid, '4. Save Configuration:\n');
    fprintf(fid, '   - Click "Save Model" to save parameter changes\n\n');
    
    fprintf(fid, 'SYSTEM REQUIREMENTS\n');
    fprintf(fid, '-------------------\n\n');
    fprintf(fid, '- Windows 10/11 (64-bit)\n');
    fprintf(fid, '- 4 GB RAM minimum (8 GB recommended)\n');
    fprintf(fid, '- 3 GB free disk space (for MATLAB Runtime)\n');
    fprintf(fid, '- Screen resolution: 1280x720 or higher\n\n');
    
    fprintf(fid, 'IMPORTANT NOTES\n');
    fprintf(fid, '---------------\n\n');
    fprintf(fid, '- NO MATLAB LICENSE REQUIRED!\n');
    fprintf(fid, '- MATLAB Runtime is FREE\n');
    fprintf(fid, '- All files must be in same folder\n');
    fprintf(fid, '- First launch may take 10-15 seconds\n\n');
    
    fprintf(fid, 'TROUBLESHOOTING\n');
    fprintf(fid, '---------------\n\n');
    fprintf(fid, 'See TROUBLESHOOTING.txt for detailed solutions\n\n');
    
    fprintf(fid, 'Common issues:\n');
    fprintf(fid, '- "MATLAB Runtime not found" → Install Runtime\n');
    fprintf(fid, '- "DLL not found" → Keep all files in same folder\n');
    fprintf(fid, '- Application crashes → Check Windows Event Viewer\n\n');
    
    fprintf(fid, 'SUPPORT\n');
    fprintf(fid, '-------\n\n');
    fprintf(fid, 'For technical support, contact your application provider.\n\n');
    
    fprintf(fid, '================================================================================\n');
    
    fclose(fid);
end

function createQuickStart(distFolder)
    filename = fullfile(distFolder, 'QUICK_START.txt');
    fid = fopen(filename, 'w');
    
    fprintf(fid, '================================================================================\n');
    fprintf(fid, '  QUICK START GUIDE\n');
    fprintf(fid, '================================================================================\n\n');
    
    fprintf(fid, 'FIRST TIME SETUP (10 minutes)\n');
    fprintf(fid, '------------------------------\n\n');
    fprintf(fid, '1. Install MATLAB Runtime:\n');
    fprintf(fid, '   → Go to: https://www.mathworks.com/products/compiler/matlab-runtime.html\n');
    fprintf(fid, '   → Download version shown in requiredMCRProducts.txt\n');
    fprintf(fid, '   → Run installer (takes ~10 minutes)\n\n');
    
    fprintf(fid, '2. Extract all files to a folder\n\n');
    
    fprintf(fid, 'EVERY TIME USE\n');
    fprintf(fid, '--------------\n\n');
    fprintf(fid, '1. Double-click DynamicModelGUI.exe\n');
    fprintf(fid, '2. Wait for GUI to open (~5 seconds)\n');
    fprintf(fid, '3. Modify parameters\n');
    fprintf(fid, '4. Click "Run Simulation"\n');
    fprintf(fid, '5. View results\n\n');
    
    fprintf(fid, "THAT'S IT!\n\n");
    
    fprintf(fid, '================================================================================\n');
    
    fclose(fid);
end

function createTroubleshooting(distFolder)
    filename = fullfile(distFolder, 'TROUBLESHOOTING.txt');
    fid = fopen(filename, 'w');
    
    fprintf(fid, '================================================================================\n');
    fprintf(fid, '  TROUBLESHOOTING GUIDE\n');
    fprintf(fid, '================================================================================\n\n');
    
    fprintf(fid, 'PROBLEM: "MATLAB Runtime not found"\n');
    fprintf(fid, 'SOLUTION:\n');
    fprintf(fid, '  1. Download MATLAB Runtime from MathWorks website\n');
    fprintf(fid, '  2. Check requiredMCRProducts.txt for exact version\n');
    fprintf(fid, '  3. Install Runtime (free, no license needed)\n');
    fprintf(fid, '  4. Restart application\n\n');
    
    fprintf(fid, 'PROBLEM: "DLL not found" or "Missing file"\n');
    fprintf(fid, 'SOLUTION:\n');
    fprintf(fid, '  1. Ensure ALL files are in the same folder\n');
    fprintf(fid, '  2. Do not move/rename files\n');
    fprintf(fid, '  3. Re-extract from ZIP if needed\n\n');
    
    fprintf(fid, 'PROBLEM: Application crashes on startup\n');
    fprintf(fid, 'SOLUTION:\n');
    fprintf(fid, '  1. Check Windows Event Viewer for error details\n');
    fprintf(fid, '  2. Verify MATLAB Runtime version matches\n');
    fprintf(fid, '  3. Try running as Administrator\n');
    fprintf(fid, '  4. Check antivirus is not blocking\n\n');
    
    fprintf(fid, 'PROBLEM: Slow performance\n');
    fprintf(fid, 'SOLUTION:\n');
    fprintf(fid, '  1. First launch is always slower (~15 seconds)\n');
    fprintf(fid, '  2. Close other applications\n');
    fprintf(fid, '  3. Ensure adequate RAM (4 GB minimum)\n\n');
    
    fprintf(fid, 'PROBLEM: GUI appears but simulation fails\n');
    fprintf(fid, 'SOLUTION:\n');
    fprintf(fid, '  1. Check parameter values are valid\n');
    fprintf(fid, '  2. Review error message in results panel\n');
    fprintf(fid, '  3. Try with default parameter values\n\n');
    
    fprintf(fid, 'Still having issues?\n');
    fprintf(fid, 'Contact your application provider with:\n');
    fprintf(fid, '  - Windows version\n');
    fprintf(fid, '  - Error message (screenshot)\n');
    fprintf(fid, '  - Steps to reproduce\n\n');
    
    fprintf(fid, '================================================================================\n');
    
    fclose(fid);
end

function createVersionInfo(distFolder, modelName, version)
    filename = fullfile(distFolder, 'VERSION_INFO.txt');
    fid = fopen(filename, 'w');
    
    fprintf(fid, '================================================================================\n');
    fprintf(fid, '  VERSION INFORMATION\n');
    fprintf(fid, '================================================================================\n\n');
    
    fprintf(fid, 'Application: Dynamic Model GUI\n');
    fprintf(fid, 'Model: %s\n', modelName);
    fprintf(fid, 'Version: %s\n', version);
    fprintf(fid, 'Build Date: %s\n', datestr(now, 'yyyy-mm-dd HH:MM:SS'));
    fprintf(fid, 'MATLAB Version: %s\n', version('-release'));
    fprintf(fid, 'Platform: %s\n\n', computer);
    
    fprintf(fid, 'Package Contents:\n');
    fprintf(fid, '  - DynamicModelGUI.exe (Main application)\n');
    fprintf(fid, '  - %s_dll.%s (Simulation engine)\n', modelName, mexext);
    fprintf(fid, '  - %s.h (Header file)\n', modelName);
    fprintf(fid, '  - Documentation files\n\n');
    
    fprintf(fid, '================================================================================\n');
    
    fclose(fid);
end

function sizeStr = formatFileSize(bytes)
    if bytes < 1024
        sizeStr = sprintf('%d B', bytes);
    elseif bytes < 1024^2
        sizeStr = sprintf('%.1f KB', bytes/1024);
    elseif bytes < 1024^3
        sizeStr = sprintf('%.1f MB', bytes/1024^2);
    else
        sizeStr = sprintf('%.1f GB', bytes/1024^3);
    end
end

function bytes = getFileSize(filename)
    info = dir(filename);
    if ~isempty(info)
        bytes = info.bytes;
    else
        bytes = 0;
    end
end
