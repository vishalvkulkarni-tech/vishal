function OIvsStrikePrice()
url = 'https://www.nseindia.com/api/option-chain-indices?symbol=NIFTY';
data = webread(url);
strikePrices = cellfun(@(x) x.strikePrice, data.records.data);
strikePrices = int16(strikePrices);
NiftyCMP = data.records.underlyingValue;
NiftyCMP = int16(NiftyCMP);
[~,closestIndex] = min(abs(NiftyCMP-strikePrices));
closestStrikePrice = strikePrices(closestIndex);
reqStrikePrices = [closestStrikePrice-50; closestStrikePrice; closestStrikePrice+50];
currentExpDate = data.records.expiryDates{1};

time = [];
currentTime = datetime("now");
t1 = datevec(currentTime);
callOI1 = [];callOI2 = [];callOI3 = [];%callOI4 = [];callOI5 = [];
putOI1 = [];putOI2 = [];putOI3 = [];%putOI4 = [];putOI5 = [];
% timeFormat='HH:MM:SS.FFF AM mm/dd/yyyy';
timerFetchData = timer('Period', 300, 'ExecutionMode', 'fixedRate', 'TimerFcn', @fetchData);
start(timerFetchData);
% yyaxis right
% plot(reqStrikePrices)
% set(gca,'ylim',[min(reqStrikePrices) max(reqStrikePrices)])

    function fetchData(~, ~)
        url = 'https://www.nseindia.com/api/option-chain-indices?symbol=NIFTY';
        data = webread(url);
        currentExpIndices = find(cellfun(@(x) strcmp(x.expiryDate, currentExpDate), data.records.data));
        currentExpiryData = data.records.data(currentExpIndices);
        currentExpStrikes = cellfun(@(x) x.strikePrice, currentExpiryData);
        [~, indIntersect] = intersect(currentExpStrikes,reqStrikePrices);
        currentTime = datetime("now");

        call_oi = cellfun(@(x) x.CE.openInterest, currentExpiryData(indIntersect));
        put_oi = cellfun(@(x) x.PE.openInterest, currentExpiryData(indIntersect));

        time = [time currentTime];
        callOI1 = [callOI1 call_oi(1)];callOI2 = [callOI2 call_oi(2)];callOI3 = [callOI3 call_oi(3)];%callOI4 = [callOI4 call_oi(4)];callOI5 = [callOI5 call_oi(5)];
        putOI1 = [putOI1 put_oi(1)];putOI2 = [putOI2 put_oi(2)];putOI3 = [putOI3 put_oi(3)];%putOI4 = [putOI4 put_oi(4)];putOI5 = [putOI5 put_oi(5)];


        % Plot the data

        hold on
        yyaxis left
        plot(time, callOI1,'Color', 'r','LineWidth',1);
        plot(time, callOI2, '--gs', 'Color', 'r','LineWidth',4);
        plot(time, callOI3, 'Color', 'r','LineWidth',1);
        %         plot(time, callOI4, '--', 'Color', 'r');
        %         plot(time, callOI5, '--', 'Color', 'r');
        %
        yyaxis right
        plot(time, putOI1,'Color', 'g','LineWidth',1);
        plot(time, putOI2, '--gs', 'Color', 'g','LineWidth',4);
        plot(time, putOI3,'Color', 'g','LineWidth',1);
        %         plot(time, putOI4, ':', 'Color', 'g');
        %         plot(time, putOI5, ':', 'Color', 'g');
        %             lgd = legend(num2str(reqStrikePrices(1)),num2str(reqStrikePrices(2)),num2str(reqStrikePrices(3)),num2str(reqStrikePrices(4)),num2str(reqStrikePrices(5)),...
        %                 num2str(reqStrikePrices(1)),num2str(reqStrikePrices(2)),num2str(reqStrikePrices(3)),num2str(reqStrikePrices(4)),num2str(reqStrikePrices(5)));
        lgd = legend(num2str(reqStrikePrices(1)),num2str(reqStrikePrices(2)),num2str(reqStrikePrices(3)),...
            num2str(reqStrikePrices(1)),num2str(reqStrikePrices(2)),num2str(reqStrikePrices(3)));
        a1 = gca;
        a1.XAxis.Limits = [datetime([t1(1) t1(2) t1(3) 11 0 0]), datetime([t1(1) t1(2) t1(3) 16 0 0])];
        lgd.Location = 'northwest';
        datetick('x','HH:MM');
        xlabel('Time')
        ylabel('Open Interest')
        title('Call and Put Open Interest')
        %         plot(reqStrikePrices)
        a1.YAxis(1).Limits = [min(call_oi) max(call_oi)];
        %         a1.YAxis(2).Limits = [min(reqStrikePrices) max(reqStrikePrices)];
        a1.YAxis(2).Limits = [min(put_oi) max(put_oi)];

        hold off
    end
end