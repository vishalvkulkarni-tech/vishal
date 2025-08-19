classdef Motor
    % Motor Class

    properties
    end

    methods (Access = public)
        function output1 = Motor(varargin)
            % initialize Motor
            input1 = ["name","part_num"];
            for k = 1:nargin
                output1.(input1{k}) = varargin{k};
            end
        end
    end
end