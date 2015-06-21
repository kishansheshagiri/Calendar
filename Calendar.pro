#-------------------------------------------------
#
# Project created by QtCreator 2015-06-21T10:44:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calendar
TEMPLATE = app


SOURCES += main.cpp\
        CalendarMainWindow.cpp \
    UiController.cpp \
    DataController.cpp \
    data/CalendarYear.cpp \
    data/CalendarMonth.cpp \
    data/CalendarWeek.cpp

HEADERS  += CalendarMainWindow.h \
    UiController.h \
    Singleton.h \
    DataController.h \
    data/CalendarYear.h \
    data/CalendarMonth.h \
    data/CalendarWeek.h

QMAKE_CXXFLAGS += -std=c++14 -pedantic-errors
