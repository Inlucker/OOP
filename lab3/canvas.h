#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <iostream>

using namespace std;

#include "qtdrawer.h"
#include "qtcanvas.h"

class Canvas : public QWidget
{
public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas();

    void clean();

protected:
    void paintEvent(QPaintEvent *);

public:
    shared_ptr<BaseDrawer> drawer;
    shared_ptr<BaseCanvas> canvas;
    //shared_ptr<QtCanvas> qtCanvas;

private:
    //QPainter *painter = nullptr;
    //QPixmap *canvasPixmap = nullptr;
    //QPen mainPen;

private:
    void setupScene();

};

#endif // CANVAS_H
