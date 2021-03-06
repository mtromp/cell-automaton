#ifndef CONWAYRULE_H
#define CONWAYRULE_H

#include "cellautomaton.h"

#include <list>

class ConwayRule
{
public:
  ConwayRule();
  virtual ~ConwayRule();

  virtual bool CalculateNextState(std::list<CellAutomaton*> neighbors, bool currentState);
};

#endif // CONWAYRULE_H
