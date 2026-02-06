function runSDRTSetup(modelName, Ts)
% ONE-CALL SDRT preparation script

    fprintf('\n===== SDRT SETUP START =====\n');

    setupSDRT(modelName, Ts);

    checkInheritedSampleTimes(modelName);

    sdrtPreflightCheck(modelName);

    wcet = measureExecutionTime(modelName);

    if wcet >= Ts
        error('ERROR: WCET (%.6f) exceeds sample time (%.6f)', wcet, Ts);
    end

    fprintf('✔ WCET within limits\n');
    fprintf('===== SDRT SETUP COMPLETE =====\n\n');
end
