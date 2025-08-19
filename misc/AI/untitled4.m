% Set the URL of the NSE India homepage to fetch the current underlying value of NIFTY
homepage_url = 'https://www1.nseindia.com/';

% Set the headers to mimic a web browser
headers = {'Accept-Encoding', 'gzip, deflate, br', ...
    'Accept-Language', 'en-US,en;q=0.9', ...
    'Cache-Control', 'max-age=0', ...
    'Connection', 'keep-alive', ...
    'Host', 'www1.nseindia.com', ...
    'Referer', 'https://www.google.com/', ...
    'User-Agent', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36'};

% Convert the headers into a cell array of name-value pairs
header_fields = reshape(headers, 2, []).';

% Send the HTTP request to fetch the current underlying value of NIFTY from the homepage of the website
response = webread(homepage_url, weboptions('Timeout', 20, 'HeaderFields', header_fields));

% Parse the HTML response using MATLAB's built-in HTML parser
html = response;
% Parse the HTML response into a DOM tree
dom = htmlTree(response);

% Extract the underlying value of NIFTY from the DOM tree
xpath_expression = '//div[@class="indexcircleindex"]/following-sibling::div[1]';
underlying_value = extractHTMLText(findElement(dom, xpath_expression));

% Extract the strike prices, call OI, and put OI data from the HTML table
table_data = extractHTMLText(table_elements);
data = strsplit(table_data{1}, '\n');
data = data(5:end-1);
strikes = [];
call_oi = [];
put_oi = [];
for i = 1:length(data)
    row_data = strsplit(data{i}, ',');
    if length(row_data) == 11
        strikes(end+1) = str2double(row_data{2});
        call_oi(end+1) = str2double(row_data{6});
        put_oi(end+1) = str2double(row_data{11});
    end
end

% % Extract the current underlying value of NIFTY from the HTML element
% nifty_value_data = extractHTMLText(nifty_value_elements);
% nifty_value = str2double(nifty_value_data{1});

% Set the URL of the NSE India website to fetch the option chain data
option_chain_url = 'https://www1.nseindia.com/live_market/dynaContent/live_watch/option_chain/optionKeys.jsp';

% Set the headers for the HTTP request as before

% Send the HTTP request to fetch the option chain data from the website
response = webread(option_chain_url, weboptions('Timeout', 20, 'HeaderFields', headers));

% Parse the HTML response using MATLAB's built-in HTML parser as before

% Extract the strike prices, call OI, and put OI data from the HTML table as before

% Find the index of the strike price closest to the underlying price
[~, idx] = min(abs(strikes - underlying_value));

% Extract the call and put OI data for the nearest strike price
nearest_strike_price = strikes(idx);
nearest_call_oi = call_oi(idx);
nearest_put_oi = put_oi(idx);

% Print the results
fprintf('Nearest Strike Price: %g\n', nearest_strike_price);
fprintf('Call OI: %g\n', nearest_call_oi);
fprintf('Put OI: %g\n', nearest_put_oi);
