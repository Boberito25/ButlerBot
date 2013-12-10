#include "forward_kinematics.h"
#include <iostream>
#include <stdio.h>
#include <Eigen/Dense>
#include <unordered_map>
#include <bitset>
#include <string>
#include <utility>
//perform the forward kinematics of the robot to figure out where you are
void* fk (double* x, double* z, double* alpha, int i, int j, int k)
{
  double theta0 = tick_to_radians(0);
  double theta1 = tick_to_radians(i);
  double theta2 = tick_to_radians(j);
  double theta3 = tick_to_radians(k);
  double theta4 = tick_to_radians(0);
  Eigen::Matrix4d T_01 = DH(M_PI/2 , 0, 26.5, theta0);
  Eigen::Matrix4d T_12 = DH(0, 150, 0 , M_PI/2+theta1);
  Eigen::Matrix4d T_23 = DH(0, 150, 0, theta2);
  Eigen::Matrix4d T_34 = DH(-M_PI/2, 0, 0, M_PI/2+theta3);
  Eigen::Matrix4d T_45 = DH(0,0,116.525, theta4);

  Eigen::Matrix4d T_05 = T_01*T_12*T_23*T_34*T_45;

  *x = T_05(0,3);
  *z = T_05(2,3);
  *alpha = tick_to_radians(0+i+j+k+0);
  //TODO calculate angles based on rotation matrix


}//end forward_kinematics

Eigen::Matrix4d DH(double alpha,double a,double d,double theta)
{
  Eigen::Matrix4d T;
  T << cos(theta),sin(theta)*cos(alpha),-sin(theta)*sin(alpha),a*cos(theta),
    sin(theta), cos(theta)*cos(alpha), -cos(theta)*sin(alpha),a*sin(theta),
    0,sin(alpha),cos(alpha),d,
    0,0,0,1;
  return T;
}

double tick_to_radians(int i){
  return (M_PI/100)*i;
}

