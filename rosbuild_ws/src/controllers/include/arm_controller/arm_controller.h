#ifndef ARM_CONTROLLER_H
#define ARM_CONTROLLER_H
#include "ros/ros.h"
#include "controller.h"
using namespace std;
class Arm_Controller : public Controller
{
  const char *name() const {return "arm_controller";};

  void run();
  void init();
}
#endif