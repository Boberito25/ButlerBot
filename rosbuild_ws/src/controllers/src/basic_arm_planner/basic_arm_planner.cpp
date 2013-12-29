#include "basic_arm_planner.h"
#include "astar.h"
#include "forward_kinematics.h"
#include "ros/ros.h"
#include "controllers/BasicArmMove.h"
Basic_Arm_Planner::Basic_Arm_Planner(){}
Basic_Arm_Planner::run(){}
Basic_Arm_Planner::init(){}
bool Basic_Arm_Planner::move(
		  controllers::BasicArmMove::Request &req,
          controllers::BasicArmMove::Response &res){

}
int main(int argc, char **argv){
	ros::init(argc, argv, "basic_arm_planner");
	Basic_Arm_Planner();
	ros::spin();

}