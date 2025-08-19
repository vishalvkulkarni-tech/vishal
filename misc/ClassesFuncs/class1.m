classdef class1

    properties
        prop1 cell
        prop2 double
    end

    properties (Access = 'private')
        prop4;
    end

    methods
        function obj = class1(var1) % constructor
            if nargin == 0
                obj.prop2 = 0;
            else
                obj.prop2 = abs(var1);
            end
        end

        function obj = displayVal(obj)
            obj.privateFunc1;
        end
    end

    methods (Access = 'private')
        function obj = privateFunc1(obj)
            disp(obj.prop2)
        end
    end

end