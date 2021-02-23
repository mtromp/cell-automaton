QMAKE_MAC_SDK = macosx10.14
TEMPLATE = subdirs

SUBDIRS += \
    cellAutomatonLibrary \
    cellAutomatonApplication \
    cellAutomatonTests

cellAutomatonApplication.depends = cellAutomatonLibrary
cellAutomatonTests.depends = cellAutomatonLibrary
