#include <pcl/range_image/range_image.h>

void range(pcl::PointCloud<pcl::PointXYZ> pointCloud) {
  float angularResolution = (float) (1.0f*(M_PI/180.0f));
  float maxAngleWidth = (float) (360.0f * (M_PI/180.0f));
  float maxAngleHeight = (float) (180.0f * (M_PI/180.0f));
  Eigen::Affine3f sensorPose = (Eigen::Affine3f)Eigen::Translation3f(0.0f, 0.0f, 0.0f);
  pcl::RangeImage::CoordinateFrame coordinate_frame = pcl::RangeImage::CAMERA_FRAME;
  float noiseLevel = 0.00;
  float minRange = 0.0f;
  int borderSize = 1;

  pcl::RangeImage rangeImage;
  rangeImage.createFromPointCloud(pointCloud, angularResolution, maxAngleWidth, maxAngleHeight, sensorPose, coordination_frame, noiseLevel, minRange, borderSize);
}
