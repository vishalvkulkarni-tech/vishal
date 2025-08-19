try
    maxCnt = 10;
    mdlFile = "upCounter";
    open_system(mdlFile);
    % simIn = Simulink.SimulationInput(mdlFile);
    % simIn = simulink.compiler.configureForDeployment(simIn);
    % simIn.setModelParameter('StopTime', 5);
    % simIn.setVariable('maxCnt', 10);
    set_param(mdlFile, 'StopTime', 10);
    set_param(mdlFile, 'SimulationCommand', 'start')
    % simOut = sim(simIn);
    msgbox('Success')
    % set_param(mdlFile,'SimulationCommand','pause')
    maxCntVar = Simulink.Simulation.Variable('maxCnt', 5);
    % set_param(mdlFile,'SimulationCommand','update')
    % set_param(mdlFile,'SimulationCommand','continue')
    simulink.compiler.modifyParameters(mdlFile, maxCntVar);
catch err
    msgbox(err.message)
end