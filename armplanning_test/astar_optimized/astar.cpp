#include "astar.h"
#include <queue>
#include <deque>
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <math.h>
#include <stdio.h>
#include "forward_kinematics.h"
#define BASIC 0
#define NOALPHA 1
#define WRENCH 2
#define WRENCH_NOALPHA 3
#define WRENCH_RATIO 4
#define ENERGY_LINEAR 5
#define ENERGY_ANGULAR 6
#define ENERGY_KINETIC 7
#define TORQUE_RATE 8
#define TORQUE_KINETIC 9
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

std::vector<PState*> Astar::run(int* start, double* target,double targett0){
	// std::cout << "Running A*\n";
	// std::cout << "Initializing target\n";
    this->target = target;
    this -> t0 = radian_to_ticks(targett0,numticks);
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
#if COSTFUNCTION == NOALPHA
	return pow(s1->x - s2->x,2)+pow(s1->z - s2->z,2);
#elif COSTFUNCTION == WRENCH
	double dist = pow(s1->x - s2->x,2)+pow(s1->z - s2->z,2)
		+pow(s1->alpha - s2->alpha,2);
	double t1 = tick_to_radians(s2->id[0],numticks);
	double t2 = tick_to_radians(s2->id[1],numticks);
	double t3 = tick_to_radians(s2->id[2],numticks);
	double c1 = 150*cos(t1)*obj_mass;
	double c12 = 150*cos(t1+t2)*obj_mass;
	double s123 = 116.525*sin(t1+t2+t3)*obj_mass;

	double mag_torque = pow(c1+c12+s123,2)
		+pow(c12+s123, 2)+pow(s123, 2);
	return dist+mag_torque;
#elif COSTFUNCTION == WRENCH_NOALPHA
	double dist = pow(s1->x - s2->x,2)+pow(s1->z - s2->z,2);
	double t1 = tick_to_radians(s2->id[0],numticks);
	double t2 = tick_to_radians(s2->id[1],numticks);
	double t3 = tick_to_radians(s2->id[2],numticks);
	double c1 = 150*cos(t1)*obj_mass;
	double c12 = 150*cos(t1+t2)*obj_mass;
	double s123 = 116.525*sin(t1+t2+t3)*obj_mass;

	double mag_torque = pow(c1+c12+s123,2)
		+pow(c12+s123, 2)+pow(s123, 2);
	return dist+mag_torque;
#elif COSTFUNCTION == WRENCH_RATIO
	double dist = pow(s1->x - s2->x,2)+pow(s1->z - s2->z,2)
		+pow(s1->alpha - s2->alpha,2);
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
	return dist + (mag_torque2/mag_torque1);
#elif COSTFUNCTION == ENERGY_LINEAR
	double dist = pow(s1->x - s2->x,2)+pow(s1->z - s2->z,2)
		+pow(s1->alpha - s2->alpha,2);
	double s2t1 = tick_to_radians(s2->id[0],numticks);
	double s2t2 = tick_to_radians(s2->id[1],numticks);
	double s2t3 = tick_to_radians(s2->id[2],numticks);
	double s1t1 = tick_to_radians(s1->id[0],numticks);
	double s1t2 = tick_to_radians(s1->id[1],numticks);
	double s1t3 = tick_to_radians(s1->id[2],numticks);

	Eigen::Matrix<double,3,5> J = jacobian(0,s1->id[0],s1->id[1],s1->id[2],0,numticks);
	Eigen::Matrix<double,5,1> thetadot;
	thetadot << 0, ((s2t1-s1t1)/time_step), ((s2t2-s1t2)/time_step), ((s2t3-s1t3)/time_step),  0;
	Eigen::Vector3d vel = J*thetadot;
        return dist+ obj_mass*vel.squaredNorm();
#elif COSTFUNCTION == ENERGY_ANGULAR
    double dist = pow(s1->x - s2->x,2)+pow(s1->z - s2->z,2);

	double alphadist = dist + pow(s1->alpha - s2->alpha,2);
	double s2t1 = tick_to_radians(s2->id[0],numticks);
	double s2t2 = tick_to_radians(s2->id[1],numticks);
	double s2t3 = tick_to_radians(s2->id[2],numticks);
	double s1t1 = tick_to_radians(s1->id[0],numticks);
	double s1t2 = tick_to_radians(s1->id[1],numticks);
	double s1t3 = tick_to_radians(s1->id[2],numticks);

	double angular_vel = ((s2t1-s1t1)+(s2t2-s1t2)+(s2t3-s1t3))/time_step;
	return alphadist + obj_mass*dist*pow(angular_vel,2);

#elif COSTFUNCTION == ENERGY_KINETIC
	double dist = pow(s1->x - s2->x,2)+pow(s1->z - s2->z,2);

	double alphadist = dist + pow(s1->alpha - s2->alpha,2);
	double s2t1 = tick_to_radians(s2->id[0],numticks);
	double s2t2 = tick_to_radians(s2->id[1],numticks);
	double s2t3 = tick_to_radians(s2->id[2],numticks);
	double s1t1 = tick_to_radians(s1->id[0],numticks);
	double s1t2 = tick_to_radians(s1->id[1],numticks);
	double s1t3 = tick_to_radians(s1->id[2],numticks);

	double angular_vel = ((s2t1-s1t1)+(s2t2-s1t2)+(s2t3-s1t3))/time_step;
	Eigen::Matrix<double,3,5> J = jacobian(0,s1->id[0],s1->id[1],s1->id[2],0,numticks);
	Eigen::Matrix<double,5,1> thetadot;
	thetadot << 0, ((s2t1-s1t1)/time_step), ((s2t2-s1t2)/time_step), ((s2t3-s1t3)/time_step),  0;
	Eigen::Vector3d vel = J*thetadot;
    return alphadist+ obj_mass*vel.squaredNorm()+ obj_mass*dist*pow(angular_vel,2);
#elif COSTFUNCTION == TORQUE_RATE

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
	return abs(mag_torque2-mag_torque1)/time_step;
#elif COSTFUNCTION == TORQUE_KINETIC
	//Torque Rate
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

	//Kinetic

	Eigen::Matrix<double,3,5> J = jacobian(0,s1->id[0],s1->id[1],s1->id[2],0,numticks);
	Eigen::Matrix<double,5,1> thetadot;
	thetadot << 0, ((s2t1-s1t1)/time_step), ((s2t2-s1t2)/time_step), ((s2t3-s1t3)/time_step),  0;
	Eigen::Vector3d vel = J*thetadot;
	return abs(mag_torque2-mag_torque1)/time_step+obj_mass*vel.squaredNorm();

#else
	return pow(s1->x - s2->x,2)+pow(s1->z - s2->z,2)
		+pow(s1->alpha - s2->alpha,2);

#endif
}

double Astar::heuristic(State* s){
#if COSTFUNCTION == NOALPHA || COSTFUNCTION == WRENCH_NOALPHA
	return pow(s->x - target[0],2)+pow(s->z - target[1],2);
#elif COSTFUNCTION == TORQUE_RATE || COSTFUNCTION == TORQUE_KINETIC
	return 0;
#else
	return pow(s->x - target[0],2)+pow(s->z - target[1],2)
		+pow(s->alpha - target[2],2);
#endif
}

void Astar::compute_fk(int i, int j, int k){
	double x;
	double z;
	double alpha;
	fk(&x, &z, &alpha,t0, i, j, k,numticks);
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
#if COSTFUNCTION == NOALPHA || COSTFUNCTION == WRENCH_NOALPHA
	double dist = pow(current->x-target[0], 2) + pow(current->z-target[1], 2);
	return dist > dist_threshold;
#elif COSTFUNCTION == TORQUE_RATE || COSTFUNCTION == TORQUE_KINETIC
	double dist = pow(current->x-target[0], 2) + pow(current->z-target[1], 2);
	return dist > dist_threshold;
#else
	double dist = pow(current->x-target[0], 2) + pow(current->z-target[1], 2);
	double angle = current->alpha;
	return !(dist < dist_threshold && (fabs(angle-target[2]) < angle_threshold
		|| (fabs(angle+2*M_PI-target[2]) < angle_threshold)
		|| (fabs(angle-2*M_PI-target[2]) < angle_threshold )));
#endif

}
