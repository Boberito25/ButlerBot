#ifndef ASTAR_H
#define ASTAR_H

#include <Eigen/Dense>
#include <iostream>
#include <stdio.h>
#include <queue>          // std::priority_queue
#include <deque>         // std::vector
#include <functional>     // std::greater
#include "forward_kinematics.h"
class Astar {
public:
	Astar();
	std::vector<State*> run(int* start, double* target);
private:
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
	double numticks;
	double* target;
	void compute_fk(int i, int j, int k);
};
#endif
