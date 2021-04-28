#ifndef CONSTConstIterator_H
#define CONSTConstIterator_H

#include "baseiterator.h"

using namespace std;

template<class Type>
class Vector;

template<typename Type>
class ConstIterator:public BaseIterator<Type>
{
public:
    ConstIterator();
    virtual ~ConstIterator() = default;
    ConstIterator(const ConstIterator<Type>& it); //copy

    explicit ConstIterator(const Vector<Type>& vec, int index = 0); //init

protected:
    /*weak_ptr<Type[]> data_ptr;
    bool check_ptr(int line) const;
    Type& cur_elem() const;
    weak_ptr<Type[]> get_data_ptr() const;*/
};

template<typename Type>
ConstIterator<Type>::ConstIterator()// : BaseIterator<Type>()
{
}

template<typename Type>
ConstIterator<Type>::ConstIterator(const ConstIterator<Type> &it) : BaseIterator<Type>(it)
{
    /*this->id = it.id;
    this->elems_num = it.elems_num;
    this->data_ptr = it.data_ptr;*/
}

template<typename Type>
ConstIterator<Type>::ConstIterator(const Vector<Type> &vec, int index)// : BaseIterator<Type>(vec, index)
{
    this->id = index;
    this->elems_num = vec.elems_num;
    this->data_ptr = vec.data_ptr;
}

#endif // CONSTConstIterator_H
