#ifndef QTFACTORY_H
#define QTFACTORY_H

#include "abstractfactory.h"

class QtFactory : AbstractFactory
{
public:
    //QtFactory() = default;
    //~QtFactory() = default;
    virtual unique_ptr<BaseDrawer> createGraphics() override;

    unique_ptr<AbstractFactory> getAbstractFactoryPtr();
};

#endif // QTFACTORY_H
