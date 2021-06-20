#include "basedrawer.h"

BaseDrawer::BaseDrawer()
{
    canvas.reset();
}

BaseDrawer::~BaseDrawer()
{

}

void BaseDrawer::setCanvas(shared_ptr<BaseCanvas> newScene)
{
    this->canvas = newScene;
}
