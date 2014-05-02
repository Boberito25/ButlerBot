#include "pipes/plane_segmentors.h"
#include <pcl/ModelCoefficients.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>

void plane_extraction(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud, pcl::ModelCoefficients::Ptr coefficients, pcl::PointIndices::Ptr inliers)
{
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
