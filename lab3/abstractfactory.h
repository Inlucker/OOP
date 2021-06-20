#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <memory>

using namespace std;

class BaseDrawer;

class AbstractFactory
{
public:
    AbstractFactory() = default;
    virtual ~AbstractFactory() = 0;
    virtual unique_ptr<BaseDrawer> createGraphics() = 0;
};

#endif // ABSTRACTFACTORY_H
