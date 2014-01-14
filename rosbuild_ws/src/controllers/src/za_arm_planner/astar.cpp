#include "za_arm_planner/astar.h"
#include <queue>
#include <deque>
#include <iostream>
#include <math.h>
#include <cmath>
#include <stdio.h>
#include "za_arm_planner/forward_kinematics.h"

Astar::Astar(){
	dist_threshold = 30;
	int n_ticks = 100;
	numticks = n_ticks;
	n_ticks = numticks;
    time_step = .01;
    angle_threshold = .1;
	space = new State**[n_ticks];
	obj_mass = 1;
	for(int i = 0; i < n_ticks; i++){
		space[i] = new State*[n_ticks];
		for(int j = 0; j < n_ticks; j++){
			space[i][j] = new State[n_ticks];
			for(int k = 0; k < n_ticks; k++){
				space[i][j][k].visited = false;
				space[i][j][k].heuristic = -1;
				space[i][j][k].value = -1;
				space[i][j][k].id[0] = i;
				space[i][j][k].id[1] = j;
				space[i][j][k].id[2] = k;
			}
		}
	}

	
}

std::vector<PState*> Astar::run(int* start, double* target){
	// std::cout << "Running A*\n";
	// std::cout << "Initializing target\n";
    this->target = target;

    // std::cout << "Initialize Start\n";
	compute_fk(start[0], start[1], start[2]);
	State* starts = &space[start[0]][start[1]][start[2]];
	starts->heuristic 
		= heuristic(&space[start[0]][start[1]][start[2]]);
	starts->prev[0] = -1;
	starts->prev[1] = -1;
	starts->prev[2] = -1;

	starts->value = starts->heuristic;
	// std::cout << "Initialzing Priority Queue\n";
	PState* pstart = new PState;
	pstart->value = starts->value;
	pstart->state[0] = start[0];
	pstart->state[1] = start[1];
	pstart->state[2] = start[2];
	
	frontier.push(pstart);

	State* current = starts;
	PState* tracker = new PState;
	// std::cout << "Searching For Target\n";
	
	while(!frontier.empty() && will_continue(current)){
		/* Get the next priority */
		PState* pcur = frontier.top();
		frontier.pop();
		
		tracker->value = pcur->value;
		tracker->state[0] = pcur->state[0];
		tracker->state[1] = pcur->state[1];
		tracker->state[2] = pcur->state[2];
		current = 
			&space[pcur->state[0]][pcur->state[1]][pcur->state[2]];
		
		if(current->visited == false){
			current->visited = true;
			expand_frontier(pcur->state[0],pcur->state[1],pcur->state[2]);
		}
		delete(pcur);
	}
	
	// std::cout << "Search Completed\n";
	std::vector<PState*> path;
	State* back_tracker = current;;
	path.push_back(tracker);
	// std::cout <<"Compiling Path\n";
	while(back_tracker != starts){
		int i0 = back_tracker->prev[0];
		int i1 = back_tracker->prev[1];
		int i2 = back_tracker->prev[2];
		PState* next = new PState;
		next->value = back_tracker->value;
		next->state[0] = i0;
		next->state[1] = i1;
		next->state[2] = i2;
		back_tracker = &space[i0][i1][i2];
		path.push_back(next);
	}

	return path;


}

void Astar::expand_frontier(int is, int js, int ks){
	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			for(int k = -1; k <= 1; k++){
				if(i == 0 && j == 0 && k == 0){
					continue;
				}

				if(inbounds(is+i, js+j, ks+k)){
					/* Check if visited */

					if(space[is+i][js+j][ks+k].visited){
						continue;
					}
					/* Has the heuristic been calculated */	

					if(space[is+i][js+j][ks+k].heuristic < 0){
						compute_fk(is+i, js+j, ks+k);
						space[is+i][js+j][ks+k].heuristic
							= heuristic(&space[is+i][js+j][ks+k]);
					}
					double curcost =  (space[is][js][ks].value - 
						space[is][js][ks].heuristic) + 
						cost(&space[is][js][ks], 
						&space[is+i][js+j][ks+k]);
						

				    /* Check if new value is less than min value */
					if(space[is+i][js+j][ks+k].value < 0){
						space[is+i][js+j][ks+k].value = 
							space[is+i][js+j][ks+k].heuristic+curcost;
						space[is+i][js+j][ks+k].prev[0] = is;
		                space[is+i][js+j][ks+k].prev[1] = js;
		                space[is+i][js+j][ks+k].prev[2] = ks;	
	
						PState* p = new PState;
						p->state[0] = is+i;
						p->state[1] = js+j;
						p->state[2] = ks+k;
						p->value = space[is+i][js+j][ks+k].value;
						frontier.push(p);
					} else {
						if(curcost + space[is+i][js+j][ks+k].heuristic 
							< space[is+i][js+j][ks+k].value){
							space[is+i][js+j][ks+k].value = 
								curcost+space[is+i][js+j][ks+k].heuristic;
							space[is+i][js+j][ks+k].prev[0] = is;
		                	space[is+i][js+j][ks+k].prev[1] = js;
		                	space[is+i][js+j][ks+k].prev[2] = ks;	
							PState* p = new PState;
							p->state[0] = is+i;
							p->state[1] = js+j;
							p->state[2] = ks+k;
							p->value = space[is+i][js+j][ks+k].value;
							frontier.push(p);
						} 
					}
				}
			}
		}
	}
}

double Astar::cost(State* s1, State* s2){


    
	double s2t1 = tick_to_radians(s2->id[0],numticks);
	double s2t2 = tick_to_radians(s2->id[1],numticks);
	double s2t3 = tick_to_radians(s2->id[2],numticks);
	double s2c1 = 150*cos(s2t1)*obj_mass;
	double s2c12 = 150*cos(s2t1+s2t2)*obj_mass; 
	double s2s123 = 116.525*sin(s2t1+s2t2+s2t3)*obj_mass;

	double s1t1 = tick_to_radians(s1->id[0],numticks);
	double s1t2 = tick_to_radians(s1->id[1],numticks);
	double s1t3 = tick_to_radians(s1->id[2],numticks);
	double s1c1 = 150*cos(s1t1)*obj_mass;
	double s1c12 = 150*cos(s1t1+s1t2)*obj_mass; 
	double s1s123 = 116.525*sin(s1t1+s1t2+s1t3)*obj_mass;	

	double mag_torque2 = pow(s2c1+s2c12+s2s123,2)
		+pow(s2c12+s2s123, 2)+pow(s2s123, 2)+.0001;

	double mag_torque1 = pow(s1c1+s1c12+s1s123,2)
		+pow(s1c12+s1s123, 2)+pow(s1s123, 2)+.0001;
	return std::abs(mag_torque2-mag_torque1)/time_step;
}

double Astar::heuristic(State* s){
	return 0;
}

void Astar::compute_fk(int i, int j, int k){
	double x;
	double z;
	double alpha;
	fk(&x, &z, &alpha, i, j, k,numticks);
	space[i][j][k].x  = x;
	space[i][j][k].z = z;
	space[i][j][k].alpha = alpha;
}

bool Astar::inbounds(int i, int j, int k){
	if(i<numticks && j < numticks && k < numticks){
		if(i >= 0 && j >= 0 && k >= 0)
			return true;
	}
	return false;
}

bool Astar::will_continue(State* current){
	double dist = pow(current->x-target[0], 2) + pow(current->z-target[1], 2);
	return dist > dist_threshold;
}
