classdef DynamicModelGUI < matlab.apps.AppBase

    % Properties that correspond to app components
    properties (Access = public)
        UIFigure                matlab.ui.Figure
        GridLayout              matlab.ui.container.GridLayout
        ControlPanel            matlab.ui.container.Panel
        ControlGrid             matlab.ui.container.GridLayout
        SimulationPanel         matlab.ui.container.Panel
        SimulationGrid          matlab.ui.container.GridLayout
        ModelNameLabel          matlab.ui.control.Label
        ModelNameValue          matlab.ui.control.Label
        LoadModelButton         matlab.ui.control.Button
        RunSimulationButton     matlab.ui.control.Button
        ResultTextArea          matlab.ui.control.TextArea
        ResultLabel             matlab.ui.control.Label
        SaveModelButton         matlab.ui.control.Button
    end
    
    properties (Access = private)
        Parser                  % ModelParameterParser object
        ModelName               % Current model name
        ModelPath               % Full path to model file
        ParameterControls       % Cell array of dynamically created controls
        ParameterLabels         % Cell array of parameter labels
    end

    % Callbacks that handle component events
    methods (Access = private)

        % Code that executes after component creation
        function startupFcn(app, modelName)
            if nargin < 2
                modelName = 'SimpleAdditionModel';
            end
            app.ModelName = modelName;
            
            % Disable Save button in deployed mode (no Simulink)
            if isdeployed
                app.SaveModelButton.Enable = 'off';
                app.SaveModelButton.Tooltip = 'Model saving not available in deployed mode';
                app.LoadModelButton.Enable = 'off';
                app.LoadModelButton.Tooltip = 'Model loading not available in deployed mode';
            end
            
            % Determine model path - deployed vs development
            if isdeployed
                % In deployed mode, model is extracted to ctfroot
                app.ModelPath = fullfile(ctfroot, [modelName '.slx']);
                if ~exist(app.ModelPath, 'file')
                    app.ModelPath = fullfile(ctfroot, [modelName '.mdl']);
                end
            else
                % Development mode - find on path
                app.ModelPath = which(modelName);
                if isempty(app.ModelPath)
                    app.ModelPath = [modelName '.slx'];
                end
            end
            app.ModelNameValue.Text = modelName;
            
            % Try to load model parameters
            try
                loadModelParameters(app);
            catch ME
                uialert(app.UIFigure, ME.message, 'Error Loading Model');
            end
        end

        % Button pushed function: LoadModelButton
        function LoadModelButtonPushed(app, event)
            % Let user select a model
            [file, path] = uigetfile('*.slx', 'Select Simulink Model');
            if isequal(file, 0)
                return;
            end
            
            % Extract model name
            [~, modelName, ~] = fileparts(file);
            
            % Add to path if needed
            addpath(path);
            
            % Update model name
            app.ModelName = modelName;
            app.ModelNameValue.Text = modelName;
            
            % Load parameters
            try
                loadModelParameters(app);
                uialert(app.UIFigure, 'Model loaded successfully!', 'Success', 'Icon', 'success');
            catch ME
                uialert(app.UIFigure, ME.message, 'Error Loading Model');
            end
        end

        % Button pushed function: RunSimulationButton
        function RunSimulationButtonPushed(app, event)
            try
                % Run simulation
                app.ResultTextArea.Value = 'Running simulation...';
                drawnow;
                
                % Build parameter list from GUI
                paramArgs = {};
                for i = 1:length(app.ParameterControls)
                    ctrl = app.ParameterControls{i};
                    paramName = ctrl.Tag;  % Tag stores the parameter name
                    
                    % Extract actual block name (remove _Value suffix)
                    blockName = strrep(paramName, '_Value', '');
                    
                    % Get value from control
                    if isa(ctrl, 'matlab.ui.control.NumericEditField')
                        paramArgs{end+1} = blockName;
                        paramArgs{end+1} = ctrl.Value;
                    end
                end
                
                % Call MATLAB equivalent function (no Simulink needed!)
                matlabFunction = str2func([app.ModelName '_matlab']);
                [output, time] = matlabFunction(paramArgs{:});
                
                % Display results
                resultText = sprintf('Simulation completed successfully!\n\n');
                resultText = sprintf('%sSimulation Time: %.3f seconds\n', resultText, time(end));
                resultText = sprintf('%sFinal Output Value: %.4f\n\n', resultText, output(end));
                resultText = sprintf('%sFirst 10 samples:\n', resultText);
                resultText = sprintf('%sTime\t\tOutput\n', resultText);
                resultText = sprintf('%s-------------------\n', resultText);
                
                numSamples = min(10, length(time));
                for i = 1:numSamples
                    resultText = sprintf('%s%.3f\t\t%.4f\n', resultText, time(i), output(i));
                end
                
                app.ResultTextArea.Value = resultText;
                
                % Plot results
                figure('Name', 'Simulation Results');
                plot(time, output.Data);
                grid on;
                xlabel('Time (s)');
                ylabel('Output');
                title(sprintf('%s - Simulation Output', app.ModelName));
                
            catch ME
                app.ResultTextArea.Value = sprintf('Error: %s', ME.message);
                uialert(app.UIFigure, ME.message, 'Simulation Error');
            end
        end

        % Button pushed function: SaveModelButton
        function SaveModelButtonPushed(app, event)
            if isdeployed
                uialert(app.UIFigure, 'Model saving not available in deployed mode', 'Not Available');
                return;
            end
            
            try
                % Update model parameters from GUI
                updateModelFromGUI(app);
                
                % Save model
                save_system(app.ModelName);
                
                uialert(app.UIFigure, 'Model saved successfully!', 'Success', 'Icon', 'success');
            catch ME
                uialert(app.UIFigure, ME.message, 'Error Saving Model');
            end
        end
    end
    
    % Helper methods
    methods (Access = private)
        
        function loadModelParameters(app)
            % Create parser and get parameters
            app.Parser = ModelParameterParser(app.ModelPath);
            params = app.Parser.getParameters();
            
            % Clear existing parameter controls
            if ~isempty(app.ParameterControls)
                for i = 1:length(app.ParameterControls)
                    if isvalid(app.ParameterControls{i})
                        delete(app.ParameterControls{i});
                    end
                    if isvalid(app.ParameterLabels{i})
                        delete(app.ParameterLabels{i});
                    end
                end
            end
            
            app.ParameterControls = {};
            app.ParameterLabels = {};
            
            % Dynamically create controls for each parameter
            for i = 1:length(params)
                param = params(i);
                
                % Create label
                label = uilabel(app.ControlGrid);
                label.Layout.Row = i;
                label.Layout.Column = 1;
                label.Text = param.ParameterName;
                label.Tooltip = sprintf('%s - %s', param.BlockType, param.Description);
                app.ParameterLabels{i} = label;
                
                % Create control based on parameter type
                switch param.ParameterType
                    case 'numeric'
                        ctrl = uieditfield(app.ControlGrid, 'numeric');
                        ctrl.Value = str2double(param.CurrentValue);
                        
                    case 'dropdown'
                        ctrl = uidropdown(app.ControlGrid);
                        ctrl.Items = param.DropdownOptions;
                        ctrl.Value = param.CurrentValue;
                        
                    otherwise
                        ctrl = uieditfield(app.ControlGrid, 'text');
                        ctrl.Value = param.CurrentValue;
                end
                
                ctrl.Layout.Row = i;
                ctrl.Layout.Column = 2;
                ctrl.Tag = param.ParameterName;
                app.ParameterControls{i} = ctrl;
            end
            
            % Update grid layout rows
            app.ControlGrid.RowHeight = repmat({22}, 1, length(params));
        end
        
        function updateModelFromGUI(app)
            % Update all model parameters from GUI controls
            params = app.Parser.Parameters;
            
            for i = 1:length(params)
                if i <= length(app.ParameterControls)
                    ctrl = app.ParameterControls{i};
                    
                    % Get value from control
                    if isprop(ctrl, 'Value')
                        newValue = ctrl.Value;
                    else
                        newValue = ctrl.Text;
                    end
                    
                    % Update parameter
                    app.Parser.setParameter(params(i).ParameterName, newValue);
                end
            end
        end
    end

    % Component initialization
    methods (Access = private)

        % Create UIFigure and components
        function createComponents(app)

            % Create UIFigure and hide until all components are created
            app.UIFigure = uifigure('Visible', 'off');
            app.UIFigure.Position = [100 100 800 600];
            app.UIFigure.Name = 'Dynamic Model Parameter GUI';

            % Create GridLayout
            app.GridLayout = uigridlayout(app.UIFigure);
            app.GridLayout.ColumnWidth = {'1x'};
            app.GridLayout.RowHeight = {100, '1x', 200};

            % Create SimulationPanel
            app.SimulationPanel = uipanel(app.GridLayout);
            app.SimulationPanel.Title = 'Model Information';
            app.SimulationPanel.Layout.Row = 1;
            app.SimulationPanel.Layout.Column = 1;

            % Create SimulationGrid
            app.SimulationGrid = uigridlayout(app.SimulationPanel);
            app.SimulationGrid.ColumnWidth = {120, '1x', 120, 120, 120};
            app.SimulationGrid.RowHeight = {22, 22};

            % Create ModelNameLabel
            app.ModelNameLabel = uilabel(app.SimulationGrid);
            app.ModelNameLabel.Layout.Row = 1;
            app.ModelNameLabel.Layout.Column = 1;
            app.ModelNameLabel.Text = 'Model Name:';

            % Create ModelNameValue
            app.ModelNameValue = uilabel(app.SimulationGrid);
            app.ModelNameValue.Layout.Row = 1;
            app.ModelNameValue.Layout.Column = 2;
            app.ModelNameValue.Text = 'Not Loaded';

            % Create LoadModelButton
            app.LoadModelButton = uibutton(app.SimulationGrid, 'push');
            app.LoadModelButton.ButtonPushedFcn = createCallbackFcn(app, @LoadModelButtonPushed, true);
            app.LoadModelButton.Layout.Row = 1;
            app.LoadModelButton.Layout.Column = 3;
            app.LoadModelButton.Text = 'Load Model';

            % Create SaveModelButton
            app.SaveModelButton = uibutton(app.SimulationGrid, 'push');
            app.SaveModelButton.ButtonPushedFcn = createCallbackFcn(app, @SaveModelButtonPushed, true);
            app.SaveModelButton.Layout.Row = 1;
            app.SaveModelButton.Layout.Column = 4;
            app.SaveModelButton.Text = 'Save Model';

            % Create RunSimulationButton
            app.RunSimulationButton = uibutton(app.SimulationGrid, 'push');
            app.RunSimulationButton.ButtonPushedFcn = createCallbackFcn(app, @RunSimulationButtonPushed, true);
            app.RunSimulationButton.Layout.Row = 1;
            app.RunSimulationButton.Layout.Column = 5;
            app.RunSimulationButton.Text = 'Run Simulation';
            app.RunSimulationButton.BackgroundColor = [0.39 0.83 0.07];

            % Create ControlPanel
            app.ControlPanel = uipanel(app.GridLayout);
            app.ControlPanel.Title = 'Model Parameters';
            app.ControlPanel.Layout.Row = 2;
            app.ControlPanel.Layout.Column = 1;
            app.ControlPanel.Scrollable = 'on';

            % Create ControlGrid
            app.ControlGrid = uigridlayout(app.ControlPanel);
            app.ControlGrid.ColumnWidth = {200, '1x'};
            app.ControlGrid.RowHeight = {22};
            app.ControlGrid.Scrollable = 'on';

            % Create Results Panel
            resultsPanel = uipanel(app.GridLayout);
            resultsPanel.Title = 'Simulation Results';
            resultsPanel.Layout.Row = 3;
            resultsPanel.Layout.Column = 1;

            % Create results grid
            resultsGrid = uigridlayout(resultsPanel);
            resultsGrid.ColumnWidth = {'1x'};
            resultsGrid.RowHeight = {'1x'};

            % Create ResultTextArea
            app.ResultTextArea = uitextarea(resultsGrid);
            app.ResultTextArea.Layout.Row = 1;
            app.ResultTextArea.Layout.Column = 1;
            app.ResultTextArea.Value = 'Click "Run Simulation" to see results...';

            % Show the figure after all components are created
            app.UIFigure.Visible = 'on';
        end
    end

    % App creation and deletion
    methods (Access = public)

        % Construct app
        function app = DynamicModelGUI(varargin)

            % Create UIFigure and components
            createComponents(app);

            % Register the app with App Designer
            registerApp(app, app.UIFigure);

            % Execute the startup function
            runStartupFcn(app, @(app)startupFcn(app, varargin{:}));

            if nargout == 0
                clear app
            end
        end

        % Code that executes before app deletion
        function delete(app)

            % Delete UIFigure when app is deleted
            delete(app.UIFigure);
        end
    end
end
