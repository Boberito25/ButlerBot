function [ newpath ] = JitterFilter( path, iters )
%JITTERFILTER Summary of this function goes here
%   Detailed explanation goes here
newpath = path;
for i = 0:iters-2
    newpath = nodemerge(newpath, 300,iters-i);
end


end

