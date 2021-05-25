#include "qtfactory.h"

#include "qtdrawer.h"

/*QtFactory::QtFactory()
{

}*/

unique_ptr<BaseDrawer> QtFactory::createGraphics()
{
    return std::unique_ptr<BaseDrawer> (new QtDrawer());
}

unique_ptr<AbstractFactory> QtFactory::getAbstractFactoryPtr()
{
    return unique_ptr<AbstractFactory>(this);
}
