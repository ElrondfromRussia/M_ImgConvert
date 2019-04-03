#-------------------------------------------------
#
# Project created by QtCreator 2018-10-17T09:04:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IconMaker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    imgs.qrc

win32: RC_FILE = myapp.rc

DISTFILES += \
    myapp.rc
