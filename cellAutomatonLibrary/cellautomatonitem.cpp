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


}
