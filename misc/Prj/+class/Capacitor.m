classdef Capacitor < class.EleCompnt
    % capacitor class

    properties
        Capacitance(1,1)   class.ValueSI
        ESR(1,1)           class.ValueSI
    end

    properties (Dependent, Hidden)
        R
        C
    end

    methods (Access = 'public')
        % constructor
        function output = Capacitor(varargin)
            % intialize Capactior
            input = ["Capacitance","ESR"];
            for k = 1:nargin
                [value, prefix, unit] = func.getValPrefixUnit(varargin{k});
                tempObj = class.ValueSI;
                tempObj.value = value;
                tempObj.prefix = prefix;
                tempObj.unit = unit;
                output.(input{k}) = tempObj;
            end
        end
    end

    methods
        function R = get.R(obj)
            R = obj.ESR.data;
        end
        function C = get.C(obj)
            C = obj.Capacitance.data;
        end
    end
end