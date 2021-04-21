#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>

#include "baseiterator.h"

using namespace std;

template<class Type>
class Vector3D;

template<typename Type>
class Iterator:public BaseIterator
{
public:
    //Iterator();
    //~Iterator();
    explicit Iterator(const Iterator<Type>& it); //copy
    explicit Iterator(const Vector3D<Type>& vec, int index = 0); //init

    //bool operator !=(const weak_ptr<Type>, const weak_ptr<Type>) const;
    bool operator !=(const Iterator<Type>& it) const;
    operator bool() const;
    Type operator *();
    //Type& operator *() const;
    Iterator<Type> &operator ++(); //++it
    Iterator<Type> &operator ++(int); //it++

private:
    void set_cur_ptr();
    //Type data;
    shared_ptr<Type> cur_ptr;
    shared_ptr<Vector3D<Type>> vec_ptr;

protected:
    //Type* get_cur_ptr() const; // delete this bandit's code
};

template<typename Type>
Iterator<Type>::Iterator(const Iterator<Type> &it)
{
    id = it.id;
    elems_num = it.elems_num;
    cur_ptr = it.cur_ptr;
    vec_ptr = it.vec_ptr;
}

template<typename Type>
Iterator<Type>::Iterator(const Vector3D<Type> &vec, int index)
{
    id = index;
    elems_num = vec.elems_num;
    vec_ptr = make_shared<Vector3D<Type>>(vec);
    set_cur_ptr();
}

template<typename Type>
bool Iterator<Type>::operator !=(const Iterator<Type> &it) const
{
    bool test1 = id != it.id;
    bool test2 = vec_ptr != it.vec_ptr;
    return id != it.id;// && vec_ptr != i.vec_ptr;
}

template<typename Type>
Iterator<Type>::operator bool() const
{
    return (id >= 0 && id < elems_num && elems_num > 0);
}

template<typename Type>
Type Iterator<Type>::operator *()
{
    return *cur_ptr;
}

/*template<typename Type>
Type &Iterator<Type>::operator *() const
{
    Type t = 8.0;
    return t;
    //shared_ptr<Type> tmp_ptr = ptr.lock();
    //return *(ptr.lock().get());
    //shared_ptr<Type> tmp_ptr = ptr.lock();
    //return tmp_ptr.get() + id; // ????????????? НАСТОЯЩИЙ МУЖЧИНА
}*/

/*template<typename Type>
Type *Iterator<Type>::get_cur_ptr() const
{
    std::shared_ptr<Type> tmp_ptr = ptr.lock();
    return tmp_ptr.get() + id; // ????????????? НАСТОЯЩИЙ МУЖЧИНА
}*/

template<typename Type>
Iterator<Type> &Iterator<Type>::operator ++() //++it
{
    id++;
    set_cur_ptr();
    return *this;
}

template<typename Type>
Iterator<Type>& Iterator<Type>::operator ++(int) //it++ //Не было & на лекции
{
    Iterator<Type> tmp(*this);
    id++;

    set_cur_ptr();

    return tmp; // *this Ошибка в лекции????
}

template<typename Type>
void Iterator<Type>::set_cur_ptr()
{
    if (id == 0)
        cur_ptr = make_shared<Type>((*vec_ptr).x);
    else if (id == 1)
        cur_ptr = make_shared<Type>((*vec_ptr).y);
    else if (id == 2)
        cur_ptr = make_shared<Type>((*vec_ptr).z);
    else
        cur_ptr.reset();
}


#endif // ITERATOR_H
