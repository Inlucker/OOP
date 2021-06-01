#include "loadmanager.h"

#include "modelloader.h"

LoadManager::LoadManager()
{
    modelLoader = shared_ptr<BaseModelLoader>(new ModelLoader());
}

shared_ptr<Model> LoadManager::loadModel(string fileName)
{
    return modelLoader->loadModel(fileName);
}
