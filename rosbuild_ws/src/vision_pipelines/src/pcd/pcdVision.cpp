#include <pcl/visualization/cloud_viewer.h>
#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
/*
class SimpleOpenNIViewer {
  public:
    SimpleOpenNIViewer () : viewer ("PCL OpenNI Viewer") {}
    
    void cloud_cb_ (const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud) {
      if (!viewer.wasStopped())
        viewer.showCloud(cloud);
    }
    void run () {
      boost::function<void (const pcl::PointCloud<pcl::PointXYZ>::ConstPtr&)> f = boost::bind (&SimpleOpenNIViewer::cloud_cb_, this, _1);
    
    interface -> registerCallback(f);
    interface -> start ();
    
    while (!viewer.wasStopped()) {
      boost::this_thread::sleep (boost::posix_time::seconds(1));
    }
    interface->stop();
    }
*/
int main(int argc, char **argv) {
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGB>);
  if (pcl::io::loadPCDFile<pcl::PointXYZRGB> (argv[1], *cloud) == -1) {
    PCL_ERROR ("Couldn't read file test1.pcd\n");
    return(-1);
  }
  pcl::visualization::CloudViewer viewer ("Simple cloud viewer");
  viewer.showCloud(cloud);
  while(!viewer.wasStopped()) {}

//  SimpleOpenNIViewer v;
//  v.run();
  return 0;
}
