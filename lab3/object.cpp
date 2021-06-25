#include "object.h"

Object::Object()
{
    name = "default_name";
    cout << "created Object: " << name;
}

Object::Object(string new_name)
{
    name = new_name;
}

void Object::setName(string newName)
{
    name = newName;
}

string Object::getName() const
{
    return name;
}

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
