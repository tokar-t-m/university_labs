TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=gnu11

SOURCES += main.c \
    aa_tree.c

include(deployment.pri)
qtcAddDeployment()

OTHER_FILES +=

HEADERS += \
    aa_tree.h

