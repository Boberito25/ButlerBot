function [] = plotPath(angles)
%plotPath(angles) plots the path of the robot arm moving through each of the given angles

figure;
last  = length(angles);
for i = 0:last-1
    displayArm(angles(last-i,1),angles(last-i,2),angles(last-i,3),angles(last-i,4),angles(last-i,5));
   axis([-500,500,-500,500,-500,500]);
   % m(i) = getframe();
   pause;
end

end
