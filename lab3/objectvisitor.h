#ifndef OBJECTVISITOR_H
#define OBJECTVISITOR_H

#include <memory>
#include <iostream>

using namespace std;

#include "basevisitor.h"
#include "basedrawer.h"

class ObjectVisitor : public BaseVisitor
{
public:
    ObjectVisitor();

    virtual void visit(const Model &model) override;
    virtual void visit(const Camera &camera) override;

    //shared_ptr<BaseVisitor> getBaseVisitorPtr(); //Костыль?
private:
    shared_ptr<BaseDrawer> drawer;
};

#endif // OBJECTVISITOR_H
