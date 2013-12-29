#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "arduino-serial-lib.c"

int main () {
  int fd;
  char *portname = malloc(sizeof(char) * 40);
  strcpy(portname, "/dev/tty.usbserial-A602ZALM");
  printf("copy success\n");
  fd = serialport_init(portname, 9600);
  printf("open success!\n");
  char teststr[256];
  char returnval[256];
  strcpy(teststr, "Start:35,55,55,42,42,66,12,100:End");
  printf("copy success\n");
  serialport_write(fd, teststr);
  printf("write success!\n");
  serialport_read_until(fd, returnval, ':', 256, 10000);
  printf("read success!\n");
  printf("%s\n", returnval);
  free(portname);
}