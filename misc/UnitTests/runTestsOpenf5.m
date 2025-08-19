strtTime = timeofday(datetime("now"));
import java.awt.Robot;
import java.awt.event.*;
% gather all the paths
sourceCodeFolder = fileparts(which(mfilename));
testFolder = fullfile(sourceCodeFolder, 'allTests');
% all available m files in testing folder
allTestfiles = dir(fullfile(testFolder, "*.m"));
% traverse over all the m files and run only test files, it would be
% identified if name starts with test (case in sensativity should be used)
for fileCnt = 1:size(allTestfiles,1)
    if startsWith(allTestfiles(fileCnt).name, 'test', 'IgnoreCase', true)
        % Create a Robot object
        robot = Robot();
        filenameWithFullPath = fullfile(allTestfiles(fileCnt).folder, allTestfiles(fileCnt).name);
        % open the file
        e = matlab.desktop.editor.openAndGoToLine(filenameWithFullPath, 1);
        % Press and release the F5 key
        robot.keyPress(KeyEvent.VK_F5);
        robot.keyRelease(KeyEvent.VK_F5);
        % close the opened file
        docs = matlab.desktop.editor.getAll;
        fileInd = find(strcmp(string({docs.Filename}'), filenameWithFullPath));
    end
end
% calculate time required for full process, all test files run
endTime = timeofday(datetime("now"));
timeDiff = minutes(endTime - strtTime);
disp(strcat("Overall test is completed in ", num2str(timeDiff), " minutes."));