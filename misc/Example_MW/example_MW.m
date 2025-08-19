clear P p Skv

%% openExample('simscapeelectrical/MicrogridEVToGridExample')

%% parameter Simplorer aus AIM_INNOVATION_400V_v7_11
Un = 400;
fn = 50;
p.In = 320;
p.Un = Un;
p.RSC = 20;
p.Pn = p.Un*p.In*sqrt(3);  % VA,   nominal power
X_R = 10;

p.HF = 1.5;
p.Udc = p.Un*p.HF;
p.fn = fn;
p.om = 2*pi*p.fn;

p.Lk = 0.00017;
p.X_R_Lk =100;
p.Le = 9e-05;
p.X_R_Le = 100;
p.Cz = 6.75e-05;
p.Rz = .15;

p.Cd = 10e-3*2;
p.Rd = 2e-3;
p.Rd2 = 60e3;
p.cab.l = 10;
p.cab.ll = 200e-9; % H/m
p.cab.rl = 0.150e-3; % Ohmkm


%% parameters (for Three-phase Grid-Connected Rectifier Control Example)

%% Transformer parameters
R1pu = 0.01;   % p.u., primary resistance
L1pu = 0.05;   % p.u., primary leakage inductance

%% References
p.wtbase = 2*pi*fn;              % rad/s, base elec. radial frequency
p.Vt1base = Un/sqrt(3)*sqrt(2);  % primary base voltage
p.It1base = p.Pn/(1.5*p.Vt1base);    % primary base current
p.Zt1base = p.Vt1base / p.It1base;   % primary base impedance

p.R1 = R1pu * p.Zt1base;           % ohm, primary resistance
p.L1 = L1pu * p.Zt1base/p.wtbase;    % H,   primary leakage inductance

p.Req = (p.R1)/p.Zt1base;  % p.u., equivalent resistance
p.Leq = (p.L1)/(p.Zt1base/p.wtbase);  % p.u., equivalent leakage inductance


%% Control parameters
p.fsw = 4e3;        % Hz, switching frequency
p.Tsc = 1/p.fsw;    % s, control sample time
Ts = p.Tsc/10; %1e-6;        % s, fundamental sample time

p.Kp_iq = 0.3315;
p.Ki_iq = 36.7288;
p.Kp_id = 0.3315;
p.Ki_id = 36.7288;
p.Kp_vdc = 3.582;
p.Ki_vdc = 500;

% Internal model voltage controller
p.numd = [0    0.0022    0.0000   -0.0022];
p.dend = [1.0000   -2.9832    2.9708   -0.9876];

%% Setup model
n_dev = 4; %% <<--- 4 Devices

P(1:n_dev,1) = p;

for k = 1:n_dev
    Skv(k) = Un*P(k).In*sqrt(3)*P(k).RSC;
    P(k).p = .75 + .25*(-1)^(k+1);
    P(k).cab.l = P(k).cab.l * 2^k;
end
Skv = sum(Skv);

Ts0 = Ts;
step = 5;

name_mat = ['results_',num2str(n_dev),'.mat'];
if 0
    load(name_mat);
else
    %% Simulate
    simin = Simulink.SimulationInput("system_MW");
    for k = 1:step
        ts(k) = Ts0/2^(k-1);
        Ts = ts(k);

        out(k) = sim(simin);
        disp(out(k).SimulationMetadata.TimingInfo);
    end

    save(name_mat,'out')
end

%% Postprocessing
for k = 1:step
    t_wall(k,:) = [out(k).SimulationMetadata.TimingInfo.ExecutionElapsedWallTime, out(k).SimulationMetadata.TimingInfo.InitializationElapsedWallTime];
    vol(k) = out(k).logsout{1}.Values;
    cur(k) = out(k).logsout{2}.Values;
end


figure('Color','white')
ts_ = min(ts):.1e-6:max(ts);
for j = 1:2
    t_wall_(:,j) = makima(ts, t_wall(:,j), ts_);
end
plot(ts_*1e6, t_wall_,'-')
hold on
plot(ts*1e6, t_wall(:,1),'ob')
plot(ts*1e6, t_wall(:,2),'or')
grid on
grid minor
title('$t_{wall}$', 'interpreter', 'latex', 'FontSize', 14)
legend("execution","init")
xlabel("$t$ / $\mu$s", 'interpreter', 'latex', 'FontSize', 12)
ylabel("$t$ / s", 'interpreter', 'latex', 'FontSize', 12)

