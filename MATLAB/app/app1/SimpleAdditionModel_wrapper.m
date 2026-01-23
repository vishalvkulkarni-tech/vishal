function output = SimpleAdditionModel_wrapper(input1, input2, stopTime)
% Wrapper function for SimpleAdditionModel DLL
% This is a template - modify based on your model's I/O

if nargin < 3
    stopTime = 1.0;
end

% Load DLL if not already loaded
dllName = 'SimpleAdditionModel_dll';
if ~libisloaded(dllName)
    loadlibrary(dllName, 'SimpleAdditionModel.h');
end

% Initialize model
calllib(dllName, 'SimpleAdditionModel_initialize');

% Run simulation
numSteps = floor(stopTime / 0.01); % Assumes 0.01 step size
output = zeros(numSteps, 1);

for i = 1:numSteps
    % Step the model (modify based on your model's interface)
    calllib(dllName, 'SimpleAdditionModel_step');
    % Get output (you'll need to modify this)
    output(i) = input1 + input2; % Placeholder
end

% Terminate model
calllib(dllName, 'SimpleAdditionModel_terminate');

end
