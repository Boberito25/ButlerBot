#include "test_behavior/test_behavior.h"
#include "behavior.h"
#include "ros/ros.h"
#include <string>
#include <vector>
#include "behaviors/Activate.h"
#include "behaviors/Deactivate.h"
#include "behaviors/Shutdown.h"
#include "behaviors/Startup.h"
#include "behaviors/Completed.h"
#include "controllers/TestService.h"
#include "controller_manager/RequestController.h"
#include "controller_manager/ReleaseController.h"
#include "behavior.h"
Test_Behavior::Test_Behavior()
{

}

void Test_Behavior::init()
{
    name = "test_behavior";
  tester = n.serviceClient<controllers::TestService>("test");
  counter = 0;	
}

void Test_Behavior::run()
{
  ros::Rate loop_rate(10);

	while(!shutdown){
    if(is_active){

    	//Acquire Access of controller
    	while(!request_controller("test_controller"))
    		loop_rate.sleep();
    	controllers::TestService srv;
    	srv.request.input = counter;
    	if(tester.call(srv))
    	{
    		counter =srv.response.output;
    	}

    	ROS_INFO("Counter: %d\n", counter);
    	release_controller("test_controller");
    	is_active = false;
    }
        loop_rate.sleep();
	}
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "test_behavior");
  Test_Behavior b;
  Behavior* s = &b;
  
  b.ignition =
    b.n.subscribe("behavior_starter", 100, &Behavior::startup_callback, s);
  b.activator = 
    b.n.subscribe("behavior_activator", 100, &Behavior::activator_callback, s);
  b.deactivator = 
    b.n.subscribe("behavior_deactivator", 100, &Behavior::deactivator_callback, s);
  b.shutdown_seq =
    b.n.subscribe("behavior_shutdown", 100, &Behavior::terminator_callback, s);
  b.notify_completion = 
    b.n.advertise<behaviors::Completed>("behavior_completecd",100);
  b.creq = 
    b.n.serviceClient<controller_manager::RequestController>("request_controller");
  b.crel = 
    b.n.advertise<controller_manager::ReleaseController>("controller_release",100);


  b.init();

  /* Rest of function calls */
  
  ros::spin();

  return 0;
}
