#ifndef PLANE_SEGMENTORS_H
#define PLANE_SEGMENTORS_H
void segment_RANSAC_plane(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud,
						  pcl::ModelCoefficents:Ptr coefficients, 
						  pcl::PointIndices::Ptr inliers);
#endif