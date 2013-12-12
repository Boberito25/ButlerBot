#include "astar.cpp"
#include <Eigen/Dense>
#include "forward_kinematics.h"
#include <vector>
#include <stdio.h>
int main(int argc, char** argv )
{
  std::cout << "Start Program\n";
    
  Astar planner;

  int start[3] = {0,0,0};
  double x;
  double z;
  double alpha;

  fk(&x, &z, &alpha, 99,99,0);
  double target[3] = {x,z,alpha};
  printf("Target: %f, %f, %f\n", x, z, alpha);
  std::vector<State*> path = planner.run(start, target);
  int n = path.size();
  for(int i = 0; i < n; i++){
    State* s = path.at(i);
    x = s->x;
    z = s->z;
    alpha = s->alpha;

    printf("X: %f, Z: %f, Alpha: %f\n",x,z,alpha);
  }


  return 0;
}
