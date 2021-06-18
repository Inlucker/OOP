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
    ObjectDrawer(const weak_ptr<Camera> newCamera, const shared_ptr<BaseScene> scene);

    virtual void visit(const Model &model) override;
    virtual void visit(const Camera &camera) override;
    virtual void visit(const Composite &comp) override;

private:
    Point getProection(Point &_point);
    weak_ptr<Camera> curCamera;
};

#endif // OBJECTDRAWER_H
