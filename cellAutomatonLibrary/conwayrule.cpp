#include "conwayrule.h"

ConwayRule::ConwayRule()
{

}

ConwayRule::~ConwayRule()
{

}

bool ConwayRule::CalculateNextState(std::list<CellAutomaton*> neighbors)
{
  std::list<CellAutomaton*>::iterator it;
  int aliveCount = 0;

  for (it = neighbors.begin(); it != neighbors.end(); it++)
  {
    (*it)->isAlive() ? aliveCount++:0;
  }

  return aliveCount>2 ? true : false;
}
