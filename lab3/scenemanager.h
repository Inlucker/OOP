#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QWidget>

#include "basemanager.h"
#include "scene.h"
#include "model.h"
#include "camera.h"
#include "objectdrawer.h"

class SceneManager : public BaseManager
{
public:
    SceneManager();
    ~SceneManager() = default;

    void drawScene();
    //void clearScene();
    void addModel(shared_ptr<Model> new_model);
    void addCamera(shared_ptr<Camera> new_camera);
    void deleteModel(const size_t model_id);
    void deleteCamera(const size_t camera_id);
    //void useCamera(shared_ptr<Camera> new_camera);

    void setDrawerScene(shared_ptr<BaseScene> newScene);

    //int method1(string str); //test
private:
    unique_ptr<Scene> scene;
    shared_ptr<BaseVisitor> objectDrawer;
};

#endif // SCENEMANAGER_H
