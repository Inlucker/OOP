#ifndef BASEDRAWER_H
#define BASEDRAWER_H

#include <memory>

using namespace std;

class Point;
class BaseCanvas;
//#include "point.h"
//#include "basecanvas.h"

class BaseDrawer
{
public:
    //BaseDrawer() = default;
    BaseDrawer();
    virtual ~BaseDrawer() = 0;
    virtual void drawLine(const Point &p1, const Point &p2) = 0;
    virtual void setCanvas(shared_ptr<BaseCanvas> newCanvas);
    virtual void clear() = 0;

protected:
    shared_ptr<BaseCanvas> canvas;
};

#endif // BASEDRAWER_H
