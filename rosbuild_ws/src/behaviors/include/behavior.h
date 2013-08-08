#ifndef BEHAVIOR_H
#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "ros/ros.h"
#include <string>
#include <vector>
#include "behaviors/Activate.msg"
#include "behaviors/Deactivate.msg"
#include <boost/thread.hpp>
using namespace std;

class Behavior
{
public:
  Behavior();
  virtual const char *name() const=0;
protected:
  

  ros::NodeHandle n; 
  ros::Subscriber activator;
  ros::Subscriber deactivator; 

  virtual void activator_callback(const BehaviorManager::Activate& msg);
  virtual void deactivator_callback(const BehaviorManager::Deactivate& msg);
  virtual void run(); 
private:
};

#endif
