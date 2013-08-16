#include "test_controller/test_controller.h"
#include "ros/ros.h"
#include "controllers/TestService.h"
Test_Controller::Test_Controller()
{}
void Test_Controller::run()
{
  ros::spin();
}
void Test_Controller::init()
{
   ros::ServiceServer tester = n.advertiseService("test", &Test_Controller::test, this); 

}

bool Test_Controller::test(controllers::TestService::Request &req,
          controllers::TestService::Response &res)
{
  int input = req.input;
  int output = input+1;
  res.output = output;
  return true;
}
int main(int argc, char **argv)
{
 ros::init(argc, argv, "test_controller");

  Test_Controller c;
  c.init();
  c.run();
  return 0;
}
