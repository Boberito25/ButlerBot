#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "ros/ros.h"
using namespace std;

class Controller
{
public:
  Controller();
  virtual void run();
  virtual const char *name() const=0;
protected:
  bool is_activated;
};
 
#endif
