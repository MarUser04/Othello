#-------------------------------------------------
#
# Project created by QtCreator 2017-11-24T07:20:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Othello
TEMPLATE = app


SOURCES += main.cpp \
    juego.cpp \
    tablero.cpp \
    tablerografico.cpp \
    ficha.cpp \
    menu.cpp \
    inteligenciaartificial.cpp \
    score.cpp

HEADERS  += \
    juego.h \
    tablero.h \
    tablerografico.h \
    ficha.h \
    menu.h \
    inteligenciaartificial.h \
    listasimpleenlazada.h \
    nodo.h \
    score.h

FORMS    += mainwindow.ui
