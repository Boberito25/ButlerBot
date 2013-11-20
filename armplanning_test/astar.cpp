#include "astar.h"
#include <Eigen/Dense>

//Initialzie target point
Astar (int x, int y, int z, int alpha, int theta, int phi)
{
  *target = malloc(sizeof(wsState));
  target->x = x;
  target->y = y;
  target->z = z;
  target->alpha = alpha;
  target->theta = theta;
  target->phi = phi;

}


Eigen::Matrix4f DH(alpha,a,d,theta)
{
  Matrix4f T;
  T << cos(theta),sin(theta)*cos(alpha),-sin(theta)*sin(alpha),a*cos(theta),
    sin(theta), cos(theta)*cos(alpha), -cos(theta)*sin(alpha),a*sin(theta),
    0,sin(alpha),cos(alpha),d,
    0,0,0,1;
  return T;
}

//perform the forward kinematics of the robot to figure out where you are
wsState* forward_kinematics (configState* c)
{
  Eigen::Matrix4f T_01;
  T_01 = DH(M_PI/2 , 0, 26.5, c.theta1);
  Eigen::Matrix4f T_12;
  T_12 = DH(0, 150, 0 , M_PI/2+c.theta2);
  Eigen::Matrix4f T_23;
  T_23 = DH(0, 150, 0, c.theta3);
  Eigen::Matrix4f T_34;
  T_34 = DH(-M_PI/2, 0, 0, M_PI/2+c.theta4);
  Eigen::Matrix4f T_45;
  T_34 = DH(0,0,116.525, c.theta5);
  Eigen::Matrix4f T_05 = T_01*T_12*T_23*T_34*T_45;

  wsState* outstate = malloc(sizeof(wsState));
  outstate->x = T_05(1,4);
  outstate->y = T_05(2,4);
  outstate->z = T_05(3,4);
  //TODO calculate angles based on rotation matrix

  return outstate;


}
