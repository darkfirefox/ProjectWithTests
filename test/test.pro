QT += testlib
#QT -= gui

#CONFIG += qt console warn_on depend_includepath testcase
#CONFIG -= app_bundle

#TEMPLATE = app

TARGET = SailfishProjectTest
CONFIG+=sailfishapp c++11 qt

SOURCES +=  \
    main.cpp \
    testservicehistory.cpp
INCLUDEPATH +=../translateMVC/
include(../translateMVC/translateMVC.pri)

HEADERS += \
    testservicehistory.h
