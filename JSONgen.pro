#-------------------------------------------------
#
# Project created by QtCreator 2014-12-01T16:46:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JSONgen
TEMPLATE = app


SOURCES += main.cpp\
        json.cpp \
    about.cpp

HEADERS  += json.h \
    about.h

FORMS    += json.ui \
    about.ui

RC_FILE = myapp.rc
