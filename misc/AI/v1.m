% Initialize variables
time = datetime('now');
pcrValues = [];
spotValues = [];

% Create a figure for plotting
figure;
hold on;
title('Nifty PCR and Spot Value vs. Time');
xlabel('Time');
ylabel('Value');

while true
    try
        % Define the URL to fetch Nifty PCR and spot values
        url = 'https://www.nseindia.com/live_market/dynaContent/live_watch/option_chain/optionKeys.jsp';

        % Specify headers to mimic a web browser request
        options = weboptions('KeyName', 'Cookie', 'KeyValue', 'your_cookie_here');

        % Fetch the web page content
        pageContent = webread(url, options);

        % Extract PCR and spot values from the pageContent (you'll need to parse the HTML)
        % Replace this part with HTML parsing code specific to the NSE website structure

        % For demonstration purposes, we'll use random values
        pcrValue = rand(1);
        spotValue = rand(1);

        % Store the fetched values
        pcrValues = [pcrValues, pcrValue];
        spotValues = [spotValues, spotValue];

        % Update the time vector
        time = [time, datetime('now')];

        % Plot the data
        plot(time, pcrValues, 'r', 'DisplayName', 'PCR');
        plot(time, spotValues, 'b', 'DisplayName', 'Spot');

        % Add legend
        legend('Location', 'northwest');

        % Pause for 5 minutes (300 seconds) before fetching data again
        pause(300);
    catch
        disp('Error fetching data. Retrying in 5 minutes...');
        pause(300); % Retry after 5 minutes in case of an error
    end
end
