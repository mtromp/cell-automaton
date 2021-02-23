#include "cellautomaton.h"

#include <gtest/gtest.h>

using namespace testing;

class CellAutomatonTest: public Test
{
protected:
  CellAutomatonTest() : cell(){}
  ~CellAutomatonTest() {}

  CellAutomaton cell;
};

