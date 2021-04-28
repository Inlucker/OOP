#ifndef BASEBaseIterator_H
#define BASEBaseIterator_H
#include <memory>
#include <time.h>
#include <iostream>

#include "abstractIterator.h"
#include "errors.h"

using namespace std;

template<class Type>
class Vector;

template<typename Type>
class BaseIterator:public AbstractIterator
{
public:
    BaseIterator();
    virtual ~BaseIterator() = default;
    BaseIterator(const BaseIterator<Type>& it); //copy
    BaseIterator<Type>& operator =(const BaseIterator<Type>& it);

    explicit BaseIterator(const Vector<Type>& vec, int index = 0); //init

    int get_id() const;
    int get_els_num() const;

    bool operator ==(const BaseIterator<Type>& it) const;
    bool operator !=(const BaseIterator<Type>& it) const;
    operator bool() const;

    BaseIterator<Type> &operator ++(); //++it
    BaseIterator<Type> operator ++(int); //it++

    //--, +=, -=, +, -, -It, [], <, >, <=, >=

    BaseIterator<Type> &operator --(); //++it
    BaseIterator<Type> operator --(int); //it++

    BaseIterator<Type>& operator +=(int n);
    BaseIterator<Type> operator +(int n) const;
    BaseIterator<Type>& operator -=(int n);
    BaseIterator<Type> operator -(int n) const;

    int operator -(const BaseIterator<Type>& it) const;

    const Type& operator *() const;
    const Type& operator [](int index) const;
    const Type* operator ->() const;

    bool operator <(const BaseIterator<Type>& it) const;
    bool operator <=(const BaseIterator<Type>& it) const;
    bool operator >(const BaseIterator<Type>& it) const;
    bool operator >=(const BaseIterator<Type>& it) const;
private:
    //weak_ptr<Type[]> data_ptr;

protected:
    weak_ptr<Type[]> data_ptr;
    bool check_ptr(int line) const;
    Type& cur_elem() const;
};

template<typename Type>
BaseIterator<Type>::BaseIterator()
{
    id = 0;
    elems_num = 0;
}

template<typename Type>
BaseIterator<Type>::BaseIterator(const BaseIterator<Type> &it)
{
    id = it.id;
    elems_num = it.elems_num;
    data_ptr = it.data_ptr;
}

template<typename Type>
BaseIterator<Type> &BaseIterator<Type>::operator =(const BaseIterator<Type> &it)
{
    id = it.id;
    elems_num = it.elems_num;
    data_ptr = it.data_ptr;
    return *this;
}

template<typename Type>
BaseIterator<Type>::BaseIterator(const Vector<Type> &vec, int index)
{
    id = index;
    elems_num = vec.elems_num;
    data_ptr = vec.data_ptr;
}

template<typename Type>
int BaseIterator<Type>::get_id() const
{
    return id;
}

template<typename Type>
int BaseIterator<Type>::get_els_num() const
{
    return elems_num;
}

template<typename Type>
bool BaseIterator<Type>::operator ==(const BaseIterator<Type> &it) const
{
    check_ptr(__LINE__);

    return !(id != it.id || data_ptr.lock() != it.data_ptr.lock());
}

template<typename Type>
bool BaseIterator<Type>::operator !=(const BaseIterator<Type> &it) const
{
    check_ptr(__LINE__);

    return id != it.id || data_ptr.lock() != it.data_ptr.lock();
}

template<typename Type>
BaseIterator<Type>::operator bool() const
{
    check_ptr(__LINE__);

    return (id >= 0 && id < elems_num && elems_num > 0);
}

template<typename Type>
BaseIterator<Type> &BaseIterator<Type>::operator ++() //++it
{
    check_ptr(__LINE__);

    id++;
    return *this;
}

template<typename Type>
BaseIterator<Type> BaseIterator<Type>::operator ++(int) //it++
{
    check_ptr(__LINE__);

    BaseIterator<Type> tmp(*this);
    ++(*this); //id++;
    return tmp;
}

template<typename Type>
BaseIterator<Type> &BaseIterator<Type>::operator --()
{
    check_ptr(__LINE__);

    id--;
    return *this;
}

template<typename Type>
BaseIterator<Type> BaseIterator<Type>::operator --(int)
{
    check_ptr(__LINE__);

    BaseIterator<Type> tmp(*this);
    --(*this); //id--;
    return tmp;
}

template<class Type>
BaseIterator<Type>& BaseIterator<Type>::operator +=(int n)
{
    check_ptr(__LINE__);

    id += n;
    return *this;
}

template<class Type>
BaseIterator<Type> BaseIterator<Type>::operator +(int n) const
{
    check_ptr(__LINE__);

    BaseIterator<Type> sum_it(*this);
    sum_it += n;
    return sum_it;
}

template<class Type>
BaseIterator<Type>& BaseIterator<Type>::operator -=(int n)
{
    check_ptr(__LINE__);

    id -= n;
    return *this;
}

template<class Type>
BaseIterator<Type> BaseIterator<Type>::operator -(int n) const
{
    check_ptr(__LINE__);

    BaseIterator<Type> dif_it(*this);
    dif_it -= n;
    return dif_it;
}

template<class Type>
int BaseIterator<Type>::operator -(const BaseIterator<Type>& it) const
{
    check_ptr(__LINE__);

    int dif = id - it.id;
    return dif;
}

template<class Type>
const Type& BaseIterator<Type>::operator *() const
{
    this->check_ptr(__LINE__);

    return this->cur_elem();
}

template<typename Type>
const Type &BaseIterator<Type>::operator [](int index) const
{
    BaseIterator<Type> tmp(*this);
    tmp += index;
    return *tmp;
}

template<typename Type>
const Type *BaseIterator<Type>::operator ->() const
{
    return &(this->cur_elem());
}

template<typename Type>
bool BaseIterator<Type>::operator <(const BaseIterator<Type> &it) const
{
    return id < it.id;
}

template<typename Type>
bool BaseIterator<Type>::operator <=(const BaseIterator<Type> &it) const
{
    return id <= it.id;
}

template<typename Type>
bool BaseIterator<Type>::operator >(const BaseIterator<Type> &it) const
{
    return id > it.id;
}

template<typename Type>
bool BaseIterator<Type>::operator >=(const BaseIterator<Type> &it) const
{
    return id >= it.id;
}

template<typename Type>
bool BaseIterator<Type>::check_ptr(int line) const
{
    if (!data_ptr.expired())
        return true;

    time_t t_time = time(NULL);
    throw MemoryError("BaseIterator with no ptr", __FILE__, line, ctime(&t_time)); //Выделить отдельно
    return false;
}

template<typename Type>
Type &BaseIterator<Type>::cur_elem() const
{
    shared_ptr<Type[]> copy_ptr = data_ptr.lock();
    return (copy_ptr[id]);
}

#endif // BASEBaseIterator_H
