#ifndef BASEDRAWER_H
#define BASEDRAWER_H

#include <memory>

using namespace std;

#include "point.h"
#include "basecanvas.h"

class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = 0;
    virtual void drawLine(const Point &p1, const Point &p2) = 0;
    virtual void setCanvas(shared_ptr<BaseCanvas> newScene);
    virtual void clear() = 0;

protected:
    shared_ptr<BaseCanvas> canvas;
};

#endif // BASEDRAWER_H
