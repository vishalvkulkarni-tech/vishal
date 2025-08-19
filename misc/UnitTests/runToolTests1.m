import matlab.unittest.plugins.CodeCoveragePlugin
import matlab.unittest.plugins.codecoverage.CoverageReport
runner = testrunner("textoutput");
% Add the TestRunProgressPlugin to show progress in the Test Browser
runner.addPlugin(matlab.unittest.plugins.TestRunProgressPlugin.withVerbosity(matlab.unittest.Verbosity.Detailed));
sourceCodeFolder = pwd;
testFolder = fullfile(sourceCodeFolder, 'allTests');
reportFolder = "coverageReport";
reportFormat2 = CoverageReport(reportFolder);
plugin1 = CodeCoveragePlugin.forFolder(sourceCodeFolder, Producing=reportFormat2);
runner.addPlugin(plugin1);
suite = matlab.unittest.TestSuite.fromFolder(testFolder);
results = runner.run(suite);