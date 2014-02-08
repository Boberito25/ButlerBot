#ifndef ARM_CONTROLLER_H
#define ARM_CONTROLLER_H
#include "ros/ros.h"
#include "controller.h"
#include "controllers/armMove.h"

using namespace std;
class Arm_Controller : public Controller
{
public:
  Arm_Controller();
  const char *name() const {return "arm_controller";};

  void run();
  void init();
  bool armMove(controllers::armMove::Request &req,
  	           controllers::armMove::Response &res);
  int* rad2ticks(float* inarr);
};
#endif
