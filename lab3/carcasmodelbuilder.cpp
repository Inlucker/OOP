#include "carcasmodelbuilder.h"
#include "model.h"

shared_ptr<Model> CarcasModelBuilder::createModel()
{
    if (this->isBuild())
        model = shared_ptr<Model>(new Model());

    return model;
}
bool CarcasModelBuilder::isBuild() const
{
    return nullptr != modelElements;
}

bool CarcasModelBuilder::build(shared_ptr<ifstream> file)
{
    //addPoints and addEdges by file info
    modelElements = make_shared<ModelElements>();
    return true;
}

bool CarcasModelBuilder::addPoint(const double &x, const double &y, const double &z)
{
    modelElements->addPoint(x, y, z);
    return true;
}

bool CarcasModelBuilder::addEdge(const int &p1, const int &p2)
{
    modelElements->addEdge(p1, p2);
    return true;
}
