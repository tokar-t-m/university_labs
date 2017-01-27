TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    trie.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    trie.h

