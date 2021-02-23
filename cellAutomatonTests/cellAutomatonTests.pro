macx: GOOGLETEST_DIR = /Users/Shared/gitrepositories/googletest/
unix:!macx: GOOGLETEST_DIR = /usr/src/googletest/

include(gtest_dependency.pri)

QT += testlib
QT += core

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG += testcase

HEADERS +=  tst_cellautomatontestcase.h

SOURCES +=  main.cpp  \
  tst_cellautomaton.cpp

INCLUDEPATH += $$PWD/../cellAutomatonLibrary
LIBS += -L$$OUT_PWD/../cellAutomatonLibrary -lcellAutomatonLibrary

