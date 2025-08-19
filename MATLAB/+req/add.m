function out = add(varargin)
out = 0;
for cnt = 1:length(varargin)
    out = out + varargin{cnt};
end