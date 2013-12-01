#include "astar.h"
#include <Eigen/Dense>
#include <math.h>
#include <vector>
#include <map>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <functional>
#include "forward_kinematics.h"
#include <iomanip>
Astar::Astar(){target_threshold = .025;}

std::vector<configState*> Astar::run(configState* s, wsState* t){
  
  std::cout << "Initializing Start and Target\n";
  
  target = t;
  start = s;
  std::cout << "Target: ";
  wsstate_tostring(target);

  std::cout << "Initialize start data structures\n";

  /* Init */
  visData* startv = create_visdata();
  startv->current = start;
  startv->prev = 0;
  startv->value = heuristic(start);
  frontier.push(startv);
  visData* next = 0;
  wsState* wscurrent = fk(start);
  while(distance(target, wscurrent) > target_threshold){
   
    next = frontier.top();
    frontier.pop();
    delete(wscurrent);
    wscurrent = fk(next->current);

    // std::cout << "\n";
    // configstate_tostring(next->current);
    // std::cout << "Queue: "<< frontier.size() << '\n';
    // std::cout << "Visited Set: "<< visited_set.size() << '\n';

    // printf("Value: %f \n", next->value);
    // std::cout << "\n";
    if(next != 0){
      add_visited(next->current, next);
      expand_frontier(next->current);
    } else {
      std::vector<configState*> path;
      return path;
    }


  }
  std::cout << "Visited Set: "<< visited_set.size() << '\n';
  std::cout << "Queue: "<< frontier.size() << '\n';

  std::cout << "Completed Search\n";
  visData* current = next;

  std::vector<configState*> path;

  std::cout << "Backtracing path\n";
  while(current != 0){
    path.push_back(current->current);
    if(current -> prev == 0){
      current = 0;
      continue;
    }
    current = get_visdata(current->prev);
  }
  std::cout << "Back trace completed\n";
  return path; 
}

//Determines how close a configuration is to the target by measuring Euclidean
//  distance in the workspace
double Astar::heuristic(configState* c)
{
  wsState* state = fk(c);
  double d = distance(state,target);
  delete(state);
  return d;
}//end heurisitic

double Astar::cost(configState* c1,configState* c2)
{
  wsState* state1 = fk(c1);
  wsState* state2 = fk(c2);
  double workdist = distance(state1,state2);
  delete(state1);
  delete(state2);
  //TODO experiment with various angle penalties to determine the optimum path
  double anglepenalty = 1000*abs(c1->theta[4]-c2->theta[4]);

  return workdist+anglepenalty;
}

void Astar::expand_frontier(configState* c){
  if(c == 0){
    printf("not configed\n");
  }
  for(int i = 0; i < 4; i++){
    configState* pos = 0;
    configState* neg = 0;
    pos = clone_configstate(c);
    pos->theta[i] = c->theta[i]+1; 

    // printf("State %i: ",i);
    // configstate_tostring(pos);

    neg = clone_configstate(c);
    neg->theta[i] = c->theta[i]-1; 
    visData* cv = get_visdata(c);
    if(!has_visited(pos)){
      visData* posv;
      posv = create_visdata();
      posv->current = pos;
      posv->prev = c;      
      posv->value = heuristic(pos)+cost(c, pos)+cv->value;
      // std::cout << "Value: " <<std::setprecision(30) << posv->value << '\n';
      frontier.push(posv);

    } else {
      deallocate_configstate(pos);
    }

    if(!has_visited(neg)){
      visData* negv;
      negv = create_visdata();
      negv->current = neg;
      negv->prev = c;
      negv->value = heuristic(neg)+cost(c, neg)+cv->value;
      frontier.push(negv);
    } else {
      deallocate_configstate(neg);
    }
  }	
  // std::cout << '\n';
}

bool Astar::has_visited(configState* c){
  std::map<configState*,visData*,configcomp>::const_iterator it;
	it = visited_set.find(c);
  return it != visited_set.end(); 
}

void Astar::add_visited(configState* c, visData* v){
  visited_set.insert(std::pair<configState*, visData*>(c,v));
}

visData*  Astar::get_visdata(configState* c){
  return visited_set.at(c);
}
