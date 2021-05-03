#ifndef CELLAUTOMATONTOOLBAR_H
#define CELLAUTOMATONTOOLBAR_H

#include <QToolBar>

class CellAutomatonToolBar : public QToolBar
{
  Q_OBJECT
public:
  CellAutomatonToolBar(QWidget* parent = nullptr);
  virtual ~CellAutomatonToolBar();
};

#endif // CELLAUTOMATONTOOLBAR_H
