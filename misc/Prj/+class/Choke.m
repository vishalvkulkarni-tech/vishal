classdef Choke < class.EleCompnt
    % Choke Class
    % Description:

    properties (SetAccess=public)
        Inductance      class.ValueSI
        R_coil          class.ValueSI         
        Pv              class.ValueSI
        n_phases        double = 1
        n_coil_taps     double = 1
        common_mode     logical = false
    end

    properties (Dependent, Hidden)
        R
        L
    end

    methods
        function output = Choke(varargin)
            % initialize Choke
            input = ["Inductance", "R_coil", "Pv", "n_phases", "n_coil_taps","common_mode"];
            for k = 1:nargin
                if k <= 3
                [value, prefix, unit] = func.getValPrefixUnit(varargin{k});
                tempObj = class.ValueSI;
                tempObj.value = value;
                tempObj.prefix = prefix;
                tempObj.unit = unit;
                output.(input{k}) = tempObj;
                end
            end
        end
    end
    methods
        function R = get.R(obj)
            R = obj.R_coil.data;
        end
        function L = get.L(obj)
            L = obj.Inductance.data;
        end
    end
end