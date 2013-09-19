#include "ros/ros.h"
#include <cstdlib>
#include <string>
#include <vector>
#include "behavior_manager/Initialize.h"
#include "behavior_manager/RequestBehavior.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "intelligence");
  ros::NodeHandle n;
  

  /* Set up clients */
  ros::ServiceClient starter
   = n.serviceClient<behavior_manager::Initialize>("startup behavior manager");
  ros::ServiceClient test 
   = n.serviceClient<behavior_manager::RequestBehavior>("request behavior");

  std::string test_behavior = "test_behavior";
  behavior_manager::Initialize srv;
  ros::Rate loop_rate(10);
  srv.request.behaviors.push_back(test_behavior);
  if(starter.call(srv))
  { 
     if(srv.response.ready)
     {
  	for(int i = 0; i < 100000; i++)
  	{
  		behavior_manager::RequestBehavior srv1;
  		srv1.request.behavior = test_behavior;
  		srv1.request.params = "";
  		srv1.request.priority = 0;
  		if(test.call(srv1))
  			loop_rate.sleep(); 	

  	}

     }
  }
  else
  {
  	ROS_INFO("Failed to initialize behavior list");
  }
    
  /* Check startup */
  
  return 0;

}
