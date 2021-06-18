#include "object.h"

bool Object::add(shared_ptr<Object> comp)
{
    return false;
}

bool Object::remove(const IteratorObject &it)
{
    return false;
}

bool Object::isComposite() const
{
    return false;
}

bool Object::clear()
{
    return false;
}

size_t Object::size()
{
    return 1;
}

IteratorObject Object::begin() const
{
    return IteratorObject();
}

IteratorObject Object::end() const
{
    return IteratorObject();
}
