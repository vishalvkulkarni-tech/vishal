function color = getWinThemeColor()

    % Get Windows registry settings
    winSettings = winqueryreg('HKEY_CURRENT_USER', ...
        'Software\Microsoft\Windows\CurrentVersion\Themes\Personalize',...
        'SystemUsesLightTheme');
    
    if winSettings == 0
        color = [0.2 0.2 0.2]; % Dark theme
    else
        color = [0.94 0.94 0.94]; % Light theme
    end

end