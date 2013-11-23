#include "astar.h"
#include <Eigen/Dense>
#include <math.h>
#include <vector>
void Astar::Astar(){

}

std::vector<configState*> Astar::run(configState* start, wsSate* target){
  this.target = target;
  this.start = start;

  /* Init */
  visData* startv;
  create_visdata(startv);
  startv->current = start;
  startv->prev = 0;
  startv->value = heuristic(start);
  frontier.push(startv);

  configState* next = 0;
  while(/* Some condition regarding the target */){
    next = frontier.pop();
    if(next != 0){
      expand_frontier(next->current);
      add_visited(next->current, next);
    }
  }
  configState* current = next;
  std::vector<configState*> path;
  while(path != 0){
    path.push_back(current);
    current = current->prev;
  }
  return path; 
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

void Astar::expand_frontier(configState* c){
  for(int i = 0; i < 5; i++){
    configState* pos = 0;
    configState* neg = 0;
    clone_configstate(c, pos);
    pos->theta[i] = c->theta[i]+1; //TODO change this to the actual increment
    clone_configstate(c, neg);
    neg->theta[i] = c->theta[i]-1; //TODO see above
    if(!has_visited(pos)){
      visData* posv;
      create_visdata(posv);
      posv->current = pos;
      posv->prev = c;
      posv->value = heurisitic(pos)+cost(c, pos);
      frontier.push(posv);
    } else {
      deallocate_configstate(pos);
    }

    if(!has_visited(neg)){
      visData* negv;
      create_visdata(negv);
      posv->current = neg;
      posv->prev = c;
      posv->value = heurisitic(neg)+cost(c, neg);
      frontier.push(negv);
    } else {
      deallocate_configstate(neg);
    }
  }	
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



