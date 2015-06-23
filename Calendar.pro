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
            CalendarYear.cpp \
            CalendarMonth.cpp \
            CalendarWeek.cpp \
            CalendarMainWindow.cpp \
            DataController.cpp \
            UiController.cpp \

HEADERS +=  UiController.h \
            Singleton.h \
            DataController.h \
            CalendarYear.h \
            CalendarMonth.h \
            CalendarWeek.h \
            CalendarMainWindow.h \

QMAKE_CXXFLAGS += -std=c++0x
