#-------------------------------------------------
#
# Project created by QtCreator 2015-06-21T10:44:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calendar
TEMPLATE = app

VPATH   +=  data \
            widget \

INCLUDEPATH = $$VPATH

SOURCES +=  Main.cpp \
            CalendarMainWindow.cpp \
            CalendarMonth.cpp \
            CalendarView.cpp \
            CalendarWeek.cpp \
            CalendarYear.cpp \
            DataController.cpp \
            UiController.cpp

HEADERS +=  CalendarMainWindow.h \
            CalendarMonth.h \
            CalendarView.h \
            CalendarWeek.h \
            CalendarYear.h \
            DataController.h \
            Singleton.h \
            UiController.h

QMAKE_CXXFLAGS += -std=c++0x
