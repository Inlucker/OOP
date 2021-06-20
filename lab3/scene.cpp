#include "scene.h"
#include "errors.h"

using namespace std;

Scene::Scene()
{
    objects = shared_ptr<Object>(new Composite);
}

void Scene::addObject(shared_ptr<Object> new_model)
{
    objects->add(new_model);
}

void Scene::deleteObject(const size_t obg_id)
{
    if (obg_id + 1 > objects->size() || obg_id + 1 < 0)
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

shared_ptr<Object> Scene::getObject(const size_t id)
{
    if (id + 1 > objects->size() || id < 0)
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
}
