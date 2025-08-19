classdef class1
    properties (Access = public)
        prop1
    end
    properties (GetAccess = protected)
        prop2
    end
    properties (Access = private)
        prop3
    end
    properties (Dependent)
        prop4
    end
    properties
        prop5
    end
    properties (Constant)
        prop7 = 5;
        prop8 = "name"
    end

    properties
        prop9 (1, 1) double {mustBeNegative} = -5
    end

    methods (Access = private)
        function obj = func1(obj)
            obj.prop2 = 10;
        end
        %
        function func2(obj)
        end
    end
    methods
        function func3(obj)
        end

        function outVal = get.prop4(obj)
             outVal = obj.prop1 * obj.prop1;
        end

        function obj = set.prop5(obj, val1)
            obj.prop5 = val1;
        end
    end
end