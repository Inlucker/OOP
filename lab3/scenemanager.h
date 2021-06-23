#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "basemanager.h"
#include "scene.h"
#include "model.h"
#include "camera.h"
#include "objectvisitor.h"

class SceneManager : public BaseManager
{
public:
    SceneManager();
    ~SceneManager() = default;

    void clearCanvas();
    void drawScene();
    void clearObjects();
    shared_ptr<Scene> getScene() const;
    void addModel(shared_ptr<Model> new_model);
    void addCamera(shared_ptr<Camera> new_camera);
    void deleteObject(const size_t objId);
    void useCamera(shared_ptr<Camera> newCamera);
    weak_ptr<Camera> getCamera() const;

    void setDrawer(shared_ptr<BaseDrawer> newDrawer);
    shared_ptr<BaseDrawer> getDrawer() const;
    //void setCanvas(shared_ptr<BaseCanvas> newCanvas);

private:
    shared_ptr<Scene> scene;
    weak_ptr<Camera> curCamera;
    //shared_ptr<BaseVisitor> objectDrawer;
    shared_ptr<BaseDrawer> drawer;
    //shared_ptr<BaseCanvas> canvas;
};

#endif // SCENEMANAGER_H
