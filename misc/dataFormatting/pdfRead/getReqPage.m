function [opStrArrayPage, cnt] = getReqPage(opStrArrayPage, strArray, cnt)
pageArrayCAPS = string(upper(strArray));
pageArrayCAPS = arrayfun(@(x) getReqString(x), pageArrayCAPS);
for ii = 1:length(pageArrayCAPS)
    strinchar = char(pageArrayCAPS(ii));
    % secondlastChar = str2num(strinchar(end-1));
    if contains(strinchar, '.') && (startsWith(strinchar, '(ADJ.') || startsWith(strinchar, '(N.') || startsWith(strinchar, '(V.') || (startsWith(strinchar, '(NUMBER') && contains(strinchar, 'ADV.')))
        lastStrinChar = char(opStrArrayPage(cnt-1,1));
        lastStrinChar(end) = [];
        strinchar(1) = [];
        opStrArrayPage(cnt-1,1) = strcat(string(lastStrinChar), string(strinchar));
    else
        opStrArrayPage(cnt,1) = string(strcat("(", num2str(cnt), ")=", pageArrayCAPS(ii)));
        cnt = cnt + 1;
    end
end