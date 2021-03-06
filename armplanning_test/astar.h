#ifndef ASTAR_H
#define ASTAR_H
#include <unordered_map>			  // maps
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <deque>         // std::vector
#include <functional>     // std::greater
#include "forward_kinematics.h"
#include <unordered_map>
#include <bitset>
#include <string>
#include <utility>
class Astar
{

public:
	Astar();
	std::vector<configState*> run(configState* start, wsState* target);
	/* Visited set helper functions */
	bool has_visited(configState* c);
	void add_visited(configState* c, visData* v);
	visData* get_visdata(configState* c);
private:
	wsState* target;

	double target_threshold;
	/* computation */
	double heuristic(configState* c1, configState* c2);
	double cost(configState* c);
	void expand_frontier(configState* c);

	double heuristic(configState* c);
	double cost(configState* c1,configState* c2);

	/* Frontier set as a priority queue */
	typedef std::priority_queue
	  <visData*,std::deque<visData*>,visdatacomp> statepq;
	statepq frontier;   //This keeps track of the frontier state

	/* Visited set as a map*/
	std::unordered_map<configState*,visData*, configHash, configEquals> visited_set;
	//Visited set as a map


	/* params */
	configState* start;

	/* Runtime Debug */
	float get_visdata_time;
	float value_comp_time;
	float frontier_insert_time;
	float mem_time;





};

#endif
