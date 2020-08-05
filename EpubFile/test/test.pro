QT       -= core
QT       -= gui

TARGET = test
TEMPLATE = app
CONFIG   += console
CONFIG   -= app_bundle

DEFINES += EPUBFORMAT_USE_DYNAMIC_LIBRARY

CORE_ROOT_DIR = $$PWD/../..
PWD_ROOT_DIR = $$PWD
include($$CORE_ROOT_DIR/Common/base.pri)

DESTDIR = $$PWD_ROOT_DIR/build/$$CORE_BUILDS_PLATFORM_PREFIX/$$CORE_BUILDS_CONFIGURATION_PREFIX

ADD_DEPENDENCY(EpubFile, kernel)

SOURCES += main.cpp
