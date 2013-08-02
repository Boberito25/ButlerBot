#include "behavior_reserver.h"
#include <string>
#include <vector>

Behavior_Reserver::Behavior_Reserver()
   : list(0)
{
  /* Add to the list here */  
}

vector<string> Behavior_Reserver::get(string behavior)
{
  for(int i = 0; i < list.size(); i++){
    string s = list.at(i).behavior;
    if(!s.compare(behavior)){
      return list.at(i).reserves;
    }
  }
}
