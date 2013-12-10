#include "astar.h"
#include <queue>
#include <deque>
#include <iostream>
#include <Eigen/Dense>
#include <math.h>
#include "forward_kinematics.h"
Astar::Astar(){
	space = new State**[100];
	for(int i = 0; i < 100; i++){
		space[i] = new State*[100];
		for(int j = 0; j < 100; j++){
			space[i][j] = new State[100];
			for(int k = 0; k < 100; k++){
				space[i][j][k].visited = false;
				space[i][j][k].heuristic = -1;
				space[i][j][k].value = -1;
			}
		}
	}

	dist_threshold = .5;
	numticks = 100;
}

std::vector<State*> Astar::run(int* start, double* target){
    this->target = target;

	compute_fk(start[0], start[1], start[2]);
	State* starts = &space[start[0]][start[1]][start[2]];
	starts->heuristic 
		= heuristic(&space[start[0]][start[1]][start[2]]);
	starts->prev[0] = -1;
	starts->prev[1] = -1;
	starts->prev[2] = -1;

	starts->value = starts->heuristic;

	PState* pstart = new PState;
	pstart->value = starts->value;
	pstart->state[0] = start[0];
	pstart->state[1] = start[1];
	pstart->state[2] = start[2];
	
	frontier.push(pstart);

	State* current = starts;
	while(current->heuristic > dist_threshold){
		/* Get the next priority */
		
		PState* pcur = frontier.top();
		frontier.pop();
		current = 
			&space[pcur->state[0]][pcur->state[1]][pcur->state[2]];
		current->visited = true;
		expand_frontier(pcur->state[0],pcur->state[1],pcur->state[2]);
		delete(pcur);
	}	
	std::vector<State*> path;
	State* back_tracker = current;;
	while(back_tracker != starts){
		path.push_back(back_tracker);
		int i0 = back_tracker->prev[0];
		int i1 = back_tracker->prev[1];
		int i2 = back_tracker->prev[2];
		back_tracker = &space[i0][i1][i2];
	}

	path.push_back(starts);
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

					if(!space[is+i][js+j][ks+k].visited)
						continue;
					/* Has the heuristic been calculated */	


					if(space[is+i][js+j][ks+k].heuristic < 0){
						compute_fk(is+i, js+j, ks+k);
						space[is+i][js+j][ks+k].heuristic
							= heuristic(&space[is+i][js+j][ks+k]);
					}
					double curcost =  space[i][j][k].value - 
						space[i][j][k].heuristic + 
						cost(&space[i][j][k], &space[is+i][js+j][ks+k]);

				    /* Check if new value is less than min value */

					if(space[is+i][js+j][ks+k].value < 0){
						space[is+i][js+j][ks+k].value = 
							space[is+i][js+j][ks+k].heuristic+curcost;
						space[is+i][js+j][ks+k].prev[0] = i;
		                space[is+i][js+j][ks+k].prev[1] = j;
		                space[is+i][js+j][ks+k].prev[2] = k;	
	
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
							space[is+i][js+j][ks+k].prev[0] = i;
		                	space[is+i][js+j][ks+k].prev[1] = j;
		                	space[is+i][js+j][ks+k].prev[2] = k;	
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
	return pow(s1->x - s2->x,2)+pow(s1->z - s2->z,2)
		+pow(s1->alpha - s2->alpha,2);
}

double Astar::heuristic(State* s){
	return pow(s->x - target[0],2)+pow(s->z - target[1],2)
		+pow(s->alpha - target[2],2);
}

void Astar::compute_fk(int i, int j, int k){
	double x;
	double z;
	double alpha;
	fk(&x, &z, &alpha, i, j, k);
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