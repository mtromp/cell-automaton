#ifndef CONWAYRULE_H
#define CONWAYRULE_H

#include "cellautomaton.h"

class ConwayRule
{
public:
  ConwayRule();
  virtual ~ConwayRule();

  virtual bool CalculateNextState(CellAutomaton* theNeighbor);
};

#endif // CONWAYRULE_H
