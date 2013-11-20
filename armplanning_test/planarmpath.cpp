#include "astar.cpp"
#include <Eigen/Dense>

int main(int argc, char** argv )
{
  std::cout << "Start Program\n";
  Astar* test;
  test  =  new Astar(10,10,10,0,0,0);
  std::cout << "Made Astar object\n";
  Astar::configState* testState = new Astar::configState;
  testState->theta1 = 0;
  testState->theta2 = 0;
  testState->theta3 = 0;
  testState->theta4 = M_PI;
  testState->theta5 = 0;
  std::cout << "Made test State for FK\n";

  Astar::wsState* output = test->Astar::forward_kinematics(testState);
  std::cout << "Ran FK and got output of: ";
  std::cout << "(" << output->x << "," << output->y << "," << output->z<<"\n";
  return 0;
}
