try
    maxCnt = 10;
    mdlFile = "upCounter";
    open_system(mdlFile);
    set_param(mdlFile, 'Stoptime', 'Inf');
    set_param(mdlFile, 'SimulationCommand', 'start')
    set_param(mdlFile, 'SimulationCommand', 'pause')
    maxCnt = 5;
    set_param(mdlFile, 'SimulationCommand', 'update')
    set_param(mdlFile, 'SimulationCommand', 'continue')
    msgbox('Success')
catch err
    msgbox(err.message)
end