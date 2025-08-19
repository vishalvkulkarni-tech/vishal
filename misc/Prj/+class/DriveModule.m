classdef DriveModule < class.EleModule
    % Module class

    properties
        FiltMot         class.EleRLCCompstn
        FiltInfe        class.EleRLCCompstn
        Conv            class.Converter
        Auxi            class.Auxilaries
    end
    methods (Access = public)
        function Module(varargin)
            % constructor 
        end
    end
end