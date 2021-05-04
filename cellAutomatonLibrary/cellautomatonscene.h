#ifndef CELLAUTOMATONSCENE_H
#define CELLAUTOMATONSCENE_H

#include <QGraphicsScene>

class CellAutomatonScene : public QGraphicsScene
{
  Q_OBJECT
public:
  CellAutomatonScene(QObject* parent = nullptr);
  virtual ~CellAutomatonScene();

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);

private:
  void createCells();
  void setAllNeighborLists();
};

#endif // CELLAUTOMATONSCENE_H
