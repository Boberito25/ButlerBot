#include "basic_arm_planner/basic_arm_planner.h"
#include "basic_arm_planner/astar.h"
#include "basic_arm_planner/forward_kinematics.h"
#include "ros/ros.h"
#include "controllers/BasicArmPlan.h"
#include <vector>
Basic_Arm_Planner::Basic_Arm_Planner(){}
void Basic_Arm_Planner::run(){}
void Basic_Arm_Planner::init(){}
bool Basic_Arm_Planner::move(
		  controllers::BasicArmMove::Request &req,
          controllers::BasicArmMove::Response &res){
	Astar planner;
	int start[3] = {req.theta1, req.theta2, req.theta3};
	double target[3] = {req.x, req.z, req.alpha};
	vector<PState*> path = planner.run(start, target);
	
	//Construct paths
	int len = path.size();

	for(int i = 0; i < len; i++){
		res.theta1s.push_back(tick_to_radians(path.at(i)->state[0], planner.numticks));
		res.theta2s.push_back(tick_to_radians(path.at(i)->state[1], planner.numticks));
		res.theta3s.push_back(tick_to_radians(path.at(i)->state[2], planner.numticks));
	}

	delete &planner;

	return true;

}
int main(int argc, char **argv){
	ros::init(argc, argv, "basic_arm_planner");
	Basic_Arm_Planner c = Basic_Arm_Planner();
	ros::ServiceServer planner = c.n.advertiseService("Basic_Arm_Plan", &Basic_Arm_Planner::move, &c);
	ros::spin();
}