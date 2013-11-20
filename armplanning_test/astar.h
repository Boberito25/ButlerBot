#ifndef ASTAR_H
#define ASTAR_H
#include <map>			  // maps
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater

class Astar
{


public:

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
    configState* current;
    double cost;
    configState* prev;
  } visData;


	wsState* target;
	Astar(int x, int y, int z, int alpha, int theta, int phi);
	wsState* forward_kinematics(configState* c);
	double heuristic(configState* c);
	double cost(configState* c1,configState* c2);

private:

	//Frontier set as a priority queue
	typedef std::priority_queue
	  <visData*,std::vector<visData*>/*,statecompare*/> statepq;

	statepq frontier;   //This keeps track of the frontier state

	//Visited set as a map
	std::map<configState, visData*/*,statecompare*/> visited_set;


	/* Visited set helper functions */
	bool has_visited(configState* c);
	void add_visited(configState* c, visData* v);
	void get_visdata(configState* c, visData* v);

	/* Allocators */
	void create_wsstate(wsState* w);
	void create_configstate(configState* c);
	void create_visdata(visData* v);

};

#endif
