#-------------------------------------------------
#
# Project created by QtCreator 2015-03-16T16:08:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = trab1
TEMPLATE = app


SOURCES += main.cpp\
        mainWindow.cpp \
    objects/coordinate.cpp \
    objects/displayFileObject.cpp \
    displayFile.cpp \
    qviewport.cpp \
    main.cpp

HEADERS  += mainWindow.h \
    objects/coordinate.h \
    objects/displayFileObject.h \
    objects/geometricObjects.h \
    displayFile.h \
    mainwindow.h \
    qviewport.h

FORMS    += mainWindow.ui
