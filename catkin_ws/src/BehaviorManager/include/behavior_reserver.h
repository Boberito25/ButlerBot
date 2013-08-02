#ifndef BEHAVIOR_RESERVER_H
#define BEHAVIOR_RESERVER_H
#include <vector>
#include <string>
using namespace std;
typedef struct Behavior_Res{
  string behavior;
  vector<string> reserves;
}  Behavior_Res;
class Behavior_Reserver
{
public:
  Behavior_Reserver();
  vector<string> get(string behavior);
private:
  vector<Behavior_Res> list;
  
};
#endif
