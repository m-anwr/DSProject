#-------------------------------------------------
#
# Project created by QtCreator 2016-04-07T01:25:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dsproj
TEMPLATE = app

SOURCES += src/main.cpp \
           src/mainwindow.cpp \
           src/request.cpp \
           src/elevator.cpp \
           src/pair.cpp \
           src/scene.cpp

HEADERS  += src/mainwindow.h \
    src/request.h \
    src/elevator.h \
    src/pair.h \
    src/scene.h

FORMS    += src/mainwindow.ui
