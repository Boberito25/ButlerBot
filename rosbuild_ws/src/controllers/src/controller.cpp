#include "controller.h"
#include "ros/ros.h"
#include <boost/thread.hpp>
Controller(){
  is_activated = false;
  boost::thread runner(run); 
}
