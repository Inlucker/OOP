#include "qtcanvas.h"

QtCanvas::QtCanvas()
{
    myPixmap = shared_ptr<QPixmap>(new QPixmap(2000, 2000));
    myPixmap->fill(QColor(0, 0, 0, 0));

    //painter.reset();
}

QtCanvas::QtCanvas(shared_ptr<QPixmap> newPixmap)
{
    myPixmap = newPixmap;
    myPixmap->fill(QColor(0, 0, 0, 0));

    //painter.reset();
}

/*void QtCanvas::drawLine(double x1, double y1, double x2, double y2)
{
    painter = shared_ptr<QPainter>(new QPainter(&*myPixmap));
    painter->setPen(Qt::black);
    painter->drawLine(x1, y1, x2, y2);
    painter->end();
}*/

void QtCanvas::clear()
{
    myPixmap->fill();
}

shared_ptr<QPixmap> QtCanvas::getPixMap() const
{
    return myPixmap;
}
