#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "ros/ros.h"
using namespace std;

class Controller
{
public:
  virtual const char *name() const = 0;
  ros::NodeHandle n; 
  Controller();
  virtual void init();
  virtual void run();
  protected:
  bool is_activated;
};
 
#endif
