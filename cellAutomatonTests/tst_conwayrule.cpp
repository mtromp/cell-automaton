#include "cellautomaton.h"
#include "conwayrule.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <list>

using namespace testing;

class MockCellAutomaton : public CellAutomaton
{
public:
  MOCK_METHOD0(isAlive, bool());
};

TEST(ConwayRule, CalculatesNextStateWhenAll3NeighborsIsAlive)
{
  MockCellAutomaton mockCellAutomaton1,mockCellAutomaton2,mockCellAutomaton3;
  EXPECT_CALL(mockCellAutomaton1, isAlive()).WillOnce(Return(true));
  EXPECT_CALL(mockCellAutomaton2, isAlive()).WillOnce(Return(true));
  EXPECT_CALL(mockCellAutomaton3, isAlive()).WillOnce(Return(true));

  std::list<CellAutomaton*> theNeighbors = {&mockCellAutomaton1,&mockCellAutomaton2,&mockCellAutomaton3};
  ConwayRule theRule;

  EXPECT_TRUE(theRule.CalculateNextState(theNeighbors));
}
