#ifndef BASESCENE_H
#define BASESCENE_H

class BaseScene
{
public:
    BaseScene() = default;
    virtual ~BaseScene() = 0;

    virtual void drawLine(double x1, double y1, double x2, double y2) = 0;
};

#endif // BASESCENE_H
