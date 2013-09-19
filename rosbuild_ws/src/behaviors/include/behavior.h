#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "ros/ros.h"
#include <string>
#include <vector>
#include "behaviors/Activate.h"
#include "behaviors/Deactivate.h"
#include "behaviors/Shutdown.h"
#include "behaviors/Startup.h"
#include "behaviors/Completed.h"
#include "controller_manager/RequestController.h"
#include "controller_manager/ReleaseController.h"
#include <boost/thread.hpp>
using namespace std;


class Behavior
{

public:

  Behavior();
  virtual inline void init();
  string name;
  void run(); 
   //Externally Called
  void activator_callback(const behaviors::Activate& msg);
  void deactivator_callback(const behaviors::Deactivate& msg);
  void terminator_callback(const behaviors::Shutdown& msg);
  void startup_callback(const behaviors::Startup& msg);
  ros::NodeHandle n; 

  ros::Subscriber activator;
  ros::Subscriber deactivator;
  ros::Subscriber shutdown_seq; 
  ros::Subscriber ignition;

  ros::ServiceClient creq;

  ros::Publisher crel;
  ros::Publisher notify_completion;

  //Internally Called
  bool request_controller(string controller);
  void release_controller(string controller);
  void completed();


protected:

  boost::thread* runner;  


  bool is_active;
  bool shutdown;


};

#endif
