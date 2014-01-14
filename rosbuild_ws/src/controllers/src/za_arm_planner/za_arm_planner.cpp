#include "za_arm_planner/za_arm_planner.h"
#include "za_arm_planner/astar.h"
#include "za_arm_planner/forward_kinematics.h"
#include "ros/ros.h"
#include "controllers/ZAArmMove.h"
#include <vector>
ZA_Arm_Planner::ZA_Arm_Planner(){}
void ZA_Arm_Planner::run(){}
void ZA_Arm_Planner::init(){}
bool ZA_Arm_Planner::move(
		  controllers::ZAArmMove::Request &req,
          controllers::ZAArmMove::Response &res){
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
	ros::init(argc, argv, "za_arm_planner");
	ZA_Arm_Planner c = ZA_Arm_Planner();
	ros::ServiceServer planner = c.n.advertiseService("ZA_Arm_Mover", &Basic_Arm_Planner::move, &c);
	ros::spin();
}