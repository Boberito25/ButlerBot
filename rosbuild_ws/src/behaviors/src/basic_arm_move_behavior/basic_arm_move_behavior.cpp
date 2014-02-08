#include "basic_arm_move_behavior/basic_arm_move_behavior.h"
#include "ros/ros.h"
#include "controller_manager/RequestController.h"
#include "controller_manager/ReleaseController.h"
#include "behavior.h"
#include "behaviors/Activate.h"
#include "behaviors/Deactivate.h"
#include "behaviors/Shutdown.h"
#include "behaviors/Startup.h"
#include "behaviors/Completed.h"
#include "behaviors/LoadTarget.h"
#include "controllers/BasicArmPlan.h"
#include "controllers/armMove.h"
#include <string>
#include <vector>

Basic_Arm_Move_Behavior::Basic_Arm_Move_Behavior(){}
void Basic_Arm_Move_Behavior::init()
{
	name = "basic_arm_move_behavior"
	xz_planner 
		= n.serviceCleint<controllers::BasicArmPlan>("Basic_Arm_Plan");
	arm_driver 
		= n.serviceCleint<controllers::armMove>("plan2ArmMove");


	arm_pose[0] = 0;
	arm_pose[1] = 0;
	arm_pose[2] = 0;
	arm_pose[3] = 0;
	arm_pose[4] = 0;
	target_x = 0;
	target_z = 0;


}
void Basic_Arm_Move_Behavior::run()
{
	while(!shutdown){
		if(is_active){

			//Request access to all controllers
			while(!request_controller("arm_controller"))
    			loop_rate.sleep();
    		while(!request_controller("basic_arm_planner"))
    			loo_rate.sleep();

    		//Get Current Pose


    		//Plan a Path
    		plan_path();

    		//Move arm if path plan exists
    		if(theta0_path.size() != 0){
    			arm_move();
    		}
		}		
	}
}

void Basic_Arm_Move_Behavior::arm_move()
{
	controllers::armMove srv;
	srv.request.base = theta0_path;
	srv.request.shoulder = theta1_path;
	srv.request.elbow = theta2_path;
	srv.request.wrist = theta3_path;
	srv.request.wrot = theta4_path;
	srv.request.grip = theta5_path;
	arm_driver.call(srv)

}

void Basic_Arm_Move_Behavior::plan_path()
{
	controllers::BasicArmPlan srv;
	srv.request.theta1 = arm_pose[1];
	srv.request.theta2 = arm_pose[2];
	srv.request.theta3 = arm_pose[3];
	srv.request.x = target_x;
	srv.request.z = target_z;
	srv.request.alpha = 0;

	if(xz_planner.call(srv))
	{
		theta1_path = srv.response.theta1s;
		theta2_path = srv.response.theta2s;
		theta3_path = srv.response.theta3s;
		//No Motion for other joints
		theta0_path.clear();
		theta4_path.clear();
		theta5_path.clear();

		theta0.path.resize(theta1_path.size(),0);
		theta4_path.resize(theta1_path.size(),0);
		theta5_path.resize(theta1_path.size(),0);

	}

void Basic_Arm_Move_Behavior::load_target(const behaviors::LoadTarget& msg)
{
	target_x = msg.x;
	target_z = msg.z;
}

int main(int argc, char** argv)
{
	ros::init("basic_arm_move_behavior");
	Basic_Arm_Move_Behavior b;
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


	b.target_loader
		= b.n.advertise<behaviors::ArmMoveTest>("test arm loader".100, 
			&Basic_Arm_Move_Behavior::load_target, b);
	b.init();
	ros::spin();

	return 0;

}

