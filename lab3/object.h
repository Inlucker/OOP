#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <memory>
#include <vector>
#include <iterator>

using namespace std;

class Object;

using VectorObject = vector<shared_ptr<Object>>;
using IteratorObject = VectorObject::const_iterator;

class Object
{
public:
    Object() = default;
    virtual ~Object() = default;

    virtual void transform() = 0;
    virtual bool isVisible() = 0;
    //virtual void accept(ObjectDrawer visitor) = 0;

    virtual bool add(shared_ptr<Object> comp);
    virtual bool remove(const IteratorObject& it);
    virtual bool isComposite() const;
    virtual IteratorObject begin() const;
    virtual IteratorObject end() const;
};

#endif // OBJECT_H
