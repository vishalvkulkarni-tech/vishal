function optionInterestApp
    % Create figure and axes for plot
    f = figure('Name', 'Option Interest App', 'NumberTitle', 'off', 'Position', [100 100 640 480]);
    ax = axes('Parent', f, 'Position', [0.15 0.15 0.8 0.8]);
    xlabel(ax, 'Time');
    ylabel(ax, 'Open Interest');
    title(ax, 'Open Interest of Call and Put Options');
    
    % Initialize data and plot
    data = struct('time', [], 'openIntCall', [], 'openIntPut', []);
    plot(ax, data.time, data.openIntCall, 'r-', 'LineWidth', 2);
    hold(ax, 'on');
    plot(ax, data.time, data.openIntPut, 'b-', 'LineWidth', 2);
    hold(ax, 'off');
    legend(ax, 'Call Option', 'Put Option');
    
    % Set timer for fetching data every 30 seconds
    timerFetchData = timer('Period', 30, 'ExecutionMode', 'fixedRate', 'TimerFcn', @fetchData);
    
    % Set timer for plotting data every minute
    timerPlotData = timer('Period', 60, 'ExecutionMode', 'fixedRate', 'TimerFcn', @plotData);
    
    % Start timers
    start(timerFetchData);
    start(timerPlotData);
    
    % Callback function for fetching data
    function fetchData(~, ~)
        % Fetch data from NSE India website
        url = 'https://www.nseindia.com/live_market/dynaContent/live_watch/option_chain/optionKeys.jsp';
        options = weboptions('Timeout', 20, 'UserAgent', 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3');
        dataCurrent = webread(url, options);
        
        % Parse data to extract open interest of call and put options
        startIndex = strfind(dataCurrent, 'openInt');
        endIndex = strfind(dataCurrent, 'pChange');
        openIntCall = str2double(extractBetween(dataCurrent(startIndex(1):startIndex(1)+50), '>', '<'));
        openIntPut = str2double(extractBetween(dataCurrent(startIndex(2):startIndex(2)+50), '>', '<'));
        
        % Append data to data structure
        data.time(end+1) = now;
        data.openIntCall(end+1) = openIntCall;
        data.openIntPut(end+1) = openIntPut;
    end

    % Callback function for plotting data
    function plotData(~, ~)
        % Update plot with latest data
        plot(ax, data.time, data.openIntCall, 'r-', 'LineWidth', 2);
        hold(ax, 'on');
        plot(ax, data.time, data.openIntPut, 'b-', 'LineWidth', 2);
        hold(ax, 'off');
        legend(ax, 'Call Option', 'Put Option');
    end
end