#include "plane_segmentor.h"


void segment_RANSAC_plane(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud,pcl::ModelCoefficents:Ptr coefficients, pcl::PointIndices::Ptr inliers)
{
  // Create the segmentation object
  pcl::SACSegmentation<pcl::PointXYZ> seg;
  // Optional
  seg.setOptimizeCoefficients (true);
  // Mandatory
  seg.setModelType (pcl::SACMODEL_PLANE);
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setDistanceThreshold (0.01);

  seg.setInputCloud (cloud);
  seg.segment (*inliers, *coefficients);
}