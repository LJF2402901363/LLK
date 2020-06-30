#-------------------------------------------------
#
# Project created by QtCreator 2020-06-11T22:18:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LLK
TEMPLATE = app
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QT       += multimedia

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    entergamepanel.cpp \
    settingpanel.cpp \
    introductionpanel.cpp \
    helppanel.cpp \
    rankingpanel.cpp \
    basicgame.cpp \
    gameview.cpp \
    gamecontroller.cpp \
    gameservice.cpp \
    vertex.cpp \
    lowlevelgame.cpp \
    leisuregame.cpp \
    lowlevelgamecontroller.cpp \
    lowlevelgameservice.cpp \
    leisuregamecontroller.cpp \
    leisuregameservice.cpp \
    gamemediauitl.cpp \
    playerthread.cpp

HEADERS += \
     mainwindow.h \
    entergamepanel.h \
    settingpanel.h \
    introductionpanel.h \
    helppanel.h \
    rankingpanel.h \
    basicgame.h \
    gameview.h \
    gamecontroller.h \
    gameglobalconstants.h \
    gameservice.h \
    vertex.h \
    lowlevelgame.h \
    leisuregame.h \
    lowlevelgamecontroller.h \
    lowlevelgameservice.h \
    leisuregamecontroller.h \
    leisuregameservice.h \
    gamemediauitl.h \
    playerthread.h

FORMS += \
        mainwindow.ui \
    settingpanel.ui \
    introductionpanel.ui \
    helppanel.ui \
    rankingpanel.ui \
    basicgame.ui

RESOURCES += \
    resources.qrc \
    mediafile.qrc

CONFIG +=C++11
