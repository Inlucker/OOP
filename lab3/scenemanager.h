#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "basemanager.h"
#include "scene.h"
#include "model.h"
#include "camera.h"
#include "objectvisitor.h"

#include "caretaker.h"

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
    //void deleteObject(const size_t objId);
    void deleteObject(string name);
    //void useCamera(shared_ptr<Camera> newCamera);
    //void useCamera(size_t cameraId);
    void useCamera(string cameraName);
    weak_ptr<Camera> getCamera() const;

    void setDrawer(shared_ptr<BaseDrawer> newDrawer);
    shared_ptr<BaseDrawer> getDrawer() const;
    //void setCanvas(shared_ptr<BaseCanvas> newCanvas);

    void returnScene();
    shared_ptr<Caretaker> getCareTaker() const;

private:
    void resetCaretaker();

private:
    shared_ptr<Scene> scene;
    weak_ptr<Camera> curCamera;
    //long curCameraId;
    string curCameraName;
    shared_ptr<BaseDrawer> drawer;
    shared_ptr<Caretaker> caretaker;
};

#endif // SCENEMANAGER_H
