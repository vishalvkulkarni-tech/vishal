classdef PowDrivSys
    % Module class

    properties
        Moto        class.Motor
        DM          class.DriveModule
        Cable       % class.Cable
    end
    methods (Access = public)
        function output1 = Module(varargin)
            % initialize module
            input1 = [];
            for k = 1:nargin
                output1.(input1{k}) = varargin{k};
            end
        end
    end
end