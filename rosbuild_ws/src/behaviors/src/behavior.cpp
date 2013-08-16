#include "behavior.h"
#include "ros/ros.h"
#include "behaviors/Activate.h"
#include "behaviors/Deactivate.h"
#include "behaviors/Shutdown.h"
#include "behaviors/Completed.h"
#include "controller_manager/ReleaseController.h"
#include "controller_manager/RequestController.h"
#include <boost/thread.hpp>

Behavior::Behavior(){
  ignition =
     n.subscribe("behavior starter, 100", startup_callback);
  activator = 
     n.subscribe("behavior activator", 100, activator_callback);
  deactivator = 
     n.subscribe("behavior deactivator", 100, deactivator_callback);
  shutdown_seq =
  	 n.subscribe("behavior shutdown", 100, terminator_callback);
  notify_completion = 
     n.advertise<behaviors::Completed>("behavior_completecd",100);
  creq = 
     n.serviceClient<controller_manager::RequestController>("request controller");
  crel = 
     n.advertise<controller_manager::ReleaseController>("controller release",100);

  shutdown = true;
  is_active = false;

}

void Behavior::startup_callback(const behaviors::Startup& msg)
{
  if(!shutdown)
    return;
  shutdown = false;
  boost::thread runner(run); 
}
void Behavior::activator_callback(const behaviors::Activate& msg)
{
	is_active = true;
}

void Behavior::deactivator_callback(const behaviors::Deactivate& msg)
{
	is_active = false;
}

void Behavior::terminator_callback(const behaviors::Shutdown& msg)
{
  is_active = false;
  shutdown = true;
}

void Behavior::completed()
{
   behaviors::Completed msg;
   msg.behavior = name;
   msg.error = 0;
   notify_completion.publish(msg);
}


bool Behavior::request_controller(string controller)
{
  controller_manager::RequestController srv;
  srv.request.controller = name;
  if(creq.call(srv))
  {
    return srv.response.granted;
  }
  return false;
}

void Behavior::release_controller(string controller)
{
  controller_manager::ReleaseController msg;
  msg.controller = name;
  crel.publish(msg);
}
