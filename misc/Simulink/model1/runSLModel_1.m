try
    maxCnt = 10;
    mdlFile = "upCounter";
    open_system(mdlFile);
    set_param(mdlFile, 'Stoptime', '10');
    set_param(mdlFile, 'SimulationCommand', 'start')
    msgbox('Success')
catch err
    msgbox(err.message)
end