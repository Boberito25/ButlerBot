#ifndef NAVIGATION_CONTROLLER_H
#define NAVIGATION_CONTROLLER_H
#include "ros/ros.h"
#include "controller.h"
using namespace std;
class Navigation_Controller : public Controller
{
  const char *name() const {return "navigation_controller";};

  void run();
  void init();
}
#endif