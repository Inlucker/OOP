#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <cmath>
#include <stdarg.h>
#include <iostream>
#include <time.h>

#include "basevector.h"
#include "iterator.h"
#include "errors.h"

#define EPS 1e-6

using namespace std;

template<typename Type>
class Vector:public BaseVector
{
public:
    Vector();
    explicit  Vector(int elements_number);
    Vector(int elements_number, Type* vec);
    Vector(int elements_number, Type vec, ...);
    Vector(initializer_list<Type> args);

    explicit Vector(const Vector& vec); //copy

    ~Vector();

    bool is_empty() const;
    int size() const;
    double len() const;
    bool is_zero() const;
    bool is_unit() const;

    Iterator<Type> begin();
    Iterator<Type> end();
    Iterator<Type> cbegin() const;
    Iterator<Type> cend() const;
    Iterator<Type> begin() const;
    Iterator<Type> end() const;

    Type &get_elem(int id);
    const Type& get_elem(int id) const;
    Type& operator [](int id);
    const Type& operator [](int id) const;


    void set_elem(int id, Type value);

    /*template<typename T>
    friend ostream& operator <<(ostream& out, const Vector<T>& vec);*/

    friend class Iterator<Type>;

private:
    //unique_ptr<Type[]> data_ptr;
    shared_ptr<Type[]> data_ptr;

protected:
    void alloc_data();
};


template<typename Type>
Vector<Type>::Vector()
{
    elems_num = 0;
    alloc_data();
}

template<typename Type>
Vector<Type>::Vector(int elements_number)
{
    time_t t_time = time(NULL);
    if (elements_number < 0)
        throw NegativeSizeError("elements_number < 0", __FILE__, __LINE__, ctime(&t_time));

    elems_num = elements_number;
    alloc_data();

    for (auto &elem:*this)
        elem = 0;
    /*for (Iterator<Type> It = this->begin(); It != this->end(); ++It)
        *It = 0;*/
}

template<typename Type>
Vector<Type>::Vector(int elements_number, Type *vec)
{
    //check elems number?
    time_t t_time = time(NULL);
    if (elements_number < 0)
        throw NegativeSizeError("elements_number < 0", __FILE__, __LINE__, ctime(&t_time));


    elems_num = elements_number;
    alloc_data();

    int i = 0;
    /*for (Iterator<Type> It = this->begin(); It != this->end(); ++It)
        *It = vec[i++];*/
    for (auto &elem:*this)
        elem = vec[i++];
}

template<typename Type>
Vector<Type>::Vector(int elements_number, Type vec, ...)
{
    //check args number?
    time_t t_time = time(NULL);
    if (elements_number < 0)
        throw NegativeSizeError("elements_number < 0", __FILE__, __LINE__, ctime(&t_time));

    elems_num = elements_number;
    alloc_data();// inside allocationg check

    //if (!data_ptr)
    //    throw MemoryError("data_ptr", __FILE__, __LINE__, ctime(&t_time));

    va_list ap;
    va_start(ap, vec);
    /*for (Iterator<Type> It = this->begin(); It != this->end(); ++It)
    {
        *It = vec;
        vec = va_arg(ap, Type);
    }*/
    for (auto &elem:*this)
    {
        elem = vec;
        vec = va_arg(ap, Type);
    }
    va_end(ap);
}

template<typename Type>
Vector<Type>::Vector(initializer_list<Type> args)
{
    if (args.size() == 0)
        Vector();

    elems_num = int(args.size());
    alloc_data();

    Iterator<Type> it(*this);
    for (auto elem : args)
    {
        *it = elem;
        it++;
    }
}

template<typename Type>
Vector<Type>::Vector(const Vector &vec)
{
    time_t t_time = time(NULL);
    elems_num = vec.elems_num;
    if (elems_num < 0)
        throw NegativeSizeError("elements_number < 0", __FILE__, __LINE__, ctime(&t_time));

    alloc_data();

    for (int i = 0; i < elems_num; i++)
    {
        data_ptr[i] = vec[i]; //vec.get_elem(i); //vec.data_ptr[i] WHY THIS WORKS?????????
    }

    //data_ptr = shared_ptr(vec.data_ptr); //Check if its ok???
}

template<typename Type>
Vector<Type>::~Vector()
{
    //destructor
}

template<typename Type>
bool Vector<Type>::is_empty() const
{
    return !elems_num;
}

template<typename Type>
int Vector<Type>::size() const
{
    return elems_num;
}

template<typename Type>
double Vector<Type>::len() const
{
    double len = 0;

    Vector<double> tmp_vec(*this);
    for (auto elem:tmp_vec)
        len += elem * elem;
    return sqrt(len);
}

template<typename Type>
bool Vector<Type>::is_zero() const
{
    return this->len() == 0;
}

template<typename Type>
bool Vector<Type>::is_unit() const
{
    return fabs(this->len() - 1) <= EPS;
}

/*template<typename Type>
Vector<Type> Vector<Type>::sum(Vector<Type> vec)
{
    Vector<Type> &rez = *this;
    return rez;
}*/

template<typename Type>
Iterator<Type> Vector<Type>::begin()
{
    return Iterator<Type>(*this, 0);
}

template<typename Type>
Iterator<Type> Vector<Type>::end()
{
    return Iterator<Type>(*this, elems_num);
}

template<typename Type>
Iterator<Type> Vector<Type>::cbegin() const
{
    return Iterator<Type>(*this, 0);
}

template<typename Type>
Iterator<Type> Vector<Type>::cend() const
{
    return Iterator<Type>(*this, elems_num);
}

template<typename Type>
Iterator<Type> Vector<Type>::begin() const
{
    return Iterator<Type>(*this, 0);
}

template<typename Type>
Iterator<Type> Vector<Type>::end() const
{
    return Iterator<Type>(*this, elems_num);
}

template<typename Type>
Type& Vector<Type>::get_elem(int id)
{
    time_t t_time = time(NULL);
    if (id < 0 || id >= elems_num)
        throw IndexError("id", __FILE__, __LINE__, ctime(&t_time));
    return data_ptr[id];
}

template<typename Type>
const Type &Vector<Type>::get_elem(int id) const
{
    time_t t_time = time(NULL);
    if (id < 0 || id >= elems_num)
        throw IndexError("id", __FILE__, __LINE__, ctime(&t_time));

    return data_ptr[id];
}

template<typename Type>
Type &Vector<Type>::operator [](int id)
{
    return get_elem(id);
}

template<typename Type>
const Type &Vector<Type>::operator [](int id) const
{
    return get_elem(id);
}

template<typename Type>
void Vector<Type>::set_elem(int id, Type value)
{
    time_t t_time = time(NULL);
    if (id < 1 || id > elems_num)
        throw IndexError("id", __FILE__, __LINE__, ctime(&t_time));

    data_ptr[id] = value;
    //get_elem(id) = value;
}

template<typename Type>
void Vector<Type>::alloc_data()
{
    data_ptr.reset();
    shared_ptr<Type[]> new_ptr(new Type[elems_num]);
    data_ptr = new_ptr;

    time_t t_time = time(NULL);
    if (!data_ptr)
        throw MemoryError("data_ptr", __FILE__, __LINE__, ctime(&t_time));
}

//template<typename T> constexpr const T &as_const(T &t) noexcept { return t; }
//for (auto &v: as_const(container))

template<typename Type>
ostream& operator <<(ostream& os, const Vector<Type>& vec)
{

    if (vec.is_empty())
    {
        os << "Vector is empty.";
        return os;
    }

    Iterator It = vec.cbegin();
    os << '(' << *It++;
    for (; It != vec.cend(); It++)
        os << ", " << *It ;
    os << ')';

    //for each
    /*int i = 0;
    os << '(';
    for (auto &elem:vec)
    {
        os << elem;
        if (++i != vec.size())
            os << ", ";
    }
    os << ')';*/

    return os;
}

#endif // VECTOR_H
