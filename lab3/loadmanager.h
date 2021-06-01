#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include <memory>

using namespace std;

#include "basemanager.h"

class BaseModelLoader; //ToDo

class LoadManager : public BaseManager
{
public:
    LoadManager();
    ~LoadManager() = default;

    void loadModel(string fileName);
private:
    shared_ptr<BaseModelLoader> modelLoader;
};

#endif // LOADMANAGER_H
