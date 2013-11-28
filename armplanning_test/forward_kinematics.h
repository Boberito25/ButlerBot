#ifndef FORWARDKINEMATICS_H
#define FORWARDKINEMATICS_H
#include <Eigen/Dense>
#include <vector>
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
	configState* current;
	double value;
	configState* prev;
} visData;

struct visdatacomp {
  bool operator() (const visData* lhs, const visData* rhs) const
  {return lhs->value<rhs->value;}
};

struct configcomp {
	bool operator()(const configState& lhs, const configState& rhs) const
	{
		if(lhs.theta[0] != rhs.theta[0]){
			return lhs.theta[0] < rhs.theta[0];
		}
		if(lhs.theta[1] != rhs.theta[1]){
			return lhs.theta[1] < rhs.theta[1];
		}
		if(lhs.theta[2] != rhs.theta[2]){
			return lhs.theta[2] < rhs.theta[2];
		}
		if(lhs.theta[3] != rhs.theta[3]){
			return lhs.theta[3] < rhs.theta[3];
		}
		return lhs.theta[4] < rhs.theta[4];
	}
};

wsState* fk(configState* c);
double distance(wsState* s1, wsState* s2);
Eigen::Matrix4d DH(double alpha, double a, double d, double theta);


/* Allocators */
configState* clone_configstate(configState* c)	;

wsState* create_wsstate();
configState* create_configstate();
visData* create_visdata();

/* Deallocators */
void deallocate_wsstate(wsState* w);
void deallocate_configstate(configState* c);
void deallocate_visdata(visData* v);

/* IO Conversions */
void wsstate_tostring(wsState* w);
void configstate_tostring(configState* c);
#endif