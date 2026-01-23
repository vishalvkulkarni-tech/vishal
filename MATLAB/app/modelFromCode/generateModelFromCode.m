function generateModelFromCode()
% GENERATEMODELFROMCODE - Convert C/C++ files to Simulink/Stateflow model
%
% This script analyzes C/C++ source files and generates appropriate
% Simulink or Stateflow models with data dictionary support.
%
% Usage: generateModelFromCode()
%
% Author: Auto-generated
% Date: 2026-01-22

    % Select folder containing C/C++ files
    folderPath = uigetdir(pwd, 'Select folder containing C/C++ files');
    if folderPath == 0
        disp('Operation cancelled by user.');
        return;
    end
    
    fprintf('Analyzing files in: %s\n', folderPath);
    
    % Step 1: Find all relevant files
    fileList = findRelevantFiles(folderPath);
    
    if isempty(fileList)
        error('No C/C++ files found in the selected folder.');
    end
    
    fprintf('Found %d files to process.\n', length(fileList));
    
    % Step 2: Parse all files and extract information
    parsedData = parseAllFiles(fileList);
    
    % Step 3: Analyze and filter to find main model functions
    parsedData = analyzeAndFilterFunctions(parsedData);
    
    % Generate JSON structure
    jsonStruct = generateJSONStructure(parsedData);
    
    % Save JSON to file in output folder
    outputFolder = fullfile(pwd, 'GeneratedModels');
    if ~exist(outputFolder, 'dir')
        mkdir(outputFolder);
    end
    
    jsonFile = fullfile(outputFolder, 'parsed_structure.json');
    saveJSON(jsonStruct, jsonFile);
    fprintf('\n*** JSON structure saved to: %s ***\n', jsonFile);
    fprintf('Please review this file to see what was parsed.\n\n');
    
    fprintf('\nAnalysis Summary:\n');
    fprintf('  Total functions found: %d\n', length(parsedData.allFunctions));
    fprintf('  Main model functions: %d\n', length(parsedData.functions));
    fprintf('  Constants/Defines: %d\n', length(parsedData.constants) + length(parsedData.defines));
    fprintf('  Inputs detected: %d\n', length(parsedData.inputs));
    fprintf('  Outputs detected: %d\n', length(parsedData.outputs));
    fprintf('  Connections found: %d\n', length(parsedData.connections));
    fprintf('  Global variables: %d\n', length(parsedData.globalVars));
    
    % Show some connection details if found
    if ~isempty(parsedData.connections)
        fprintf('\nDetected Operations:\n');
        ops = {parsedData.connections.operation};
        uniqueOps = unique(ops);
        for i = 1:length(uniqueOps)
            count = sum(strcmp(ops, uniqueOps{i}));
            fprintf('  %s: %d\n', uniqueOps{i}, count);
        end
    end
    
    % Step 4: Decide model type based on logic analysis
    modelType = decideModelType(parsedData);
    fprintf('Determined model type: %s\n', modelType);
    
    % Step 5: Generate the model
    modelName = ['GeneratedModel_' datestr(now, 'yyyymmdd_HHMMSS')];
    
    % Create output folder without spaces
    outputFolder = fullfile(pwd, 'GeneratedModels');
    if ~exist(outputFolder, 'dir')
        mkdir(outputFolder);
    end
    
    % Try model generation with retries
    maxRetries = 5;
    success = false;
    
    for attempt = 1:maxRetries
        fprintf('\n========== Attempt %d of %d ==========\n', attempt, maxRetries);
        
        try
            generateModel(modelName, modelType, parsedData, outputFolder, attempt);
            success = true;
            break;
        catch ME
            fprintf('\nAttempt %d failed: %s\n', attempt, ME.message);
            
            if attempt < maxRetries
                fprintf('Trying alternative approach...\n');
                
                % Modify approach based on error type
                if contains(ME.message, 'block', 'IgnoreCase', true)
                    fprintf('  -> Will try with simplified block structure\n');
                    parsedData.simplifyBlocks = true;
                elseif contains(ME.message, 'Stateflow', 'IgnoreCase', true)
                    fprintf('  -> Will skip Stateflow and use Simulink only\n');
                    modelType = 'simulink';
                elseif contains(ME.message, 'name', 'IgnoreCase', true)
                    fprintf('  -> Will sanitize block names more strictly\n');
                    parsedData.strictNames = true;
                elseif contains(ME.message, 'dictionary', 'IgnoreCase', true)
                    fprintf('  -> Will skip data dictionary creation\n');
                    parsedData.globalVars = {};
                else
                    fprintf('  -> Will try with minimal configuration\n');
                    parsedData.minimalMode = true;
                end
                
                pause(0.5); % Brief pause before retry
            else
                fprintf('\n*** All %d attempts failed ***\n', maxRetries);
                error('Model generation failed after %d attempts. Last error: %s', maxRetries, ME.message);
            end
        end
    end
    
    if success
        fprintf('\n========================================\n');
        fprintf('Model generation complete!\n');
        fprintf('Model name: %s\n', modelName);
        fprintf('Output folder: %s\n', outputFolder);
        fprintf('========================================\n');
    end
    
end

%% Helper Functions

function fileList = findRelevantFiles(folderPath)
    % Find all C, C++, and H files in the folder and subfolders
    
    extensions = {'*.c', '*.cpp', '*.cc', '*.cxx', '*.h', '*.hpp', '*.hxx'};
    fileList = {};
    
    for i = 1:length(extensions)
        files = dir(fullfile(folderPath, '**', extensions{i}));
        for j = 1:length(files)
            fileList{end+1} = fullfile(files(j).folder, files(j).name);
        end
    end
    
    fileList = unique(fileList);
end

function parsedData = parseAllFiles(fileList)
    % Parse all files and extract relevant information
    
    parsedData = struct();
    parsedData.files = {};
    parsedData.functions = {};
    parsedData.globalVars = {};
    parsedData.includes = {};
    parsedData.stateMachines = {};
    parsedData.constants = {};
    parsedData.defines = {};
    parsedData.inputs = {};
    parsedData.outputs = {};
    
    for i = 1:length(fileList)
        filePath = fileList{i};
        fprintf('Parsing: %s\n', filePath);
        
        fileInfo = parseFile(filePath);
        parsedData.files{end+1} = fileInfo;
        
        % Aggregate functions
        parsedData.functions = [parsedData.functions, fileInfo.functions];
        
        % Aggregate global variables
        parsedData.globalVars = [parsedData.globalVars, fileInfo.globalVars];
        
        % Aggregate includes
        parsedData.includes = [parsedData.includes, fileInfo.includes];
        
        % Aggregate constants and defines
        parsedData.constants = [parsedData.constants, fileInfo.constants];
        parsedData.defines = [parsedData.defines, fileInfo.defines];
        
        % Aggregate inputs and outputs
        parsedData.inputs = [parsedData.inputs, fileInfo.inputs];
        parsedData.outputs = [parsedData.outputs, fileInfo.outputs];
        
        % Detect state machines
        if fileInfo.hasStateMachine
            parsedData.stateMachines{end+1} = fileInfo;
        end
    end
    
    % Analyze connections and data flow
    parsedData = analyzeConnections(parsedData);
end

function parsedData = analyzeAndFilterFunctions(parsedData)
    % Analyze functions to identify main model logic vs helper functions
    
    fprintf('\nAnalyzing function structure...\n');
    
    % Keep all functions for JSON
    parsedData.allFunctions = parsedData.functions;
    
    mainFunctions = {};
    
    % Patterns that indicate autogenerated helper functions (to skip)
    skipPatterns = {'_initialize', '_terminate', '_step', 'main', 'rt_', 'rtw', ...
                    'ert_main', 'MW_', 'rtGet', 'rtSet', 'model_', 'initialize', ...
                    'terminate', 'memcpy', 'memset', 'sizeof'};
    
    % Patterns that indicate main model functions (to keep)
    keepPatterns = {'_step', '_output', '_update', 'output', 'calculate', 'compute'};
    
    for i = 1:length(parsedData.functions)
        funcData = parsedData.functions{i};
        funcName = lower(funcData.name);
        
        % Check if it's a main function
        isMainFunc = false;
        
        % First priority: step/output functions
        for k = 1:length(keepPatterns)
            if contains(funcName, keepPatterns{k})
                isMainFunc = true;
                fprintf('  Found main function: %s\n', funcData.name);
                break;
            end
        end
        
        % Skip common autogenerated functions
        shouldSkip = false;
        for s = 1:length(skipPatterns)
            if contains(funcName, skipPatterns{s}) && ~isMainFunc
                shouldSkip = true;
                break;
            end
        end
        
        if ~shouldSkip || isMainFunc
            mainFunctions{end+1} = funcData;
        end
    end
    
    % If we filtered everything out, keep a few representative functions
    if isempty(mainFunctions) && ~isempty(parsedData.functions)
        fprintf('  No main functions identified, using first 3 functions\n');
        mainFunctions = parsedData.functions(1:min(3, length(parsedData.functions)));
    end
    
    parsedData.functions = mainFunctions;
end

function parsedData = analyzeConnections(parsedData)
    % Analyze data flow and connections in the code
    
    fprintf('Analyzing data flow and connections...\n');
    
    parsedData.connections = [];
    parsedData.dataFlow = struct();
    parsedData.detectedOperation = 'unknown';
    
    % Trace how inputs flow to outputs through functions
    for i = 1:length(parsedData.files)
        fileData = parsedData.files{i};
        content = fileData.content;
        
        % Remove comments for cleaner analysis
        contentClean = removeComments(content);
        
        % Look for the main computation/step function body
        stepFuncPattern = 'void\s+\w*step\w*\s*\([^)]*\)\s*{([^}]+)}';
        stepMatches = regexp(contentClean, stepFuncPattern, 'tokens');
        
        if ~isempty(stepMatches)
            stepBody = stepMatches{1}{1};
            fprintf('  Found step function body\n');
            
            % Look for arithmetic operations in the step function
            % Pattern: something = something + something
            addPattern = '(\w+(?:\.\w+|->\w+|\[\w+\])?)\s*=\s*([^;]+\+[^;]+);';
            addMatches = regexp(stepBody, addPattern, 'tokens');
            
            if ~isempty(addMatches)
                parsedData.detectedOperation = 'addition';
                fprintf('  Detected ADDITION operation\n');
                for j = 1:length(addMatches)
                    conn = struct();
                    conn.to = strtrim(addMatches{j}{1});
                    conn.from = strtrim(addMatches{j}{2});
                    conn.operation = 'addition';
                    conn.line = [conn.to ' = ' conn.from ';'];
                    conn.file = fileData.name;
                    fprintf('    %s = %s\n', conn.to, conn.from);
                    parsedData.connections = [parsedData.connections; conn];
                end
            end
            
            % Check for subtraction
            subPattern = '(\w+(?:\.\w+|->\w+|\[\w+\])?)\s*=\s*([^;]+-[^;]+);';
            subMatches = regexp(stepBody, subPattern, 'tokens');
            if ~isempty(subMatches) && strcmp(parsedData.detectedOperation, 'unknown')
                parsedData.detectedOperation = 'subtraction';
                fprintf('  Detected SUBTRACTION operation\n');
            end
            
            % Check for multiplication
            mulPattern = '(\w+(?:\.\w+|->\w+|\[\w+\])?)\s*=\s*([^;]+\*[^;]+);';
            mulMatches = regexp(stepBody, mulPattern, 'tokens');
            if ~isempty(mulMatches) && strcmp(parsedData.detectedOperation, 'unknown')
                parsedData.detectedOperation = 'multiplication';
                fprintf('  Detected MULTIPLICATION operation\n');
            end
            
            % Check for division
            divPattern = '(\w+(?:\.\w+|->\w+|\[\w+\])?)\s*=\s*([^;]+/[^;]+);';
            divMatches = regexp(stepBody, divPattern, 'tokens');
            if ~isempty(divMatches) && strcmp(parsedData.detectedOperation, 'unknown')
                parsedData.detectedOperation = 'division';
                fprintf('  Detected DIVISION operation\n');
            end
        end
        
        % Fallback: scan all lines for operations
        if strcmp(parsedData.detectedOperation, 'unknown')
            lines = strsplit(contentClean, '\n');
            
            for j = 1:length(lines)
                line = strtrim(lines{j});
                
                % Look for assignments with operations
                if contains(line, '=') && ~startsWith(line, '#') && ~contains(line, '==') && contains(line, ';')
                    parts = strsplit(line, '=');
                    if length(parts) >= 2
                        lhs = strtrim(parts{1});
                        rhs = strtrim(strjoin(parts(2:end), '='));
                        rhs = strrep(rhs, ';', '');
                        
                        % Check if output-related
                        isOutput = contains(lhs, 'Out') || contains(lhs, 'rtY') || contains(lhs, '_Y') || contains(lhs, 'output');
                        
                        if isOutput
                            conn = struct();
                            conn.from = rhs;
                            conn.to = lhs;
                            conn.line = line;
                            conn.file = fileData.name;
                            
                            % Detect operation type
                            if contains(rhs, '+')
                                conn.operation = 'addition';
                                parsedData.detectedOperation = 'addition';
                                fprintf('  Found addition: %s\n', line);
                            elseif contains(rhs, '-') && ~contains(rhs, '->')
                                conn.operation = 'subtraction';
                                parsedData.detectedOperation = 'subtraction';
                            elseif contains(rhs, '*')
                                conn.operation = 'multiplication';
                                parsedData.detectedOperation = 'multiplication';
                            elseif contains(rhs, '/')
                                conn.operation = 'division';
                                parsedData.detectedOperation = 'division';
                            else
                                conn.operation = 'assignment';
                            end
                            
                            parsedData.connections = [parsedData.connections; conn];
                        end
                    end
                end
            end
        end
    end
    
    fprintf('  Found %d connections\n', length(parsedData.connections));
    fprintf('  Main operation type: %s\n', parsedData.detectedOperation);
end

function fileInfo = parseFile(filePath)
    % Parse a single file and extract information
    
    fileInfo = struct();
    fileInfo.path = filePath;
    [~, fileInfo.name, fileInfo.ext] = fileparts(filePath);
    
    % Read file content
    fid = fopen(filePath, 'r', 'n', 'UTF-8');
    if fid == -1
        warning('Could not open file: %s', filePath);
        fileInfo.content = '';
        fileInfo.functions = {};
        fileInfo.globalVars = {};
        fileInfo.includes = {};
        fileInfo.constants = {};
        fileInfo.defines = {};
        fileInfo.inputs = {};
        fileInfo.outputs = {};
        fileInfo.hasStateMachine = false;
        return;
    end
    
    content = fread(fid, '*char')';
    fclose(fid);
    fileInfo.content = content;
    
    % Extract includes
    fileInfo.includes = extractIncludes(content);
    
    % Extract defines and constants
    fileInfo.defines = extractDefines(content);
    fileInfo.constants = extractConstants(content);
    
    % Extract functions
    fileInfo.functions = extractFunctions(content);
    
    % Extract global variables
    fileInfo.globalVars = extractGlobalVars(content);
    
    % Extract input/output structures
    fileInfo.inputs = extractInputSignals(content);
    fileInfo.outputs = extractOutputSignals(content);
    
    % Detect state machine patterns
    fileInfo.hasStateMachine = detectStateMachine(content);
    
end

function includes = extractIncludes(content)
    % Extract #include statements
    
    includes = {};
    pattern = '#include\s*[<"]([^>"]+)[>"]';
    matches = regexp(content, pattern, 'tokens');
    
    for i = 1:length(matches)
        includes{end+1} = matches{i}{1};
    end
end

function defines = extractDefines(content)
    % Extract #define constants
    
    defines = {};
    lines = strsplit(content, '\n');
    
    for i = 1:length(lines)
        line = strtrim(lines{i});
        if startsWith(line, '#define')
            % Parse #define NAME VALUE
            tokens = regexp(line, '#define\s+(\w+)\s+(.+)', 'tokens');
            if ~isempty(tokens)
                defineInfo = struct();
                defineInfo.name = tokens{1}{1};
                defineInfo.value = strtrim(tokens{1}{2});
                defines{end+1} = defineInfo;
            end
        end
    end
end

function constants = extractConstants(content)
    % Extract constant variable declarations
    
    constants = {};
    
    % Remove comments first
    contentNoComments = removeComments(content);
    lines = strsplit(contentNoComments, '\n');
    
    for i = 1:length(lines)
        line = strtrim(lines{i});
        
        % Look for const declarations or static const
        if contains(line, 'const') && contains(line, ';') && ~contains(line, '(')
            constInfo = struct();
            constInfo.declaration = line;
            
            % Try to extract name and value
            % Pattern: type const name = value; or const type name = value;
            tokens = regexp(line, '(?:const\s+)?\w+\s+(?:const\s+)?(\w+)\s*=\s*([^;]+)', 'tokens');
            if ~isempty(tokens)
                constInfo.name = tokens{1}{1};
                constInfo.value = strtrim(tokens{1}{2});
                constants{end+1} = constInfo;
            end
        end
    end
end

function inputs = extractInputSignals(content)
    % Extract input signal structures and variables
    
    inputs = {};
    
    % Look for common input patterns in generated code
    patterns = {'ExtU_\w+', 'rtU\.', '_U\.', 'U->', 'Input', 'In\d+'};
    
    for p = 1:length(patterns)
        matches = regexp(content, patterns{p}, 'match');
        if ~isempty(matches)
            uniqueMatches = unique(matches);
            for m = 1:length(uniqueMatches)
                inputInfo = struct();
                inputInfo.name = uniqueMatches{m};
                inputInfo.type = 'input';
                inputs{end+1} = inputInfo;
            end
        end
    end
end

function outputs = extractOutputSignals(content)
    % Extract output signal structures and variables
    
    outputs = {};
    
    % Look for common output patterns in generated code
    patterns = {'ExtY_\w+', 'rtY\.', '_Y\.', 'Y->', 'Output', 'Out\d+'};
    
    for p = 1:length(patterns)
        matches = regexp(content, patterns{p}, 'match');
        if ~isempty(matches)
            uniqueMatches = unique(matches);
            for m = 1:length(uniqueMatches)
                outputInfo = struct();
                outputInfo.name = uniqueMatches{m};
                outputInfo.type = 'output';
                outputs{end+1} = outputInfo;
            end
        end
    end
end

function functions = extractFunctions(content)
    % Extract function definitions
    
    functions = {};
    
    % Remove comments to avoid false matches
    contentNoComments = removeComments(content);
    
    % Pattern for function declarations/definitions
    % Simplified pattern - can be enhanced
    pattern = '(?:^|\n)\s*(\w+\s+\**\s*\w+)\s*\(([^)]*)\)\s*(?:{|;)';
    matches = regexp(contentNoComments, pattern, 'tokens');
    
    for i = 1:length(matches)
        funcInfo = struct();
        funcInfo.returnType = strtrim(matches{i}{1});
        funcInfo.parameters = strtrim(matches{i}{2});
        
        % Extract function name
        nameMatch = regexp(funcInfo.returnType, '\w+$', 'match');
        if ~isempty(nameMatch)
            funcInfo.name = nameMatch{1};
        else
            funcInfo.name = 'unknown';
        end
        
        % Parse parameters
        funcInfo.inputs = parseParameters(funcInfo.parameters);
        funcInfo.outputs = {funcInfo.returnType};
        
        functions{end+1} = funcInfo;
    end
end

function params = parseParameters(paramStr)
    % Parse function parameters
    
    params = {};
    if isempty(strtrim(paramStr)) || strcmp(strtrim(paramStr), 'void')
        return;
    end
    
    % Split by comma
    parts = strsplit(paramStr, ',');
    for i = 1:length(parts)
        param = struct();
        param.declaration = strtrim(parts{i});
        
        % Extract type and name (simplified)
        tokens = regexp(param.declaration, '(\w+)\s*\**\s*(\w+)$', 'tokens');
        if ~isempty(tokens)
            param.type = tokens{1}{1};
            param.name = tokens{1}{2};
        else
            param.type = 'unknown';
            param.name = sprintf('param%d', i);
        end
        
        params{end+1} = param;
    end
end

function globalVars = extractGlobalVars(content)
    % Extract global variable declarations
    
    globalVars = {};
    
    % Remove comments
    contentNoComments = removeComments(content);
    
    % Split into lines
    lines = strsplit(contentNoComments, '\n');
    
    for i = 1:length(lines)
        line = strtrim(lines{i});
        
        % Check for global variable patterns (simplified)
        % Variables outside functions, not in #define, not function declarations
        if ~isempty(line) && ~startsWith(line, '#') && ...
           ~contains(line, '(') && contains(line, ';')
            
            % Extract variable info
            varInfo = struct();
            varInfo.declaration = line;
            
            % Try to extract type and name
            tokens = regexp(line, '^\s*(\w+)\s+(\w+)\s*[;=]', 'tokens');
            if ~isempty(tokens)
                varInfo.type = tokens{1}{1};
                varInfo.name = tokens{1}{2};
                globalVars{end+1} = varInfo;
            end
        end
    end
end

function hasStateMachine = detectStateMachine(content)
    % Detect if the code contains state machine patterns
    
    hasStateMachine = false;
    
    % Look for common state machine keywords
    keywords = {'switch\s*\(.*state', 'enum.*state', 'STATE_', ...
                'case\s+\w+:', 'fsm', 'state_machine'};
    
    for i = 1:length(keywords)
        if ~isempty(regexpi(content, keywords{i}))
            hasStateMachine = true;
            return;
        end
    end
end

function contentNoComments = removeComments(content)
    % Remove C/C++ comments from content
    
    % Remove single-line comments
    contentNoComments = regexprep(content, '//[^\n]*', '');
    
    % Remove multi-line comments - use simple approach to avoid hanging
    while contains(contentNoComments, '/*')
        startIdx = strfind(contentNoComments, '/*');
        endIdx = strfind(contentNoComments, '*/');
        if isempty(startIdx) || isempty(endIdx) || endIdx(1) < startIdx(1)
            break;
        end
        contentNoComments = [contentNoComments(1:startIdx(1)-1) contentNoComments(endIdx(1)+2:end)];
    end
end

function jsonStruct = generateJSONStructure(parsedData)
    % Generate JSON structure with all extracted information
    
    jsonStruct = struct();
    jsonStruct.timestamp = datestr(now, 'yyyy-mm-dd HH:MM:SS');
    jsonStruct.summary = struct();
    jsonStruct.summary.totalFiles = length(parsedData.files);
    jsonStruct.summary.totalFunctions = length(parsedData.allFunctions);
    jsonStruct.summary.mainFunctions = length(parsedData.functions);
    jsonStruct.summary.globalVariables = length(parsedData.globalVars);
    jsonStruct.summary.constants = length(parsedData.constants);
    jsonStruct.summary.defines = length(parsedData.defines);
    jsonStruct.summary.inputs = length(parsedData.inputs);
    jsonStruct.summary.outputs = length(parsedData.outputs);
    jsonStruct.summary.connections = length(parsedData.connections);
    
    if isfield(parsedData, 'detectedOperation')
        jsonStruct.summary.detectedOperation = parsedData.detectedOperation;
    else
        jsonStruct.summary.detectedOperation = 'unknown';
    end
    
    jsonStruct.files = [];
    jsonStruct.constants = [];
    jsonStruct.defines = [];
    jsonStruct.inputs = [];
    jsonStruct.outputs = [];
    jsonStruct.allFunctions = [];
    jsonStruct.mainFunctions = [];
    jsonStruct.globalVariables = [];
    jsonStruct.connections = [];
    jsonStruct.dataFlowAnalysis = struct();
    
    % Process files
    for i = 1:length(parsedData.files)
        fileData = parsedData.files{i};
        fileEntry = struct();
        fileEntry.name = fileData.name;
        fileEntry.path = fileData.path;
        fileEntry.extension = fileData.ext;
        fileEntry.includes = fileData.includes;
        fileEntry.hasStateMachine = fileData.hasStateMachine;
        fileEntry.functionCount = length(fileData.functions);
        fileEntry.constantCount = length(fileData.constants);
        fileEntry.defineCount = length(fileData.defines);
        jsonStruct.files = [jsonStruct.files; fileEntry];
    end
    
    % Process constants
    for i = 1:length(parsedData.constants)
        constData = parsedData.constants{i};
        jsonStruct.constants = [jsonStruct.constants; constData];
    end
    
    % Process defines
    for i = 1:length(parsedData.defines)
        defineData = parsedData.defines{i};
        jsonStruct.defines = [jsonStruct.defines; defineData];
    end
    
    % Process inputs
    for i = 1:length(parsedData.inputs)
        inputData = parsedData.inputs{i};
        jsonStruct.inputs = [jsonStruct.inputs; inputData];
    end
    
    % Process outputs
    for i = 1:length(parsedData.outputs)
        outputData = parsedData.outputs{i};
        jsonStruct.outputs = [jsonStruct.outputs; outputData];
    end
    
    % Process all functions
    for i = 1:length(parsedData.allFunctions)
        funcData = parsedData.allFunctions{i};
        funcEntry = struct();
        funcEntry.name = funcData.name;
        funcEntry.returnType = funcData.returnType;
        funcEntry.inputCount = length(funcData.inputs);
        funcEntry.inputs = funcData.inputs;
        jsonStruct.allFunctions = [jsonStruct.allFunctions; funcEntry];
    end
    
    % Process main functions (filtered)
    for i = 1:length(parsedData.functions)
        funcData = parsedData.functions{i};
        funcEntry = struct();
        funcEntry.name = funcData.name;
        funcEntry.returnType = funcData.returnType;
        funcEntry.inputCount = length(funcData.inputs);
        funcEntry.inputs = funcData.inputs;
        jsonStruct.mainFunctions = [jsonStruct.mainFunctions; funcEntry];
    end
    
    % Process global variables
    for i = 1:length(parsedData.globalVars)
        varData = parsedData.globalVars{i};
        varEntry = struct();
        varEntry.name = varData.name;
        varEntry.type = varData.type;
        jsonStruct.globalVariables = [jsonStruct.globalVariables; varEntry];
    end
    
    % Process connections (data flow)
    jsonStruct.connections = parsedData.connections;
    
    % Add data flow analysis summary
    if ~isempty(parsedData.connections)
        operations = {parsedData.connections.operation};
        uniqueOps = unique(operations);
        for i = 1:length(uniqueOps)
            opName = uniqueOps{i};
            count = sum(strcmp(operations, opName));
            jsonStruct.dataFlowAnalysis.(opName) = count;
        end
    end
end

function connections = detectConnections(parsedData)
    % Detect connections between functions
    
    connections = [];
    
    for i = 1:length(parsedData.files)
        fileData = parsedData.files{i};
        content = fileData.content;
        
        % For each function, check if it's called in the content
        for j = 1:length(parsedData.functions)
            funcData = parsedData.functions{j};
            
            % Look for function calls
            pattern = [funcData.name '\s*\('];
            if ~isempty(regexp(content, pattern, 'once'))
                conn = struct();
                conn.from = fileData.name;
                conn.to = funcData.name;
                conn.type = 'function_call';
                connections = [connections; conn];
            end
        end
    end
end

function saveJSON(jsonStruct, filename)
    % Save JSON structure to file
    
    try
        % Encode to JSON
        jsonText = jsonencode(jsonStruct);
        
        % Pretty print JSON (simple approach)
        jsonText = strrep(jsonText, ',"', sprintf(',\n  "'));
        jsonText = strrep(jsonText, '[{', sprintf('[\n  {'));
        jsonText = strrep(jsonText, '}]', sprintf('}\n]'));
        jsonText = strrep(jsonText, '},{', sprintf('},\n  {'));
        
        % Write to file
        fid = fopen(filename, 'w', 'n', 'UTF-8');
        if fid == -1
            error('Could not open file for writing: %s', filename);
        end
        
        fprintf(fid, '%s', jsonText);
        fclose(fid);
        
        % Verify file was created
        if exist(filename, 'file')
            fileInfo = dir(filename);
            fprintf('JSON file saved: %s (%.2f KB)\n', filename, fileInfo.bytes/1024);
        else
            warning('JSON file was not created: %s', filename);
        end
        
    catch ME
        warning('Could not save JSON: %s', ME.message);
        fprintf('Attempted to save to: %s\n', filename);
        
        % Try alternative method
        try
            fid = fopen(filename, 'w');
            fprintf(fid, '%s', jsonencode(jsonStruct));
            fclose(fid);
            fprintf('JSON saved using fallback method\n');
        catch
            error('Failed to save JSON file');
        end
    end
end

function modelType = decideModelType(parsedData)
    % Decide whether to create Simulink, Stateflow, or combined model
    
    hasStateMachines = ~isempty(parsedData.stateMachines);
    hasComplexLogic = length(parsedData.functions) > 5;
    hasManyFunctions = length(parsedData.functions) > 10;
    
    if hasStateMachines && hasComplexLogic
        modelType = 'combined';  % Both Simulink and Stateflow
    elseif hasStateMachines
        modelType = 'stateflow';
    else
        modelType = 'simulink';
    end
end

function generateModel(modelName, modelType, parsedData, folderPath, attempt)
    % Generate Simulink/Stateflow model based on parsed data
    % attempt: current retry attempt number for progressive simplification
    
    modelCreated = false;
    
    try
        fprintf('\n=== Starting Model Generation (Attempt %d) ===\n', attempt);
        
        % Progressive simplification based on attempt number
        if attempt > 1
            fprintf('Applying simplifications for attempt %d...\n', attempt);
        end
        
        % Reduce complexity on later attempts
        if attempt >= 2 && length(parsedData.functions) > 5
            fprintf('  - Limiting to 5 functions\n');
            parsedData.functions = parsedData.functions(1:min(5, length(parsedData.functions)));
        end
        
        if attempt >= 3 && length(parsedData.functions) > 3
            fprintf('  - Further limiting to 3 functions\n');
            parsedData.functions = parsedData.functions(1:min(3, length(parsedData.functions)));
        end
        
        if attempt >= 4
            fprintf('  - Using minimal mode (1 function only)\n');
            if ~isempty(parsedData.functions)
                parsedData.functions = parsedData.functions(1);
            end
            parsedData.globalVars = {}; % Skip data dictionary
        end
        
        % Check if model already exists and close it
        if bdIsLoaded(modelName)
            fprintf('Closing existing model: %s\n', modelName);
            close_system(modelName, 0);
        end
        
        % Create new model
        fprintf('Creating new model: %s\n', modelName);
        new_system(modelName);
        modelCreated = true;
        
        fprintf('Opening model...\n');
        open_system(modelName);
        
        % Set model properties
        fprintf('Setting model properties...\n');
        set_param(modelName, 'Solver', 'FixedStepDiscrete');
        set_param(modelName, 'FixedStep', '0.1');
        
        % Add blocks based on model type
        fprintf('Adding blocks (type: %s)...\n', modelType);
        switch modelType
            case 'simulink'
                generateSimulinkBlocks(modelName, parsedData);
                
            case 'stateflow'
                generateStateflowChart(modelName, parsedData);
                
            case 'combined'
                generateCombinedModel(modelName, parsedData);
        end
        
        % Auto-arrange blocks
        fprintf('Arranging blocks...\n');
        try
            Simulink.BlockDiagram.arrangeSystem(modelName);
        catch arrangeErr
            warning('Could not auto-arrange blocks: %s', arrangeErr.message);
        end
        
        % Save model to specific folder
        modelPath = fullfile(folderPath, modelName);
        fprintf('Saving model to: %s\n', modelPath);
        save_system(modelName, modelPath);
        
        fprintf('\n*** Model saved successfully: %s.slx ***\n', modelPath);
        
        % Only create data dictionary after model is successfully saved
        if ~isempty(parsedData.globalVars)
            fprintf('\nCreating data dictionary...\n');
            ddFile = generateDataDictionary(modelName, parsedData, folderPath);
            if ~isempty(ddFile) && exist(ddFile, 'file')
                try
                    set_param(modelName, 'DataDictionary', ddFile);
                    save_system(modelName, modelPath);
                    fprintf('Data dictionary linked and model re-saved.\n');
                catch ddErr
                    warning('Could not link data dictionary: %s', ddErr.message);
                end
            end
        end
        
    catch ME
        fprintf('\n***** ERROR GENERATING MODEL *****\n');
        fprintf('Error: %s\n', ME.message);
        fprintf('\nStack trace:\n');
        for i = 1:length(ME.stack)
            fprintf('  %s (line %d)\n', ME.stack(i).name, ME.stack(i).line);
        end
        fprintf('\nPossible causes:\n');
        fprintf('  - Simulink not loaded or licensed\n');
        fprintf('  - Model name conflicts\n');
        fprintf('  - Invalid block parameters\n');
        fprintf('**********************************\n\n');
        
        % Clean up
        if modelCreated && bdIsLoaded(modelName)
            fprintf('Cleaning up failed model...\n');
            try
                close_system(modelName, 0);
            catch
                % Ignore close errors
            end
        end
        
        error('Model generation failed. See error details above.');
    end
end

function generateSimulinkBlocks(modelName, parsedData)
    % Generate Simulink blocks for functions
    
    fprintf('  Creating Simulink blocks...\n');
    
    try
        % Analyze model structure
        numFuncs = length(parsedData.functions);
        numConstants = length(parsedData.constants) + length(parsedData.defines);
        numInputs = max(1, length(parsedData.inputs));
        numOutputs = max(1, length(parsedData.outputs));
        
        fprintf('  Model structure: %d constants, %d inputs, %d outputs, %d functions\n', ...
                numConstants, numInputs, numOutputs, numFuncs);
        
        yPos = 100;
        xPos = 50;
        spacing = 200;
        blockHeight = 60;
        
        % Create constant blocks if constants detected
        if numConstants > 0
            fprintf('  Adding constant blocks...\n');
            constCount = 0;
            
            % Add constants from defines
            for i = 1:min(5, length(parsedData.defines))
                defineData = parsedData.defines{i};
                constName = sanitizeBlockName(defineData.name, i);
                
                try
                    constValue = str2double(defineData.value);
                    if isnan(constValue)
                        constValue = 0; % Default if can't parse
                    end
                catch
                    constValue = 0;
                end
                
                fprintf('    Adding Constant: %s = %g\n', constName, constValue);
                add_block('simulink/Sources/Constant', [modelName '/' constName], ...
                          'Value', num2str(constValue), ...
                          'Position', [xPos, yPos + constCount*blockHeight, xPos+60, yPos + constCount*blockHeight + 30]);
                constCount = constCount + 1;
            end
            
            % Add constants from const declarations
            for i = 1:min(5-constCount, length(parsedData.constants))
                constData = parsedData.constants{i};
                constName = sanitizeBlockName(constData.name, i+constCount);
                
                try
                    constValue = str2double(constData.value);
                    if isnan(constValue)
                        constValue = 0;
                    end
                catch
                    constValue = 0;
                end
                
                fprintf('    Adding Constant: %s = %g\n', constName, constValue);
                add_block('simulink/Sources/Constant', [modelName '/' constName], ...
                          'Value', num2str(constValue), ...
                          'Position', [xPos, yPos + constCount*blockHeight, xPos+60, yPos + constCount*blockHeight + 30]);
                constCount = constCount + 1;
            end
            
            yPos = 100; % Reset for next column
            xPos = xPos + spacing;
        end
        
        % If no constants but has inputs, create input ports
        if numConstants == 0 && numInputs > 0
            for i = 1:min(numInputs, 5)
                inputName = sprintf('Input%d', i);
                fprintf('  Adding %s...\n', inputName);
                add_block('simulink/Sources/In1', [modelName '/' inputName], ...
                          'Position', [xPos, yPos + (i-1)*blockHeight, xPos+30, yPos + (i-1)*blockHeight + 30]);
            end
            yPos = 100;
            xPos = xPos + spacing;
        end
        
        % Detect operation type from analysis
        operationType = 'unknown';
        if isfield(parsedData, 'detectedOperation')
            operationType = parsedData.detectedOperation;
        end
        
        fprintf('  Operation type: %s\n', operationType);
        
        % Add operation block based on detected operation
        if ~strcmp(operationType, 'unknown')
            fprintf('  Creating %s block...\n', operationType);
            
            switch operationType
                case 'addition'
                    add_block('simulink/Math Operations/Add', [modelName '/Add'], ...
                              'Position', [xPos, yPos+30, xPos+60, yPos+90]);
                    fprintf('  *** Add block created ***\n');
                case 'subtraction'
                    add_block('simulink/Math Operations/Subtract', [modelName '/Subtract'], ...
                              'Position', [xPos, yPos+30, xPos+60, yPos+90]);
                case 'multiplication'
                    add_block('simulink/Math Operations/Product', [modelName '/Multiply'], ...
                              'Position', [xPos, yPos+30, xPos+60, yPos+90]);
                case 'division'
                    add_block('simulink/Math Operations/Divide', [modelName '/Divide'], ...
                              'Position', [xPos, yPos+30, xPos+60, yPos+90]);
            end
            
            xPos = xPos + spacing;
        elseif numFuncs > 0
            % Create function blocks for complex logic
            numFuncs = min(3, numFuncs);
            fprintf('  Adding %d function blocks...\n', numFuncs);
            
            for i = 1:numFuncs
                funcData = parsedData.functions{i};
                cleanName = sanitizeBlockName(funcData.name, i);
                blockName = [modelName '/' cleanName];
                
                fprintf('    Adding block: %s\n', cleanName);
                
                try
                    if ~isempty(find_system(modelName, 'SearchDepth', 1, 'Name', cleanName))
                        cleanName = sprintf('%s_%d', cleanName, i);
                        blockName = [modelName '/' cleanName];
                    end
                    
                    add_block('simulink/User-Defined Functions/MATLAB Function', ...
                              blockName, ...
                              'Position', [xPos, yPos + (i-1)*80, xPos+100, yPos + (i-1)*80 + 50]);
                catch blockErr
                    warning('Could not create block %s: %s', cleanName, blockErr.message);
                    continue;
                end
            end
            
            xPos = xPos + spacing;
        end
        
        % Create output port(s)
        fprintf('  Adding output port...\n');
        for i = 1:min(numOutputs, 3)
            outputName = sprintf('Out%d', i);
            add_block('simulink/Sinks/Out1', [modelName '/' outputName], ...
                      'Position', [xPos, yPos + (i-1)*blockHeight, xPos+30, yPos + (i-1)*blockHeight + 30]);
        end
        
        fprintf('  Simulink blocks created successfully.\n');
        
    catch ME
        warning('Error creating Simulink blocks: %s', ME.message);
        rethrow(ME);
    end
end

function numInputs = determineInputCount(parsedData)
    % Determine the number of model inputs from parsed data
    
    numInputs = 1; % Default
    
    % Look for common input patterns in function names or variables
    if ~isempty(parsedData.functions)
        for i = 1:length(parsedData.functions)
            func = parsedData.functions{i};
            numParams = length(func.inputs);
            if numParams > numInputs
                numInputs = numParams;
            end
        end
    end
    
    % Look for input-related global variables
    inputVarCount = 0;
    for i = 1:length(parsedData.globalVars)
        varName = lower(parsedData.globalVars{i}.name);
        if contains(varName, 'in') || contains(varName, 'input') || contains(varName, 'u')
            inputVarCount = inputVarCount + 1;
        end
    end
    
    if inputVarCount > 0
        numInputs = max(numInputs, inputVarCount);
    end
    
    % Reasonable limits
    numInputs = max(1, min(numInputs, 10));
end

function generateStateflowChart(modelName, parsedData)
    % Generate Stateflow chart
    
    fprintf('  Creating Stateflow chart...\n');
    
    try
        % Add Stateflow chart
        chartBlock = [modelName '/StateflowChart'];
        add_block('sflib/Chart', chartBlock, ...
                  'Position', [100, 100, 400, 300]);
        
        fprintf('  Stateflow chart created.\n');
        
        % Get chart object
        rt = sfroot;
        chart = rt.find('-isa', 'Stateflow.Chart', '-and', 'Path', chartBlock);
        
        if ~isempty(chart)
            numStates = min(3, max(1, length(parsedData.stateMachines)));
            fprintf('  Adding %d states...\n', numStates);
            
            % Add states
            for i = 1:numStates
                state = Stateflow.State(chart);
                state.Name = sprintf('State%d', i);
                state.Position = [50 + (i-1)*120, 50, 100, 80];
            end
        else
            warning('Could not access Stateflow chart object.');
        end
        
    catch ME
        warning('Error creating Stateflow chart: %s', ME.message);
        rethrow(ME);
    end
end

function generateCombinedModel(modelName, parsedData)
    % Generate combined Simulink and Stateflow model
    
    % Add Stateflow chart
    generateStateflowChart(modelName, parsedData);
    
    % Add Simulink blocks
    yPos = 350;
    xPos = 100;
    
    for i = 1:min(5, length(parsedData.functions))
        funcData = parsedData.functions{i};
        blockName = [modelName '/' funcData.name];
        
        add_block('simulink/User-Defined Functions/MATLAB Function', ...
                  blockName, ...
                  'Position', [xPos, yPos, xPos+100, yPos+50]);
        
        xPos = xPos + 150;
    end
end

function ddFile = generateDataDictionary(modelName, parsedData, folderPath)
    % Generate data dictionary for global variables
    
    % Create valid filename (no spaces, valid path)
    ddFileName = [modelName '_DataDict.sldd'];
    ddFile = fullfile(folderPath, ddFileName);
    
    % Check if path is valid
    if ~isvarname(modelName)
        warning('Model name contains invalid characters for data dictionary.');
        ddFile = '';
        return;
    end
    
    try
        % Delete existing file if present
        if exist(ddFile, 'file')
            delete(ddFile);
        end
        
        % Create data dictionary
        dd = Simulink.data.dictionary.create(ddFile);
        
        % Get design data section
        dDataSectObj = getSection(dd, 'Design Data');
        
        % Add global variables to dictionary
        for i = 1:length(parsedData.globalVars)
            varData = parsedData.globalVars{i};
            
            % Create Simulink.Parameter object
            param = Simulink.Parameter;
            param.Value = 0;  % Default value
            param.DataType = mapCTypeToSimulink(varData.type);
            
            % Add to dictionary
            try
                addEntry(dDataSectObj, varData.name, param);
            catch
                % Variable might already exist
            end
        end
        
        % Save dictionary
        saveChanges(dd);
        
        fprintf('Data dictionary created: %s\n', ddFile);
        
    catch ME
        warning('Could not create data dictionary: %s', ME.message);
        ddFile = '';
    end
end

function slType = mapCTypeToSimulink(cType)
    % Map C data types to Simulink data types
    
    cType = lower(strtrim(cType));
    
    switch cType
        case {'int', 'int32_t', 'long'}
            slType = 'int32';
        case {'short', 'int16_t'}
            slType = 'int16';
        case {'char', 'int8_t'}
            slType = 'int8';
        case {'unsigned int', 'uint32_t', 'unsigned long'}
            slType = 'uint32';
        case {'unsigned short', 'uint16_t'}
            slType = 'uint16';
        case {'unsigned char', 'uint8_t'}
            slType = 'uint8';
        case {'float'}
            slType = 'single';
        case {'double'}
            slType = 'double';
        case {'bool', 'boolean'}
            slType = 'boolean';
        otherwise
            slType = 'double';
    end
end

function cleanName = sanitizeBlockName(name, index)
    % Sanitize block name to be valid for Simulink
    
    % Remove invalid characters
    cleanName = regexprep(name, '[^a-zA-Z0-9_]', '_');
    
    % Ensure it starts with a letter
    if ~isempty(cleanName) && ~isletter(cleanName(1))
        cleanName = ['Func_' cleanName];
    end
    
    % Ensure it's not empty
    if isempty(cleanName)
        cleanName = sprintf('Function_%d', index);
    end
    
    % Limit length
    if length(cleanName) > 63
        cleanName = cleanName(1:63);
    end
    
    % Ensure uniqueness by avoiding reserved names
    reservedNames = {'Input', 'Output', 'In1', 'Out1', 'Subsystem'};
    if ismember(cleanName, reservedNames)
        cleanName = ['User_' cleanName];
    end
end
