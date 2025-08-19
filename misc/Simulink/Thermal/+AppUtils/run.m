appFolder = fullfile(fileparts(mfilename("fullpath")), '..');
mlappFile = fullfile(appFolder, 'IGBTThermalTempBehav');
run(mlappFile);
