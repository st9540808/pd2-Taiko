#-------------------------------------------------
#
# Project created by QtCreator 2016-05-07T23:55:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pd2-Taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    popup.cpp \
    note.cpp \
    target.cpp \
    note2.cpp

HEADERS  += mainwindow.h \
    popup.h \
    note.h \
    target.h \
    note2.h

FORMS    += mainwindow.ui \
    popup.ui

RESOURCES += \
    image.qrc
