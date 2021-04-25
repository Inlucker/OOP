#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>

#include "baseiterator.h"

using namespace std;

template<class Type>
class Vector;

template<typename Type>
class Iterator:public BaseIterator
{
public:
    //Iterator();
    //~Iterator();
    Iterator(const Iterator<Type>& it); //copy
    explicit Iterator(const Vector<Type>& vec, int index = 0); //init

    //bool operator !=(const weak_ptr<Type>, const weak_ptr<Type>) const;
    bool operator ==(const Iterator<Type>& it) const;
    bool operator !=(const Iterator<Type>& it) const;
    operator bool() const;
    Type& operator *();
    Iterator<Type> &operator ++(); //++it
    Iterator<Type> operator ++(int); //it++

private:
    weak_ptr<Type[]> data_ptr;
    weak_ptr<Type> cur_ptr;
};

template<typename Type>
Iterator<Type>::Iterator(const Iterator<Type> &it)
{
    id = it.id;
    elems_num = it.elems_num;
    data_ptr = it.data_ptr; // Check is this ok?
}

template<typename Type>
Iterator<Type>::Iterator(const Vector<Type> &vec, int index)
{
    id = index;
    elems_num = vec.elems_num;
    data_ptr = vec.data_ptr;
}

template<typename Type>
bool Iterator<Type>::operator ==(const Iterator<Type> &it) const
{
    return !(id != it.id || data_ptr.lock() != it.data_ptr.lock());
}

template<typename Type>
bool Iterator<Type>::operator !=(const Iterator<Type> &it) const
{
    //bool test1 = id != it.id;
    //bool test2 = data_ptr.lock() != it.data_ptr.lock();
    return id != it.id || data_ptr.lock() != it.data_ptr.lock();// && data_ptr.lock() != it.data_ptr.lock();
}

template<typename Type>
Iterator<Type>::operator bool() const
{
    return (id >= 0 && id < elems_num && elems_num > 0);
}

template<typename Type>
Type& Iterator<Type>::operator *()
{
    shared_ptr<Type[]> copy_ptr = data_ptr.lock();
    return (copy_ptr[id]);
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator ++() //++it
{
    id++;
    return *this;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator ++(int) //it++
{
    Iterator<Type> tmp(*this);
    ++(*this);
    //id++;
    return tmp;
}


#endif // ITERATOR_H
