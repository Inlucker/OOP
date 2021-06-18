#include "qtdrawer.h"
#include "qtcanvas.h"
#include "errors.h"

QtDrawer::QtDrawer()
{
    /*myPixmap = shared_ptr<QPixmap>(new QPixmap(2000, 2000));
    myPixmap->fill(QColor(0, 0, 0, 0));

    painter = shared_ptr<QPainter>(new QPainter(&*myPixmap));
    painter->setPen(Qt::black);*/
    canvas = shared_ptr<BaseCanvas> (new QtCanvas());
}

/*QtDrawer::QtDrawer(shared_ptr<QPixmap> newPixMap)
{
    myPixmap = newPixMap;
    myPixmap->fill(QColor(0, 0, 0, 0));

    painter = shared_ptr<QPainter>(new QPainter(&*myPixmap));
    painter->setPen(Qt::black);
}*/

QtDrawer::~QtDrawer()
{
    //delete myPixMap;
}

void QtDrawer::drawLine(const Point &p1, const Point &p2)
{
    //canvas->drawLine(p1, p2);
    if (canvas)
        this->canvas->drawLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
    else
    {
        time_t t_time = time(NULL);
        throw NoCameraError("No active camera", __FILE__, __LINE__, ctime(&t_time));
    }
}

void QtDrawer::clear()
{
    this->canvas->clear();
}

/*void QtDrawer::setScene(shared_ptr<BaseScene> newScene)
{
    this->scene = newScene;
}*/
