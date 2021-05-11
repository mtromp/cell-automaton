#include "mainwindow.h"
#include "automatongridview.h"
#include "cellautomatonscene.h"

#include <QDockWidget>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
  CellAutomatonScene* automatonScene = new CellAutomatonScene(this);
  AutomatonGridView* automatonView = new AutomatonGridView(automatonScene, this);
  this->setCentralWidget(automatonView);

  QDockWidget* dock = new QDockWidget("Controls", this);
  dock->setAllowedAreas(Qt::BottomDockWidgetArea);
  nextButton = new QPushButton("NEXT", dock);

  connect(nextButton, SIGNAL(clicked()),automatonScene, SLOT(handleNextClicked()));

  dock->setWidget(nextButton);
  this->addDockWidget(Qt::BottomDockWidgetArea, dock);
  setWindowTitle("Cell Automaton");
  setFixedSize(400, 450);
}

MainWindow::~MainWindow()
{
}
