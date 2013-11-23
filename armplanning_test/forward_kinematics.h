#ifndef FORWARDKINEMATICS_H
#define FORWARDKINEMATICS_H
#include <Eigen/Dense>


  typedef struct configState{
    double theta1;
    double theta2;
    double theta3;
    double theta4;
    double theta5;
  } configState;

  typedef struct wsState{
    double x;
    double y;
    double z;
    double alpha;
    double theta;
    double phi;
  } wsState;

  typedef struct visData{
    configStatbe* current;
    double value;
    configState* prev;
  } visData;

wsState forward_kinematics(configState* c);
double distance(wsState* s1, wsSate* s2);



/* Allocators */
void clone_configstate(configState* c, configState* clone);

void create_wsstate(wsState* w);
void create_configstate(configState* c);
void create_visdata(visData* v);

/* Deallocators */
void deallocate_wsstate(wsState* w);
void deallocate_configstate(configState* c);
void deallocate_visdata(visData* v);
#endif