#-------------------------------------------------
#
# Project created by QtCreator 2014-03-11T13:19:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExpGame
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
    gui/mainwindow.cpp \
    gui/qgameboard.cpp \
    gui/qtile.cpp \
    gui/qresetbutton.cpp \
    gui/qgameoverwindow.cpp \
    core/input.cpp \
    core/notmain.cpp \
    core/output.cpp \
    core/process.cpp \
    core/randomgen.cpp

HEADERS  += gui/mainwindow.h \
    gui/qgameboard.h \
    gui/qtile.h \
    gui/qresetbutton.h \
    gui/qgameoverwindow.h \
    gui/qwinwindow.h \
    core/global.h

