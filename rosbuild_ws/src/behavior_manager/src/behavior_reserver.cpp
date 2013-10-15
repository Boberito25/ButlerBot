#include "behavior_reserver.h"
#include <string>
#include <vector>

Behavior_Reserver::Behavior_Reserver()
   : list(0)
{
  /* Allocate Behavior_Res blocks */

  //test behavior
  Behavior_Res test;
  test.behavior = "test_behavior"
  vector<string> test_reserves;
  test.reserves = test_reserves;
  
  /* Add to the list here */ 
  list.push_back(test);
   
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
