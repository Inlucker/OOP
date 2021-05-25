#ifndef BASEDRAWER_H
#define BASEDRAWER_H

#include "point.h"

class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = 0;
    virtual void drawLine(const Point &p1, const Point &p2) = 0;
};

#endif // BASEDRAWER_H
