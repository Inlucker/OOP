#ifndef MODEL_H
#define MODEL_H

#include "object.h"

#include "modelelements.h"
//#include "basevisitor.h"
#include "objectvisitor.h"

//class ObjectVisitor;

class Model : public Object
{
public:
    //Model() = default;
    Model();
    Model(string new_name);
    Model(const Model &model); //copy
    Model(shared_ptr<ModelElements> modelElements);
    ~Model() = default;

    virtual void transform(const Point move, const Point scale, const Point rotate) override;
    virtual bool isVisible() const override;
    virtual void accept(shared_ptr<BaseVisitor> visitor) override;

    virtual shared_ptr<Object> clone() override;

private:
    shared_ptr<ModelElements> modelElements;

private:
    const shared_ptr<ModelElements> getElements() const;
    //friend ObjectVisitor;
    friend void ObjectVisitor::visit(const Model &model);
};

#endif // MODEL_H
