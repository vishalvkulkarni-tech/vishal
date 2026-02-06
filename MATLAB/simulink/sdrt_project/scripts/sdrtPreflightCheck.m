function sdrtPreflightCheck(modelName)
% Fail-fast checks for SDRT compatibility

    if ~bdIsLoaded(modelName)
        load_system(modelName);
    end

    fprintf('Running SDRT pre-flight checks...\n');

    % Solver check
    assert(strcmp(get_param(modelName,'SolverType'),'Fixed-step'), ...
        'ERROR: SolverType must be Fixed-step');

    assert(strcmp(get_param(modelName,'Solver'),'FixedStepDiscrete'), ...
        'ERROR: Solver must be FixedStepDiscrete');

    % Zero crossing
    assert(strcmp(get_param(modelName,'ZeroCross'),'off'), ...
        'ERROR: Zero-crossing must be OFF');

    % Logging
    assert(strcmp(get_param(modelName,'SignalLogging'),'off'), ...
        'ERROR: Signal logging must be OFF');

    % Algebraic loops
    al = Simulink.BlockDiagram.getAlgebraicLoops(modelName);
    assert(isempty(al), 'ERROR: Algebraic loops detected');

    % Variable-size signals
    vs = Simulink.findBlocks(modelName,'VariableSizeSignals','on');
    assert(isempty(vs), 'ERROR: Variable-size signals found');

    fprintf('✔ SDRT pre-flight checks PASSED\n');
end
