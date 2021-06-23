#include "scenemanager.h"
#include "errors.h"

//#include "graphicsolution.h" //???

SceneManager::SceneManager()
{
    scene = shared_ptr<Scene>(new Scene());
    curCamera.reset();
    curCameraId = -1;

    //objectDrawer = shared_ptr<BaseVisitor>(new ObjectVisitor());

    drawer.reset();

    //caretaker = make_unique<Caretaker>();
    caretaker = shared_ptr<Caretaker>(new Caretaker());
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
    curCameraId = -1;
    resetCaretaker();
}

shared_ptr<Scene> SceneManager::getScene() const
{
    return scene;
}

void SceneManager::addModel(shared_ptr<Model> new_model)
{
    scene->addObject(new_model);
    resetCaretaker();
}

void SceneManager::addCamera(shared_ptr<Camera> new_camera)
{
    scene->addObject(new_camera);
    resetCaretaker();
}

void SceneManager::deleteObject(const size_t objId)
{
    scene->deleteObject(objId);
    if (objId < curCameraId)
    {
        curCameraId--;
        useCamera(curCameraId);
    }
    else if (objId == curCameraId)
    {
        curCameraId = -1;
    }
    resetCaretaker();
}

/*void SceneManager::useCamera(shared_ptr<Camera> newCamera)
{
    if (!newCamera)
    {
        time_t t_time = time(NULL);
        throw UseCameraError("Trying to use not camera object as camera", __FILE__, __LINE__, ctime(&t_time));
    }
    curCamera = newCamera; // weak_ptr = shared_ptr ok?
}*/

void SceneManager::useCamera(size_t cameraId)
{
    shared_ptr<Camera> newCamera = dynamic_pointer_cast<Camera>(getScene()->getObject(cameraId));
    if (!newCamera)
    {
        time_t t_time = time(NULL);
        throw UseCameraError("Trying to use not camera object as camera", __FILE__, __LINE__, ctime(&t_time));
    }
    curCameraId = cameraId;
    curCamera = newCamera; // weak_ptr = shared_ptr ok?
}

weak_ptr<Camera> SceneManager::getCamera() const
{
    //IF WANT TO DELETE curCamera
    /*if (curCameraId < 0)
    {
        time_t t_time = time(NULL);
        throw NoCameraError("No active camera", __FILE__, __LINE__, ctime(&t_time));
    }
    shared_ptr<Camera> curCamera = dynamic_pointer_cast<Camera>(scene->getObject(curCameraId));
    if (!curCamera)
    {
        time_t t_time = time(NULL);
        throw UseCameraError("Trying to use not camera object as camera", __FILE__, __LINE__, ctime(&t_time));
    }
    return curCamera;*/

    if (curCamera.expired())
    {
        time_t t_time = time(NULL);
        throw NoCameraError("No active camera", __FILE__, __LINE__, ctime(&t_time));
    }
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

void SceneManager::returnScene()
{
    scene->restoreMemento(getCareTaker()->getMemento());
    useCamera(curCameraId);
}

shared_ptr<Caretaker> SceneManager::getCareTaker() const
{
    return caretaker;
}

void SceneManager::resetCaretaker()
{
    caretaker = shared_ptr<Caretaker>(new Caretaker());
}
