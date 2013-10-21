function [ T_05 ] = ButlerBotFK( t1, t2,t3,t4,t5 )
%BUTLERBOTFK Summary of this function goes here
%   Detailed explanation goes here

DH = [pi/2 0 26.5 0; 0 150 0 pi/2; 0 150 0 0; -pi/2 0 0 -pi/2; 0 0 116.525 0];
DH(:,4) = DH(:,4)+[t1;t2;t3;t4;t5];

T_01 = FK(DH(1,:));
T_12 = FK(DH(2,:));
T_23 = FK(DH(3,:));
T_34 = FK(DH(4,:));
T_45 = FK(DH(5,:));

T_05 = T_01*T_12*T_23*T_34*T_45;
end

