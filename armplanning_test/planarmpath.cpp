#include "astar.cpp"
#include <Eigen/Dense>
#include "forward_kinematics.h"
#include <vector>
#include <stdio.h>
int main(int argc, char** argv )
{
  std::cout << "Start Program\n";

  Astar planner;

  configState start;

  start.theta[0] = 0;
  start.theta[1] = 0;
  start.theta[2] = 0;
  start.theta[3] = 0;
  start.theta[4] = 0;

  configState target;

  target.theta[0] = 0;
  target.theta[1] = 12;
  target.theta[2] = 12;
  target.theta[3] = 0;
  target.theta[4] = 0;

  wsState* actarget = fk(&target);

  std::cout << "Start Running\n";
  clock_t startTime = clock();
  std::vector<configState*> path = planner.run(&start, actarget);
  float secsElapsed = (float)(clock() - startTime)/CLOCKS_PER_SEC;
  printf("Runtime %f\n",secsElapsed);
  for(int i = 0; i < path.size(); i++){
    configstate_tostring(path.at(i));
  }
  return 0;
}
