% Step 1: Read the image
img = imread('example.jpg');

% Step 2: Convert image to grayscale
gray_img = rgb2gray(img);

% Step 3: Convert to string for searching
img_str = lower(string(gray_img)); % Convert to lower case for case insensitivity

% Step 4: Text to find
text_to_find = '30/12/2021';

% Step 5: Find the position of the text
idx_cell = strfind(img_str, text_to_find);

% Ensure idx_cell is not empty and contains numeric indices
if isempty(idx_cell) || ~iscell(idx_cell) || isempty(idx_cell{1})
    error('Text not found in the image.');
end

% Extract numeric indices from the cell array
idx = idx_cell{1}; % Access the numeric indices

% Extract position of the text
x_text = idx; % Column index of the first occurrence
y_text = 1;    % Row index (assuming text is in the first row)

% Step 6: Define the region size (adjust as needed)
region_width = length(text_to_find) * 10; % Estimate based on text length
region_height = 20;

% Step 7: Replace the identified region with a solid color (white in this case)
img(y_text:y_text+region_height-1, x_text:x_text+region_width-1, :) = 255; % Set RGB values to 255 (white)

% Step 8: Add updated text "30/12/2022" in the same location and font
img_with_updated_text = insertText(img, [x_text y_text], '30/12/2022', 'FontSize', 12, 'TextColor', 'black', 'BoxColor', 'white', 'BoxOpacity', 0.8);

% Step 9: Display the modified image
figure;
imshow(img_with_updated_text);
title('Image with Updated Text');
