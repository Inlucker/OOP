QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractfactory.cpp \
    basecommand.cpp \
    basedrawer.cpp \
    basefileloader.cpp \
    basemanager.cpp \
    basemodelbuilder.cpp \
    basemodelloader.cpp \
    basescene.cpp \
    basevisitor.cpp \
    camera.cpp \
    canvas.cpp \
    carcasmodelbuilder.cpp \
    commands.cpp \
    composite.cpp \
    edge.cpp \
    facade.cpp \
    fileloader.cpp \
    graphicsolution.cpp \
    loadmanager.cpp \
    loadmanagercreator.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    modeldirector.cpp \
    modelelements.cpp \
    modelloader.cpp \
    object.cpp \
    objectdrawer.cpp \
    point.cpp \
    qtdrawer.cpp \
    qtfactory.cpp \
    qtscene.cpp \
    scene.cpp \
    scenemanager.cpp \
    scenemanagercreator.cpp \
    transformmanager.cpp \
    transformmanagercreator.cpp

HEADERS += \
    abstractfactory.h \
    basecommand.h \
    basedrawer.h \
    basefileloader.h \
    basemanager.h \
    basemodelbuilder.h \
    basemodelloader.h \
    basescene.h \
    basevisitor.h \
    camera.h \
    canvas.h \
    carcasmodelbuilder.h \
    commands.h \
    composite.h \
    edge.h \
    facade.h \
    fileloader.h \
    graphicsolution.h \
    loadmanager.h \
    loadmanagercreator.h \
    mainwindow.h \
    model.h \
    modeldirector.h \
    modelelements.h \
    modelloader.h \
    object.h \
    objectdrawer.h \
    point.h \
    qtdrawer.h \
    qtfactory.h \
    qtscene.h \
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
