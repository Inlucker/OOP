#ifndef QTDRAWER_H
#define QTDRAWER_H

#include "basedrawer.h"

class QtDrawer : public BaseDrawer
{
public:
    QtDrawer();
    virtual ~QtDrawer() override = default;

    virtual void drawLine(const Point &p1, const Point &p2) override;

private:
    //shared_ptr<Canvas> *canvas;
};

#endif // QTDRAWER_H
