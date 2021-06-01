#include "loadmanager.h"

#include "modelloader.h"

LoadManager::LoadManager()
{
    modelLoader = shared_ptr<BaseModelLoader>(new ModelLoader());
}

void LoadManager::loadModel(string fileName)
{
    modelLoader->loadModel(fileName);
}
