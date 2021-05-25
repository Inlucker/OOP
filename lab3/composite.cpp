#include "composite.h"

Composite::Composite(initializer_list<shared_ptr<Object>> args)
{
    for (auto &elem : args)
    {
        vec.push_back(elem);
    }
}

void Composite::transform()
{
    cout << "Composite transform method:" << endl;
    for (auto elem : vec)
        elem->transform();
}

bool Composite::isVisible() //what do I do here?
{
    cout << "Composite isVisible method:" << endl;
    bool rez = false;
    for (auto elem : vec)
        if (elem->isVisible())
            rez = true;
    return rez; //return true????
}

bool Composite::add(shared_ptr<Object> comp)
{
    vec.push_back(comp);
    return true;
}

bool Composite::remove(const IteratorObject &it)
{
    vec.erase(it);
    return true;
}

bool Composite::isComposite() const
{
    return true;
}

IteratorObject Composite::begin() const
{
    return vec.begin();
}

IteratorObject Composite::end() const
{
    return vec.end();
}
