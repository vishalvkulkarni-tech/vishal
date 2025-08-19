function recOut = recFunc(num1)

if num1 <= 1 
    recOut = 1;
    return
end

recOut = num1 * recFunc(num1-1);


% 5-> 5! = 5*4*3*2*1