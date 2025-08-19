% Define the folder containing images
imageFolder = 'C:\Users\Z004F2SE\Pictures\Vibha\annualDay'; % Change this to your folder path

% Get all images in the folder
imageFiles = dir(fullfile(imageFolder, '*.jpg')); % Adjust for other formats if needed
numImages = length(imageFiles);

% Generate a random order for images
randomOrder = randperm(numImages);

% Create a VideoWriter object
outputVideo = VideoWriter('random_sequence_video', 'MPEG-4'); 
outputVideo.FrameRate = 2; % Set frame rate (adjust as needed)
open(outputVideo); % Open the video file

% Loop through images in a random order and write to video
for i = 1:numImages
    % Read image from randomly selected order
    img = imread(fullfile(imageFolder, imageFiles(randomOrder(i)).name));
    
    % Resize images if necessary (uncomment below)
    img = imresize(img, [1080, 1080]); 
    
    % Write the frame to video
    writeVideo(outputVideo, img);
end

% Close the video file
close(outputVideo);

disp('Randomized sequence video created successfully!');
