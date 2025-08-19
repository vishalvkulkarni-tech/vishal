function blkStruct = slblocks
    % SLBLOCKS Defines the library block listing for the Simulink Library Browser.

    % Name of the library (without .slx)
    % blkStruct.Name = 'My Custom Library';
    % Path to the library
    % blkStruct.OpenFcn = 'sqaure_sl_library';
    % Library icon (optional)
    % blkStruct.MaskDisplay = 'disp(''My Custom Lib'')';

    % Register the library
    Browser.Library = 'sqaure_sl_library';
    Browser.Name    = 'My Custom Library';
    % Browser.IsFlat  = 0; % 1 for no hierarchy, 0 to keep hierarchy

    blkStruct.Browser = Browser;
end
