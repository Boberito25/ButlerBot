function [ newpath ] = nodemerge( path, thresh, lookback )
%NODEMERGE Summary of this function goes here
%   Detailed explanation goes here
[n,~] = size(path);
i = lookback+1;
lastpt = n;
newpath = path;
while(i < lastpt)
    if(i < lookback)
        continue;
    end
    begin = newpath(i-lookback+1,:);
    last = newpath(i,:);
    
    [x1,y1,z1] = ButlerBotFKF(begin(1), begin(2), begin(3), begin(4), begin(5));
    [x2,y2,z2] = ButlerBotFKF(last(1), last(2), last(3), last(4), last(5));
    
    dist = (x2-x1)^2+(y2-y1)^2+(z2-z1)^2;
    
    if(dist < thresh)
        newpath = [newpath(1:i-lookback+1,:) ; newpath(i:lastpt, :)];
        [lastpt, ~] = size(newpath);
    end
    i = i+1;
end

end

