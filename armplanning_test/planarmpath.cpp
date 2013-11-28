#include "astar.cpp"
#include <Eigen/Dense>
#include "forward_kinematics.h"
#include <vector>

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

  wsState target;
  target.x = 0;
  target.y = 0;
  target.z = 441;
  target.alpha = 0;
  target.theta = 0;
  target.phi = 0;

  std::cout << "Start Running\n";
  std::vector<configState*> path = planner.run(&start, &target);
  for(int i = 0; i < path.size(); i++){
    configstate_tostring(path.at(i));
  }
  return 0;
}
