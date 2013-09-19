#include "behavior.h"
#include "ros/ros.h"
#include "behavior.h"
#include "behaviors/Activate.h"
#include "behaviors/Deactivate.h"
#include "behaviors/Shutdown.h"
#include "behaviors/Completed.h"
#include "controller_manager/ReleaseController.h"
#include "controller_manager/RequestController.h"
#include <boost/thread.hpp>
#include <string>
Behavior::Behavior(){

  shutdown = true;
  is_active = false;

}

void Behavior::run(){}
void Behavior::init(){}

void Behavior::startup_callback(const behaviors::Startup& msg)
{
  if(!shutdown)
    return;
  if(!(msg.behavior.compare(name)))
    return;

  shutdown = false;
  runner = new boost::thread(boost::bind(&Behavior::run, this));


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
  
