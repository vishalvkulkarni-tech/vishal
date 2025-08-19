classdef System < class.NameDef & class.EleNW
    properties
        Grid            class.Grid
        PDS             class.PowDrivSys
        Cable           % class.Cable
        Trans           % class.Transformer
        Moto            class.Motor
    end

    methods
        % constructor
        function obj = System(varargin)
        end

        function generateOpStruct()
        end

        function calc_ele_ckts()
        end

        function calc_loss(obj)
        end
    end

end