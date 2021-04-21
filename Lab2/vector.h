#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <cmath>
#include <stdarg.h>
#include <iostream>

#include "basevector.h"
#include "iterator.h"

#define EPS 1e-6

using namespace std;

template<typename Type>
class Vector:public BaseVector
{
public:
    //Vector3D();
    //Vector(Type new_x = 0., Type new_y = 0., Type new_z = 0.);
    Vector(int num_elements, Type vec, ...);

    explicit Vector(const Vector& vec); //copy

    ~Vector();

    bool is_empty() const;
    int size() const;
    double len() const;
    bool is_zero() const;
    bool is_unit() const;

    //Vector<Type> sum(Vector<Type> vec);

    Iterator<Type> begin();
    Iterator<Type> end();
    Iterator<Type> cbegin() const;
    Iterator<Type> cend() const;

    /*template<typename T>
    friend ostream& operator <<(ostream& out, const Vector<T>& vec);*/

    friend class Iterator<Type>;

private:
    //unique_ptr<Type[]> data_ptr;
    shared_ptr<Type[]> data_ptr;
protected:
    void alloc_data();
};

/*template<typename Type>
Vector3D<Type>::Vector3D()
{
    //elems_num = 0;
    //data_ptr.reset();
    x = 0;
    y = 0;
    z = 0;
}*/

/*template<typename Type>
Vector<Type>::Vector(Type new_x, Type new_y, Type new_z)
{
    elems_num = 3;
    x = new_x;
    y = new_y;
    z = new_z;
    //alloc();
}*/

template<typename Type>
Vector<Type>::Vector(int elements_number, Type vec, ...) //constructor?
{
    elems_num = elements_number;
    alloc_data();

    va_list ap;
    va_start(ap, vec);
    Vector<double> tmp_vec(*this);
    for (Iterator<Type> It = this->begin(); It != this->end(); ++It)
    {
        *It = vec;
        vec = va_arg(ap, Type);
    }
    va_end(ap);
}

template<typename Type>
Vector<Type>::Vector(const Vector &vec)
{
    elems_num = vec.elems_num;
    data_ptr = vec.data_ptr; //Check if its ik???
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
    return Iterator<Type>(Vector(*this));
}

template<typename Type>
Iterator<Type> Vector<Type>::end()
{
    return Iterator<Type>(Vector(*this), elems_num);
}

template<typename Type>
Iterator<Type> Vector<Type>::cbegin() const
{
    return Iterator<Type>(Vector(*this));
}

template<typename Type>
Iterator<Type> Vector<Type>::cend() const
{
    return Iterator<Type>(Vector(*this), elems_num);
}

template<typename Type>
void Vector<Type>::alloc_data()
{
    data_ptr.reset();
    shared_ptr<Type[]> new_ptr(new Type[elems_num]);
    data_ptr = new_ptr;
}

template<typename Type>
ostream& operator <<(ostream& os, const Vector<Type>& vec)
{
    Iterator It = vec.cbegin();

    if (!It)
    {
        os << "Vector is empty.";
        return os;
    }

    os << '(' << *It;
    It++;
    for (; It != vec.cend(); It++)
    {
        auto elem = *It;
        os << ", " << *It ;
    }
    os << ')';

    return os;
}

#endif // VECTOR_H
