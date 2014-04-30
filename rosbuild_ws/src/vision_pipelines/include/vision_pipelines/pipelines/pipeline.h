#ifndef PIPELINE_H
#define PIPELINE_H

#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/common/time.h>
using namespace std;

class Pipeline
{
public:
	Pipeline::Pipeline();
	/* This is where point clouds will be gathered from openni_launch */
	virtual void callback(const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& msg);
	/* Vision Processing is expensive so we will only 
	   do it upon request from a behavior(or controller)*/
	virtual void process_request();
private:
	ros::NodeHandle n;

};

#endif 