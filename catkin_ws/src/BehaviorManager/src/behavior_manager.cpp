#include "ros/ros.h"
#include "Intelligence/Startup.h"
#include "Intelligence/RequestBehavior.h"
#include "BehaviorManager/Startup.h"
#include "BehaviorManager/Activate.h"
#include "BehaviorManager/Deactivate.h"
#include <boost/thread.hpp>
#include "behavior_queue.h"
#include "Behaviors/Completed.h"
#include "behavior_reserver.h"
//Intitialized
bool ready;
bool terminated;

//Node handle
ros::NodeHandle n;


//Publishers
ros::Publisher deactivator;
ros::Publisher activator;
ros::Publisher starter;

//Behavior queue
Behavior_Queue queue;

//Behavior reserve list
Behavior_Reserver reserver;

//Thread stuff
boost::mutex m;



//Behavior runner thing of science
void run_behavior_queue(){
  while(!ready){}
  while(!terminated){
    string next_behavior;
    string params;
    boost::unique_lock<boost::mutex> lock(m); 
    if(queue.next_behavior(&next_behavior, &params))
    {
      BehaviorManager::Activate msg;
      msg.behavior = next_behavior;
      msg.params = params;
      activator.publish(msg);	

    }
    lock.unlock();
    
  }
}

/* msg/srv handlers */

/* Response to the Intelligence's startup request */
bool intel_startup(Intelligence::Startup::Request &req,
		  Intelligence::Startup::Response &res)
{
    int num_behaviors = req.behaviors.size();

    for(int i = 0; i < num_behaviors; i++){

          BehaviorManager::Startup msg;
          msg.behavior = req.behaviors.at(i);
          starter.publish(msg);

      
    }
    
    res.ready = true;
    ready = true;
    return true;
}

bool behavior_request(Intelligence::RequestBehavior::Request &req,
                      Intelligence::RequestBehavior::Response &res)
{
  string behavior = req.behavior;
  string params = req.params;
  unsigned int priority = req.priority;
  vector<string> reserves = reserver.get(behavior);
  boost::unique_lock<boost::mutex> lock(m);
  queue.enqueue(behavior, params, reserves, priority);
  lock.unlock();  
  
  

  
  return true;
}

void completed_callback(const Behaviors::Completed& msg){
  string behavior = msg.behavior;
  int error = msg.error;
  if(error == 0){
    boost::unique_lock<boost::mutex> lock(m);
    queue.terminated(behavior);
    lock.unlock();
  }  
}

/* Main */
int main(int argc, char **argv)
{
  /* Initialize */
  terminated = false;
  ready = false;
  ros::init(argc, argv, "behavior_manager");
  
  /* Activate Publishers */
  deactivator = n.advertise<BehaviorManager::Deactivate>("behavior deactivator", 100);
  activator = n.advertise<BehaviorManager::Activate>("behavior activator", 100);
  starter = n.advertise<BehaviorManager::Startup>("behavior starter", 100);
  
  /* Setup Service Handlers */
  ros::ServiceServer startup_handler = n.advertiseService("startup behavior manager", intel_startup);

  /* Setup Subscribers */
  ros::Subscriber completed = n.subscribe("behavior deactivated", 100, completed_callback); 
  /* Start the queue */ 
  boost::thread queuer(run_behavior_queue);

  ROS_INFO("Behaviors Will be managed hopefully");
  ros::spin();

  return 0;
}  
