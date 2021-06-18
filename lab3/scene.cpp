#include "scene.h"
#include "errors.h"

using namespace std;

Scene::Scene()
{
    objects = shared_ptr<Object>(new Composite);
    //models = shared_ptr<Object>(new Composite);
    //cameras = shared_ptr<Object>(new Composite);
}

void Scene::addModel(shared_ptr<Object> new_model)
{
    //models->add(new_model);
    objects->add(new_model);
}

/*void Scene::deleteModel(const size_t model_id)
{
    IteratorObject it = models->begin();
    for (size_t i = 0; i <= model_id; i++)
        it++;

    models->remove(it);
}*/

void Scene::addCamera(shared_ptr<Object> new_camera)
{
    objects->add(new_camera);
}

/*void Scene::deleteCamera(const size_t camera_id)
{
    IteratorObject it = cameras->begin();
    for (size_t i = 0; i <= camera_id; i++)
        it++;

    cameras->remove(it);
}*/

void Scene::deleteObject(const size_t obg_id)
{
    if (obg_id + 1 > objects->size())
    {
        time_t t_time = time(NULL);
        throw IndexError("Id error", __FILE__, __LINE__, ctime(&t_time));
    }
    IteratorObject it = objects->begin();
    for (size_t i = 0; i < obg_id; i++)
        it++;
    objects->remove(it);
}

void Scene::clear()
{
    objects->clear();
}

/*shared_ptr<Object> Scene::getModels()
{
    return models;
}

shared_ptr<Object> Scene::getModel(const size_t id)
{
    if (id + 1 > models->size())
    {
        //return *cameras->begin(); //THROW
        //cout << "HERE?";
        time_t t_time = time(NULL);
        throw IndexError("Id error", __FILE__, __LINE__, ctime(&t_time));
    }
    IteratorObject it = models->begin();
    for (size_t i = 0; i < id; i++)
        it++;
    return *it;
}

shared_ptr<Object> Scene::getCameras()
{
    return cameras;
}

shared_ptr<Object> Scene::getCamera(const size_t id)
{
    if (id + 1 > models->size())
    {
        //return *cameras->begin(); //THROW
        //cout << "HERE?";
        time_t t_time = time(NULL);
        throw IndexError("Id error", __FILE__, __LINE__, ctime(&t_time));
    }
    IteratorObject it = cameras->begin();
    for (size_t i = 0; i < id; i++)
        it++;
    return *it;
}*/

shared_ptr<Object> Scene::getObject(const size_t id)
{
    if (id + 1 > objects->size())
    {
        time_t t_time = time(NULL);
        throw IndexError("Id error", __FILE__, __LINE__, ctime(&t_time));
    }
    IteratorObject it = objects->begin();
    for (size_t i = 0; i < id; i++)
        it++;
    return *it;
}

shared_ptr<Object> Scene::getObjects()
{
    return objects;
    //return shared_ptr<Object>(new Composite{models, cameras});
}
