desktop = com.mathworks.mde.desk.MLDesktop.getInstance;
mainFrame = desktop.getMainFrame;
editor = desktop.getGroupContainer('Editor');
% Get all components in the main frame
allComponentsMain = mainFrame.getComponents;
% Get all components in the editor
allComponentsEditor = editor.getComponents;

import java.awt.Component
import javax.swing.JButton

% Find all buttons starting from the main frame
allButtonsMain = findButtons(mainFrame);

% Display the buttons
for i = 1:length(allButtonsMain)
    disp(allButtonsMain{i}.getText());
end

% % Step 4: Find All Buttons Starting from the Editor
% allButtonsEditor = findButtons(editor);
% 
% % Display the Buttons
% for i = 1:length(allButtonsEditor)
%     disp(['Button ' num2str(i) ': ' char(allButtonsEditor{i}.getText())]);
% end

% Recursive function to find all buttons
function buttons = findButtons(component)
    buttons = {};
    if isa(component, 'javax.swing.JButton')
        buttons{end+1} = component; % Collect the button
    elseif isa(component, 'java.awt.Container')
        subComponents = component.getComponents;
        for i = 1:length(subComponents)
            buttons = [buttons, findButtons(subComponents(i))]; %#ok<AGROW>
        end
    end
end

%{
All available buttons on home:
Vishal

New
Script

New
Live Script

New

Open

Find Files

Compare

Import
Data

Clean
Data

Variable

Save Workspace

Clear Workspace

Favorites

Analyze Code

Run and Time

Clear Commands

Simulink

Layout

Preferences

Set Path

Parallel

Add-Ons

Help

Community

Request Support

Learn MATLAB
%}