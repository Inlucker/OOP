#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <memory>

using namespace std;

class BaseDrawer;
class BaseCanvas;

class AbstractFactory
{
public:
    AbstractFactory() = default;
    virtual ~AbstractFactory() = 0;
    virtual unique_ptr<BaseDrawer> createDrawer() = 0;
    virtual unique_ptr<BaseCanvas> createCanvas() = 0;
};

#endif // ABSTRACTFACTORY_H
