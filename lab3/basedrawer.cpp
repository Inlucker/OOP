#include "basedrawer.h"

BaseDrawer::~BaseDrawer()
{

}

void BaseDrawer::setScene(shared_ptr<BaseScene> newScene)
{
    this->scene = newScene;
}
