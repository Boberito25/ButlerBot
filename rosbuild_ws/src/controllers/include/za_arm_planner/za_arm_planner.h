#ifndef ZA_ARM_PLANNER_H
#define ZA_ARM_PLANNER_H
#include "ros/ros.h"
#include "controller.h"
#include "za_arm_planner/astar.h"
#include "za_arm_planner/forward_kinematics.h"
#include "controllers/ZAArmMove.h"
using namespace std;
class ZA_Arm_Planner: public Controller
{
public:
  ZA_Arm_Planner();
  const char *name() const {return "za_arm_planner";};

  void run();
  void init();
  bool move(controllers::ZAArmMove::Request &req,
  			controllers::ZAArmMove::Response &res);
};
#endif
