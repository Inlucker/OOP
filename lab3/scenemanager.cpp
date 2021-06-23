#include "scenemanager.h"
#include "errors.h"

//#include "graphicsolution.h" //???

SceneManager::SceneManager()
{
    scene = shared_ptr<Scene>(new Scene());
    curCamera.reset();

    //objectDrawer = shared_ptr<BaseVisitor>(new ObjectVisitor());

    drawer.reset();
}

void SceneManager::clearCanvas()
{
    time_t t_time = time(NULL);
    if (!drawer)
        throw NoDrawerError("No active drawer", __FILE__, __LINE__, ctime(&t_time));
    drawer->clear();
}

void SceneManager::drawScene()
{
    //scene->getObjects()->accept(objectDrawer);
    scene->getObjects()->accept(shared_ptr<BaseVisitor>(new ObjectVisitor()));
}

void SceneManager::clearObjects()
{
    scene->clear();
}

shared_ptr<Scene> SceneManager::getScene() const
{
    return scene;
}

void SceneManager::addModel(shared_ptr<Model> new_model)
{
    scene->addObject(new_model);
}

void SceneManager::addCamera(shared_ptr<Camera> new_camera)
{
    scene->addObject(new_camera);
}

void SceneManager::deleteObject(const size_t objId)
{
    scene->deleteObject(objId);
}

void SceneManager::useCamera(shared_ptr<Camera> newCamera)
{
    if (!newCamera)
    {
        time_t t_time = time(NULL);
        throw UseCameraError("Trying to use not camera object as camera", __FILE__, __LINE__, ctime(&t_time));
    }
    curCamera = newCamera; // weak_ptr = shared_ptr ok?
}

weak_ptr<Camera> SceneManager::getCamera() const
{
    time_t t_time = time(NULL);
    if (curCamera.expired())
        throw NoCameraError("No active camera", __FILE__, __LINE__, ctime(&t_time));
    return curCamera;
}

void SceneManager::setDrawer(shared_ptr<BaseDrawer> newDrawer)
{
    drawer = newDrawer;
}

shared_ptr<BaseDrawer> SceneManager::getDrawer() const
{
    time_t t_time = time(NULL);
    if (!drawer)
        throw NoDrawerError("No active drawer", __FILE__, __LINE__, ctime(&t_time));
    return drawer;
}

/*void SceneManager::setCanvas(shared_ptr<BaseCanvas> newCanvas)
{
    drawer->setCanvas(newCanvas);
}*/
