#ifndef PLANE_SEGMENTORS_H
#define PLANE_SEGMENTORS_H
#include <pcl/ModelCoefficients.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/io/pcd_io.h>

void segment_RANSAC_plane(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud,
						  pcl::ModelCoefficients::Ptr coefficients, 
						  pcl::PointIndices::Ptr inliers);
#endif