url = 'https://www.nseindia.com/';
strikeUrl = strcat(url, 'live_market/dynaContent/live_watch/option_chain/optionKeys.jsp');
strikePricePattern = '<b id="underlineId">(.*?)</b>';
callOIPattern = '<td class="grybg"><b>(.*?)</b></td>';
putOIPattern = '<td class="grybg" align="right"><b>(.*?)</b></td>';

time = [];
callOI = [];
putOI = [];

figure;
title('Call and Put Open Interest vs Time');
xlabel('Time (minutes)');
ylabel('Open Interest');
hold on;

while true
    html = webread(strikeUrl);
    
    % Extract current strike price
    startIndex = regexp(html, strikePricePattern);
    currentStrikePrice = html(startIndex+26:startIndex+31);
    
    % Extract call and put open interest
    callOIIndex = regexp(html, callOIPattern);
    putOIIndex = regexp(html, putOIPattern);
    callOIValue = html(callOIIndex+22:callOIIndex+27);
    putOIValue = html(putOIIndex+23:putOIIndex+28);
    
    % Convert data types
    currentCallOI = str2double(strrep(callOIValue, ',', ''));
    currentPutOI = str2double(strrep(putOIValue, ',', ''));
    currentTime = now;
    
    % Plot data
    time = [time currentTime];
    callOI = [callOI currentCallOI];
    putOI = [putOI currentPutOI];
    plot((time-time(1))*24*60, callOI, 'r');
    plot((time-time(1))*24*60, putOI, 'b');
    legend('Call Open Interest', 'Put Open Interest');
    
    % Wait for 1 minute
    pause(60);
end
