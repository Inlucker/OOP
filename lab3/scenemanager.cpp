#include "scenemanager.h"

SceneManager::SceneManager()
{
    scene = shared_ptr<Scene>(new Scene());
    //curCamera = shared_ptr<Camera>(new Camera());
    curCamera = shared_ptr<Camera>(new Camera(Point(0, 300, -300), Point(45, 45, 45)));

    /*ObjectVisitor* tmpObjVis = new ObjectVisitor();
    objectDrawer = tmpObjVis->getBaseVisitorPtr();*/

    objectDrawer = shared_ptr<BaseVisitor>(new ObjectDrawer(curCamera));

}

void SceneManager::drawScene()
{
    scene->getModels()->accept(objectDrawer);
}

void SceneManager::clearScene()
{
    //scene->clear();
    objectDrawer->clear();
}

shared_ptr<Scene> SceneManager::getScene() const
{
    return  scene;
}

void SceneManager::addModel(shared_ptr<Model> new_model)
{
    scene->addModel(new_model);
}

void SceneManager::addCamera(shared_ptr<Camera> new_camera)
{
    scene->addCamera(new_camera);
}

void SceneManager::deleteModel(const size_t modelId)
{
    scene->deleteModel(modelId);
}

void SceneManager::deleteCamera(const size_t cameraId)
{
    scene->deleteCamera(cameraId);
}

void SceneManager::useCamera(shared_ptr<Camera> newCamera)
{
    curCamera = newCamera;
    objectDrawer = shared_ptr<ObjectDrawer>(new ObjectDrawer(newCamera));
}

void SceneManager::setDrawerScene(shared_ptr<BaseScene> newScene)
{
    objectDrawer->setScene(newScene);
}

/*int SceneManager::method1(string str) //test
{
    cout << "method1 - " << str << endl;
    return 1;
}*/
