function runMyTests
import matlab.unittest.plugins.CodeCoveragePlugin
import matlab.unittest.plugins.codecoverage.CoverageReport
fileRootPath = fileparts(which(mfilename));
disp(["File Root Path: " fileRootPath])
testFolder = fullfile(fileRootPath, 'allTests');
runner = testrunner("textoutput");
reportFolder = "coverageReport";
reportFormat2 = CoverageReport(reportFolder);
plugin1 = CodeCoveragePlugin.forFolder(fileRootPath, Producing=reportFormat2);
runner.addPlugin(plugin1);
suite = matlab.unittest.TestSuite.fromFolder(testFolder);
results = runner.run(suite);
generateHTMLReport(results, 'TestsReport')
end
