#include "model.h"

Model::Model()
{
    modelElements = shared_ptr<ModelElements>(new ModelElements());
}

void Model::transform()
{
    cout << "Model Transform method;" << endl;
    modelElements->transform();
}

bool Model::isVisible()
{
    cout << "Model isVisible method;" << endl;
    return true;
}

void Model::accept(shared_ptr<BaseVisitor> visitor)
{
    visitor->visit(*this);
}
