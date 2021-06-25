#include "loadmanager.h"

#include "modelloader.h"

#include "model.h"

LoadManager::LoadManager()
{
    modelLoader = shared_ptr<BaseModelLoader>(new ModelLoader());
}

shared_ptr<Model> LoadManager::loadModel(string fileName)
{
    //createBuilder?
    return modelLoader->loadModel(fileName);
}

shared_ptr<Model> LoadManager::loadModel(string fileName, string modelName)
{
    shared_ptr<Model> newModel = modelLoader->loadModel(fileName);
    newModel->setName(modelName);
    return newModel;
}
