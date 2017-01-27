TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=gnu++11

SOURCES += main.cpp \
    base.cpp \
    subaltern.cpp \
    senior_officers.cpp \
    big_brass.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    base.h \
    subaltern.h \
    senior_officers.h \
    big_brass.h

