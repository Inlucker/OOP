#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "basemanager.h"

class SceneManager : BaseManager
{
public:
    SceneManager();
    ~SceneManager() = default;

    //void drawScene();
    //void clearScene();
    void addModel();
    void addCamera();
    void deleteModel();
    void deleteCamera();
    void useCamera();
};

#endif // SCENEMANAGER_H
