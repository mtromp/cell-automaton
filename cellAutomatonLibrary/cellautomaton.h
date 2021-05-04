#ifndef CELLAUTOMATON_H
#define CELLAUTOMATON_H

#include <QObject>

class ConwayRule;

class CellAutomaton
{

public:
  CellAutomaton();
  virtual ~CellAutomaton();
  virtual bool isAlive();
  void setRule(ConwayRule* rule);
  void setNeighborList(std::list<CellAutomaton*>* neighbors);
  void calculateNextState();
  void updateCurrentState();

  void toggleState();
private:
  bool currentState = false;
  bool nextState = false;
  ConwayRule* theRule = nullptr;
  std::list<CellAutomaton*>* theNeighborList = nullptr;
};

#endif // CELLAUTOMATON_H
