#include "forward_kinematics.h"
#include <iostream>
#include <stdio.h>
#include <Eigen/Dense>
#include <bitset>
#include <string>
#include <utility>
//perform the forward kinematics of the robot to figure out where you are
void fk (double* x, double* z, double* alpha, int t0, int i, int j, int k, int numticks)
{
  double theta0 = tick_to_radians(t0,numticks);
  double theta1 = tick_to_radians(i,numticks)+M_PI/2;
  double theta2 = tick_to_radians(j,numticks)+M_PI/2;
  double theta3 = tick_to_radians(k,numticks)+M_PI/2;
  double theta4 = tick_to_radians(0,numticks);

  double c0 = cos(theta0);
  double c1 = cos(theta1);
  double s1 = sin(theta1);
  double c12 = cos(theta1+theta2);
  double s12 = sin(theta1+theta2);
  double c123 = cos(theta1+theta2+theta3);
  double s123 = sin(theta1+theta2+theta3);


  *x = c0*(150*(c1+c12) + 116.525*s123);
  *z = 150*(s12+s1) - 116.525*c123 + 26.5;

  *alpha = theta1-M_PI/2+theta2+theta3-M_PI/2;

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

Eigen::Matrix<double,3,5> jacobian(int t0, int t1,int t2,int t3, int t4,int numticks)
{
  Eigen::Matrix<double,3,5> J;
  double theta0 = tick_to_radians(t0,numticks);
  double theta1 = tick_to_radians(t1,numticks)+M_PI/2;
  double theta2 = tick_to_radians(t2,numticks)+M_PI/2;
  double theta3 = tick_to_radians(t3,numticks)+M_PI/2;
  double theta4 = tick_to_radians(t4,numticks);

  double c0 = cos(theta0);
  double s0 = sin(theta0);
  double c1 = 150*cos(theta1);
  double s1 = 150*sin(theta1);
  double c12 = 150*cos(theta1+theta2);
  double s12 = 150*sin(theta1+theta2);
  double c123 = 116.525*cos(theta1+theta2+theta3);
  double s123 = 116.525*sin(theta1+theta2+theta3);

  J << -s0*(c1+c12+s123) , c0*(-1*(s1+s12)+c123) , c0*(-1*s12+c123) , c0*c123 , 0,
       -c0*(c1+c12+s123) , s0*(-1*(s1+s12)+c123) , s0*(-1*s12+c123) , s0*c123 , 0,
       0                 , c1+c12+s123           , c12+s123         , s123    , 0;

  return J;
}


double tick_to_radians(int i, int numticks){
  return (M_PI/numticks)*(i-(numticks/2 -1));
}

int radian_to_ticks(double t, int numticks){
  return numticks/M_PI*t + 49;
}

