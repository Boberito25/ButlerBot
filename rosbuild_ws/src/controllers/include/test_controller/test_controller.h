#ifndef TEST_CONTROLLER_H
#define TEST_CONTROLLER_H
#include "ros/ros.h"
#include "controller.h"
#include "controllers/TestService.h"
using namespace std;
class Test_Controller: public Controller
{
public:
  Test_Controller();
  const char *name() const {return "test_controller";};

  void run();
  void init();
  bool test(controllers::TestService::Request &req,
            controllers::TestService::Response &res); 
};
#endif
