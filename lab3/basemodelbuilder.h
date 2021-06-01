#ifndef BASEMODELBUILDER_H
#define BASEMODELBUILDER_H

#include <memory>

using namespace std;

class Model;

class BaseModelBuilder
{
public:
    BaseModelBuilder() = default;
    virtual ~BaseModelBuilder() = default;
    virtual bool addPoint(const double &x, const double &y, const double &z) = 0;
    virtual bool addEdge(const int &p1, const int &p2) = 0;
    virtual bool build() = 0;
    virtual bool isBuild() const = 0;
    shared_ptr<Model> getModel();

protected:
    virtual shared_ptr<Model> createModel() = 0;

    shared_ptr<Model> model;
};

#endif // BASEMODELBUILDER_H
