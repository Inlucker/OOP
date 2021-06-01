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
    //QtDrawer(shared_ptr<QPixmap> myPixMap);
    virtual ~QtDrawer() override;

    virtual void drawLine(const Point &p1, const Point &p2) override;
    virtual void clear() override;
    //virtual void setScene(shared_ptr<BaseScene> newScene) override;

private:
    //shared_ptr<QPainter> painter;
    //shared_ptr<QPixmap> myPixmap;
    //QPixmap *myPixMap;
};

#endif // QTDRAWER_H
