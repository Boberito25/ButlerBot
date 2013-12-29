//port name: /dev/tty.usbserial-A602ZALM

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <iostream>

/* My Arduino is on /dev/ttyACM0 */
char *portname = (char *)malloc(sizeof(char) * 30);

char buf[256];
 
int main(int argc, char *argv[])
{
  std::cout << "Testing \n";

  std::strcpy(portname, "/dev/tty.usbserial-A602ZALM");
  int fd;
 
  /* Open the file descriptor in non-blocking mode */
  std::cout << "Testing \n";

  while ((fd = open(portname, O_RDWR | O_NOCTTY)) < 0) {
  	std::cout << "not open yet\n";
  }
  std::cout << "Testing \n";

  struct termios toptions;
  tcgetattr(fd, &toptions);
  std::cout << "Testing \n";
  cfsetispeed(&toptions, B9600);
  cfsetospeed(&toptions, B9600);

  toptions.c_cflag &= ~PARENB;
  toptions.c_cflag &= ~CSTOPB;
  toptions.c_cflag &= ~CSIZE;
  toptions.c_cflag |= CS8;
  /* Canonical mode */
  toptions.c_lflag |= ICANON;
  /* commit the serial port settings */
  tcsetattr(fd, TCSANOW, &toptions);

  /* Send byte to trigger Arduino to send string back */
  while(1) {
    write(fd, "0", 1);
    std::cout << "Hello!\n";
    /* Receive string from Arduino */
    int n = read(fd, buf, 64);
    /* insert terminating zero in the string */
    buf[n] = 0;
 
    std::cout << n << " bytes read, buffer contains: " << buf << "\n";
  }
}