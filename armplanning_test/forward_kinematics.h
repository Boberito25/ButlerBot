#ifndef FORWARDKINEMATICS_H
#define FORWARDKINEMATICS_H
#include <Eigen/Dense>

using namespace Eigen;

typedef struct configState{
	double theta[5];
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

struct visDatacomp {
  bool operator() (const visData& lhs, const visData& rhs) const
  {return lhs->value<rhs->value;}
};

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