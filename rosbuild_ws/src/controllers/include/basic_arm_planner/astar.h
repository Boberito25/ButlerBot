#ifndef ASTAR_H
#define ASTAR_H

#include <iostream>
#include <stdio.h>
#include <queue>          // std::priority_queue
#include <deque>         // std::vector
#include <functional>     // std::greater
#include "basic_arm_planner/forward_kinematics.h"
class Astar {
public:
  Astar();
  std::vector<PState*> run(int* start, double* target);
  int numticks;

private:
  double obj_mass;
  double time_step;
  /* Space Matrix */
  State*** space;
  /* Frontier Set */
  typedef std::priority_queue
    <PState*,std::deque<PState*>,pstate_comp> statepq;

  void expand_frontier(int is,int js, int ks);

  double cost(State* s1, State* s2);

  double heuristic(State* s);
  bool inbounds(int i, int j, int k);
  statepq frontier;

  /* Constants */
  double dist_threshold;
  double angle_threshold;
  int* target1;
  int* target2;
  void compute_ik(double x,double y, double alpha,int* tUp,int* tDown);

  void compute_fk(int i, int j, int k);
  bool will_continue(State* current);
};
#endif
