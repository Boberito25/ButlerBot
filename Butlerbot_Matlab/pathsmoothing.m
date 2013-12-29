function [ sp ] = pathsmoothing( path, f)
%PATHSMOOTHING Summary of this function goes here
%   Detailed explanation goes here
[n,~] = size(path);
np = path(f:n,:);
gaussFilter = gausswin(f);
gaussFilter = gaussFilter / sum(gaussFilter); % Normalize.
sp = np;

sp(:,2) = conv(np(:,2), gaussFilter, 'same');
sp(:,3) = conv(np(:,3), gaussFilter, 'same');
sp(:,4) = conv(np(:,4), gaussFilter, 'same');

sp = [path(1:5, :) ; sp];
end

