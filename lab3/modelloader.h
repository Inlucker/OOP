#ifndef MODELLOADER_H
#define MODELLOADER_H

#include "basemodelloader.h"

//class Model;

class ModelLoader : public BaseModelLoader
{
public:
    ModelLoader();
    virtual ~ModelLoader() = default;
    shared_ptr<Model> loadModel(string fileName) override;
};

#endif // MODELLOADER_H
