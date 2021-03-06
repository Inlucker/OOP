#ifndef BASEVISITOR_H
#define BASEVISITOR_H

//#include "object.h"
#include "basedrawer.h"

class Model;
class Camera;
class Composite;

class BaseVisitor
{
public:
    BaseVisitor() = default;
    virtual ~BaseVisitor() = default; //Почему не = 0???

    //virtual void visit(const Object &obj) = 0;
    virtual void visit(const Model &obj) = 0;
    virtual void visit(const Camera &obj) = 0;
    virtual void visit(const Composite &comp) = 0;
};

#endif // BASEVISITOR_H
