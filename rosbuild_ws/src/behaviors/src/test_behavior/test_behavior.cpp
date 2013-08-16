#include "test_behavior/test_behavior.h"
#include "ros/ros.h"
Test_Behavior::Test_Behavior()
{
	isRunning = true;
	isActive = false;
}

void Test_Behavior::init()
{
	tester = n.serviceClient<controllers::TestService("test");
  counter = 0;	
	ros::spin();
}

void Test_Behavior::run()
{
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

    	ROS_INFO("Counter: %d", counter);
    	release_controller("test_controller");
    	is_active = false;
    }
    loop_rate.sleep();
	}
}

int main(int argc, char **argv)
{
	Test_Behavior b;
	ros::init(argc, argv, b.name);
	b.init();
  return 0;
}
