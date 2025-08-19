% Fetch the data from the website
url = 'https://www.nseindia.com/api/option-chain-indices?symbol=NIFTY';
data = webread(url);

% Extract the Call and Put OI data
call_oi = data.records.data(:, :, 4);
put_oi = data.records.data(:, :, 22);

% Plot the data
hold on
plot(call_oi, '-b')
plot(put_oi, '-r')
legend('Call OI', 'Put OI')
xlabel('Time')
ylabel('Open Interest')
title('Call and Put Open Interest')
hold off

% Pause for 30 seconds before fetching the data again
pause(30);
