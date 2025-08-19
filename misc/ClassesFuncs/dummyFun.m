% add as many inputs as user pass
function varargout = dummyFun(varargin) %nargin
outputVar = 0;
for loopCnt = 1:length(varargin)
    outputVar = outputVar + varargin{loopCnt};
end
varargout{1} = nargin;
varargout{2} = outputVar;
end