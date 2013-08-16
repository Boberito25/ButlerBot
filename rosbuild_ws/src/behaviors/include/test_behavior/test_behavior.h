#ifndef TEST_BEHAVIOR_H
#define TEST_BEHAVIOR_H

#include "ros/ros.h"
#include "behavior.h"
#include "controllers/test_controller/TestService.h"

class Test_Behavior:public Behavior
{
public:
	const char *name() const {return "test_behavior";};

  Test_Behavior();
  void init();
  void run();
private:
  int counter;
  ros::ServiceClient tester;
	ros::Rate loop_rate(10);

  
};
