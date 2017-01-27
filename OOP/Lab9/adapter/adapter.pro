TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    FahrenheitSensor.cpp \
    Sensor.cpp \
    Adapter.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    FahrenheitSensor.h \
    Sensor.h \
    Adapter.h

