#ifndef FORWARDKINEMATICS_H
#define FORWARDKINEMATICS_H
#include <Eigen/Dense>
#include <vector>
#include <bitset>
#include <string>
#include <utility>
using namespace Eigen;
/* Types */
typedef struct State {
	int prev[3];
	double x;
	double z;
	double alpha;
	double heuristic;
	double value;
	bool visited;
	int id[3];
} State;
typedef struct PState {
	double value;
	int state[3];
} PState;

/* Comparators */
struct pstate_comp {
  bool operator() (const PState* lhs, const PState* rhs) const
  {return lhs->value > rhs->value;}
};
/* Utils */

void fk(double* x, double* z, double* alpha,
	int t0, int i, int j,int k, int numticks);
Eigen::Matrix4d DH(double alpha, double a, double d, double theta);
Eigen::Matrix<double,3,5> jacobian(int t0, int t1,int t2,int t3, int t4,int numticks);
double tick_to_radians(int i, int numticks);
int radian_to_ticks(double t0, int numticks);


/* Allocators */

#endif
