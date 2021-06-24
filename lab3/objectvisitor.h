#ifndef OBJECTVISITOR_H
#define OBJECTVISITOR_H

#include <memory>
#include <iostream>

using namespace std;

#include "basevisitor.h"

class Object;

class ObjectVisitor : public BaseVisitor
{
public:
    ObjectVisitor();
    ObjectVisitor(shared_ptr<BaseDrawer> newDrawer, shared_ptr<Camera> newCamera);

    virtual void visit(const Model &model) override;
    virtual void visit(const Camera &camera) override;
    virtual void visit(const Composite &comp) override;

private:
    Point getProection(Point &_point, Point cameraPosition, Point angles);

private:
    shared_ptr<BaseDrawer> drawer;
    shared_ptr<Camera> curCamera;
};

#endif // OBJECTVISITOR_H
