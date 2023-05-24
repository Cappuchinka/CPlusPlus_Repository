QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_replacesynonym.cpp

SUBDIRS += \
    ../Task4_6/Task4_6.pro \
