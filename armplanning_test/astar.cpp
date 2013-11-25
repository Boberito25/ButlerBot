#include "astar.h"
#include <Eigen/Dense>
#include <math.h>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <functional>
#include "forward_kinematics.h"
Astar::Astar(){target_threshold = .01;}

std::vector<configState*> Astar::run(configState* s, wsState* t){
  target = t;
  start = s;

  /* Init */
  visData* startv;
  create_visdata(startv);
  startv->current = start;
  startv->prev = 0;
  startv->value = heuristic(start);
  frontier.push(startv);

  visData* next = frontier.top();
  frontier.pop();
  wsState* wscurrent = fk(next->current);
  while(distance(target, wscurrent) > target_threshold){
    if(next != 0){
      expand_frontier(next->current);
      add_visited(next->current, next);
    } else {
      std::vector<configState*> path;
      return path;
    }
    next = frontier.top();
    frontier.pop();
    wscurrent = fk(next->current);

  }
  visData* current = next;
  std::vector<configState*> path;
  while(current != 0){
    path.push_back(current->current);
    get_visdata(current->prev,current);
  }
  return path; 
}

//Determines how close a configuration is to the target by measuring Euclidean
//  distance in the workspace
double Astar::heuristic(configState* c)
{
  wsState* state = fk(c);
  double d = distance(state,target);
  return d;
}//end heurisitic

double Astar::cost(configState* c1,configState* c2)
{
  wsState* state1 = fk(c1);
  wsState* state2 = fk(c2);
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
      posv->value = heuristic(pos)+cost(c, pos);
      frontier.push(posv);
    } else {
      deallocate_configstate(pos);
    }

    if(!has_visited(neg)){
      visData* negv;
      create_visdata(negv);
      negv->current = neg;
      negv->prev = c;
      negv->value = heuristic(neg)+cost(c, neg);
      frontier.push(negv);
    } else {
      deallocate_configstate(neg);
    }
  }	
}

bool Astar::has_visited(configState* c){
  std::map<configState,visData*,configcomp>::const_iterator it;
	it = visited_set.find(*c);
  return it != visited_set.end(); 
}

void Astar::add_visited(configState* c, visData* v){
  visited_set.insert(std::pair<configState, visData*>(*c,v));
}

void  Astar::get_visdata(configState* c, visData* v){
  v = visited_set.at(*c);
}
