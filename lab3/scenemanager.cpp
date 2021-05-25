#include "scenemanager.h"

SceneManager::SceneManager()
{
    scene = unique_ptr<Scene>(new Scene());
    /*ObjectVisitor* tmpObjVis = new ObjectVisitor();
    objectDrawer = tmpObjVis->getBaseVisitorPtr();*/

    objectDrawer = shared_ptr<BaseVisitor>(new ObjectVisitor()); //не работала (исправлено с помощью public наследования)
}

void SceneManager::drawScene()
{
    scene->getModels()->accept(objectDrawer);
}

void SceneManager::addModel(shared_ptr<Model> new_model)
{
    scene->addModel(new_model);
}

void SceneManager::addCamera(shared_ptr<Camera> new_camera)
{
    scene->addCamera(new_camera);
}

void SceneManager::deleteModel(const size_t model_id)
{
    scene->deleteModel(model_id);
}

void SceneManager::deleteCamera(const size_t camera_id)
{
    scene->deleteCamera(camera_id);
}

/*int SceneManager::method1(string str) //test
{
    cout << "method1 - " << str << endl;
    return 1;
}*/
