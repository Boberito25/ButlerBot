#include "ros/ros.h"
#include <Arduino.h>
#include <cstdlib>
#include <string>
#include <vector>

comm::comm() {
	
}

void comm::begin(int baud) {
	Serial.begin(baud);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "communcation");

}