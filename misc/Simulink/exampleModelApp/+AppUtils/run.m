appFolder = fullfile(fileparts(mfilename("fullpath")), '..');
mlappFile = fullfile(appFolder, 'RectifierApp');
run(mlappFile);
