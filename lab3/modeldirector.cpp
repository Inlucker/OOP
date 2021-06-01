#include "modeldirector.h"

/*shared_ptr<Model> ModelDirector::create(shared_ptr<BaseModelBuilder> builder, shared_ptr<ifstream> &file)
{
    if (builder->build(file)) return builder->getModel();

    return shared_ptr<Model>();
}*/

shared_ptr<Model> ModelDirector::create(shared_ptr<BaseModelBuilder> builder, shared_ptr<ifstream> file)
{

    if (builder->build(file)) return builder->getModel();

    return shared_ptr<Model>();
}
