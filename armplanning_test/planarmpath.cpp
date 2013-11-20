#include "astar.cpp"
#include <Eigen/Dense>

int main(int argc, char** argv )
{
  std::cout << "Start Program\n";
  Astar* test;
  test  =  new Astar(0,0,443,0,0,0);
  std::cout << "Made Astar object\n";
  Astar::configState* testState = new Astar::configState;
  testState->theta1 = 0;
  testState->theta2 = 0;
  testState->theta3 = 0;
  testState->theta4 = 0;
  testState->theta5 = 0;
  Astar::configState* testState2 = new Astar::configState;
  testState2->theta1 = 0;
  testState2->theta2 = 0;
  testState2->theta3 = 0;
  testState2->theta4 = M_PI/10;
  testState2->theta5 = 0;
  std::cout << "Made test States for FK\n";

  Astar::wsState* output = test->Astar::forward_kinematics(testState);
  std::cout << "Ran FK and got output of: ";
  std::cout << "(" << output->x << "," << output->y << "," << output->z<<")\n";

  double h1 = test->heuristic(testState);
  std::cout << "The first state is "<<h1 << " away from the target\n";
  double h2 = test->heuristic(testState2);
  std::cout << "The second state is "<<h2 << " away from the target\n";

  double cst  = test->cost(testState,testState2);
  std::cout << "The cost to move between these states is "<<cst<<"\n";
  return 0;
}
