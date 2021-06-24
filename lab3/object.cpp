#include "object.h"

bool Object::add(shared_ptr<Object> comp)
{
    return false;
}

bool Object::remove(ConstIteratorObject &it)
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

int Object::size() const
{
    return 1;
}

Iterator<Type> Object::begin() noexcept
{
    return Iterator<Type>();
}

Iterator<Type> Object::end() noexcept
{
    return Iterator<Type>();
}

ConstIterator<Type> Object::cbegin() const noexcept
{
    return ConstIterator<Type>();
}

ConstIterator<Type> Object::cend() const noexcept
{
    return ConstIterator<Type>();
}
