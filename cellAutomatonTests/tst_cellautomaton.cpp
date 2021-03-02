#include "cellautomaton.h"
#include "conwayrule.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

// Use mock for Neighbors ONLY
class MockCellAutomaton : public CellAutomaton
{
public:
  MOCK_METHOD0(isAlive, bool());
};

class CellAutomatonTest: public Test
{
protected:
  CellAutomatonTest() {}
  ~CellAutomatonTest() {}

  CellAutomaton cell;
};

TEST_F(CellAutomatonTest, CellIsNotAliveInitially)
{
  EXPECT_FALSE(cell.isAlive());
}

TEST_F(CellAutomatonTest, CellBecomesAliveWith3LiveNeighbors)
{
  ConwayRule theRule;
  cell.setRule(&theRule);
  MockCellAutomaton mockCellAutomaton1,
                    mockCellAutomaton2,
                    mockCellAutomaton3,
                    mockCellAutomaton4,
                    mockCellAutomaton5,
                    mockCellAutomaton6,
                    mockCellAutomaton7,
                    mockCellAutomaton8;
  EXPECT_CALL(mockCellAutomaton1, isAlive()).WillOnce(Return(true));
  EXPECT_CALL(mockCellAutomaton2, isAlive()).WillOnce(Return(true));
  EXPECT_CALL(mockCellAutomaton3, isAlive()).WillOnce(Return(true));

  std::list<CellAutomaton*> theNeighbors = {&mockCellAutomaton1,&mockCellAutomaton2,&mockCellAutomaton3};

  cell.setNeighborList(&theNeighbors);
  cell.calculateNextState();
  cell.updateCurrentState();

  EXPECT_TRUE(cell.isAlive());
}
