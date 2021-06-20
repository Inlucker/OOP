#ifndef MODELDIRECTOR_H
#define MODELDIRECTOR_H

#include <fstream>
#include <memory>

using namespace std;

//#include "basemodelbuilder.h"
class Model;
class BaseModelBuilder;

class ModelDirector
{
public:
    ModelDirector() = default;
    ~ModelDirector() = default;

    shared_ptr<Model> create(shared_ptr<BaseModelBuilder> builder, shared_ptr<ifstream> file);
};

#endif // MODELDIRECTOR_H
