#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <iostream>

using namespace std;

#include "qtscene.h"

class Canvas : public QWidget
{
public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas();

    void clean();

protected:
    void paintEvent(QPaintEvent *);

public:
    shared_ptr<QtScene> scene;

private:
    //QPainter *painter = nullptr;
    //QPixmap *canvasPixmap = nullptr;
    //QPen mainPen;

private:
    void setupScene();

};

#endif // CANVAS_H
