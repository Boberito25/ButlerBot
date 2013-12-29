#ifndef BASIC_ARM_PLANNER_H
#define BASIC_ARM_PLANNER_H
#include "ros/ros.h"
#include "controller.h"
#include "astar.h"
#include "forward_kinematics.h"
using namespace std;
class Basic_Arm_Planer: public Controller
{
public:
  Test_Controller();
  const char *name() const {return "basic_arm_planner";};

  void run();
  void init();
};
#endif
