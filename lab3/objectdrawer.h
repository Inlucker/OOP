#ifndef OBJECTDRAWER_H
#define OBJECTDRAWER_H

#include <memory>
#include <iostream>

using namespace std;

#include "basevisitor.h"

class Object;

class ObjectDrawer : public BaseVisitor
{
public:
    ObjectDrawer();
    ObjectDrawer(const shared_ptr<Camera> newCamera);

    virtual void visit(const Model &model) override;
    virtual void visit(const Camera &camera) override;

    //shared_ptr<BaseVisitor> getBaseVisitorPtr(); //РљРѕСЃС‚С‹Р»СЊ?
/*private:
    shared_ptr<BaseDrawer> drawer;*/

private:
    Point getProection(Point &_point);
    shared_ptr<Camera> curCamera;
};

#endif // OBJECTDRAWER_H
