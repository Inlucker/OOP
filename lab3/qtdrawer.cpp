#include "qtdrawer.h"
#include "qtcanvas.h"
#include "errors.h"

#include "scenemanagercreator.h"
#include "scenemanager.h"

QtDrawer::QtDrawer()
{
    //canvas.reset(); //переместил в BaseDrawer
    //painter.reset();
    painter = shared_ptr<QPainter>(new QPainter());
}

QtDrawer::~QtDrawer()
{
    if (painter->isActive())
        painter->end();
}

void QtDrawer::drawLine(const Point &p1, const Point &p2)
{
    if (canvas)
    {
        //this->canvas->drawLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
        //shared_ptr<QtCanvas> myPixmap = dynamic_pointer_cast<QtCanvas>(canvas);
        //painter = shared_ptr<QPainter>(new QPainter(&*myPixmap->getPixMap()));
        //painter->setPen(Qt::black);
        painter->drawLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
        //painter->end();
    }
    else
    {
        time_t t_time = time(NULL);
        throw NoCanvasError("No active canvas", __FILE__, __LINE__, ctime(&t_time));
    }
}

void QtDrawer::setCanvas(shared_ptr<BaseCanvas> newCanvas)
{
    if (painter->isActive())
        painter->end();
    shared_ptr<QtCanvas> qtCanvas = dynamic_pointer_cast<QtCanvas>(newCanvas);
    if (!qtCanvas)
    {
        time_t t_time = time(NULL);
        throw SetCanvasError("Trying to set wrong canvas", __FILE__, __LINE__, ctime(&t_time));
    }
    else
    {
        canvas = newCanvas;
        painter = shared_ptr<QPainter>(new QPainter(&*qtCanvas->getPixMap()));
        painter->setPen(Qt::black);
        //painter->setPen(Qt::red);
    }
}

void QtDrawer::clear()
{
    if (canvas)
        this->canvas->clear();
    else
    {
        time_t t_time = time(NULL);
        throw NoCanvasError("No active canvas", __FILE__, __LINE__, ctime(&t_time));
    }
}
