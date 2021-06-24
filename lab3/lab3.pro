QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractfactory.cpp \
    abstractiterator.cpp \
    basecanvas.cpp \
    basecommand.cpp \
    basedrawer.cpp \
    basefileloader.cpp \
    basemanager.cpp \
    basemodelbuilder.cpp \
    basemodelloader.cpp \
    basevisitor.cpp \
    camera.cpp \
    canvas.cpp \
    carcasmodelbuilder.cpp \
    caretaker.cpp \
    commands.cpp \
    composite.cpp \
    edge.cpp \
    errors.cpp \
    facade.cpp \
    fileloader.cpp \
    graphicsolution.cpp \
    loadmanager.cpp \
    loadmanagercreator.cpp \
    main.cpp \
    mainwindow.cpp \
    memento.cpp \
    model.cpp \
    modeldirector.cpp \
    modelelements.cpp \
    modelloader.cpp \
    object.cpp \
    objectvisitor.cpp \
    point.cpp \
    qtcanvas.cpp \
    qtdrawer.cpp \
    qtfactory.cpp \
    scene.cpp \
    scenemanager.cpp \
    scenemanagercreator.cpp \
    transformmanager.cpp \
    transformmanagercreator.cpp

HEADERS += \
    abstractfactory.h \
    abstractiterator.h \
    basecanvas.h \
    basecommand.h \
    basedrawer.h \
    basefileloader.h \
    baseiterator.h \
    baseiterator.hpp \
    basemanager.h \
    basemodelbuilder.h \
    basemodelloader.h \
    basevisitor.h \
    camera.h \
    canvas.h \
    carcasmodelbuilder.h \
    caretaker.h \
    commands.h \
    composite.h \
    constiterator.h \
    constiterator.hpp \
    edge.h \
    errors.h \
    facade.h \
    fileloader.h \
    graphicsolution.h \
    iterator.h \
    iterator.hpp \
    loadmanager.h \
    loadmanagercreator.h \
    mainwindow.h \
    memento.h \
    model.h \
    modeldirector.h \
    modelelements.h \
    modelloader.h \
    object.h \
    objectvisitor.h \
    point.h \
    qtcanvas.h \
    qtdrawer.h \
    qtfactory.h \
    scene.h \
    scenemanager.h \
    scenemanagercreator.h \
    transformmanager.h \
    transformmanagercreator.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
