#include "cellautomatonscene.h"

#include "cellautomaton.h"
#include "cellautomatonitem.h"

#include <QGraphicsSceneMouseEvent>
#include <QTransform>

CellAutomatonScene::CellAutomatonScene(QObject* parent) : QGraphicsScene(parent)
{
  this->setSceneRect(0, 0, 400, 400);

  this->createCells();
  this->setAllNeighborLists();
}

CellAutomatonScene::~CellAutomatonScene()
{
}

void CellAutomatonScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    QPointF position = event->scenePos();
    QGraphicsItem* selectedItem = itemAt(position, QTransform());
    CellAutomatonItem* mySelection = dynamic_cast<CellAutomatonItem*>(selectedItem);
    if (mySelection != nullptr)
    {
        mySelection->handleMouseEvent();
        this->update(0, 0, 400, 400);
    }
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

void CellAutomatonScene::setAllNeighborLists()
{
  QTransform theTransform;

  // make a loop that goes through the 40x40 matrix and calculates the neighbors for each cell
  // special cases for x or y == 0 or 390.
  int xposition = 0;
  int xNeighborPosition;
  int yposition = 0;
  int yNeighborPosition;
  CellAutomatonItem* cellItem;
  CellAutomaton* theCell;
  CellAutomatonItem* neighborItem;
   for (unsigned int cellNumber = 1; cellNumber <= 1600; cellNumber++)
  {

    cellItem = dynamic_cast<CellAutomatonItem*>(this->itemAt(xposition,yposition,theTransform));
    theCell = cellItem->getCell();
    std::list<CellAutomaton*>* theNeighbors = new std::list<CellAutomaton*>;

    //left neighbor
    xNeighborPosition = xposition - 10;
    yNeighborPosition = yposition;
    if ((xNeighborPosition > 0 && xNeighborPosition < 400) && (yNeighborPosition > 0 && yNeighborPosition < 400))
    {
      neighborItem = dynamic_cast<CellAutomatonItem*>(this->itemAt(xNeighborPosition,yNeighborPosition,theTransform));
      theNeighbors->push_back(neighborItem->getCell());
    }
    //upper left neighbor
    yNeighborPosition = yposition - 10;
    if ((xNeighborPosition > 0 && xNeighborPosition < 400) && (yNeighborPosition > 0 && yNeighborPosition < 400))
    {
      neighborItem = dynamic_cast<CellAutomatonItem*>(this->itemAt(xNeighborPosition,yNeighborPosition,theTransform));
      theNeighbors->push_back(neighborItem->getCell());
    }
    //above neighbor
    xNeighborPosition = xposition;
    if ((xNeighborPosition > 0 && xNeighborPosition < 400) && (yNeighborPosition > 0 && yNeighborPosition < 400))
    {
      neighborItem = dynamic_cast<CellAutomatonItem*>(this->itemAt(xNeighborPosition,yNeighborPosition,theTransform));
      theNeighbors->push_back(neighborItem->getCell());
    }
    //upper right neighbor
    xNeighborPosition = xposition + 10;
    if ((xNeighborPosition > 0 && xNeighborPosition < 400) && (yNeighborPosition > 0 && yNeighborPosition < 400))
    {
      neighborItem = dynamic_cast<CellAutomatonItem*>(this->itemAt(xNeighborPosition,yNeighborPosition,theTransform));
      theNeighbors->push_back(neighborItem->getCell());
    }
    //right neighbor
    yNeighborPosition = yposition;
    if ((xNeighborPosition > 0 && xNeighborPosition < 400) && (yNeighborPosition > 0 && yNeighborPosition < 400))
    {
      neighborItem = dynamic_cast<CellAutomatonItem*>(this->itemAt(xNeighborPosition,yNeighborPosition,theTransform));
      theNeighbors->push_back(neighborItem->getCell());
    }
    //lower right neighbor
    yNeighborPosition = yposition + 10;
    if ((xNeighborPosition > 0 && xNeighborPosition < 400) && (yNeighborPosition > 0 && yNeighborPosition < 400))
    {
      neighborItem = dynamic_cast<CellAutomatonItem*>(this->itemAt(xNeighborPosition,yNeighborPosition,theTransform));
      theNeighbors->push_back(neighborItem->getCell());
    }
    //below neighbor
    xNeighborPosition = xposition;
    if ((xNeighborPosition > 0 && xNeighborPosition < 400) && (yNeighborPosition > 0 && yNeighborPosition < 400))
    {
      neighborItem = dynamic_cast<CellAutomatonItem*>(this->itemAt(xNeighborPosition,yNeighborPosition,theTransform));
      theNeighbors->push_back(neighborItem->getCell());
    }
    //lower left neighbor
    xNeighborPosition = xposition - 10;
    if ((xNeighborPosition > 0 && xNeighborPosition < 400) && (yNeighborPosition > 0 && yNeighborPosition < 400))
    {
      neighborItem = dynamic_cast<CellAutomatonItem*>(this->itemAt(xNeighborPosition,yNeighborPosition,theTransform));
      theNeighbors->push_back(neighborItem->getCell());
    }

    theCell->setNeighborList(theNeighbors);
  }
}
