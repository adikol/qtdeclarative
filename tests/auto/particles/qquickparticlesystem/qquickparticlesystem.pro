CONFIG += testcase
TARGET = tst_qquickparticlesystem
SOURCES += tst_qquickparticlesystem.cpp
macx:CONFIG -= app_bundle

include (../../shared/util.pri)
TESTDATA = data/*

QT += core-private gui-private v8-private qml-private quick-private testlib

