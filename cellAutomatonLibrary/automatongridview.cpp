#include "automatongridview.h"

AutomatonGridView::AutomatonGridView(QGraphicsScene* theScene, QWidget* parent) : QGraphicsView(theScene, parent)
{
  this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setFrameStyle(QFrame::NoFrame);

  this->setBackgroundBrush(QColor(114, 213, 175));
}

AutomatonGridView::~AutomatonGridView()
{

}
