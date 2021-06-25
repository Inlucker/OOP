#ifndef SCENE_H
#define SCENE_H

#include <memory>

using namespace std;

//#include "composite.h"
//#include "iterator.hpp"
//#include "constiterator.hpp"
#include "object.h"
//class Object;
class Camera;

//For CareTaker
class Memento;

using SceneObject = shared_ptr<Object>;

class Scene
{
public:
    Scene();
    Scene(const Scene &scene);
    ~Scene() = default;

    void addObject(shared_ptr<Object> new_model);
    void deleteObject(const size_t obg_id);
    void deleteObject(string name);
    void deleteObject(IteratorObject it);
    void clear();
    shared_ptr<Object> getObject(const size_t id) const; //Добавить идентефикатор
    shared_ptr<Object> getObject(string name) const;
    shared_ptr<Object> getObjects() const;

    //Реализовать итератор для сцены - это контейнер
    IteratorObject begin() noexcept;
    IteratorObject end() noexcept;
    ConstIteratorObject cbegin() const noexcept; //Added constIterator
    ConstIteratorObject cend() const noexcept;

    //For CareTaker
    std::unique_ptr<Memento> createMemento();
    void restoreMemento(unique_ptr<Memento> memento);

private:
    //objects;
    shared_ptr<Object> objects; //Объеденил модели и камеры
    //shared_ptr<Object> models;
    //shared_ptr<Object> cameras;
};

#endif // SCENE_H
