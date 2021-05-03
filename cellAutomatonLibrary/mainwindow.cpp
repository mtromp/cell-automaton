#include "mainwindow.h"
#include "automatongridview.h"

#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
  AutomatonGridView* automatonView = new AutomatonGridView(this);
  this->setCentralWidget(automatonView);

  QDockWidget* dock = new QDockWidget("Controls", this);
  dock->setAllowedAreas(Qt::BottomDockWidgetArea);
  nextButton = new QPushButton("NEXT", dock);
  dock->setWidget(nextButton);
  this->addDockWidget(Qt::BottomDockWidgetArea, dock);
  setWindowTitle("Cell Automaton");
  setFixedSize(400, 450);
}

MainWindow::~MainWindow()
{
}
