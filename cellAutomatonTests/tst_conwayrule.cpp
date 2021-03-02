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

class ConwayRuleTest : public Test{
protected:
  ConwayRuleTest() {}

  ConwayRule theRule;
  MockCellAutomaton mockCellAutomaton1,
                    mockCellAutomaton2,
                    mockCellAutomaton3,
                    mockCellAutomaton4,
                    mockCellAutomaton5,
                    mockCellAutomaton6,
                    mockCellAutomaton7,
                    mockCellAutomaton8;
};

TEST_F(ConwayRuleTest, BecomeAliveWhen3AliveNeighbors)
{
  EXPECT_CALL(mockCellAutomaton1, isAlive()).WillOnce(Return(true));
  EXPECT_CALL(mockCellAutomaton2, isAlive()).WillOnce(Return(true));
  EXPECT_CALL(mockCellAutomaton3, isAlive()).WillOnce(Return(true));

  std::list<CellAutomaton*> theNeighbors = {&mockCellAutomaton1,&mockCellAutomaton2,&mockCellAutomaton3};

  EXPECT_TRUE(theRule.CalculateNextState(theNeighbors, false));
}

TEST_F(ConwayRuleTest, ReturnNotAliveWhenMoreThan3AliveNeighbors)
{
  EXPECT_CALL(mockCellAutomaton1, isAlive()).WillOnce(Return(true));
  EXPECT_CALL(mockCellAutomaton2, isAlive()).WillOnce(Return(true));
  EXPECT_CALL(mockCellAutomaton3, isAlive()).WillOnce(Return(true));
  EXPECT_CALL(mockCellAutomaton4, isAlive()).WillOnce(Return(true));

  std::list<CellAutomaton*> theNeighbors = {&mockCellAutomaton1,
                                            &mockCellAutomaton2,
                                            &mockCellAutomaton3,
                                            &mockCellAutomaton4
                                           };

  EXPECT_FALSE(theRule.CalculateNextState(theNeighbors, true));
}

TEST_F(ConwayRuleTest, ReturnNotAliveWhenLessThan2AliveNeighbors)
{
  EXPECT_CALL(mockCellAutomaton1, isAlive()).WillOnce(Return(false));
  EXPECT_CALL(mockCellAutomaton2, isAlive()).WillOnce(Return(false));
  EXPECT_CALL(mockCellAutomaton3, isAlive()).WillOnce(Return(true));
  EXPECT_CALL(mockCellAutomaton4, isAlive()).WillOnce(Return(false));

  std::list<CellAutomaton*> theNeighbors = {&mockCellAutomaton1,
                                            &mockCellAutomaton2,
                                            &mockCellAutomaton3,
                                            &mockCellAutomaton4
                                           };

  EXPECT_FALSE(theRule.CalculateNextState(theNeighbors, true));
}

TEST_F(ConwayRuleTest, RemainNotAliveWhenNot3AliveNeighbors)
{
  EXPECT_CALL(mockCellAutomaton1, isAlive()).WillOnce(Return(true));
  EXPECT_CALL(mockCellAutomaton2, isAlive()).WillOnce(Return(false));
  EXPECT_CALL(mockCellAutomaton3, isAlive()).WillOnce(Return(true));
  EXPECT_CALL(mockCellAutomaton4, isAlive()).WillOnce(Return(false));

  std::list<CellAutomaton*> theNeighbors = {&mockCellAutomaton1,
                                            &mockCellAutomaton2,
                                            &mockCellAutomaton3,
                                            &mockCellAutomaton4
                                           };

  EXPECT_FALSE(theRule.CalculateNextState(theNeighbors, false));
}

TEST_F(ConwayRuleTest, StayAliveWhen3AliveNeighbors)
{
  EXPECT_CALL(mockCellAutomaton1, isAlive()).WillOnce(Return(false));
  EXPECT_CALL(mockCellAutomaton2, isAlive()).WillOnce(Return(true));
  EXPECT_CALL(mockCellAutomaton3, isAlive()).WillOnce(Return(true));
  EXPECT_CALL(mockCellAutomaton4, isAlive()).WillOnce(Return(true));

  std::list<CellAutomaton*> theNeighbors = {&mockCellAutomaton1,
                                            &mockCellAutomaton2,
                                            &mockCellAutomaton3,
                                            &mockCellAutomaton4
                                           };

  EXPECT_TRUE(theRule.CalculateNextState(theNeighbors, true));
}
