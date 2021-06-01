#include "basevisitor.h"

/*BaseVisitor::~BaseVisitor()
{

}*/

void BaseVisitor::setScene(shared_ptr<BaseScene> newScene)
{
    drawer->setScene(newScene);
}
