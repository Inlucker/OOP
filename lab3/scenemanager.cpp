#include "scenemanager.h"

SceneManager::SceneManager()
{
    scene = shared_ptr<Scene>(new Scene());
    //curCamera = shared_ptr<Camera>(new Camera());
    //curCamera = shared_ptr<Camera>(new Camera(Point(0, 300, -300), Point(45, 45, 45)));
    curCamera.reset();

    /*ObjectVisitor* tmpObjVis = new ObjectVisitor();
    objectDrawer = tmpObjVis->getBaseVisitorPtr();*/

    //objectDrawer = shared_ptr<BaseVisitor>(new ObjectDrawer(curCamera, drawerScene));
}

void SceneManager::drawScene()
{
    shared_ptr<BaseVisitor> objectDrawer = shared_ptr<BaseVisitor>(new ObjectDrawer(curCamera, canvas));
    scene->getObjects()->accept(objectDrawer);
}

void SceneManager::clearCanvas()
{
    //objectDrawer->clear();
    canvas->clear();
}

void SceneManager::clearObjects()
{
    scene->clear();
    //curCamera.reset();
    //useCamera(nullptr);
}

shared_ptr<Scene> SceneManager::getScene() const
{
    return scene;
}

void SceneManager::addModel(shared_ptr<Model> new_model)
{
    //scene->addModel(new_model);
    scene->addObject(new_model);
}

void SceneManager::addCamera(shared_ptr<Camera> new_camera)
{
    //scene->addCamera(new_camera);
    scene->addObject(new_camera);
}

void SceneManager::deleteObject(const size_t objId)
{
    scene->deleteObject(objId);
}

/*void SceneManager::deleteModel(const size_t modelId)
{
    //scene->deleteModel(modelId);
    scene->deleteObject(modelId);
}

void SceneManager::deleteCamera(const size_t cameraId)
{
    //scene->deleteCamera(cameraId);
    scene->deleteObject(cameraId);
}*/

void SceneManager::useCamera(shared_ptr<Camera> newCamera)
{
    curCamera = newCamera; // weak_ptr = shared_ptr ok?
    //objectDrawer = shared_ptr<BaseVisitor>(new ObjectDrawer(curCamera, drawerScene));
}

void SceneManager::setCanvas(shared_ptr<BaseCanvas> newCanvas)
{
    canvas = newCanvas;
    //objectDrawer->setScene(newScene);
}

/*int SceneManager::method1(string str) //test
{
    cout << "method1 - " << str << endl;
    return 1;
}*/
