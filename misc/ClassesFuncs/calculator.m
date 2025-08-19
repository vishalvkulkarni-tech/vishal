classdef calculator

    methods
        function calculator_output(obj, val)
            
            if ~isa(val,'sym')
                disp('Input is not symbolic. Please use method again with symbolic input.')
                return
            end

            squareRootofInputNum =  obj.squareRoot(val);
            obj.displyInput('Sqaure Root of input number is ');
            obj.displyInput(squareRootofInputNum);

            thirdRootofInput =  obj.thirdRoot(val);
            obj.displyInput('Third Root of input number is ');
            obj.displyInput(thirdRootofInput);
        end
    end

    methods (Access=private)

        function squareRootofInputNum = squareRoot(~, inputNumber)
            squareRootofInputNum = sqrt(inputNumber);
        end

        function squareRootofInputNum = thirdRoot(~, inputNumber)
            squareRootofInputNum = inputNumber^(1/3);
        end

        function displyInput(~, inputVar_Num)
            disp(inputVar_Num);
        end

    end

end