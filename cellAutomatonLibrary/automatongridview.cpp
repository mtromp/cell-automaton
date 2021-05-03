#include "automatongridview.h"
#include "cellautomatonscene.h"

AutomatonGridView::AutomatonGridView(QWidget* parent) : QGraphicsView(parent)
{
  this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setFrameStyle(QFrame::NoFrame);

  this->setBackgroundBrush(QColor(114, 213, 175));
  this->setScene(new CellAutomatonScene(this));

}

AutomatonGridView::~AutomatonGridView()
{

}
