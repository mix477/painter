QT += gui
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    painter.cpp \
    figures.cpp \
    mypainter.cpp

HEADERS += \
    painter.h \
    figures.h \
    mypainter.h

