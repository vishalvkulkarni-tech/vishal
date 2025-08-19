classdef TestRand2 < matlab.unittest.TestCase
    properties
        fileRootPath
    end
    methods (TestClassSetup)
        function testClassSetUp1(testCase)
            if isdeployed
                [~, result] = system('set PATH');
                testCase.fileRootPath = char(regexpi(result, 'Path=(.*?);', 'tokens', 'once'));
            else
                testCase.fileRootPath = fileparts(which(mfilename));
                addpath(testCase.fileRootPath);
                cd(fileparts(testCase.fileRootPath));
            end
        end
    end
    methods (Test)
        function test1(testCase)
            if isdeployed
                command1 = 'D:\Vishal\Misc\UnitTests\app1.exe';
                msgbox('calling the app1 exe from runMyTests EXE');
                system(command1);
                msgbox('called the app1 exe from runMyTests EXE');
            else
                app1;
                msgbox('called the app1 mlapp from runMyTests script');
            end
            msgbox('app has been run successfully')
            mlappFind = findall(0, 'Name', 'MATLAB App');
            pushButtonFind = findall(0, 'Tag', 'clickButton');
            feval(pushButtonFind.ButtonPushedFcn, mlappFind, []);
            msgBox = findall(0, 'Tag', 'MessageBox');
            testCase.verifyTrue(any(arrayfun(@(x) strcmp(string(x.String), 'push button clicked'), msgBox)));
        end
    end
end