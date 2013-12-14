#include "forward_kinematics.h"
#include <iostream>
#include <stdio.h>
#include <Eigen/Dense>
#include <bitset>
#include <string>
#include <utility>
//perform the forward kinematics of the robot to figure out where you are
void fk (double* x, double* z, double* alpha, int i, int j, int k)
{
  double theta0 = tick_to_radians(0);
  double theta1 = tick_to_radians(i);
  double theta2 = tick_to_radians(j);
  double theta3 = tick_to_radians(k);
  double theta4 = tick_to_radians(0);

  double c0 = cos(theta0);
  double c1 = cos(theta1);
  double s1 = sin(theta1);
  double c12 = cos(theta1+theta2);
  double s12 = sin(theta1+theta2);
  double c123 = cos(theta1+theta2+theta3);
  double s123 = sin(theta1+theta2+theta3);


  *x = c0*(150*(c1+c12) + 116.525*s123);
  *z = 150*(s12+s1) - 116.525*c123 + 26.5;
  *alpha = theta1+theta2+theta3;

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
  return (M_PI/100)*(i-49);
}

