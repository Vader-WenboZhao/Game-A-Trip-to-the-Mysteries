#-------------------------------------------------
#
# Project created by QtCreator 2014-02-18T17:42:36
#
#-------------------------------------------------

QT       += core gui
QT += multimedia
CONFIG+=resources_big
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = A_Trip_to_the_Mysteries
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
        mainwindow.cpp \
    qgameelement.cpp \
    qguide.cpp \
    qgameboard.cpp \
    qbuffinvcb.cpp \
    qbuffaddscore.cpp \
    qbuff.cpp \
    qbuffdestroy.cpp \
    qmeteor.cpp \
    qbuffice.cpp \
    qfairy.cpp \
    qstone.cpp \
    qintroduction.cpp

HEADERS  += mainwindow.h \
    qgameelement.h \
    qguide.h \
    qgameboard.h \
    qbuffinvcb.h \
    qbuffaddscore.h \
    qbuff.h \
    qbuffdestroy.h \
    qmeteor.h \
    qbuffIce.h \
    qfairy.h \
    qstone.h \
    qintroduction.h

RESOURCES += \
    A_Trip_to_the_Mysteries.qrc

DISTFILES +=

RC_FILE = myicon.rc
