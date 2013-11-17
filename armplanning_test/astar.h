#ifndef ASTAR_H 
#define ASTAR_H

class Astar 
{

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
	double cost;
	configState* prev;
} visDate;

public:
	wsState* target;
	Astar(int x, int y, int z, int alpha, int theta, int phi);
	wsState forward_kinematics(configState* c);
	double heuristic(configState* c);
	double cost(configState* c);

private:
	void create_wsstate(wsState* w);
	void create_configstate(configState* c);
	void create_visdata(visData* v);
};

#endif