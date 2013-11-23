#include "forward_kinematics.h"
#include <Eigen/Dense>
//perform the forward kinematics of the robot to figure out where you are
wsState* forward_kinematics (configState* c)
{
  Eigen::Matrix4d T_01 = DH(M_PI/2 , 0, 26.5, c->theta[1]);
  Eigen::Matrix4d T_12 = DH(0, 150, 0 , M_PI/2+c->theta[2]);
  Eigen::Matrix4d T_23 = DH(0, 150, 0, c->theta[3]);
  Eigen::Matrix4d T_34 = DH(-M_PI/2, 0, 0, M_PI/2+c->theta[4]);
  Eigen::Matrix4d T_45 = DH(0,0,116.525, c->theta[5]);

  Eigen::Matrix4d T_05 = T_01*T_12*T_23*T_34*T_45;

  wsState* outstate = new wsState;
  outstate->x = T_05(0,3);
  outstate->y = T_05(1,3);
  outstate->z = T_05(2,3);
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
  return sqrt(pow(s1->x - s2->x,2)+pow(s1->y-s2->y,2)+pow(s1->z-s2->z,2));
}

void clone_configstate(configState* c, configState* clone){
  if(clone == 0 || c == 0)
    return;
  clone = (configState*)malloc(sizeof(struct configState));
  clone->theta[1] = c->theta[1];
  clone->theta[2] = c->theta[2];
  clone->theta[3] = c->theta[3];
  clone->theta[4] = c->theta[4];
  clone->theta[5] = c->theta[5];
}

void create_wssate(wsState* w){
  w = (wsState*)malloc(sizeof(struct wsState));
}

void create_configstate(configState* c){
  c = (configState*)malloc(sizeof(struct configState));
}

void create_visdata(visData* v){
  v = (visData*)malloc(sizeof(struct visData));
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