#-------------------------------------------------
#
# Project created by QtCreator 2015-05-29T19:57:49
#
#-------------------------------------------------

QT       -= core gui

TARGET = PVRTexLibWrapper
TEMPLATE = lib

DEFINES += PVRTEXLIBWRAPPER_LIBRARY

INCLUDEPATH += $$PWD/PVRTexTool/Library/Include

SOURCES += \
    PVRTexLibWrapper.cpp \
    Stdafx.cpp

HEADERS += \
    PVRTexLibWrapper.h \
    Stdafx.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
