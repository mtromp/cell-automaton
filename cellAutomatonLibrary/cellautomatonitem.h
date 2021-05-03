#ifndef CELLAUTOMATONITEM_H
#define CELLAUTOMATONITEM_H

#include "cellautomaton.h"

#include <QGraphicsItem>

class CellAutomatonItem : public QGraphicsItem
{
public:
  CellAutomatonItem(CellAutomaton* theCell = nullptr
                    , QGraphicsItem* parent = nullptr);
  virtual ~CellAutomatonItem();
  QRectF boundingRect() const;

  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);

  CellAutomaton* getCell();

private:
  CellAutomaton* cell;
};

#endif // CELLAUTOMATONITEM_H
