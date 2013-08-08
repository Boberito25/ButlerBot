#include "behavior_queue.h"
#include <string>
#include <vector>
#include <cstdlib>
Behavior_Queue::Behavior_Queue()
   : active(0)
{
  queue = 0;
}

bool Behavior_Queue::enqueue(string behavior, string params, 
			const std::vector<string>& reserves,
                        unsigned int priority)
{
  /* Construct Behavior */
  Behavior* b = (Behavior*)malloc(sizeof(struct Behavior));
  b->behavior = behavior;
  b->params = params;
  b->priority = priority;
  b->next = 0;
  for(int i = 0; i < reserves.size(); i++){
    b->reserves.push_back(reserves.at(i));
  }

  /* Enqueue */
  if(queue == 0){
    queue = b;
  }  else {
    Behavior* temp = queue;
    while(queue->next != 0){
      temp = temp->next;
    }
    queue->next = b;
  }  return true;

}

bool Behavior_Queue::next_behavior(string *behavior, string *params){
  if(queue == 0 || reserves_in_use(queue->reserves))
    return false;
  *behavior = queue -> behavior;
  *params = queue -> params;
  active.push_back(queue->behavior);
  Behavior *tmp = queue;
  queue = queue -> next;
  free(tmp);
  return true;
 }

void Behavior_Queue::terminated(string behavior){
  for(int i = 0; i < active.size(); i++){
    if(!active.at(i).compare(behavior))
      active.erase(active.begin()+i);
  }
}

bool Behavior_Queue::reserves_in_use(const vector<string>& reserves){
  for(int i = 0; i < active.size(); i++){
     for(int j = 0; j < reserves.size(); j++){
	if(!active.at(i).compare(reserves.at(j)))
	  return true;
     }
  }
  return false;
} 
