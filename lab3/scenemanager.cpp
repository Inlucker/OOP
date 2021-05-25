#include "scenemanager.h"

SceneManager::SceneManager()
{
    scene = unique_ptr<Scene>(new Scene());
    objectDrawer = unique_ptr<ObjectDrawer>(new ObjectDrawer());
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
