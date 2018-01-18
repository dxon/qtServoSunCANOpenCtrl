#-------------------------------------------------
#
# Project created by QtCreator 2016-10-28T09:45:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtServoSunCAN_ctrl
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += c++11



win32: LIBS += $$PWD/../libusb-1.0.20/MinGW32/static/libusb-1.0.a
win32: INCLUDEPATH += $$PWD/../libusb-1.0.20/include/libusb-1.0
win32: DEPENDPATH += $$PWD/../libusb-1.0.20/include/libusb-1.0
win32: PRE_TARGETDEPS += $$PWD/../libusb-1.0.20/MinGW32/static/libusb-1.0.a

QMAKE_LFLAGS_RELEASE += -static -static-libgcc

DISTFILES +=
