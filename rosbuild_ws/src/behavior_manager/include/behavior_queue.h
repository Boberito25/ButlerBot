#ifndef BEHAVIOR_QUEUE_H
#define BEHAVIOR_QUEUE_H
#include <string>
#include <vector>
using namespace std;
class Behavior_Queue
{

typedef  struct Behavior_N{
  //Data
  string behavior;
  string params;
  unsigned int priority;
  vector<string> reserves;

  //Links
  Behavior_N *next;
} Behavior_N;

public:
  Behavior_Queue();
  bool enqueue(string behavior, string params, const std::vector<string>& reserves,
	unsigned int priority);
  bool next_behavior(string *behavior, string *params);
  void terminated(string behavior);
private:
  bool reserves_in_use(const vector<string>& reserves);

  Behavior_N* queue;
  vector<string> active; 
 
};


#endif

