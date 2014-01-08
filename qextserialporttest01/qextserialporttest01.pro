#-------------------------------------------------
#
# Project created by QtCreator 2013-06-05T09:26:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qextserialporttest01
TEMPLATE = app

include(qextserialport/qextserialport.pri)

SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h \
    deviceinfo.h

FORMS    += widget.ui
