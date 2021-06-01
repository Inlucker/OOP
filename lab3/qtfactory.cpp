#include "qtfactory.h"

#include "qtdrawer.h"

QtFactory::QtFactory()
{
    //myPixMap = shared_ptr<QPixmap>(new QPixmap());
}

/*QtFactory::QtFactory(shared_ptr<QPixmap> newPixMap) : myPixMap(newPixMap)
{

}*/

unique_ptr<BaseDrawer> QtFactory::createGraphics()
{
    return std::unique_ptr<BaseDrawer> (new QtDrawer());
}

/*void QtFactory::setScene(shared_ptr<QPixmap> newPixMap)
{
    myPixMap = newPixMap;
}*/

unique_ptr<AbstractFactory> QtFactory::getAbstractFactoryPtr()
{
    return unique_ptr<AbstractFactory>(this);
}
