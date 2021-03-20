QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    action_funcs.cpp \
    canvas.cpp \
    edge.cpp \
    edges_arr.cpp \
    entry_point.cpp \
    file_stream.cpp \
    main.cpp \
    mainwindow.cpp \
    model_funcs.cpp \
    point.cpp \
    point_2d.cpp \
    points_arr.cpp \
    points_arr_2d.cpp \
    proection.cpp

HEADERS += \
    action.h \
    action_funcs.h \
    canvas.h \
    defines.h \
    edge.h \
    edges_arr.h \
    entry_point.h \
    error_codes.h \
    file_stream.h \
    mainwindow.h \
    model_funcs.h \
    point.h \
    point_2d.h \
    points_arr.h \
    points_arr_2d.h \
    proection.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
