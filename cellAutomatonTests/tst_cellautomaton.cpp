#include "cellautomaton.h"

#include <gtest/gtest.h>

using namespace testing;

class CellAutomatonTest: public Test
{
protected:
  CellAutomatonTest() {}
  ~CellAutomatonTest() {}

  CellAutomaton cell;
};

TEST_F(CellAutomatonTest, CellIsNotAlive)
{
  EXPECT_TRUE(cell.isAlive());
}
