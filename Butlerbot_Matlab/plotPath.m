function [m,distances] = plotPath(angles)
%plotPath(angles) plots the path of the robot arm moving through each of the given angles

figure;
last  = length(angles);
distances = cell(1,last);
for i = 0:last-1
   points = displayArm(angles(last-i,1),angles(last-i,2),angles(last-i,3),angles(last-i,4),angles(last-i,5));
%    axis([-300,300,-300,300,-500,500]);
axis([-500,500,-500,500]);
   grid on;
   m(i+1) = getframe();
   
   distances{i+1} = dist(points);
   
  % pause;
end

end
