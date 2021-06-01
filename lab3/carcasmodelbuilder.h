#ifndef CARCASMODELBUILDER_H
#define CARCASMODELBUILDER_H

#include <fstream>

using namespace std;

#include "basemodelbuilder.h"

class ModelElements;

class CarcasModelBuilder : public BaseModelBuilder
{
public:
    CarcasModelBuilder() = default;
    virtual ~CarcasModelBuilder() = default;

    virtual bool isBuild() const override;

    bool addPoint(const double &x, const double &y, const double &z) override;
    bool addEdge(const int &p1, const int &p2) override;

    virtual bool build() override;

protected:
    virtual shared_ptr<Model> createModel() override;

private:
    std::shared_ptr<ModelElements> modelElements;
};



#endif // CARCASMODELBUILDER_H
