#-------------------------------------------------
#
# Project created by QtCreator 2014-03-11T13:19:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048_PoPL
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

DESTDIR = build/

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui


SOURCES += main.cpp\
    gui/mainwindow.cpp \
    gui/qgameboard.cpp \
    gui/qtile.cpp \
    gui/qgameoverwindow.cpp \
    core/input.cpp \
    core/process.cpp \
    core/randomgen.cpp

HEADERS  += gui/mainwindow.h \
    gui/qgameboard.h \
    gui/qtile.h \
    gui/qgameoverwindow.h \
    core/global.h

