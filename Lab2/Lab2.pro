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
    baseiterator.hpp \
    basevector.h \
    constiterator.h \
    constiterator.hpp \
    errors.h \
    iterator.h \
    iterator.hpp \
    vector.h \
    vector.hpp
