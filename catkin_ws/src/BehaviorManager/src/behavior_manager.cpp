#include "ros/ros.h"
#include "Intelligence/Startup.h"
#include "BehaviorManager/Startup.h"
#include <boost/thread.hpp>
#include "behavior_queue.h"
//Node handle
ros::NodeHandle n;

//Service Clients
ros::ServiceClient startup;


/* msg/srv handlers */
void runBehaviorQueue(){
}
bool intelStartup(Intelligence::Startup::Request &req,
		  Intelligence::Startup::Response &res)
{
    int num_behaviors = req.behaviors.size();

    for(int i = 0; i < num_behaviors; i++){

      BehaviorManager::Startup s;

      s.request.behavior = req.behaviors.at(i);

      if(startup.call(s)){
        //Check if behavior initialized
	if(!(res.ready)){
	  ROS_INFO("Behavior failed to start");
          continue;
        }


      } else {
	ROS_ERROR("Behavior start call failed");
      }
    }
    res.ready = true;
}

/* Main */
int main(int argc, char **argv)
{
  ros::init(argc, argv, "behavior_manager");
  startup = n.serviceClient<BehaviorManager::Startup>("start behaviors");

  ROS_INFO("Behaviors Will be managed hopefully");
  ros::spin();

  return 0;
}
