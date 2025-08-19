function runMyTestsV
if ~isdeployed
    fileRootPath = fileparts(which(mfilename));
    disp(["File Root Path: " fileRootPath])
    testFolder = fullfile(fileRootPath, 'allTests');
    disp(["Test Folder: " testFolder])
end
if isdeployed
    suite = matlab.unittest.TestSuite.fromFolder('allTests');
else
    suite = matlab.unittest.TestSuite.fromFolder(testFolder);
end
disp(suite)
runner = matlab.unittest.TestRunner.withNoPlugins;
results = runner.run(suite);
disp(results)
end
