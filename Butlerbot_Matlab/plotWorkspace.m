function [ cloud ] = plotWorkspace( bounds,step )
%PLOTWORKSPACE Summary of this function goes here
%   Detailed explanation goes here
    cloud = [];
    for i1 = bounds(1,1):step:bounds(1,2)
        for i2 = bounds(2,1):step:bounds(2,2)
            for i3 = bounds(3,1):step:bounds(3,2)
                for i4 = bounds(4,1):step:bounds(4,2)
                    for i5 = bounds(5,1):step:bounds(5,2)
                        H_05 =butlerbotFK(i1,i2,i3,i4,i5);
                        origin = H_05*[0;0;0;1];
                        cloud = [cloud,origin];
                    end
                end
            end
        end
    end
end

