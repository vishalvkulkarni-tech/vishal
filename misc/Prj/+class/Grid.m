classdef Grid
    % Grid Class

    properties
        RSC         double
        X_R_ratio   double
        Skv         class.ValueSI
    end

    properties (Dependent, Hidden)
        R
        L
    end

    methods (Access = public)
        function output1 = Grid(varargin)
            % initialize Grid
            input1 = ["name","part_num"];
            for k = 1:nargin
                output1.(input1{k}) = varargin{k};
            end
        end
    end
end