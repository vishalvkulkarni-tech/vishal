function [varargout] = func1(in1, varargin)
addition = 0;
for counter = 1:size(varargin, 2)
    addition = addition + varargin{1, counter};
end
varargout{1,1} = in1;
if in1 > 5
    varargout{1, 2} = addition;
end