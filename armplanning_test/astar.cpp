#include "astar.h"
#include <Eigen/Dense>
#include <math.h>
#include <vector>
#include <map>
#include <stdio.h>
#include <iostream>
#include <queue>
#include "forward_kinematics.h"
#include <iomanip>
#include <unordered_map>
#include <bitset>
#include <string>
#include <utility>

Astar::Astar(){
  target_threshold = .025;
  value_comp_time = 0;
  get_visdata_time = 0;
  frontier_insert_time = 0;
  mem_time = 0;
}

std::vector<configState*> Astar::run(configState* s, wsState* t){
  
  std::cout << "Initializing Start and Target\n";
  
  target = t;
  start = s;
  std::cout << "Target: ";
  wsstate_tostring(target);

  std::cout << "Initialize start data structures\n";


  /* Runtime checks */
  float avg_frontier_pop = 0;
  int pop_count = 0;


  float avg_vis_add = 0;
  int vis_add_count = 0;

  float avg_expansion = 0;
  int expansion_count = 0;

  /* Init */
  visData* startv = create_visdata();
  startv->current = start;
  startv->prev = 0;
  startv->value = heuristic(start);
  frontier.push(startv);
  visData* next = 0;
  wsState* wscurrent = fk(start);
  while(distance(target, wscurrent) > target_threshold){
    clock_t pqstart = clock();
    next = frontier.top();
    frontier.pop();
    float secsElapsed = (float)(clock() - pqstart)/CLOCKS_PER_SEC;
    avg_frontier_pop += secsElapsed;
    pop_count++;
    delete(wscurrent);
    wscurrent = fk(next->current);

   
    if(next != 0){
      clock_t visaddstart = clock();
      add_visited(next->current, next);
      secsElapsed= (float)(clock() - visaddstart)/CLOCKS_PER_SEC;
      avg_vis_add += secsElapsed;
      vis_add_count ++;

      clock_t expstart = clock();
      expand_frontier(next->current);
      secsElapsed = (float)(clock() - expstart)/CLOCKS_PER_SEC;
      avg_expansion += secsElapsed;
      expansion_count++;
    } else {
      std::vector<configState*> path;
      return path;
    }


  }

  


  std::cout << "Visited Set: "<< visited_set.size() << '\n';
  std::cout << "Queue: "<< frontier.size() << '\n';

  std::cout << "Completed Search\n";

  std::cout << "Runtimes: \n\n\n\n";
  std::cout << "Frontier Popping :" << avg_frontier_pop << '\n';
  std::cout << "Expansion: " << avg_expansion << '\n';
  std::cout << "  Vis Gets: " << get_visdata_time << '\n';
  std::cout << "  Value Comp Time: " << value_comp_time << '\n';
  std::cout << "  Frontier Push Time: " << frontier_insert_time << '\n';
  std::cout << "  Mem_Time: " << mem_time << '\n';
  std::cout << "  VisAdd :" << avg_vis_add*3 << '\n';
  std::cout << "Counts: " << pop_count << '\n';


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
  anglepenalty += 1000*abs(c1->theta[0] - c2->theta[0]);
  anglepenalty += 8*abs(c1->theta[1]-c2->theta[1]);
  anglepenalty += 4*abs(c1->theta[2]-c2->theta[2]);
  anglepenalty += 2*abs(c1->theta[3]-c2->theta[3]);
  return workdist+anglepenalty;
}

void Astar::expand_frontier(configState* c){
  if(c == 0){
    printf("not configed\n");
  }
  for(int i = 1; i < 4; i++){
    configState* pos = 0;
    configState* neg = 0;

    // clock_t memstart = clock();

    pos = clone_configstate(c);

    pos->theta[i] = c->theta[i]+1; 



    neg = clone_configstate(c);
    neg->theta[i] = c->theta[i]-1;

    // mem_time += (float)(clock() - memstart)/CLOCKS_PER_SEC;

    // clock_t getvisstart = clock(); 
    visData* cv = get_visdata(c);
    // get_visdata_time += (float)(clock() - getvisstart)/CLOCKS_PER_SEC;   
    if(!has_visited(pos)){
      visData* posv;
      // memstart = clock();

      posv = create_visdata();

      posv->current = pos;
      posv->prev = c;
      // mem_time += (float)(clock() - memstart)/CLOCKS_PER_SEC;
 
      clock_t getvaluestart = clock();     
      posv->value = heuristic(pos)+cost(c, pos)+cv->value;
      // std::cout << "Value: " <<std::setprecision(30) << posv->value << '\n';
      value_comp_time += (float)(clock() - getvaluestart)/CLOCKS_PER_SEC;
      // clock_t fpstart = clock();
      frontier.push(posv);
      // frontier_insert_time +=(float)(clock() - fpstart)/CLOCKS_PER_SEC;

    } else {
      // memstart = clock();
      deallocate_configstate(pos);
      // mem_time += (float)(clock() - memstart)/CLOCKS_PER_SEC;


    }

    if(!has_visited(neg)){
      visData* negv;
      // memstart = clock();

      negv = create_visdata();
      negv->current = neg;
      negv->prev = c;
      // mem_time += (float)(clock() - memstart)/CLOCKS_PER_SEC;
       clock_t getvaluestart = clock();     

      negv->value = heuristic(neg)+cost(c, neg)+cv->value;
       value_comp_time += (float)(clock() - getvaluestart)/CLOCKS_PER_SEC;
      // clock_t fpstart = clock();

      frontier.push(negv);
      // frontier_insert_time +=(float)(clock() - fpstart)/CLOCKS_PER_SEC;

    } else {
      // memstart = clock();
      deallocate_configstate(neg);
      // mem_time += (float)(clock() - memstart)/CLOCKS_PER_SEC;
      }    
    
  }	
  // std::cout << '\n';
}

bool Astar::has_visited(configState* c){
  bool found = true;
  try {
    visited_set.at(c);
  }
  catch(...) {
    found = false;
  }
  return found;
}

void Astar::add_visited(configState* c, visData* v){
  visited_set.insert(std::pair<configState*, visData*>(c,v));
}

visData*  Astar::get_visdata(configState* c){
  return visited_set.at(c);
}
