#ifndef CELLAUTOMATONSCENE_H
#define CELLAUTOMATONSCENE_H

#include <QGraphicsScene>

class CellAutomatonScene : public QGraphicsScene
{
  Q_OBJECT
public:
  CellAutomatonScene(QObject* parent = nullptr);
  virtual ~CellAutomatonScene();

private:
  void createCells();
};

#endif // CELLAUTOMATONSCENE_H
