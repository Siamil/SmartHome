#-------------------------------------------------
#
# Project created by QtCreator 2017-11-11T13:03:23
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartHome
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    light.cpp \
    heat.cpp \
    blind.cpp \
    house.cpp \
    window.cpp \
    room.cpp \
    blindui.cpp \
    windowui.cpp \
    kitchen.cpp \
    bedroom.cpp \
    hall.cpp \
    kitchenui.cpp \
    houseui.cpp \
    hallui.cpp \
    bedroomui.cpp \
    heatui.cpp \
    door.cpp \
    doorui.cpp \
    server.cpp \
    client.cpp \
    lightui.cpp

HEADERS += \
        mainwindow.h \
    light.h \
    heat.h \
    blind.h \
    house.h \
    window.h \
    room.h \
    blindui.h \
    windowui.h \
    kitchen.h \
    bedroom.h \
    hall.h \
    kitchenui.h \
    houseui.h \
    hallui.h \
    bedroomui.h \
    heatui.h \
    door.h \
    doorui.h \
    server.h \
    client.h \
    lightui.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    rscr.qrc
