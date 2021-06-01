#ifndef SCENEMANAGERCREATOR_H
#define SCENEMANAGERCREATOR_H

#include <memory>

using namespace std;

//#include "scenemanager.h"

class SceneManager;

class SceneManagerCreator
{
public:
    SceneManagerCreator() = default;
    ~SceneManagerCreator() = default;

    shared_ptr<SceneManager> getManager();

private:
    shared_ptr<SceneManager> createManager();

    shared_ptr<SceneManager> manager;
};

#endif // SCENEMANAGERCREATOR_H
