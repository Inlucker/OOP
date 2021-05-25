#ifndef QTFACTORY_H
#define QTFACTORY_H

#include "abstractfactory.h"

class QtFactory : AbstractFactory
{
public:
    //QtFactory() = default;
    //~QtFactory() = default;
    virtual unique_ptr<BaseDrawer> createGraphics() override;
};

#endif // QTFACTORY_H
