appFolder = fullfile(fileparts(mfilename("fullpath")), '..');
deployFolder = fullfile(appFolder, 'deployedDesktopApp');
assert(isfolder(deployFolder), 'Run ''AppUtils.deployDesktopApp'' first.');
system(fullfile(deployFolder, "IGBTThermalTempBehav.exe"));
