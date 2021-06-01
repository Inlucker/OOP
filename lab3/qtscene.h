#ifndef QTSCENE_H
#define QTSCENE_H

#include <QWidget>
#include <QPainter>
#include <memory>

using namespace std;

#include "basescene.h"

class QtScene : public BaseScene
{
public:
    QtScene();
    QtScene(shared_ptr<QPixmap> newPixmap);
    ~QtScene() = default;

    virtual void drawLine(double x1, double y1, double x2, double y2);

    //shared_ptr<QPainter>getPainter();
    shared_ptr<QPixmap>getPixMap();

private:
    shared_ptr<QPainter> painter;
    shared_ptr<QPixmap> myPixmap;

};

#endif // QTSCENE_H
