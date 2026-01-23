function [output, time] = SimpleAdditionModel_matlab(varargin)
% SimpleAdditionModel_matlab - MATLAB equivalent of SimpleAdditionModel Simulink model
% This is a pure MATLAB implementation (no Simulink required)
%
% Usage:
%   [output, time] = SimpleAdditionModel_matlab()
%   [output, time] = SimpleAdditionModel_matlab('ParamName', value, ...)
%
% Parameters can be overridden using name-value pairs

    % Parse inputs
    p = inputParser;
    addParameter(p, 'Param1', 10, @isnumeric);
    addParameter(p, 'Param2', 20, @isnumeric);
    addParameter(p, 'StopTime', 10, @isnumeric);
    addParameter(p, 'SampleTime', 0.01, @isnumeric);
    parse(p, varargin{:});

    % Get parameter values
    Param1 = p.Results.Param1;
    Param2 = p.Results.Param2;
    stopTime = p.Results.StopTime;
    sampleTime = p.Results.SampleTime;

    % Simulation
    time = 0:sampleTime:stopTime;
    nSamples = length(time);

    % Model computation
    % SimpleAdditionModel: Constant1 + Constant2
    output = ones(nSamples, 1) * (Constant1 + Constant2);

end
