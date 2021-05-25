#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <memory>

using namespace std;

#include "basedrawer.h"

class AbstractFactory
{
public:
    //AbstractFactory() = default;
    //~AbstractFactory() = default;
    virtual unique_ptr<BaseDrawer> createGraphics() = 0;
};

#endif // ABSTRACTFACTORY_H
