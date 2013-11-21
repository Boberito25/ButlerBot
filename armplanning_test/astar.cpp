#include "astar.h"
#include <Eigen/Dense>
#include <math.h>
void Astar::Astar(){

}
void Astar::run(configState* start, wsSate* target){

}
double Astar::heuristic(configState* c){
	return 0;
}

double Astar::cost(configState* c1, configState* c2){
	return 0;
}

void Astar::expand_frontier(configState* c){
	
}

bool Astar::has_visited(configState* c){
	return true;
}

void Astar::add_visited(configState* c){

}

void  Astar::get_visdata(configState* c, visData* v){

}

void Astar::create_wsstate(wsSate* w){

}

void Astar::create_configstate(configState* c){

}

void Astar::create_visdata(visData* v){

}

void Astar::deallocate_wsstate(wsState* w){

}
void Astar::deallocate_configstate(configState* c){

}
void Astar::deallocate_visdata(visData* v){

}




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
}


Eigen::Matrix4d DH(double alpha,double a,double d,double theta)
{
  Eigen::Matrix4d T;
  T << cos(theta),sin(theta)*cos(alpha),-sin(theta)*sin(alpha),a*cos(theta),
    sin(theta), cos(theta)*cos(alpha), -cos(theta)*sin(alpha),a*sin(theta),
    0,sin(alpha),cos(alpha),d,
    0,0,0,1;
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

  wsState* outstate = new wsState;
  outstate->x = T_05(0,3);
  outstate->y = T_05(1,3);
  outstate->z = T_05(2,3);
  //TODO calculate angles based on rotation matrix

  return outstate;
}//end forward_kinematics

//calculate Euclidean ndistance between two states
double distance(Astar::wsState* s1,Astar::wsState* s2)
{
  return sqrt(pow(s1->x - s2->x,2)+pow(s1->y-s2->y,2)+pow(s1->z-s2->z,2));
}

//Determines how close a configuration is to the target by measuring Euclidean
//  distance in the workspace
double Astar::heuristic(configState* c)
{
  wsState* state = forward_kinematics(c);
  double d = distance(state,target);
  return d;
}//end heurisitic

double Astar::cost(configState* c1,configState* c2)
{
  wsState* state1 = forward_kinematics(c1);
  wsState* state2 = forward_kinematics(c2);
  double workdist = distance(state1,state2);

  //TODO experiment with various angle penalties to determine the optimum path
  double anglepenalty = 0;

  return workdist+anglepenalty;
}


