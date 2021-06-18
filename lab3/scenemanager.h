#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

//#include <QWidget>

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
    void clearScene();
    void clearObjects();
    shared_ptr<Scene> getScene() const;
    void addModel(shared_ptr<Model> new_model);
    void addCamera(shared_ptr<Camera> new_camera);
    //void deleteModel(const size_t modelId);
    //void deleteCamera(const size_t cameraId);
    void deleteObject(const size_t objId);
    void useCamera(shared_ptr<Camera> newCamera);

    void setDrawerScene(shared_ptr<BaseScene> newScene);

    //int method1(string str); //test
private:
    shared_ptr<Scene> scene;
    weak_ptr<Camera> curCamera;
    //shared_ptr<BaseVisitor> objectDrawer;
    shared_ptr<BaseScene> drawerScene;
};

#endif // SCENEMANAGER_H
