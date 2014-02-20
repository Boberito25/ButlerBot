#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "arduino-serial-lib.c"

char *formatMessage(int base, int shoulder, int shoulder1, int elbow, int elbow1, 
                    int wrist, int wrot, int grip);

int main () {
  int fd;
  int base, shoulder, shoulder1, elbow, elbow1, wrist, wrot, grip;
  base = 500;
  shoulder = 500;
  shoulder1=  500;
  elbow = 400;
  elbow1 = 400;
  wrist = 700;
  wrot = 800;
  grip = 1000;
  char *portname = malloc(sizeof(char) * 40);
  strcpy(portname, "/dev/tty.usbserial-A602ZALM");
  printf("copy success\n");
  fd = serialport_init(portname, 9600);
  printf("open success!\n");
  char returnval[256];
  char* teststr = formatMessage(base, shoulder, shoulder1, elbow, elbow1, wrist, wrot, grip);
  strcpy(teststr, "Start:35,55,55,42,42,66,12,100:End");
  printf("copy success\n");
  serialport_write(fd, teststr);
  printf("write success!\n");
  serialport_read_until(fd, returnval, ':', 256, 10000);
  printf("read success!\n");
  printf("%s\n", returnval);
  free(portname);
}

char *formatMessage(int base, int shoulder, int shoulder1, int elbow, int elbow1, 
                    int wrist, int wrot, int grip) {
  char *teststr = malloc(sizeof(char) * 256);
  sprintf(teststr, "Start:%d,%d,%d,%d,%d,%d,%d,%d:End", base, shoulder, 
          shoulder1, elbow, elbow1, wrist, wrot, grip);
  return teststr;
}