classdef Converter
    % Module class

    properties
        PoSt        % class.PoSt
        DC          class.EleRLCCompstn
        Auxi        class.Auxilaries
        frame_size  string
        f_sw_std    class.ValueSI
    end

    methods (Access = public)
        function Module(varargin)
            % constructor 
        end
    end
end