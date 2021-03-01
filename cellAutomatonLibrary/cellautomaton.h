#ifndef CELLAUTOMATON_H
#define CELLAUTOMATON_H

#include <QObject>

class CellAutomaton
{

public:
  CellAutomaton();
  virtual ~CellAutomaton();
  virtual bool isAlive();
};

#endif // CELLAUTOMATON_H
