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
typedef struct State {
	int prev[3];
	double x;
	double z;
	double alpha;
	double heuristic;
	double value;
	bool visited;
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
		int t0, int t1, int t2);
Eigen::Matrix4d DH(double alpha, double a, double d, double theta);
double tick_to_radians(int i);


/* Allocators */

#endif
