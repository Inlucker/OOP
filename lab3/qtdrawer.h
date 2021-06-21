#ifndef QTDRAWER_H
#define QTDRAWER_H

#include <QWidget>
#include <QPainter>
#include <memory>

using namespace std;

#include "basedrawer.h"

class QtDrawer : public BaseDrawer
{
public:
    QtDrawer();
    virtual ~QtDrawer() override;

    virtual void drawLine(const Point &p1, const Point &p2) override;
    virtual void setCanvas(shared_ptr<BaseCanvas> newCanvas) override;
    virtual void clear() override;
private:
    shared_ptr<QPainter> painter;
};

#endif // QTDRAWER_H
