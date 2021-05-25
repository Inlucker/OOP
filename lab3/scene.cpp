#include "scene.h"

Scene::Scene()
{
    //objects = shared_ptr<Object>(new Composite);
    models = shared_ptr<Object>(new Composite);
    cameras = shared_ptr<Object>(new Composite);
}

/*void Scene::addObject(shared_ptr<Object> new_obj)
{
    objects->add(new_obj);
}

void Scene::deleteObject(const size_t obj_id)
{
    IteratorObject it = objects->begin();
    for (size_t i = 0; i <= obj_id; i++)
        it++;

    objects->remove(it);
}*/

void Scene::addModel(shared_ptr<Object> new_model)
{
    models->add(new_model);
}

void Scene::deleteModel(const size_t model_id)
{
    IteratorObject it = models->begin();
    for (size_t i = 0; i <= model_id; i++)
        it++;

    models->remove(it);
}

void Scene::addCamera(shared_ptr<Object> new_camera)
{
    models->add(new_camera);
}

void Scene::deleteCamera(const size_t camera_id)
{
    IteratorObject it = models->begin();
    for (size_t i = 0; i <= camera_id; i++)
        it++;

    models->remove(it);
}

shared_ptr<Object> Scene::getModels()
{
    return models;
}

shared_ptr<Object> Scene::getCameras()
{
    return cameras;
}

shared_ptr<Object> Scene::getObjects()
{
    return shared_ptr<Object>(new Composite{models, cameras});
}