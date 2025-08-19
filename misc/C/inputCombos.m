% Define maximum values for reference
maxVal31 = 39;    % Replaceable maximum value

% Test inputs for ShSM_noGearReq (scalar, range 0 to 255)
ShSM_noGearReq_cases = 0:1:136;

% Test inputs for DrM_stCluReqAry (10x1 array, min=1, max=maxVal31)
DrM_stCluReqAry_cases = {
    zeros(10, 1),                     % All elements at minimum (1)
    ones(10, 1),
    2*ones(10, 1),
    3*ones(10, 1),
    4*ones(10, 1),
    5*ones(10, 1),
    6*ones(10, 1),
    7*ones(10, 1),
    8*ones(10, 1),
    9*ones(10, 1)
};

% Test inputs for CluOM_noOncCluCnt (scalar, range 1 to 8)
CluOM_noOncCluCnt_cases = 0:10;

% Test inputs for CluOM_noOncCluAry (8x1 array, min=1, max=maxVal31)
CluOM_noOncCluAry_cases = {
    ones(8, 1),                      % All elements at minimum (1)
    ones(10, 1),
    2*ones(10, 1),
    3*ones(10, 1),
    4*ones(10, 1),
    5*ones(10, 1),
    6*ones(10, 1),
    7*ones(10, 1),
    8*ones(10, 1),
    9*ones(10, 1)
};

% Test inputs for CluOM_noOfgCluCnt (scalar, range 1 to 8)
CluOM_noOfgCluCnt_cases = 0:10;

% Test inputs for CluOM_noOfgCluAry (8x1 array, min=1, max=maxVal31)
CluOM_noOfgCluAry_cases = {
    ones(8, 1),                      
    ones(10, 1),
    2*ones(10, 1),
    3*ones(10, 1),
    4*ones(10, 1),
    5*ones(10, 1),
    6*ones(10, 1),
    7*ones(10, 1),
    8*ones(10, 1),
    9*ones(10, 1)
};

% Combine test cases for each input into a struct array for easy access
testCases = [];
caseNum = 1;
for i = 1:length(ShSM_noGearReq_cases)
    for j = 1:length(DrM_stCluReqAry_cases)
        for k = 1:length(CluOM_noOncCluCnt_cases)
            for l = 1:length(CluOM_noOncCluAry_cases)
                for m = 1:length(CluOM_noOfgCluCnt_cases)
                    for n = 1:length(CluOM_noOfgCluAry_cases)
                        % Construct each test case as a struct
                        testCases(caseNum).ShSM_noGearReq = ShSM_noGearReq_cases(i);
                        testCases(caseNum).DrM_stCluReqAry = DrM_stCluReqAry_cases{j};
                        testCases(caseNum).CluOM_noOncCluCnt = CluOM_noOncCluCnt_cases(k);
                        testCases(caseNum).CluOM_noOncCluAry = CluOM_noOncCluAry_cases{l};
                        testCases(caseNum).CluOM_noOfgCluCnt = CluOM_noOfgCluCnt_cases(m);
                        testCases(caseNum).CluOM_noOfgCluAry = CluOM_noOfgCluAry_cases{n};
                        caseNum = caseNum + 1;
                    end
                end
            end
        end
    end
end
