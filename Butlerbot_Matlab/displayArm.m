function [ points,dists ] = displayArm( t1,t2,t3,t4,t5 )
%displayArm(t1,t2,t3,t4,t5) plots the robot arm with the input arm angles
%   Detailed explanation goes here

[T_05,TS] = ButlerBotFK(t1,t2,t3,t4,t5);
origin = [0;0;0;1];
points = zeros(4,6);
for i = 2:6
    points(:,i) = cellprod(TS(1:(i-1)))*origin;
end
points = points(1:3,:);
width = 5;
height = 5;
endofector = [0,width,width,width,-width,-width; 0,0,0,0,0,0; 0,0,height,0,0,height; 1,1,1,1,1,1];
endofectorBF = T_05*endofector;


washolding = ishold();


% plot3(points(1,:),points(2,:),points(3,:),'b*-','LineWidth',4,'MarkerSize',10,'MarkerEdgeColor','m');
% hold on;
% plot3(endofectorBF(1,:),endofectorBF(2,:),endofectorBF(3,:),'b*-','LineWidth',4);
plot(points(1,:),points(3,:),'b*-','LineWidth',4,'MarkerSize',10,'MarkerEdgeColor','m');
hold on;
plot(endofectorBF(1,:),endofectorBF(3,:),'b*-','LineWidth',4);
if ~washolding
    hold off
end

end

function [M] = cellprod(MS)
    M = MS{1};
    for j = 2: length(MS)
        M = M*MS{j};
    end
end

