#ifndef TEST_BEHAVIOR_H
#define TEST_BEHAVIOR_H

#include "ros/ros.h"
#include "behavior.h"
#include "controllers/TestService.h"

class Test_Behavior : public Behavior
{
public:

  Test_Behavior();
  inline void init();
  void run();
private: 	
  int counter;
  ros::ServiceClient tester;
};
#endif