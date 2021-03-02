#include "cellautomaton.h"
#include "conwayrule.h"

CellAutomaton::CellAutomaton()
{

}

//TODO: what needs to be cleaned up??
CellAutomaton::~CellAutomaton()
{
//  delete theRule;
//  delete theNeighborList; // verify that the cells are not deleted.
}

bool CellAutomaton::isAlive()
{
  return this->currentState;
}

void CellAutomaton::setRule(ConwayRule* rule)
{
  this->theRule = rule;
}

void CellAutomaton::setNeighborList(std::list<CellAutomaton*>* neighbors)
{
  this->theNeighborList = neighbors;
}

void CellAutomaton::calculateNextState()
{
  this->nextState = this->theRule->CalculateNextState(*this->theNeighborList, this->currentState);
}

void CellAutomaton::updateCurrentState()
{
  this->currentState = this->nextState;
}
