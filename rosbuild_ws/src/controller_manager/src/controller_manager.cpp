#include "ros/ros.h"
#include <string>
#include <vector>
#include "controller_manager/RequestController.h"
#include "controller_manager/ReleaseController.h"
std::vector<std::string> active_list;
bool request_controller(controller_manager::RequestController::Request &req,
                        controller_manager::RequestController::Response &res)
{
  std::string controller = req.controller;
  int size = active_list.size();
  for(int i = 0; i < size; i++)
  {
    if(!controller.compare(active_list.at(i)))
    { 
      res.granted = false;
      return true;
    }
  }
  active_list.push_back(controller);
  res.granted = true;
  return true; 
}

void controller_release_callback(const controller_manager::ReleaseController& msg)
{
  std::string controller = msg.controller;
  int size = active_list.size();
  for(int i = 0; i < size; i++)
  {
    if(controller.compare(active_list.at(i)))
    {
      active_list.erase(active_list.begin()+i);
      break;
    }
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "controller_manager");
  ros::NodeHandle n;
  ros::Subscriber completed  = n.subscribe("controller_release", 100, 
                                          controller_release_callback);
  ros::ServiceServer requested = 
          n.advertiseService("request_controller", request_controller);
                                

  ROS_INFO("Controller will be managed hopefully");
  ros::spin();
  
}
