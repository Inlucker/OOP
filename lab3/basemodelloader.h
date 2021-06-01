#ifndef BASEMODELLOADER_H
#define BASEMODELLOADER_H

#include <memory>

using namespace std;

class BaseFileLoader;
class Model;
class ModelDirector;

class BaseModelLoader
{
public:
    BaseModelLoader() = default;
    virtual ~BaseModelLoader() = 0;
    virtual shared_ptr<Model> loadModel(string fileName) = 0;
protected:
    shared_ptr<BaseFileLoader> fileLoader;
    //shared_ptr<ModelDirector> modelDirector;
};

#endif // BASEMODELLOADER_H
