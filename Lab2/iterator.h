#ifndef ITERATOR_H
#define ITERATOR_H

#include "baseiterator.h"

using namespace std;

/*template<class Type>
class Vector;*/

template<typename Type>
class Iterator:public BaseIterator<Type>
{
public:
    Iterator();
    virtual ~Iterator() = default;
    Iterator(const Iterator<Type>& it); //copy

    explicit Iterator(const Vector<Type>& vec, int index = 0); //init

    Type& operator *();
    //const Type& operator *() const;

    Type& operator [](int index); //add const

    Type* operator ->();
    //const Type* operator ->() const;
private:
    //weak_ptr<Type[]> data_ptr;

protected:
    /*bool check_ptr(int line) const;
    Type& cur_elem() const;
    weak_ptr<Type[]> get_data_ptr() const;*/
};

template<typename Type>
Iterator<Type>::Iterator()
{
}

template<typename Type>
Iterator<Type>::Iterator(const Iterator<Type> &it)
{
    this->id = it.get_id(); // it.id как правильней?
    this->elems_num = it.get_els_num();
    this->data_ptr = it.data_ptr; // Check is this ok? //Its ok for BaseIterator
}

template<typename Type>
Iterator<Type>::Iterator(const Vector<Type> &vec, int index)
{
    this->id = index;
    this->elems_num = vec.elems_num;
    this->data_ptr = vec.data_ptr;
}

template<typename Type>
Type& Iterator<Type>::operator *()
{
    this->check_ptr(__LINE__);

    return this->cur_elem();
}

/*template<class Type>
const Type& Iterator<Type>::operator *() const
{
    this->check_ptr(__LINE__);

    return this->cur_elem();
}*/

template<typename Type>
Type &Iterator<Type>::operator [](int index)
{
    Iterator<Type> tmp(*this);
    tmp += index;
    return *tmp;
    //return *(*this + index);
}

template<typename Type>
Type *Iterator<Type>::operator ->()
{
    return &(this->cur_elem());
}

/*template<typename Type>
const Type *Iterator<Type>::operator ->() const
{
    return &(this->cur_elem());
}*/

#endif // ITERATOR_H
