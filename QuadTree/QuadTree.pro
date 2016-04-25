TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Nodo.cpp \
    QuadTree.cpp

HEADERS += \
    Nodo.h \
    QuadTree.h

INCLUDEPATH = /usr/include/

LIBS += -L/usr/lib/x86_64-linux-gnu -lm -lpthread -lX11
