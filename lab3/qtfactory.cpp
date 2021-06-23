#include "qtfactory.h"

#include "qtdrawer.h"
#include "qtcanvas.h"

unique_ptr<BaseDrawer> QtFactory::createDrawer()
{
    return unique_ptr<BaseDrawer> (new QtDrawer());
}

/*unique_ptr<BaseCanvas> QtFactory::createCanvas()
{
    return unique_ptr<BaseCanvas> (new QtCanvas());
}*/
