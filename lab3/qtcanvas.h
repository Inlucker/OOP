#ifndef QTCANVAS_H
#define QTCANVAS_H

#include <QWidget>
//#include <QPainter>
#include <memory>

using namespace std;

#include "basecanvas.h"

class QtCanvas : public BaseCanvas
{
public:
    QtCanvas();
    QtCanvas(shared_ptr<QPixmap> newPixmap);
    ~QtCanvas() = default;

    //virtual void drawLine(double x1, double y1, double x2, double y2) override;
    virtual void clear() override;

    shared_ptr<QPixmap> getPixMap() const;

private:
    //shared_ptr<QPainter> painter;
    shared_ptr<QPixmap> myPixmap;

};

#endif // QTCANVAS_H
