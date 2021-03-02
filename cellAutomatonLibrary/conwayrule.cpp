#include "conwayrule.h"

ConwayRule::ConwayRule()
{

}

ConwayRule::~ConwayRule()
{

}

bool ConwayRule::CalculateNextState(std::list<CellAutomaton*> neighbors, bool currentState)
{
  std::list<CellAutomaton*>::iterator it;
  int aliveCount = 0;
  for (it = neighbors.begin(); it != neighbors.end(); it++)
  {
    (*it)->isAlive() ? aliveCount++:0;
  }

  bool nextState = false;
  if (currentState)
  {
    if(aliveCount == 2 || aliveCount == 3) nextState = true;
  } else {
    if (aliveCount == 3) nextState = true;
  }

  return nextState;
}
