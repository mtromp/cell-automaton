#include "cellautomatonitem.h"

#include <QPainter>

CellAutomatonItem::CellAutomatonItem(CellAutomaton* theCell, QGraphicsItem* parent) : QGraphicsItem(parent)
                                                                                    , cell(theCell)
{
}

CellAutomatonItem::~CellAutomatonItem()
{
  delete cell;
}

QRectF CellAutomatonItem::boundingRect() const
{
  return QRectF(0,0,10,10);
}

void CellAutomatonItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  Q_UNUSED(widget);
  Q_UNUSED(option);

  painter->setPen(QPen(QColor(56, 165, 211), 1));
  painter->drawRect(0, 0, 10, 10);
  if (this->cell->isAlive())
  {
    painter->fillRect(1, 1, 9, 9, QColor(0, 0, 0));
  } else {
    painter->fillRect(1, 1, 9, 9, QColor(114, 213, 175));
  }

}

CellAutomaton* CellAutomatonItem::getCell()
{
  return cell;
}

void CellAutomatonItem::handleMouseEvent()
{
  this->cell->toggleState();
}

void CellAutomatonItem::calculateNextState()
{
  this->cell->calculateNextState();
}
void CellAutomatonItem::updateCurrentState()
{
  this->cell->updateCurrentState();
}
