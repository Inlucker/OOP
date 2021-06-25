#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <memory>
#include <vector>
#include <iterator>

using namespace std;

class BaseVisitor;
class Object;
class Point;

#include "iterator.hpp"
#include "constiterator.hpp"

using VectorObject = vector<shared_ptr<Object>>;
//using IteratorObject = VectorObject::const_iterator;
using Type = shared_ptr<Object>;
//using Type = Object;
using IteratorObject = Iterator<Type>;
using ConstIteratorObject = ConstIterator<Type>;

class Object
{
public:
    //Object() = default;
    Object();// = delete;
    Object(string new_name);
    virtual ~Object() = default;

    virtual void transform(const Point move, const Point scale, const Point rotate) = 0;
    virtual bool isVisible() const = 0;
    virtual void accept(shared_ptr<BaseVisitor> visitor) = 0;

    virtual shared_ptr<Object> clone() = 0;

    virtual void setName(string newName);
    virtual string getName() const;

    virtual bool add(shared_ptr<Object> comp);
    virtual bool remove(ConstIteratorObject& it);
    virtual bool isComposite() const;
    virtual bool clear();
    virtual int size() const; //Added = OK?

    //virtual IteratorObject begin() const;
    //virtual IteratorObject end() const;
    virtual Iterator<Type> begin() noexcept;
    virtual Iterator<Type> end() noexcept;
    virtual ConstIterator<Type> cbegin() const noexcept; //Added constIterator
    virtual ConstIterator<Type> cend() const noexcept;

protected:
    string name;
};

#endif // OBJECT_H
