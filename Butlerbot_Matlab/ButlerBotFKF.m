function [ x,y,z ] = ButlerBotFKF( t0, t1,t2,t3,t4 )
%BUTLERBOTFK Given arm angles t1,t2,t3,t4,t5 returns the matrix position
%of the endofector space to the base space.
%   Detailed explanation goes here
t1 = t1+pi/2;
t3 = t3+pi/2;
x = 150*cos(t0)*cos(t1-t2)+150*cos(t0)*cos(t1)+116.525*(cos(t0)*cos(t1-t2)*sin(t3)+cos(t0)*sin(t1+t2)*cos(t3));
y = 150*sin(t0)*cos(t1-t2)+150*sin(t0)*cos(t1)+116.525*(sin(t0)*cos(t1-t2)*sin(t3)+sin(t0)*sin(t1+t2)*cos(t3));
z = 116.525*sin(t1+t2)*sin(t3)+116.525*cos(t1-t2)*cos(t3)+150*sin(t1+t2)+150*sin(t1)+26.5;

end
