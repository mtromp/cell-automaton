#ifndef AUTOMATONGRIDVIEW_H
#define AUTOMATONGRIDVIEW_H

#include <QGraphicsView>

class AutomatonGridView : public QGraphicsView
{
   Q_OBJECT
public:
  AutomatonGridView(QGraphicsScene* theScene, QWidget* parent = nullptr);
  virtual ~AutomatonGridView();

};

#endif // AUTOMATONGRIDVIEW_H
