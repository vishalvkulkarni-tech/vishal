clc
% Load Simulink logged data
% load('simout.mat'); % If you save variables in a MAT file

% Set up video writer
v = VideoWriter('simulink_runtime_video', 'MPEG-4');
v.FrameRate = 10;
open(v);
pulse_data = out.simout.pulse_data;
sine_data = out.simout.sine_data;
sum_data = out.simout.sum_data;
% Get simulation time steps
numFrames = length(pulse_data.Time);

% Loop through each time step and generate frames
for i = 1:numFrames
    frame = uint8(255 * ones(240, 320, 3)); % White background

    % Create text overlays for signal values
    text1 = sprintf('Pulse: %.2f', pulse_data.Data(i));
    text2 = sprintf('Sine: %.2f', sine_data.Data(i));
    text3 = sprintf('Sum: %.2f', sum_data.Data(i));

    % Insert text into frame
    frame = insertText(frame, [50, 50], text1, 'FontSize', 16, 'TextColor', 'black');
    frame = insertText(frame, [50, 100], text2, 'FontSize', 16, 'TextColor', 'black');
    frame = insertText(frame, [50, 150], text3, 'FontSize', 16, 'TextColor', 'black');

    % Write frame to video
    writeVideo(v, frame);
end

% Close video file
close(v);

% Display the generated video
implay('simulink_runtime_video.mp4');
