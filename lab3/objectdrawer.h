#ifndef OBJECTDRAWER_H
#define OBJECTDRAWER_H

#include <memory>
#include <iostream>

using namespace std;

#include "basevisitor.h"

class ObjectDrawer : public BaseVisitor
{
public:
    ObjectDrawer();

    virtual void visit(const Model &model) override;
    virtual void visit(const Camera &camera) override;

    //shared_ptr<BaseVisitor> getBaseVisitorPtr(); //РљРѕСЃС‚С‹Р»СЊ?
/*private:
    shared_ptr<BaseDrawer> drawer;*/
};

#endif // OBJECTDRAWER_H
