function T = FK(DH)
% DH has parameters in order of alpha, a, d, theta
alpha = DH(1);
a = DH(2);
d = DH(3);
theta = DH(4);
T = [cos(theta) sin(theta)*cos(alpha) -sin(theta)*sin(alpha) a*cos(theta);
     sin(theta) cos(theta)*cos(alpha) -cos(theta)*sin(alpha) a*sin(theta);
     0 sin(alpha) cos(alpha) d;
     0 0 0 1];

end