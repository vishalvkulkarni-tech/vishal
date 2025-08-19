appFolder = fullfile(fileparts(mfilename("fullpath")), '..');
mlappFile = fullfile(appFolder, 'upCounter_SLSimApp');
run(mlappFile);
