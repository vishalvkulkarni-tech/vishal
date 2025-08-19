function modifiedStr = getReqString(str)
    % Convert the input string to a character array for processing
    strChar = upper(char(str));
    
    % Initialize an empty array to build the modified string
    modifiedStr = '';
    
    % Loop through each character in the string
    j = 1;  % Index for character array
    while j <= length(strChar)
        if strChar(j) == ' '  % Check if the character is a space
            if j > 1 && strChar(j-1) == ','  % Preceding character is a comma
                modifiedStr = [modifiedStr, ' '];  % Keep the space as is
            elseif j > 1 && strChar(j-1) == '.'  % Preceding character is a period
                % Skip this space and move to next character
                j = j + 1; 
                continue;  
            else
                modifiedStr = [modifiedStr, ')('];  % Replace space with )(
            end
        elseif j <= length(strChar) - 1 && strChar(j) == '.' && strChar(j+1) == ','  % Check for '.,'
            modifiedStr = [modifiedStr, '.,)('];  % Replace '.,' with '.,)('
            j = j + 1;  % Skip the next character (comma)
        % elseif j <= length(strChar) - 1 && strChar(j) == '.' && strChar(j+1) == '/'  % Check for '.,'
        %     modifiedStr = [modifiedStr, './)('];  % Replace '.,' with './)('
        %     j = j + 1;  % Skip the next character (/)
        else
            modifiedStr = [modifiedStr, strChar(j)];  % Add the current character to the result
        end
        j = j + 1;  % Move to the next character
    end
    modifiedStr = strrep(modifiedStr, ')( ', ')(');
    modifiedStr = strrep(modifiedStr, ', ', ',)(');
    % Ensure only one set of parentheses around the result
    if ~isempty(modifiedStr)
        modifiedStr = ['(', modifiedStr, ')'];
    end

    % Convert back to string type
    modifiedStr = string(modifiedStr);
end
