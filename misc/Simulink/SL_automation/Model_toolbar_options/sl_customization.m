function sl_customization(cm)
% Add a custom menu item to the Simulink Tools menu
disp('sl_customization executed.');
% cm.addCustomMenuFcn('Simulink:ToolsMenu', @getMyToolsMenuItems);
cm.addCustomMenuFcn('Simulink:SimulationMenu', @getMyToolsMenuItems);
end

function schemaFcns = getMyToolsMenuItems(~)
disp('getMyToolsMenuItems executed.');
schemaFcns = {@menu1, @menu2};
end

function schema = menu1(~)
disp('getCustomToolsMenuItem executed.');
schema = sl_container_schema;
schema.childrenFcns = {@subMenu1, @subMenu2};
schema.Label = 'Menu 1';
% schema.Callback = @menu1_callback;
% schema.AutoDisableWhen = 'Busy';
end

function schema = menu2(~)
schema = sl_action_schema;
schema.label = 'Menu 2';
schema.accelerator = 'Ctrl+Alt+L';
schema.userdata = 'menu2';
schema.callback = @menu2_callback;
end

function schema = subMenu1(~)
schema = sl_action_schema;
schema.label = 'Sub Menu 1';
schema.accelerator = 'Ctrl+Alt+U';
schema.userdata = 'submenu1';
schema.callback = @submenu1_callback;
end

function schema = subMenu2(~)
schema = sl_action_schema;
schema.label = 'Sub Menu 1';
schema.userdata = 'submenu2';
schema.callback = @submenu2_callback;
end

function menu2_callback(~)
msgbox('menu 2 selected')
end

function submenu1_callback(~)
msgbox('sub menu 1 selected')
end

function submenu2_callback(~)
msgbox('sub menu 2 selected')
end