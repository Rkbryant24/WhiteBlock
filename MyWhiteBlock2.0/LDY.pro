#-------------------------------------------------
#
# Project created by QtCreator 2022-05-04T13:53:31
#
#-------------------------------------------------

QT       += core gui multimedia 3dinput

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LDY
TEMPLATE = app
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    login.cpp \
    start.cpp \
    regist.cpp \
    end.cpp \
    game_widget.cpp \
    blockdata.cpp \
    gamehall.cpp \
    settings.cpp

HEADERS += \
    login.h \
    start.h \
    regist.h \
    end.h \
    game_widget.h \
    blockdata.h \
    gamehall.h \
    settings.h

FORMS += \
    login.ui \
    start.ui \
    regist.ui \
    end.ui \
    game_widget.ui \
    gamehall.ui \
    settings.ui

RESOURCES += \
    resources.qrc \
    block.qrc

