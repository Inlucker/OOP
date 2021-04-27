#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>
#include <time.h>
#include <iostream>

#include "baseiterator.h"
#include "errors.h"

using namespace std;

template<class Type>
class Vector;

template<typename Type>
class Iterator:public BaseIterator
{
public:
    Iterator();
    ~Iterator();
    explicit Iterator(const Iterator<Type>& it); //copy //убрать explicit или оставить объявление конструктора переноса?
    Iterator<Type>& operator =(const Iterator<Type>& it);
    Iterator(Iterator<Type>&& it); //transfer
    //Iterator<Type>& operator =(Iterator<Type>&& it);

    explicit Iterator(const Vector<Type>& vec, int index = 0); //init

    int get_id() const;
    int get_els_num() const;

    //bool operator !=(const weak_ptr<Type>, const weak_ptr<Type>) const;
    bool operator ==(const Iterator<Type>& it) const;
    bool operator !=(const Iterator<Type>& it) const;
    operator bool() const;

    Type& operator *();
    const Type& operator *() const;

    Iterator<Type> &operator ++(); //++it
    Iterator<Type> operator ++(int); //it++

    //--, +=, -=, +, -, -It, [], <, >, <=, >=

    Iterator<Type> &operator --(); //++it
    Iterator<Type> operator --(int); //it++

    Iterator<Type>& operator +=(int n);
    Iterator<Type> operator +(int n) const;
    Iterator<Type>& operator -=(int n);
    Iterator<Type> operator -(int n) const;

    int operator -(const Iterator<Type>& it) const;

    Type& operator [](int id); //?

    bool operator <(const Iterator<Type>& it) const;
    bool operator <=(const Iterator<Type>& it) const;
    bool operator >(const Iterator<Type>& it) const;
    bool operator >=(const Iterator<Type>& it) const;

    Type* operator ->();
    const Type* operator ->() const;

private:
    weak_ptr<Type[]> data_ptr;
    //weak_ptr<Type> cur_ptr;

protected:
    //void alloc_data();
    bool check_ptr(int line) const;
    Type& cur_elem() const;
    weak_ptr<Type[]> get_data_ptr() const;
};

template<typename Type>
Iterator<Type>::Iterator()
{
    id = 0;
    elems_num = 0;
}

template<typename Type>
Iterator<Type>::~Iterator()
{
    //Нужно ли что то делать для weak_ptr?
    /*if (data_ptr)
        data_ptr.reset();*/
}

template<typename Type>
Iterator<Type>::Iterator(const Iterator<Type> &it)
{
    id = it.get_id(); // it.id как правильней?
    elems_num = get_els_num();
    data_ptr = it.data_ptr; // Check is this ok? //Its ok for iterator
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator =(const Iterator<Type> &it)
{
    id = it.get_id();
    elems_num = get_els_num();
    data_ptr = it.data_ptr;
    return *this;
}

//TRANSFER
/*template<typename Type>
Iterator<Type>::Iterator(Iterator<Type> &&it)
{
    id = it.id;
    elems_num = it.elems_num;
    data_ptr = it.data_ptr;
}

//TRANSFER operator =
template<typename Type>
Iterator<Type> &Iterator<Type>::operator =(Iterator<Type> &&it)
{
    id = it.id;
    elems_num = it.elems_num;
    data_ptr = it.data_ptr;
    return *this;
}*/

template<typename Type>
Iterator<Type>::Iterator(const Vector<Type> &vec, int index)
{
    /*time_t t_time = time(NULL);
    if (index < 0 || index >= vec.elems_num)
        throw IndexError("index for creating an iterator", __FILE__, __LINE__, ctime(&t_time));*/

    id = index;
    elems_num = vec.elems_num;

    /*alloc_data();

    for (int i = 0; i < elems_num; i++)
        data_ptr[i] = vec[i]; //vec.get_elem(i); //vec.data_ptr[i] WHY THIS WORKS?????????*/
    data_ptr = vec.data_ptr; //wrong?
}

template<typename Type>
int Iterator<Type>::get_id() const
{
    return id;
}

template<typename Type>
int Iterator<Type>::get_els_num() const
{
    return elems_num;
}

template<typename Type>
bool Iterator<Type>::operator ==(const Iterator<Type> &it) const
{
    check_ptr(__LINE__);

    return !(id != it.get_id() || data_ptr.lock() != it.data_ptr.lock());
}

template<typename Type>
bool Iterator<Type>::operator !=(const Iterator<Type> &it) const
{
    check_ptr(__LINE__);

    //bool test1 = id != it.id;
    //bool test2 = data_ptr.lock() != it.data_ptr.lock();
    return id != it.get_id() || data_ptr.lock() != it.data_ptr.lock();// && data_ptr.lock() != it.data_ptr.lock();
}

template<typename Type>
Iterator<Type>::operator bool() const
{
    check_ptr(__LINE__);

    return (id >= 0 && id < elems_num && elems_num > 0);
}

template<typename Type>
Type& Iterator<Type>::operator *()
{
    check_ptr(__LINE__);

    return cur_elem();
    /*shared_ptr<Type[]> copy_ptr = data_ptr.lock();
    return (copy_ptr[id]);*/
}

template<class Type>
const Type& Iterator<Type>::operator *() const
{
    check_ptr(__LINE__);

    return cur_elem();
    /*shared_ptr<Type[]> copy_ptr = data_ptr.lock();
    return (copy_ptr[id]);*/
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator ++() //++it
{
    check_ptr(__LINE__);

    id++;
    return *this;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator ++(int) //it++
{
    check_ptr(__LINE__);

    Iterator<Type> tmp(*this);
    ++(*this); //id++;
    return tmp;
}

template<typename Type>
Iterator<Type> &Iterator<Type>::operator --()
{
    check_ptr(__LINE__);

    id--;
    return *this;
}

template<typename Type>
Iterator<Type> Iterator<Type>::operator --(int)
{
    check_ptr(__LINE__);

    Iterator<Type> tmp(*this);
    --(*this); //id--;
    return tmp;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator +=(int n)
{
    check_ptr(__LINE__);

    id += n;
    return *this;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator +(int n) const
{
    check_ptr(__LINE__);

    Iterator<Type> sum_it(*this);
    sum_it += n;
    return sum_it;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator -=(int n)
{
    check_ptr(__LINE__);

    id -= n;
    return *this;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator -(int n) const
{
    check_ptr(__LINE__);

    Iterator<Type> dif_it(*this);
    dif_it -= n;
    return dif_it;
}

template<class Type>
int Iterator<Type>::operator -(const Iterator<Type>& it) const
{
    check_ptr(__LINE__);

    int dif = id - it.get_id();
    return dif;
}

template<typename Type>
Type &Iterator<Type>::operator [](int id)
{
    return *(*this + id);
}

template<typename Type>
bool Iterator<Type>::operator <(const Iterator<Type> &it) const
{
    return id < it.get_id();
    //return cur_elem() < *it;
}

template<typename Type>
bool Iterator<Type>::operator <=(const Iterator<Type> &it) const
{
    return id <= it.get_id();
    //return cur_elem() <= *it;
}

template<typename Type>
bool Iterator<Type>::operator >(const Iterator<Type> &it) const
{
    return id > it.get_id();
    //return cur_elem() > *it;
}

template<typename Type>
bool Iterator<Type>::operator >=(const Iterator<Type> &it) const
{
    return id >= it.get_id();
    //return cur_elem() >= *it;
}

template<typename Type>
Type *Iterator<Type>::operator ->()
{
    return &cur_elem();
    /*std::shared_ptr<Type[]> copy_ptr = data_ptr.lock();
    return &copy_ptr[id];*/
}

//Верно?
template<typename Type>
const Type *Iterator<Type>::operator ->() const
{
    return &cur_elem();
    /*std::shared_ptr<Type> copy_ptr = data_ptr.lock();
    return &copy_ptr[id];*/
}

template<typename Type>
bool Iterator<Type>::check_ptr(int line) const
{
    if (!data_ptr.expired())
        return true;

    time_t t_time = time(NULL);
    throw MemoryError("Iterator with no ptr", __FILE__, line, ctime(&t_time));
    return false;
}

template<typename Type>
Type &Iterator<Type>::cur_elem() const
{
    shared_ptr<Type[]> copy_ptr = data_ptr.lock();
    return (copy_ptr[id]);
}

template<typename Type>
weak_ptr<Type[]> Iterator<Type>::get_data_ptr() const
{
    return data_ptr;
}


#endif // ITERATOR_H
