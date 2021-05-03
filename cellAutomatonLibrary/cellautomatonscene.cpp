#include "cellautomatonscene.h"

#include "cellautomaton.h"
#include "cellautomatonitem.h"

CellAutomatonScene::CellAutomatonScene(QObject* parent) : QGraphicsScene(parent)
{
  this->setSceneRect(0, 0, 400, 400);

  this->createCells();
}

CellAutomatonScene::~CellAutomatonScene()
{

}

void CellAutomatonScene::createCells()
{
  int xposition = 0; //Dimensions::Margin
  int yposition = 0; //Dimensions::Margin if there is an offset into the scene.

  for (unsigned int cellNumber = 1; cellNumber <= 1600; cellNumber++)
  {
    CellAutomaton* theCell = new CellAutomaton();
    CellAutomatonItem* cellItem = new CellAutomatonItem(theCell);
    cellItem->setPos(xposition, yposition);
    this->addItem(cellItem);

    //update xposition and ypositioh for a 40x40 grid
    if ( cellNumber % 40 == 0 )
    {
      xposition = 0; //or Dimension::margin
      yposition = yposition + 10;
    }
    else
    {
      xposition = xposition + 10;
    }
  }

}
