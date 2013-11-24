#ifndef ASTAR_H
#define ASTAR_H
#include <map>			  // maps
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
#include <vector>

class Astar
{



public:
	Astar();
	std::vector<configState*> run(configState* start, wsState* target)

private:
	const double targetthreshold = .1;
	/* computation */
	double heuristic(configState* c1, configState* c2);
	double cost(configState* c);
	void expand_frontier(configState* c);



	wsState* target;
	Astar(int x, int y, int z, int alpha, int theta, int phi);
	wsState* forward_kinematics(configState* c);
	double heuristic(configState* c);
	double cost(configState* c1,configState* c2);


	/* Frontier set as a priority queue */
	typedef std::priority_queue
	  <visData*,std::vector<visData*>,visdatacomp> statepq;

	statepq frontier;   //This keeps track of the frontier state

	/* Visited set as a map*/
	std::map<configState, visData*,configcomp> visited_set;
	//Visited set as a map


	/* params */
	configState* start;
	wsState* target;

	/* Visited set helper functions */
	bool has_visited(configState c);
	void add_visited(configState c, visData* v);
	void get_visdata(configState* c, visData* v);



};

#endif
