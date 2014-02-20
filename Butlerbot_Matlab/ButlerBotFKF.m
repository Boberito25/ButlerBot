function [ x,y,z ] = ButlerBotFKF( t0, t1,t2,t3,t4 )
%BUTLERBOTFK Given arm angles t1,t2,t3,t4,t5 returns the matrix position
%of the endofector space to the base space.
%   Detailed explanation goes here
t1 = t1+pi/2;
t2 = t2+pi/2;
t3 = t3+pi/2;
x = cos(t0)*(150*cos(t1)+150*cos(t1+t2)+116.525*sin(t1+t2+t3));
y = sin(t0)*(150*cos(t1)+150*cos(t1+t2)+116.525*sin(t1+t2+t3));
z = 150*sin(t1)+150*sin(t1+t2)-116.525*cos(t1+t2+t3)+26.5;

end
