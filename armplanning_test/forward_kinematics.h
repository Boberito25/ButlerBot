#ifndef FORWARDKINEMATICS_H
#define FORWARDKINEMATICS_H
#include <Eigen/Dense>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <string>
#include <utility>
#include <tr1/functional>
using namespace Eigen;
/* Types */

typedef struct configState{
	int theta[5];
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
  {return lhs->value > rhs->value;}
};

/* Visited Set Structure */

struct configHash {
	std::size_t operator() (const configState* k) const
	{
		size_t t0 = std::tr1::hash<int>()(k->theta[0]);
		size_t t1 = std::tr1::hash<int>()(k->theta[1]);
		size_t t2 = std::tr1::hash<int>()(k->theta[2]);
		size_t t3 = std::tr1::hash<int>()(k->theta[3]);
		size_t t4 = std::tr1::hash<int>()(k->theta[4]);

		return t0 ^ (t1 << 1) ^ (t2 << 2) ^ (t3 << 3) ^ (t4 << 4);
	}
};

struct configEquals {
	bool operator() (const configState* lhs, const configState* rhs) const
	{
		return lhs->theta[0] == rhs->theta[0] && lhs->theta[1] == rhs->theta[1] &&
		lhs->theta[2] == rhs->theta[2] && lhs->theta[3] == rhs->theta[3] && 
		lhs->theta[4] == rhs->theta[4];
	}
};

/* Utils */

wsState* fk(configState* c);
double distance(wsState* s1, wsState* s2);
Eigen::Matrix4d DH(double alpha, double a, double d, double theta);
double tick_to_radians(int i);


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