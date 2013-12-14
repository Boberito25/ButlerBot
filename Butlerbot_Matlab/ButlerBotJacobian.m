function [ J ] = ButlerBotJacobian( t0,t1,t2,t3,t4 )
%ButlerBotJacobian returns the Jacobian of the arm

 J = [-sin(t0)*(150*cos(t1)+150*cos(t1+t2)+116.525*sin(t1+t2+t3)), cos(t0)*(-150*(sin(t1)+sin(t1+t2))+116.525*cos(t1+t2+t3)), cos(t0)*(-150*sin(t1+t2)+116.525*cos(t1+t2+t3)), 116.525*cos(t0)*cos(t1+t2+t3), 0;
       cos(t0)*(150*cos(t1)+150*cos(t1+t2)+116.525*sin(t1+t2+t3)), sin(t0)*(-150*(sin(t1)+sin(t1+t2))+116.525*cos(t1+t2+t3)), sin(t0)*(-150*sin(t1+t2)+116.525*cos(t1+t2+t3)), 116.525*sin(t0)*cos(t1+t2+t3), 0;
       0                                                         , 150*(cos(t1)+cos(t1+t2))+116.525*sin(t1+t2+t3)           , 150*cos(t1+t2)+116.525*sin(t1+t2+t3)           , 116.525*sin(t1+t2+t3)        ,0];
end

