CONFIG += testcase
TARGET = tst_qquickgroupgoal
SOURCES += tst_qquickgroupgoal.cpp
macx:CONFIG -= app_bundle

include (../../shared/util.pri)
TESTDATA = data/*

QT += core-private gui-private v8-private qml-private testlib

