#include "astar.cpp"
#include <Eigen/Dense>
#include "forward_kinematics.h"
#include <vector>
#include <stdio.h>
int main(int argc, char** argv )
{
  // std::cout << "Start Program\n";
    
  Astar planner;

  int start[3] = {49,49,49};
  double x;
  double z;
  double alpha;

  fk(&x, &z, &alpha, 99,99,0,planner.numticks);
  double target[3] = {x,z,alpha};
  // printf("Target: %f, %f, %f\n", x, z, alpha);
  std::vector<PState*> path = planner.run(start, target);
  int n = path.size();
  for(int i = 0; i < n; i++){
    PState* s = path.at(i);
    double t0 = 0;
    double t1 = tick_to_radians(s->state[0],planner.numticks);
    double t2 = tick_to_radians(s->state[1],planner.numticks);
    double t3 = tick_to_radians(s->state[2],planner.numticks);
    double t4 = 0;

    printf("%f %f %f %f %f\n", t0, t1,t2,t3,t4);
  }


  return 0;
}
