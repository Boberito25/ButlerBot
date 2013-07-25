#include "ros/ros.h"
#include <cstdlib>
#include "Intelligence/Startup.h"
#include "Intelligence/RequestBehavior.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "intelligence");
  ros::NodeHandle n;

  /* Set up clients */
  ros::ServiceClient startup 
       = n.serviceClient<Intelligence::Startup>("start behavior manager");
  ros::ServiceClient behavior_queue 
       = n.serviceClient<Intelligence::RequestBehavior>("queue behavior");
  
  /* Check startup */
  Intelligence::Startup s;
  s.request.behaviors.push_back("test_behavior");
  if (startup.call(s))
  {
    if(!(s.response.ready)){
      ROS_ERROR("Subprocess startup failed"); 
      return 1;
    }
  }
  else
  {
    ROS_ERROR("Failed to check for behavior manager startup");
    return 1;
  }
  return 0;

}
