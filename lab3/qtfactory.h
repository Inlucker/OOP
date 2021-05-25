#ifndef QTFACTORY_H
#define QTFACTORY_H

#include "abstractfactory.h"

class QtFactory : public AbstractFactory
{
public:
    //QtFactory() = default;
    //~QtFactory() = default;
    virtual unique_ptr<BaseDrawer> createGraphics() override;

    unique_ptr<AbstractFactory> getAbstractFactoryPtr(); // no need
};

#endif // QTFACTORY_H
