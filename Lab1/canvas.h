#ifndef CANVAS_H
#define CANVAS_H

#include "proection.h"
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
    Proection proection;

private:
    QPainter painter;

};

#endif // CANVAS_H
