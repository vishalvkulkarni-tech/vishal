% Define the folder containing the test files
testFolder = 'allTests';  % Your folder name
testFiles = dir(fullfile(testFolder, '*.m'));

% Ensure the folder path is an absolute path
testFolder = fullfile(pwd, testFolder);

% Get MATLAB Desktop Instance
desktop = com.mathworks.mde.desk.MLDesktop.getInstance;

% Iterate through each test file
for i = 1:length(testFiles)
    % Get the full path of the test file
    filePath = fullfile(testFolder, testFiles(i).name);

    % Open the file in the MATLAB Editor
    matlab.desktop.editor.openDocument(filePath);

    % Pause to allow the file to open
    pause(2);

    % Access the Java components of the MATLAB Editor
    editor = desktop.getMainFrame;  % Get the main frame of MATLAB Desktop
    editorWindows = editor.getContentPane.getComponents;  % Get editor windows

    % Find the editor window for the current file
    editorWindow = [];
    for j = 1:length(editorWindows)
        if isa(editorWindows(j), 'javax.swing.JInternalFrame')
            if contains(char(editorWindows(j).getTitle()), testFiles(i).name)
                editorWindow = editorWindows(j);
                break;
            end
        end
    end
    
    if ~isempty(editorWindow)
        % Get the toolbar from the editor window
        toolbars = editorWindow.getComponents();
        for k = 1:length(toolbars)
            toolbar = toolbars(k);
            if isa(toolbar, 'javax.swing.JToolBar')
                components = toolbar.getComponents();
                for l = 1:length(components)
                    component = components(l);
                    if isa(component, 'javax.swing.JButton')
                        buttonText = char(component.getText());
                        if contains(buttonText, 'Run Tests', 'IgnoreCase', true)
                            % Click the "Run Tests" button
                            component.doClick();
                            disp(['Running tests in: ' filePath]);
                            break;
                        end
                    end
                end
            end
        end
    else
        warning('Editor window not found for file: %s', filePath);
    end

    % Pause to allow tests to run
    pause(10);

    % Close the specific document
    doc = matlab.desktop.editor.getDocument(filePath);
    if ~isempty(doc)
        doc.close();
    else
        warning('Document not found for file: %s', filePath);
    end

    % Pause before processing the next file
    pause(2);
end
