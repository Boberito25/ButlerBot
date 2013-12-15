function [m,pathpts] = plotPath(angles,is3d)
%plotPath(angles) plots the path of the robot arm moving through each of the given angles

if nargin ==1
    is3d =false;
end

last  = length(angles);
pathpts = zeros(3,last);
%distances = cell(1,last);
figure;
for i = 0:last-1
    points = displayArm(angles(last-i,1),angles(last-i,2),angles(last-i,3),angles(last-i,4),angles(last-i,5),is3d);
    if is3d
        axis([-300,300,-300,300,-500,500]);
    else
        axis([-500,500,-500,500]);
    end
    grid on;
    
    pathpts(:,i+1) = points(:,length(points));
    hold on;
    if is3d
        plot3(pathpts(1,1:i+1),pathpts(2,1:i+1),pathpts(3,1:i+1),'c-');
    else
        plot(pathpts(1,1:i+1),pathpts(3,1:i+1),'c-');
    end
    hold off;
    
    %    distances{i+1} = dist(points);
    m(i+1) = getframe();
    % pause;
end

end
