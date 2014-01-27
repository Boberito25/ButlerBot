#ifndef ARM_CONTROLLER_H
#define ARM_CONTROLLER_H
#include "ros/ros.h"
#include "controller.h"
#include "controllers/arm_controller.h"

using namespace std;
class Arm_Controller : public Controller
{
  const char *name() const {return "arm_controller";};

  void run();
  void init();
  bool armMove(controllers::Arm_Controller::Request &req,
  	           controllers::Arm_Controller::Response &res);
};
#endif