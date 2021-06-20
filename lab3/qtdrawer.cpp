#include "qtdrawer.h"
#include "qtcanvas.h"
#include "errors.h"

#include "scenemanagercreator.h"
#include "scenemanager.h"

QtDrawer::QtDrawer()
{
    //canvas.reset(); //переместил в BaseDrawer
}

QtDrawer::~QtDrawer()
{

}

void QtDrawer::drawLine(const Point &p1, const Point &p2)
{
    if (canvas)
        this->canvas->drawLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
    else
    {
        time_t t_time = time(NULL);
        throw NoCanvasError("No active canvas", __FILE__, __LINE__, ctime(&t_time));
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
