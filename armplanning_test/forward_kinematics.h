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

struct visdatacomp {
  bool operator() (const visData& lhs, const visData& rhs) const
  {return lhs->value<rhs->value;}
};

struct configcomp {
	bool operator()(const configState& lhs, const configState& rhs) const
	{
		if(lhs->theta[1] != rhs->theta[1]){
			return lhs->theta[1] < rhs->theta[1];
		}
		if(lhs->theta[2] != rhs->theta[2]){
			return lhs->theta[2] < rhs->theta[2];
		}
		if(lhs->theta[3] != rhs->theta[3]){
			return lhs->theta[3] < rhs->theta[3];
		}
		if(lhs->theta[4] != rhs->theta[4]){
			return lhs->theta[4] < rhs->theta[4];
		}
		return lhs->theta[5] < rhs->theta[5];
	}
}

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