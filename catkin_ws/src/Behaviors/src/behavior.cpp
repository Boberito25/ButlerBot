#include "behavior.h"
#include "ros/ros.h"
#include <boost/thread.hpp>
Behavior::Behavior(){
  activator = n.subscribe("behavior activator", 100, activator_callback);
  deactivator = n.subscribe("behavior deactivator", 100, deactivator_callback);
  boost::thread runner(run);
}
