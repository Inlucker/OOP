#ifndef QTFACTORY_H
#define QTFACTORY_H

#include "abstractfactory.h"

#include <QWidget>
//#include <QPainter>
#include <memory>

using namespace std;


class QtFactory : public AbstractFactory
{
public:
    QtFactory();
    //QtFactory() = default;
    //~QtFactory() = default;
    //explicit QtFactory(shared_ptr<QPixmap> newPixMap);
    virtual unique_ptr<BaseDrawer> createGraphics() override;

    //void setScene(shared_ptr<QPixmap> newPixMap);

    unique_ptr<AbstractFactory> getAbstractFactoryPtr(); // no need
private:
    //shared_ptr<QPixmap> myPixMap;
};

#endif // QTFACTORY_H
