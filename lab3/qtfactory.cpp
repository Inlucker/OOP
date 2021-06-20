#include "qtfactory.h"

#include "qtdrawer.h"

unique_ptr<BaseDrawer> QtFactory::createGraphics()
{
    return std::unique_ptr<BaseDrawer> (new QtDrawer());
}
