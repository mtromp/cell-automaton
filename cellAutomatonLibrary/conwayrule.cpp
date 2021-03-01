#include "conwayrule.h"

ConwayRule::ConwayRule()
{

}

ConwayRule::~ConwayRule()
{

}

bool ConwayRule::CalculateNextState(CellAutomaton* theNeighbor)
{
  return theNeighbor->isAlive();
}
