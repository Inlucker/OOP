#ifndef CANVAS_H
#define CANVAS_H

#include "model_funcs.h"
#include <QWidget>
#include <QPainter>
#include <iostream>

class Canvas : public QWidget
{
public:
    Canvas();
    ~Canvas();

protected:
    void paintEvent(QPaintEvent *);

public:
    Model model;

private:
    QPainter painter;

};

#endif // CANVAS_H
