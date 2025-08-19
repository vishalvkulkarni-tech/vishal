function out = runtimeParameterTuning(mdlFile)
try
    simMode = 'rapid';
    % mdlFile = "upCounter";
    load_system(mdlFile);
    set_param(mdlFile, "SimulationMode", simMode);

    simInput  = Simulink.SimulationInput(mdlFile);
    simInput = simulink.compiler.setPostStepFcn(simInput,@(time)postStepParameterTuner(time,mdlFile));
    out = sim(simInput);

    % simIn = simulink.compiler.configureForDeployment(simIn);
    % simIn.setModelParameter('StopTime', 10);
    % simIn.setVariable('maxCnt', 5);
    % simOut = sim(simIn);
    % msgbox('Success')
    % maxCntVar = Simulink.Simulation.Variable('maxCnt', 5);
    % simulink.compiler.modifyParameters(mdlFile, maxCntVar);
catch err
    msgbox(err.message)
end
end
function postStepParameterTuner(time,model)
newMaskVars = [Simulink.Simulation.Variable('maxCntVar',5),...
    Simulink.Simulation.Variable('maxCntVar',7,'Workspace',model)];
simulink.compiler.modifyParameters(model,newMaskVars);
end