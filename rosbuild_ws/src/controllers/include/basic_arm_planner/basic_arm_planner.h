#ifndef BASIC_ARM_PLANNER_H
#define BASIC_ARM_PLANNER_H
#include "ros/ros.h"
#include "controller.h"
#include "basic_arm_planner/astar.h"
#include "basic_arm_planner/forward_kinematics.h"
#include "controllers/BasicArmPlan.h"
using namespace std;
class Basic_Arm_Planner: public Controller
{
public:
  Basic_Arm_Planner();
  const char *name() const {return "basic_arm_planner";};

  void run();
  void init();
  bool move(controllers::BasicArmPlan::Request &req,
  			controllers::BasicArmPlan::Response &res);
};
#endif
