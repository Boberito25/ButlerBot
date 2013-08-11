#include "ros/ros.h"
#include "behavior_manager/Initialize.h"
#include "behavior_manager/RequestBehavior.h"
#include "behavior_manager/DeactivateBehavior.h"
#include "behaviors/Startup.h"
#include "behaviors/Activate.h"
#include "behaviors/Deactivate.h"
#include <boost/thread.hpp>
#include "behavior_queue.h"
#include "behaviors/Completed.h"
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
ros::Rate loop_rate(10);

bool deactivate_behavior(behavior_manager::DeactivateBehavior::Request &req,
                                  behavior_manager::DeactivateBehavior::Response &res)
{
   behaviors::Deactivate msg;
   msg.behavior = req.behavior;
   deactivator.publish(msg);
   res.error = 0;
   return true;
}
//Behavior runner thing of science
void run_behavior_queue(){
  while(!ready){}
  while(!terminated){
    string next_behavior;
    string params;
    boost::unique_lock<boost::mutex> lock(m); 
    if(queue.next_behavior(&next_behavior, &params))
    {
      behaviors::Activate msg;
      msg.behavior = next_behavior;
      msg.params = params;
      activator.publish(msg);	

    }
    lock.unlock();
    loop_rate.sleep();
    
  }
}

/* msg/srv handlers */

/* Response to the Intelligence's startup request */
bool intel_startup(behavior_manager::Initialize::Request &req, behavior_manager::Initialize::Response &res)
{
    int num_behaviors = req.behaviors.size();

    for(int i = 0; i < num_behaviors; i++){

          behaviors::Startup msg;
          msg.behavior = req.behaviors.at(i);
          starter.publish(msg);

      
    }
    
    res.ready = true;
    ready = true;
    return true;
}

bool behavior_request(behavior_manager::RequestBehavior::Request &req,
                      behavior_manager::RequestBehavior::Response &res)
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

void completed_callback(const behaviors::Completed& msg){
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
  deactivator = n.advertise<behaviors::Deactivate>("behavior deactivator", 100);
  activator = n.advertise<behaviors::Activate>("behavior activator", 100);
  starter = n.advertise<behaviors::Startup>("behavior starter", 100);
  
  /* Setup Service Handlers */
  //ros::ServiceServer startup_handler = n.advertiseService("startup behavior manager", intel_startup);

  /* Setup Subscribers */
  ros::Subscriber completed = n.subscribe("behavior deactivated", 100, completed_callback); 
  /* Start the queue */ 
  boost::thread queuer(run_behavior_queue);

  ROS_INFO("Behaviors Will be managed hopefully");
  ros::spin();

  return 0;
}  
