TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    derivatives.cpp \
    factory.cpp \
    base.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    base.h \
    derivatives.h \
    factory.h

