% Set the URL of the NSE India homepage to fetch the current underlying value of NIFTY
homepage_url = 'https://www1.nseindia.com/';

% Set the headers to mimic a web browser
headers = matlab.net.http.HeaderField;
headers.addFields(matlab.net.http.field.AcceptEncoding('gzip, deflate, br'));
headers.addFields(matlab.net.http.field.AcceptLanguage('en-US,en;q=0.9'));
headers.addFields(matlab.net.http.field.CacheControl('max-age=0'));
headers.addFields(matlab.net.http.field.Connection('keep-alive'));
headers.addFields(matlab.net.http.field.Host('www1.nseindia.com'));
headers.addFields(matlab.net.http.field.Referer('https://www.google.com/'));
headers.addFields(matlab.net.http.field.UserAgent('Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36'));

% Set the options for the HTTP request
options = matlab.net.http.HTTPOptions('DecodeResponse', true, 'MaxRedirects', 20, 'Authenticate', false, 'ConvertResponse', true, 'UseProxy', false);

% Send the HTTP request to fetch the current underlying value of NIFTY from the homepage of the website
response = webread(homepage_url, options, headers);

% Parse the HTML response using MATLAB's built-in HTML parser
html = response;
dom = htmltree(html);
nifty_value_elements = findElement(dom, 'id', 'indexWatch');

% Extract the current underlying value of NIFTY from the HTML element
nifty_value_data = extractHTMLText(nifty_value_elements);
nifty_value = str2double(nifty_value_data{1});

% Set the URL of the NSE India website to fetch the option chain data
option_chain_url = 'https://www1.nseindia.com/live_market/dynaContent/live_watch/option_chain/optionKeys.jsp';

% Set the headers and options for the HTTP request as before

% Send the HTTP request to fetch the option chain data from the website
response = webread(option_chain_url, options, headers);

% Parse the HTML response using MATLAB's built-in HTML parser as before

% Extract the strike prices, call OI, and put OI data from the HTML table as before

% Find the index of the strike price closest to the underlying price
[~, idx] = min(abs(strikes - nifty_value));

% Extract the call and put OI data for the nearest strike price
nearest_strike_price = strikes(idx);
nearest_call_oi = call_oi(idx);
nearest_put_oi = put_oi(idx);

% Print the results
fprintf('Nearest Strike Price: %g\n', nearest_strike_price);
fprintf('Call OI: %g\n', nearest_call_oi);
fprintf('Put OI: %g\n', nearest_put_oi);
