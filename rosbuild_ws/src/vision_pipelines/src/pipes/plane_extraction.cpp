#include "pipes/plane_segmentors.h"
#include <pcl/ModelCoefficients.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/extract_indices.h>

void remove_plane(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud, pcl::ModelCoefficients::Ptr coefficients, pcl::PointIndices::Ptr inliers)
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_f(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_plane (new pcl::PointCloud<pcl::PointXYZ>);
  // Create the segmentation object
  pcl::SACSegmentation<pcl::PointXYZ> seg;
  // Optional
  seg.setOptimizeCoefficients (true);
  // Mandatory
  seg.setModelType (pcl::SACMODEL_PLANE);
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setMaxIterations(1000);
  seg.setDistanceThreshold (0.01);

  int nr_points = (int)cloud->points.size();
  while(cloud->points.size() > .3 * nr_points) {
      seg.setInputCloud (cloud);
      seg.segment (*inliers, *coefficients);
      if (inliers->indices.size() == 0) {
          std::cout << "Could not estimate a planar model"<<std::endl;
          break;
      }
      
      //Extract planar inliers
      pcl::ExtractIndices<pcl::PointXYZ> extract;
      extract.setInputCloud(cloud);
      extract.setIndices(inliers);
      extract.setNegative(false);

      //get plane points
      extract.filter(*cloud_plane);
//      std::cout <<"PointCloud has "<<cloud_plane->points.size()<<" data points."<<std::endl;
      
      //remove planar inliers
      extract.setNegative(true);
      extract.filter(*cloud_f);
      *cloud = *cloud_f;
  }
  
}
