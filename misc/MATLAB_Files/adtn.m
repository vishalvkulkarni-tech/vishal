function o1 = adtn(varargin)
% we will see here how to use variables arguments for ip & op
o1 = 0; % set the output argument first


for count1 = 1:nargin
    o1 = o1 + varargin{count1};
end
