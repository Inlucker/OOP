#include "model.h"
#include "basevisitor.h"

Model::Model()
{
    modelElements = shared_ptr<ModelElements>(new ModelElements());
}

Model::Model(Model &model)
{
    modelElements = shared_ptr<ModelElements>(new ModelElements(*model.getElements()));
}

Model::Model(shared_ptr<ModelElements> modelElements) : modelElements(modelElements)
{

}

void Model::transform(const Point move, const Point scale, const Point rotate)
{
    modelElements->transform(move, scale, rotate);
}

bool Model::isVisible() const
{
    return true;
}

void Model::accept(shared_ptr<BaseVisitor> visitor)
{
    //if (isVisible())
    visitor->visit(*this);
}

shared_ptr<Object> Model::clone()
{
    return shared_ptr<Object>(new Model(*this));
}

const shared_ptr<ModelElements> Model::getElements() const
{
    return modelElements;
}
