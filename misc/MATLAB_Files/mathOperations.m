% mathematical operations on two numbers 
v1 = input('enter a number: ');
v2 = input('enter a number: ');

% v1 = 50;
% v2 = 10;

if ~isnumeric(v1) || ~isnumeric(v2)
    disp('either of the inputs is not a number')
    return
end

adtn1 = v1+v2;
subn = v1-v2;
muln = v1*v2;
divn = v1/v2;

disp(strcat('addition = ', num2str(adtn1)))

% adtn(1,8,50)