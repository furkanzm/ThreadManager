TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++0x -pthread 
LIBS += -pthread
SOURCES += \
        main.cpp \
        threadmanager.cpp

HEADERS += \
    threadmanager.h
