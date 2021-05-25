#include "composite.h"

Composite::Composite(initializer_list<shared_ptr<Object>> args)
{
    for (auto &elem : args)
    {
        objectsVec.push_back(elem);
    }
}

void Composite::transform()
{
    cout << "Composite transform method:" << endl;
    for (auto elem : objectsVec)
        elem->transform();
}

bool Composite::isVisible() //what do I do here?
{
    cout << "Composite isVisible method:" << endl;
    bool rez = false;
    for (auto elem : objectsVec)
        if (elem->isVisible())
            rez = true;
    return rez; //return true????
}

void Composite::accept(shared_ptr<BaseVisitor> visitor)
{
    for (auto& obj : objectsVec)
        obj->accept(visitor);
}

bool Composite::add(shared_ptr<Object> comp)
{
    objectsVec.push_back(comp);
    return true;
}

bool Composite::remove(const IteratorObject &it)
{
    objectsVec.erase(it);
    return true;
}

bool Composite::isComposite() const
{
    return true;
}

IteratorObject Composite::begin() const
{
    return objectsVec.begin();
}

IteratorObject Composite::end() const
{
    return objectsVec.end();
}
