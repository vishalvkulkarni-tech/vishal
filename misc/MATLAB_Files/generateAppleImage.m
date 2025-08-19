
function generateAppleImage()
    % Create a figure
    figure;
    hold on;

    % Draw the apple body
    theta = linspace(0, 2*pi, 100);
    x = 1 * cos(theta); % x-coordinates
    y = 1.2 * sin(theta) - 0.2; % y-coordinates to create an apple shape
    fill(x, y, 'r'); % Fill the apple shape with red color

    % Draw the apple leaf
    leafX = [-0.2, 0, 0.2]; % x-coordinates for the leaf
    leafY = [0.2, 0.5, 0.2]; % y-coordinates for the leaf
    fill(leafX, leafY, 'g'); % Fill the leaf with green color

    % Set axis properties
    axis equal;
    axis off; % Turn off the axis
    title('Apple Image');

    hold off;
end