#include "pipes/organized_edge_detection.h"
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/point_types.h>
#include <pipes/edge_detector.h>
#include <pcl/PointIndices.h>

void edgeDetector(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud) {

  pcl::PointCloud<pcl::Normal>::Ptr normal;
  pcl::OrganizedEdgeFromNormals<pcl::PointXYZ, pcl::Normal, pcl::Label> edges;
  edges.setInputNormals (normal);
  edges.setInputCloud(cloud);
  edges.setDepthDisconThreshold(0.02);
  edges.setMaxSearchNeighbors(50);
  pcl::PointCloud<pcl::Label> label;
  std::vector <pcl::PointIndices> label_indices;
  pcl::PointIndices x;
  edges.compute(label, label_indices);
  
  pcl::PointCloud<pcl::PointXYZ>::Ptr occluding_edges (new pcl::PointCloud<pcl::PointXYZ>),
        occluded_edges (new pcl::PointCloud<pcl::PointXYZ>),
        boundary_edges (new pcl::PointCloud<pcl::PointXYZ>),
        high_curvature_edges (new pcl::PointCloud<pcl::PointXYZ>),
        rgb_edges (new pcl::PointCloud<pcl::PointXYZ>);

pcl::copyPointCloud (*cloud, label_indices[0].indices, *boundary_edges);
pcl::copyPointCloud (*cloud, label_indices[1].indices, *occluding_edges);
pcl::copyPointCloud (*cloud, label_indices[2].indices, *occluded_edges);
pcl::copyPointCloud (*cloud, label_indices[3].indices, *high_curvature_edges);
pcl::copyPointCloud (*cloud, label_indices[4].indices, *rgb_edges); 
  pcl::visualization::CloudViewer viewer ("Simple cloud viewer");
  viewer.showCloud(boundary_edges);
  while(!viewer.wasStopped()) {}
  viewer.showCloud(occluding_edges);
  while(!viewer.wasStopped()) {}
  viewer.showCloud(occluded_edges);
  while(!viewer.wasStopped()) {}
  viewer.showCloud(high_curvature_edges);
  while(!viewer.wasStopped()) {}
  viewer.showCloud(rgb_edges);
  while(!viewer.wasStopped()) {}

}
