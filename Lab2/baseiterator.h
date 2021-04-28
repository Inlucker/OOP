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
    BaseIterator(const BaseIterator<Type>& it); //copy //убрать explicit или оставить объявление конструктора переноса?
    BaseIterator<Type>& operator =(const BaseIterator<Type>& it);
    //BaseIterator(BaseIterator<Type>&& it); //transfer
    //BaseIterator<Type>& operator =(BaseIterator<Type>&& it);

    explicit BaseIterator(const Vector<Type>& vec, int index = 0); //init

    int get_id() const;
    int get_els_num() const;

    //bool operator !=(const weak_ptr<Type>, const weak_ptr<Type>) const;
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

    //Type& operator [](int id); //add const

    const Type* operator ->() const;

    bool operator <(const BaseIterator<Type>& it) const;
    bool operator <=(const BaseIterator<Type>& it) const;
    bool operator >(const BaseIterator<Type>& it) const;
    bool operator >=(const BaseIterator<Type>& it) const;
private:
    //weak_ptr<Type[]> data_ptr;

protected:
    weak_ptr<Type[]> data_ptr;
    //void alloc_data();
    bool check_ptr(int line) const;
    Type& cur_elem() const;
    weak_ptr<Type[]> get_data_ptr() const;
};

template<typename Type>
BaseIterator<Type>::BaseIterator()
{
    id = 0;
    elems_num = 0;
}

/*template<typename Type>
BaseIterator<Type>::~BaseIterator()
{
    //Нужно ли что то делать для weak_ptr?
    if (data_ptr)
        data_ptr.reset();
}*/

template<typename Type>
BaseIterator<Type>::BaseIterator(const BaseIterator<Type> &it)
{
    id = it.get_id(); // it.id как правильней?
    elems_num = it.get_els_num();
    data_ptr = it.data_ptr; // Check is this ok? //Its ok for BaseIterator
}

template<typename Type>
BaseIterator<Type> &BaseIterator<Type>::operator =(const BaseIterator<Type> &it)
{
    id = it.get_id();
    elems_num = get_els_num();
    data_ptr = it.data_ptr;
    return *this;
}

//TRANSFER
/*template<typename Type>
BaseIterator<Type>::BaseIterator(BaseIterator<Type> &&it)
{
    id = it.id;
    elems_num = it.elems_num;
    data_ptr = it.data_ptr;
}

//TRANSFER operator =
template<typename Type>
BaseIterator<Type> &BaseIterator<Type>::operator =(BaseIterator<Type> &&it)
{
    id = it.id;
    elems_num = it.elems_num;
    data_ptr = it.data_ptr;
    return *this;
}*/

template<typename Type>
BaseIterator<Type>::BaseIterator(const Vector<Type> &vec, int index)
{
    /*time_t t_time = time(NULL);
    if (index < 0 || index >= vec.elems_num)
        throw IndexError("index for creating an BaseIterator", __FILE__, __LINE__, ctime(&t_time));*/

    id = index;
    elems_num = vec.elems_num;

    /*alloc_data();

    for (int i = 0; i < elems_num; i++)
        data_ptr[i] = vec[i]; //vec.get_elem(i); //vec.data_ptr[i] WHY THIS WORKS?????????*/
    data_ptr = vec.data_ptr; //wrong?
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

    return !(id != it.get_id() || data_ptr.lock() != it.data_ptr.lock());
}

template<typename Type>
bool BaseIterator<Type>::operator !=(const BaseIterator<Type> &it) const
{
    check_ptr(__LINE__);

    //bool test1 = id != it.id;
    //bool test2 = data_ptr.lock() != it.data_ptr.lock();
    return id != it.get_id() || data_ptr.lock() != it.data_ptr.lock();// && data_ptr.lock() != it.data_ptr.lock();
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

    int dif = id - it.get_id();
    return dif;
}

template<class Type>
const Type& BaseIterator<Type>::operator *() const
{
    this->check_ptr(__LINE__);

    return this->cur_elem();
}

/*template<typename Type>
Type &BaseIterator<Type>::operator [](int id)
{
    return *(*this + id);
}*/

template<typename Type>
const Type *BaseIterator<Type>::operator ->() const
{
    return &(this->cur_elem());
}

template<typename Type>
bool BaseIterator<Type>::operator <(const BaseIterator<Type> &it) const
{
    return id < it.get_id();
    //return cur_elem() < *it;
}

template<typename Type>
bool BaseIterator<Type>::operator <=(const BaseIterator<Type> &it) const
{
    return id <= it.get_id();
    //return cur_elem() <= *it;
}

template<typename Type>
bool BaseIterator<Type>::operator >(const BaseIterator<Type> &it) const
{
    return id > it.get_id();
    //return cur_elem() > *it;
}

template<typename Type>
bool BaseIterator<Type>::operator >=(const BaseIterator<Type> &it) const
{
    return id >= it.get_id();
    //return cur_elem() >= *it;
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

template<typename Type>
weak_ptr<Type[]> BaseIterator<Type>::get_data_ptr() const
{
    return data_ptr;
}

#endif // BASEBaseIterator_H
