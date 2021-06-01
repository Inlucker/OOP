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

    /*float x_center = width() / 2;
    float y_center = height() / 2;
    pixmap_painter.translate(x_center, y_center);*/

    pixmap_painter.drawPixmap(0, 0, *scene->getPixMap());
    //pixmap_painter.drawPixmap(0, 0, *canvasPixmap);
}

void Canvas::clean()
{
    scene->getPixMap()->fill(QColor(0, 0, 0, 0));

    update();
}
