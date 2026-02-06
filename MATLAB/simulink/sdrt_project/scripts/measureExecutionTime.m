function wcet = measureExecutionTime(modelName)
% Runs Simulink Profiler and reports WCET

    if ~bdIsLoaded(modelName)
        load_system(modelName);
    end

    fprintf('Measuring execution time using Simulink Profiler...\n');

    SimulinkProfiler.start(modelName);
    sim(modelName);
    profileData = SimulinkProfiler.stop(modelName);

    wcet = max(profileData.ExecutionTime);

    fprintf('WCET = %.6f seconds\n', wcet);
end
