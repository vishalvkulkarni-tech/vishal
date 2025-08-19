classdef className
    properties
        prop1;
        prop2;
    end

    properties (Access = 'private')
        prop3
    end

    properties (Constant)
        prop4 = 5;
        prop5 = 'RR';
    end

    methods
        function obj = inputFun(obj)
            obj.prop1 = 100;
        end

        function obj = outputFun(obj)
            disp(obj.prop1)
            if obj.prop1 == 100
                obj.prop1 = 200;
            else
                obj.prop1 = 300;
            end
        end
    end
end