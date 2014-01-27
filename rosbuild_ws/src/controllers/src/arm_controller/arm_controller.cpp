#include "ros/ros.h"
#include "arm_controller/arm_controller.h"
#include "controllers/arm_controller.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "arduino-serial-lib.c"

void Arm_Controller::run()
{
}

void Arm_Controller::init()
{	
}

char *formatMessage(int base, int shoulder, int shoulder1, int elbow, int elbow1, 
                    int wrist, int wrot, int grip);

bool Arm_Controller::armMove(controllers::arm_controller::Request &req,
          controllers::arm_controller::Response &res)
{
  int fd;
  int base, shoulder, shoulder1, elbow, elbow1, wrist, wrot, grip;
  base = req.base;
  shoulder = req.shoulder;
  shoulder1=  req.shoulder1;
  elbow = req.elbow;
  elbow1 = req.elbow1;
  wrist = req.wrist;
  wrot = req.wrot;
  grip = req.grip;
  char *portname = malloc(sizeof(char) * 40);
  strcpy(portname, "/dev/tty.usbserial-A602ZALM");
  printf("copy success\n");
  fd = serialport_init(portname, 9600);
  printf("open success!\n");
  char returnval[256];
  char* teststr = formatMessage(base, shoulder, shoulder1, elbow, elbow1, wrist, wrot, grip);
  //strcpy(teststr, "Start:35,55,55,42,42,66,12,100:End");
  printf("copy success\n");
  serialport_write(fd, teststr);
  printf("write success!\n");
  serialport_read_until(fd, returnval, ':', 256, 10000);
  printf("read success!\n");
  printf("%s\n", returnval);
  free(portname);
  res.output = true;
  return true;
}

char *formatMessage(int base, int shoulder, int shoulder1, int elbow, int elbow1, 
                    int wrist, int wrot, int grip) {
  char *teststr = malloc(sizeof(char) * 256);
  sprintf(teststr, "Start:%d,%d,%d,%d,%d,%d,%d,%d:End", base, shoulder, 
          shoulder1, elbow, elbow1, wrist, wrot, grip);
  return teststr;
} 

int main(int argc, char **argv) {
  ros::init(argc, argv, "arm_controller");
  Arm_Controller armC;
  ros::ServiceServer tester = c.n.advertiseService("plan2ArmMove", &Arm_Controller::armMove, &armC);
  ros::spin();

  return 0;

}
