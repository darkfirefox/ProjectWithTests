#QT -= gui

#CONFIG += qt console warn_on depend_includepath testcase
#CONFIG -= app_bundle

#TEMPLATE = app

TARGET = tst-translateMVC-sailfish
CONFIG+=sailfishapp c++11 qt

SOURCES +=  \
    main.cpp \
    testservicehistory.cpp \
    fakeservicehistory.cpp
INCLUDEPATH +=../translateMVC/
include(../translateMVC/translateMVC.pri)

HEADERS += \
    testservicehistory.h \
    fakeservicehistory.h
QT += testlib sql
TARGETPATH = /usr/bin
target.path = $$TARGETPATH

DEPLOYMENT_PATH = /usr/share/$$TARGET
qml.path = $$DEPLOYMENT_PATH

extra.path = $$DEPLOYMENT_PATH
extra.files = runTestsOnDevice.sh
