CONFIG += testcase
TARGET = tst_qquickellipseextruder
SOURCES += tst_qquickellipseextruder.cpp
macx:CONFIG -= app_bundle

include (../../shared/util.pri)
TESTDATA = data/*

QT += core-private gui-private v8-private qml-private quick-private testlib

