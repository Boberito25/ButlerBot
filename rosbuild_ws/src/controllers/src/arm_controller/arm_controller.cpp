#include "ros/ros.h"
#include "arm_controller/arm_controller.h"
#include "controllers/armMove.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <vector>
#include "arm_controller/arduino-serial-lib.h"

Arm_Controller::Arm_Controller() {}
void Arm_Controller::run()
{}

void Arm_Controller::init()
{}

char *formatMessage(int base, int shoulder, int shoulder1, int elbow, int elbow1, 
                    int wrist, int wrot, int grip);

bool Arm_Controller::armMove(controllers::armMove::Request &req,
          controllers::armMove::Response &res)
{
  //TODO Change generalize to array of angles for each join
  int fd;
  std::vector<float> base = req.base;
  std::vector<float> shoulder = req.shoulder;
  std::vector<float> elbow = req.elbow;
  std::vector<float> wrist = req.wrist;
  std::vector<float> wrot = req.wrot;
  std::vector<float> grip = req.grip;
  size_t s = base.size();
  int i;
  float* inarr = malloc(sizeof(float)*6);

  char *portname = (char*)malloc(sizeof(char) * 40);
  strcpy(portname, "/dev/ttyUSB0");
  ROS_INFO("copy success\n");
  fd = serialport_init(portname, 9600);
  ROS_INFO("open success!\n");
  char returnval[256];

  int *outarr;
  for (i = 0; i < s; i++) {
      inarr[0] = base[i];
      inarr[1] = shoulder[i];
      inarr[2] = elbow[i];
      inarr[3] = wrist[i];
      inarr[4] = wrot[i];
      inarr[5] = grip[i];
      outarr = rad2ticks(inarr);

  char* teststr = formatMessage(outarr[0], outarr[1], outarr[1], outarr[2], outarr[2], outarr[3], outarr[4], outarr[5]);
  //strcpy(teststr, "Start:35,55,55,42,42,66,12,100:End");
  ROS_INFO("copy success\n");
  serialport_write(fd, teststr);
  ROS_INFO("write success!\n");
  serialport_read_until(fd, returnval, ':', 256, 10000);
  ROS_INFO("read success!\n");
  ROS_INFO("%s\n", returnval);
}
  free(portname);
  res.success = true;
  return true;
}

int* Arm_Controller::rad2ticks(float* inarr) {
    int *outarr = malloc(sizeof(int) * 6);

    float base = inarr[0];
    float shoulder = inarr[1];
    float elbow = inarr[2];
    float wrist = inarr[3];
    float wrot = inarr[4];
    float grip = inarr[5];
    
    int minclamp = 200;
    int maxclamp = 900;

    base = base%(2*PI);
    shoulder = shoulder%(2*PI);
    elbow = elbow%(2*PI);
    wrist = wrist%(2*PI);
    wrot = wrot%(2*PI);
    grip = grip%(2*PI);

    outarr[0] = static_cast<int>(base*512/PI);
    outarr[1] = static_cast<int>(shoulder*512/PI);
    outarr[2] = static_cast<int>(elbow*512/PI);
    outarr[3] = static_cast<int>(wrist*512/PI);
    outarr[4] = static_cast<int>(wrot*512/PI);
    outarr[5] = static_cast<int>(grip*512/PI);

    if (outarr[0] < minclamp) outarr[0] = minclamp;
    if (outarr[0] > maxclamp) outarr[0] = maxclamp;
    if (outarr[1] < minclamp) outarr[1] = minclamp;
    if (outarr[1] > maxclamp) outarr[1] = maxclamp;
    if (outarr[2] < minclamp) outarr[2] = minclamp;
    if (outarr[2] > maxclamp) outarr[2] = maxclamp;
    if (outarr[3] < minclamp) outarr[3] = minclamp;
    if (outarr[3] > maxclamp) outarr[3] = maxclamp;
    if (outarr[4] < minclamp) outarr[4] = minclamp;
    if (outarr[4] > maxclamp) outarr[4] = maxclamp;
    if (outarr[5] < minclamp) outarr[5] = minclamp;
    if (outarr[5] > maxclamp) outarr[5] = maxclamp;

    return outarr;
}
    
char *formatMessage(int base, int shoulder, int shoulder1, int elbow, int elbow1, 
                    int wrist, int wrot, int grip) {
  char *teststr = (char *)malloc(sizeof(char) * 256);
  sprintf(teststr, "Start:%d,%d,%d,%d,%d,%d,%d,%d:End", base, shoulder, 
          shoulder1, elbow, elbow1, wrist, wrot, grip);
  return teststr;
} 

int main(int argc, char **argv) {
  ros::init(argc, argv, "arm_controller");
  Arm_Controller armC;
  ros::ServiceServer tester = armC.n.advertiseService("plan2ArmMove", &Arm_Controller::armMove, &armC);
  ros::spin();

  return 0;

}
