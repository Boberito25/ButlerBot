#include "astar.h"
#include <Eigen/Dense>

using namespace Eigen;

//Initialzie target point
Astar::Astar (int x, int y, int z, int alpha, int theta, int phi)
{
  target = new wsState;
  target->x = x;
  target->y = y;
  target->z = z;
  target->alpha = alpha;
  target->theta = theta;
  target->phi = phi;
  std::cout << "In Astar Constructor with parameters:";
  std::cout << x <<","<< y<<","<<z<<","<<alpha<<","<<theta<<","<<phi<<"\n";
}


Eigen::Matrix4d DH(double alpha,double a,double d,double theta)
{
  std::cout << "In DH with params: "<<alpha<<","<<a<<","<<d<<","<<theta<<"\n";
  Eigen::Matrix4d T;
  T << cos(theta),sin(theta)*cos(alpha),-sin(theta)*sin(alpha),a*cos(theta),
    sin(theta), cos(theta)*cos(alpha), -cos(theta)*sin(alpha),a*sin(theta),
    0,sin(alpha),cos(alpha),d,
    0,0,0,1;
  //  std::cout << "Made Matrix : \n"<<T<<"\n";
  return T;
}

//perform the forward kinematics of the robot to figure out where you are
Astar::wsState* Astar::forward_kinematics (configState* c)
{
  Eigen::Matrix4d T_01 = DH(M_PI/2 , 0, 26.5, c->theta1);
  Eigen::Matrix4d T_12 = DH(0, 150, 0 , M_PI/2+c->theta2);
  Eigen::Matrix4d T_23 = DH(0, 150, 0, c->theta3);
  Eigen::Matrix4d T_34 = DH(-M_PI/2, 0, 0, M_PI/2+c->theta4);
  Eigen::Matrix4d T_45 = DH(0,0,116.525, c->theta5);

  Eigen::Matrix4d T_05 = T_01*T_12*T_23*T_34*T_45;
  //  std::cout << "Transform Matrix is :\n"<<T_05<<"\n";
  wsState* outstate = new wsState;
  outstate->x = T_05(0,3);
  outstate->y = T_05(1,3);
  outstate->z = T_05(2,3);
  //TODO calculate angles based on rotation matrix

  return outstate;
}//end forward_kinematics
