#include "cellautomaton.h"
#include "conwayrule.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class MockCellAutomaton : public CellAutomaton
{
public:
  MOCK_METHOD0(isAlive, bool());
};

TEST(ConwayRule, CalculatesNextStateWhenNeighborIsAlive)
{
  MockCellAutomaton mockCellAutomaton;
  EXPECT_CALL(mockCellAutomaton, isAlive()).WillOnce(Return(true));

  ConwayRule theRule;

  EXPECT_TRUE(theRule.CalculateNextState(&mockCellAutomaton));
}
