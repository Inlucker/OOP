QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basecommand.cpp \
    basemanager.cpp \
    basevisitor.cpp \
    camera.cpp \
    composite.cpp \
    edge.cpp \
    facade.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    modelelements.cpp \
    object.cpp \
    point.cpp \
    scene.cpp \
    scenemanager.cpp

HEADERS += \
    basecommand.h \
    basemanager.h \
    basevisitor.h \
    camera.h \
    composite.h \
    edge.h \
    facade.h \
    mainwindow.h \
    model.h \
    modelelements.h \
    object.h \
    point.h \
    scene.h \
    scenemanager.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target