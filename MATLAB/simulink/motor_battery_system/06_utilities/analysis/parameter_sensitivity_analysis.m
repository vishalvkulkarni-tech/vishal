%% Parameter Sensitivity Analysis Tool
% Analyzes how parameter variations affect system performance
% Useful for design optimization and robustness analysis

function results = parameter_sensitivity_analysis(model_name, param_list, variation_range, options)
    % param_list: cell array of parameter names to vary
    % variation_range: [min_factor, max_factor] e.g., [0.8, 1.2] for ±20%
    % options: struct with analysis options
    
    if nargin < 4
        options = struct();
    end
    
    % Default options
    if ~isfield(options, 'N_points'), options.N_points = 11; end
    if ~isfield(options, 'metrics'), options.metrics = {'efficiency', 'peak_torque', 'settling_time'}; end
    if ~isfield(options, 'plot_results'), options.plot_results = true; end
    if ~isfield(options, 'parallel'), options.parallel = false; end
    
    fprintf('\n========================================\n');
    fprintf('Parameter Sensitivity Analysis\n');
    fprintf('========================================\n');
    fprintf('Model: %s\n', model_name);
    fprintf('Parameters to analyze: %d\n', length(param_list));
    fprintf('Variation range: %.0f%% to %.0f%%\n', variation_range(1)*100, variation_range(2)*100);
    fprintf('========================================\n\n');
    
    % Load model
    load_system(model_name);
    
    % Get baseline performance
    fprintf('Running baseline simulation...\n');
    baseline_results = run_simulation(model_name);
    baseline_metrics = calculate_metrics(baseline_results, options.metrics);
    
    % Initialize results storage
    N_params = length(param_list);
    N_points = options.N_points;
    
    results.param_names = param_list;
    results.variation_factors = linspace(variation_range(1), variation_range(2), N_points);
    results.baseline_metrics = baseline_metrics;
    results.sensitivity_data = cell(N_params, 1);
    
    %% Sweep each parameter
    for p = 1:N_params
        param_name = param_list{p};
        fprintf('\n--- Analyzing parameter: %s ---\n', param_name);
        
        % Get baseline value
        baseline_value = evalin('base', param_name);
        fprintf('Baseline value: %.6g\n', baseline_value);
        
        % Storage for this parameter
        param_results = struct();
        param_results.values = baseline_value * results.variation_factors;
        param_results.metrics = struct();
        
        for m = 1:length(options.metrics)
            metric_name = options.metrics{m};
            param_results.metrics.(metric_name) = zeros(1, N_points);
        end
        
        % Sweep parameter values
        for i = 1:N_points
            factor = results.variation_factors(i);
            new_value = baseline_value * factor;
            
            fprintf('  [%d/%d] Factor: %.2f, Value: %.6g\n', i, N_points, factor, new_value);
            
            % Set parameter
            assignin('base', param_name, new_value);
            
            % Run simulation
            try
                sim_results = run_simulation(model_name);
                metrics = calculate_metrics(sim_results, options.metrics);
                
                % Store metrics
                for m = 1:length(options.metrics)
                    metric_name = options.metrics{m};
                    param_results.metrics.(metric_name)(i) = metrics.(metric_name);
                end
            catch ME
                warning('Simulation failed at factor %.2f: %s', factor, ME.message);
                for m = 1:length(options.metrics)
                    metric_name = options.metrics{m};
                    param_results.metrics.(metric_name)(i) = NaN;
                end
            end
        end
        
        % Restore baseline value
        assignin('base', param_name, baseline_value);
        
        % Calculate sensitivity metrics
        param_results.sensitivity_index = calculate_sensitivity_index(param_results, baseline_metrics, options.metrics);
        
        % Store results
        results.sensitivity_data{p} = param_results;
        
        fprintf('  Sensitivity index: %.4f\n', param_results.sensitivity_index);
    end
    
    %% Rank parameters by sensitivity
    sensitivity_indices = zeros(N_params, 1);
    for p = 1:N_params
        sensitivity_indices(p) = results.sensitivity_data{p}.sensitivity_index;
    end
    
    [sorted_indices, sort_order] = sort(sensitivity_indices, 'descend');
    results.ranked_params = param_list(sort_order);
    results.ranked_sensitivity = sorted_indices;
    
    fprintf('\n========================================\n');
    fprintf('Parameter Sensitivity Ranking\n');
    fprintf('========================================\n');
    for p = 1:N_params
        fprintf('%d. %s: %.4f\n', p, results.ranked_params{p}, results.ranked_sensitivity(p));
    end
    fprintf('========================================\n\n');
    
    %% Plot results
    if options.plot_results
        plot_sensitivity_results(results, options);
    end
    
    % Close model
    close_system(model_name, 0);
end

%% Run simulation
function sim_results = run_simulation(model_name)
    % Simulate and return key signals
    sim_out = sim(model_name, 'ReturnWorkspaceOutputs', 'on');
    
    % Extract logsout data
    if isfield(sim_out, 'logsout')
        sim_results.logsout = sim_out.logsout;
        sim_results.time = sim_out.tout;
    else
        error('No logsout found. Enable signal logging in model.');
    end
end

%% Calculate metrics from simulation results
function metrics = calculate_metrics(sim_results, metric_names)
    metrics = struct();
    
    for m = 1:length(metric_names)
        metric_name = metric_names{m};
        
        switch metric_name
            case 'efficiency'
                % Calculate average efficiency
                P_in = get_signal(sim_results, 'P_input');
                P_out = get_signal(sim_results, 'P_output');
                if ~isempty(P_in) && ~isempty(P_out)
                    eff = P_out.Values.Data ./ (P_in.Values.Data + 1e-6) * 100;
                    metrics.efficiency = mean(eff(eff > 0 & eff < 100));
                else
                    metrics.efficiency = NaN;
                end
                
            case 'peak_torque'
                T = get_signal(sim_results, 'Torque');
                if ~isempty(T)
                    metrics.peak_torque = max(abs(T.Values.Data));
                else
                    metrics.peak_torque = NaN;
                end
                
            case 'settling_time'
                speed = get_signal(sim_results, 'Speed');
                if ~isempty(speed)
                    metrics.settling_time = calculate_settling_time(speed);
                else
                    metrics.settling_time = NaN;
                end
                
            case 'overshoot'
                speed = get_signal(sim_results, 'Speed');
                if ~isempty(speed)
                    metrics.overshoot = calculate_overshoot(speed);
                else
                    metrics.overshoot = NaN;
                end
                
            case 'ripple'
                torque = get_signal(sim_results, 'Torque');
                if ~isempty(torque)
                    metrics.ripple = std(torque.Values.Data);
                else
                    metrics.ripple = NaN;
                end
                
            otherwise
                warning('Unknown metric: %s', metric_name);
                metrics.(metric_name) = NaN;
        end
    end
end

%% Get signal from logsout
function signal = get_signal(sim_results, signal_name)
    signal = [];
    try
        signal = sim_results.logsout.get(signal_name);
    catch
        % Signal not found
    end
end

%% Calculate settling time (2% criterion)
function t_settle = calculate_settling_time(speed_signal)
    t = speed_signal.Values.Time;
    y = speed_signal.Values.Data;
    
    % Final value
    y_final = mean(y(end-100:end));
    
    % 2% band
    tolerance = 0.02 * abs(y_final);
    
    % Find last time outside band
    outside_band = abs(y - y_final) > tolerance;
    if any(outside_band)
        idx = find(outside_band, 1, 'last');
        t_settle = t(idx);
    else
        t_settle = 0;
    end
end

%% Calculate overshoot
function overshoot = calculate_overshoot(speed_signal)
    y = speed_signal.Values.Data;
    y_final = mean(y(end-100:end));
    y_peak = max(y);
    
    if y_final > 0
        overshoot = (y_peak - y_final) / y_final * 100;
    else
        overshoot = 0;
    end
end

%% Calculate overall sensitivity index
function SI = calculate_sensitivity_index(param_results, baseline_metrics, metric_names)
    % Normalized sensitivity across all metrics
    SI_sum = 0;
    
    for m = 1:length(metric_names)
        metric_name = metric_names{m};
        baseline_val = baseline_metrics.(metric_name);
        
        if isnan(baseline_val) || baseline_val == 0
            continue;
        end
        
        metric_values = param_results.metrics.(metric_name);
        
        % Normalized derivative at baseline (central difference)
        mid_idx = ceil(length(metric_values)/2);
        dMetric = metric_values(end) - metric_values(1);
        dParam = param_results.values(end) - param_results.values(1);
        
        if dParam ~= 0
            sensitivity = abs(dMetric / dParam * param_results.values(mid_idx) / baseline_val);
            SI_sum = SI_sum + sensitivity;
        end
    end
    
    SI = SI_sum / length(metric_names);
end

%% Plot sensitivity results
function plot_sensitivity_results(results, options)
    N_params = length(results.param_names);
    N_metrics = length(options.metrics);
    
    figure('Name', 'Parameter Sensitivity Analysis', 'Position', [50, 50, 1600, 900]);
    
    % Individual parameter plots
    for p = 1:min(N_params, 6) % Limit to 6 parameters for readability
        subplot(2, 3, p);
        param_data = results.sensitivity_data{p};
        
        hold on;
        colors = lines(N_metrics);
        
        for m = 1:N_metrics
            metric_name = options.metrics{m};
            metric_values = param_data.metrics.(metric_name);
            baseline_val = results.baseline_metrics.(metric_name);
            
            % Normalize to baseline
            norm_values = metric_values / baseline_val * 100;
            
            plot(results.variation_factors * 100, norm_values, ...
                'LineWidth', 2, 'Color', colors(m,:), 'Marker', 'o', ...
                'DisplayName', metric_name);
        end
        
        plot([100, 100], ylim, 'k--', 'LineWidth', 1, 'HandleVisibility', 'off');
        xlabel('Parameter Value [% of baseline]');
        ylabel('Metric Value [% of baseline]');
        title(sprintf('%s\nSI: %.4f', results.param_names{p}, param_data.sensitivity_index));
        grid on;
        legend('Location', 'best');
    end
    
    sgtitle('Parameter Sensitivity Analysis', 'FontSize', 14, 'FontWeight', 'bold');
    
    % Sensitivity ranking bar chart
    figure('Name', 'Sensitivity Ranking', 'Position', [100, 100, 800, 600]);
    barh(results.ranked_sensitivity);
    set(gca, 'YTick', 1:N_params, 'YTickLabel', results.ranked_params);
    xlabel('Sensitivity Index');
    title('Parameter Sensitivity Ranking');
    grid on;
end
