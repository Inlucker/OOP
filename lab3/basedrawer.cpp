#include "basedrawer.h"

BaseDrawer::~BaseDrawer()
{

}

void BaseDrawer::setCanvas(shared_ptr<BaseCanvas> newScene)
{
    this->canvas = newScene;
}
