#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    //mainPen = QPen(Qt::black);
    scene = shared_ptr<QtScene>(new QtScene());
    setStyleSheet("background-color:white;");

    clean();
}

Canvas::~Canvas()
{
    //delete painter;
    //delete canvasPixmap;
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter pixmap_painter(this);

    pixmap_painter.drawPixmap(0, 0, *scene->getPixMap());
    //pixmap_painter.drawPixmap(0, 0, *canvasPixmap);
}

void Canvas::clean()
{
    /*if (painter)
        delete painter;*/

    /*if (canvasPixmap)
        delete canvasPixmap;
    canvasPixmap = new QPixmap(2000, 2000);
    canvasPixmap->fill(QColor(0, 0, 0, 0));*/

    /*painter = new QPainter(canvasPixmap);
    painter->setPen(mainPen);*/

    update();
}
