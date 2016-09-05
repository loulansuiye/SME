#-------------------------------------------------
#
# Project created by QtCreator 2016-07-14T15:06:40
#
#-------------------------------------------------

QT       += core gui widgets location

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SME
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    showwidget.cpp \
    bugfeedback.cpp \
    preferencesdlg.cpp \
    treeviewwid.cpp \
    selectiteminfo.cpp

HEADERS  += mainwindow.h \
    showwidget.h \
    bugfeedback.h \
    preferencesdlg.h \
    treeviewwid.h \
    selectiteminfo.h

RESOURCES += \
    res.qrc
