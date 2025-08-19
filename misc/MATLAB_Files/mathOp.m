function [varargout] = mathOp(i1, i2)
varargout = {0,0,0,0}; % default output value
varargout{1} = i1 + i2;
varargout{2} = i1 - i2;
varargout{3} = i1 * i2;
varargout{4} = i1 / i2;