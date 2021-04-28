TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        abstractiterator.cpp \
        basevector.cpp \
        main.cpp

HEADERS += \
    abstractiterator.h \
    baseiterator.h \
    basevector.h \
    constiterator.h \
    errors.h \
    iterator.h \
    vector.h
