% Get MATLAB Desktop Instance
desktop = com.mathworks.mde.desk.MLDesktop.getInstance;

% Get the Editor Container
editorContainer = desktop.getGroupContainer('Editor');

% Explore all components starting from the Editor container
findEditorButtons(editorContainer);

% Recursive function to list all components and find buttons
function findEditorButtons(component, indent)
    if nargin < 2
        indent = '';
    end

    % Get the class name of the component
    className = char(component.getClass().getName());
    disp([indent className]);

    % If the component is a button or toolbar, print its details
    if isa(component, 'javax.swing.JButton') || isa(component, 'javax.swing.AbstractButton')
        disp([indent '  Button Text: ' char(component.getText())]);
        disp([indent '  Tooltip Text: ' char(component.getToolTipText())]);
        if ~isempty(component.getIcon())
            disp([indent '  Icon Description: ' char(component.getIcon().toString())]);
        end
    end

    % If the component is a toolbar, explore its components
    if isa(component, 'javax.swing.JToolBar')
        disp([indent '  Toolbar Name: ' char(component.getName())]);
        subComponents = component.getComponents();
        for i = 1:length(subComponents)
            findEditorButtons(subComponents(i), [indent '  ']);
        end
    end

    % If the component is a container, explore its components
    if isa(component, 'java.awt.Container')
        subComponents = component.getComponents();
        for i = 1:length(subComponents)
            findEditorButtons(subComponents(i), [indent '  ']);
        end
    end
end
