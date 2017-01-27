TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=gnu++11

SOURCES += main.cpp \
    translator.cpp

#include(deployment.pri)
#qtcAddDeployment()

HEADERS += \
    translator.h

