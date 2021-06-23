#include "composite.h"
#include "point.h"

Composite::Composite(initializer_list<shared_ptr<Object>> args)
{
    for (auto &elem : args)
    {
        objectsVec.push_back(elem);
    }
}

void Composite::transform(const Point move, const Point scale, const Point rotate)
{
    cout << "Composite transform method:" << endl;
    for (auto elem : objectsVec)
        elem->transform(move, scale, rotate);
}

bool Composite::isVisible() const //what do I do here?
{
    cout << "Composite isVisible method:" << endl;
    bool rez = false;
    for (const auto &elem : objectsVec)
        if (elem->isVisible())
            rez = true;
    return rez; //return true????
}

void Composite::accept(shared_ptr<BaseVisitor> visitor)
{
    for (auto& obj : objectsVec)
        obj->accept(visitor);
}

shared_ptr<Object> Composite::clone()
{
    shared_ptr<Object> newComposite = shared_ptr<Object>(new Composite());
    for (auto& obj : objectsVec)
    {
        newComposite->add(obj->clone());
    }
    return newComposite;
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

bool Composite::clear()
{
    objectsVec.clear();
    return true;
}

size_t Composite::size()
{
    return objectsVec.size();
}

IteratorObject Composite::begin() const
{
    return objectsVec.begin();
}

IteratorObject Composite::end() const
{
    return objectsVec.end();
}
