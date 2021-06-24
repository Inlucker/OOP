#include "scene.h"
#include "errors.h"
#include "memento.h"

#include "composite.h"
#include "camera.h"

using namespace std;

Scene::Scene()
{
    objects = shared_ptr<Object>(new Composite);
}

Scene::Scene(const Scene &scene)
{
    objects = scene.getObjects()->clone();
    //curCamera = scene.curCamera.lock()->clone();
    /*objects = shared_ptr<Object>(new Composite);
    IteratorObject i = scene.getObjects()->begin();
    while (i != scene.getObjects()->end())
    {
        shared_ptr<Object> newObj = shared_ptr<Object>(new Object) //НЕЛЬЗЯ СОЗДАТЬ ОБЪЕКТ АБСТРАКТНОГО КЛАССА
        objects->add(*i);
        i++;
    }*/
}

void Scene::addObject(shared_ptr<Object> new_model)
{
    objects->add(new_model);
}

void Scene::deleteObject(const size_t obg_id)
{
    if (obg_id >= objects->size() || obg_id + 1 < 0)
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

shared_ptr<Object> Scene::getObject(const size_t id) const
{
    if (id >= objects->size() || id < 0)
    {
        time_t t_time = time(NULL);
        throw IndexError("Id error", __FILE__, __LINE__, ctime(&t_time));
    }
    IteratorObject it = objects->begin();
    for (size_t i = 0; i < id; i++)
        it++;
    return *it;
}

shared_ptr<Object> Scene::getObjects() const
{
    return objects;
}

//for CareTaker
/*Scene::Scene(shared_ptr<Object> objs) : objects(objs) {}

const shared_ptr<Object> Scene::getState() const
{
    return objects;
}

void Scene::setState(shared_ptr<Object> objs)
{
    objects = objs;
}*/

std::unique_ptr<Memento> Scene::createMemento()
{
    return make_unique<Memento>(*this);
}

void Scene::restoreMemento(unique_ptr<Memento> memento)
{
    *this = memento->getOriginator();
}
