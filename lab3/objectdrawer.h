#ifndef OBJECTDRAWER_H
#define OBJECTDRAWER_H

#include <memory>
#include <iostream>

using namespace std;

#include "basevisitor.h"
#include "basedrawer.h"

class ObjectDrawer : BaseVisitor
{
public:
    ObjectDrawer();

    virtual void visit(const Model &model) override;
private:
    shared_ptr<BaseDrawer> drawer;
};

#endif // OBJECTDRAWER_H
