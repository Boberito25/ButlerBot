#include "forward_kinematics.h"
#include <iostream>
#include <stdio.h>
#include <Eigen/Dense>
#include <unordered_map>
#include <bitset>
#include <string>
#include <utility>
//perform the forward kinematics of the robot to figure out where you are
wsState* fk (configState* c)
{
  double theta0 = tick_to_radians(c->theta[0]);
  double theta1 = tick_to_radians(c->theta[1]);
  double theta2 = tick_to_radians(c->theta[2]);
  double theta3 = tick_to_radians(c->theta[3]);
  double theta4 = tick_to_radians(c->theta[4]);
  Eigen::Matrix4d T_01 = DH(M_PI/2 , 0, 26.5, theta0);
  Eigen::Matrix4d T_12 = DH(0, 150, 0 , M_PI/2+theta1);
  Eigen::Matrix4d T_23 = DH(0, 150, 0, theta2);
  Eigen::Matrix4d T_34 = DH(-M_PI/2, 0, 0, M_PI/2+theta3);
  Eigen::Matrix4d T_45 = DH(0,0,116.525, theta4);

  Eigen::Matrix4d T_05 = T_01*T_12*T_23*T_34*T_45;

  wsState* outstate = new wsState;
  outstate->x = T_05(0,3);
  outstate->y = T_05(1,3);
  outstate->z = T_05(2,3);
  outstate->alpha = tick_to_radians(c->theta[0]+c->theta[1]+
      c->theta[2]+c->theta[3]+c->theta[4]);
  //TODO calculate angles based on rotation matrix

  return outstate;

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


//calculate Euclidean ndistance between two states
double distance(wsState* s1,wsState* s2)
{
  return (pow(s1->x - s2->x,2)+pow(s1->y-s2->y,2)+pow(s1->z-s2->z,2)+pow(s1->alpha-s2->alpha,2));
}

configState* clone_configstate(configState* c){
 
  configState* clone = new configState;
  clone->theta[0] = c->theta[0];
  clone->theta[1] = c->theta[1];
  clone->theta[2] = c->theta[2];
  clone->theta[3] = c->theta[3];
  clone->theta[4] = c->theta[4];
  return clone;
} 

double tick_to_radians(int i){
  return (M_PI/100)*i;
}

wsState* create_wsstate(){
   return (wsState*)malloc(sizeof(struct wsState));
}

configState* create_configstate(){
  return (configState*)malloc(sizeof(struct configState));
}

visData* create_visdata(){
  return (visData*)malloc(sizeof(struct visData));
}

void deallocate_wsstate(wsState* w){
  if(w != 0)
    free(w);
}

void deallocate_configstate(configState* c){
  if(c != 0)
    free(c);
}

void deallocate_visdata(visData* v){
  if(v != 0)
    free(v);
}

void wsstate_tostring(wsState* w){
    printf("Work Space State: x:%f, y:%f, z:%f\n", 
      w->x, w->y, w->z);
}

void configstate_tostring(configState* c){
  printf("Theta1: %i, Theta2: %i, Theta3: %i, Theta4: %i, Theta5: %i\n"
      , c->theta[0], c->theta[1],c->theta[2], c->theta[3], c->theta[4]);
}
