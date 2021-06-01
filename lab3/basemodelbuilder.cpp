#include "basemodelbuilder.h"

shared_ptr<Model> BaseModelBuilder::getModel()
{
    if (!model)
        model = createModel();

    return model;
}
