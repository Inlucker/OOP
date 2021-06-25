#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include <memory>

using namespace std;

#include "basemanager.h"

class BaseModelLoader;
class Model;

class LoadManager : public BaseManager
{
public:
    LoadManager();
    ~LoadManager() = default;

    shared_ptr<Model> loadModel(string fileName);
    shared_ptr<Model> loadModel(string fileName, string modelName);
private:
    shared_ptr<BaseModelLoader> modelLoader;
};

#endif // LOADMANAGER_H
