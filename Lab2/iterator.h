#ifndef ITERATOR_H
#define ITERATOR_H

#include "baseiterator.h"

using namespace std;

template<typename Type>
class Iterator:public BaseIterator<Type>
{
public:
    Iterator();
    virtual ~Iterator() = default;
    Iterator(const Iterator<Type>& it); //copy

    explicit Iterator(const Vector<Type>& vec, int index = 0); //init

    Type& operator *();

    Type& operator [](int index); //add const

    Type* operator ->();
protected:
    /*weak_ptr<Type[]> data_ptr;
    bool check_ptr(int line) const;
    Type& cur_elem() const;
    weak_ptr<Type[]> get_data_ptr() const;*/
};

template<typename Type>
Iterator<Type>::Iterator()//: BaseIterator<Type>()
{
}

template<typename Type>
Iterator<Type>::Iterator(const Iterator<Type> &it) : BaseIterator<Type>(it)
{
    /*this->id = it.id;
    this->elems_num = it.elems_num;
    this->data_ptr = it.data_ptr;*/
}

template<typename Type>
Iterator<Type>::Iterator(const Vector<Type> &vec, int index) : BaseIterator<Type>(vec, index)
{
    /*this->id = index;
    this->elems_num = vec.elems_num;
    this->data_ptr = vec.data_ptr;*/
}

template<typename Type>
Type& Iterator<Type>::operator *()
{
    this->check_ptr(__LINE__);

    return this->cur_elem();
}

template<typename Type>
Type &Iterator<Type>::operator [](int index)
{
    Iterator<Type> tmp(*this);
    tmp += index;
    return *tmp;
}

template<typename Type>
Type *Iterator<Type>::operator ->()
{
    return &(this->cur_elem());
}

#endif // ITERATOR_H
