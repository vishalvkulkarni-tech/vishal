classdef Resistor < class.EleCompnt
    % Resistor class

    properties
        Resistance      class.ValueSI
    end

    properties (Dependent, Hidden)
        R
    end

    methods (Access = 'public')
        % constructor
        function output = Resistor(varargin)
            % intialize Resistor
            input = "Resistance";
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
            R = obj.Resistance.data;
        end
    end
end