CONFIG += testcase
TARGET = tst_qquickshadereffect
SOURCES += tst_qquickshadereffect.cpp

macx:CONFIG -= app_bundle

CONFIG += parallel_test
QT += core-private gui-private qml-private quick-private testlib
