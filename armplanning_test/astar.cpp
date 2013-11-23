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


