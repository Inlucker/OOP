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
    //void alloc_data();
    /*bool check_ptr(int line) const;
    Type& cur_elem() const;
    weak_ptr<Type[]> get_data_ptr() const;*/
};

template<typename Type>
ConstIterator<Type>::ConstIterator()
{
}

template<typename Type>
ConstIterator<Type>::ConstIterator(const ConstIterator<Type> &it)
{
    this->id = it.get_id(); // it.id как правильней?
    this->elems_num = it.get_els_num();
    this->data_ptr = it.data_ptr; // Check is this ok? //Its ok for BaseIterator
}

template<typename Type>
ConstIterator<Type>::ConstIterator(const Vector<Type> &vec, int index)
{
    this->id = index;
    this->elems_num = vec.elems_num;
    this->data_ptr = vec.data_ptr;
}

#endif // CONSTConstIterator_H
