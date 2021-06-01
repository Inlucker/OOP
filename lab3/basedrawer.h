#ifndef BASEDRAWER_H
#define BASEDRAWER_H

#include <memory>

using namespace std;

#include "point.h"
#include "basescene.h"

class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = 0;
    virtual void drawLine(const Point &p1, const Point &p2) = 0;
    virtual void setScene(shared_ptr<BaseScene> newScene);

protected:
    shared_ptr<BaseScene> scene;
};

#endif // BASEDRAWER_H
