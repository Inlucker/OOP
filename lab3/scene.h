#ifndef SCENE_H
#define SCENE_H

#include <memory>

using namespace std;

//#include "composite.h"
class Object;
class Camera;

//For CareTaker
class Memento;

class Scene
{
public:
    Scene();
    Scene(const Scene &scene);
    ~Scene() = default;

    void addObject(shared_ptr<Object> new_model);
    void deleteObject(const size_t obg_id);
    void clear();
    shared_ptr<Object> getObject(const size_t id) const; //Добавить идентефикатор
    //Реализовать итератор для сцены - это контейнер
    shared_ptr<Object> getObjects() const;

    //For CareTaker
    /*explicit Scene(shared_ptr<Object> objs);

    const shared_ptr<Object> getState() const;
    void setState(shared_ptr<Object> objs);*/

    //IteratorObject begin() const;
    //IteratorObject end() const;

    std::unique_ptr<Memento> createMemento();
    void restoreMemento(unique_ptr<Memento> memento);

private:
    //objects;
    shared_ptr<Object> objects; //Объеденил модели и камеры
    //shared_ptr<Object> models;
    //shared_ptr<Object> cameras;
};

#endif // SCENE_H
