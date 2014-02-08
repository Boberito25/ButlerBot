#ifndef BASIC_ARM_MOVE_BEHAVIOR_H
#define BASIC_ARM_MOVE_BEHAVIOR_H

#include "ros/ros.h"
#include "behavior.h"
#include "behaviors/LoadTarget.h"
#include <vector>

class Basic_Arm_Move_Behavior : public Behavior 
{
public:
	inline void init();
	void run();
	void load_target(const behaviors::LoadTarget& msg)

	ros::Subscriber target_loader;

private:
	void plan_path();
	void arm_move();

	std::vector<double> theta0_path;
	std::vector<double> theta1_path;
	std::vector<double> theta2_path;
	std::vector<double> theta3_path;
	std::vector<double> theta4_path;
	std::vector<double> theta5_path;

	double arm_pose[5];
	double target_x;
	double target_z;

	ros::ServiceClient xz_planner;
	ros::ServiceClient arm_driver;

}