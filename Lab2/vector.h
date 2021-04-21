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
class Vector3D:public BaseVector
{
public:
    //Vector3D();
    Vector3D(Type new_x = 0., Type new_y = 0., Type new_z = 0.);
    //Vector(int num_elements, Type vec, ...);

    explicit Vector3D(const Vector3D& vec); //copy

    ~Vector3D();

    //bool is_empty() const;
    int size() const;
    double len() const;
    bool is_zero() const;
    bool is_unit() const;

    Type getX() const;
    Type getY() const;
    Type getZ() const;

    Iterator<Type> begin();
    Iterator<Type> end();

    /*weak_ptr<Vector> operator *()
    {
        weak_ptr<Vector> wp = new weak_ptr(this);
        return wp;
    }*/

    //friend std::ostream& operator <<(std::ostream& out, const Vector3D<Type>& vec);

    friend class Iterator<Type>;
private:
    //int elems_num;
    //unique_ptr<Type> data_ptr;
    Type x;
    Type y;
    Type z;
    //shared_ptr<Type> x;
    //shared_ptr<Type> y;
    //shared_ptr<Type> z;
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

template<typename Type>
Vector3D<Type>::Vector3D(Type new_x, Type new_y, Type new_z)
{
    elems_num = 3;
    x = new_x;
    y = new_y;
    z = new_z;
}

template<typename Type>
Vector3D<Type>::Vector3D(const Vector3D &vec)
{
    elems_num = vec.elems_num;
    x = vec.x;
    y = vec.y;
    z = vec.z;
}

/*template<typename Type>
Vector<Type>::Vector(int elements_number, Type vec, ...) //constructor?
{
    elems_num = elements_number;
    data_ptr.reset();
    shared_ptr<Type> new_sp(new Type[elems_num]); //, default_delete<Type[]>());
    data_ptr = new_sp;

    Iterator<Type> it(*this);
    va_list ap;
    va_start(ap, vec);
    for (; it; it++)
    {
        *it = vec;
        vec = va_arg(ap, Type);
    }
    va_end(ap);
}*/

template<typename Type>
Vector3D<Type>::~Vector3D()
{
    //destructor
}

/*template<typename Type>
bool Vector<Type>::is_empty() const
{
    return !elems_num;
}*/

template<typename Type>
int Vector3D<Type>::size() const
{
    return elems_num;
}

template<typename Type>
double Vector3D<Type>::len() const
{
    return sqrt(x*x+y*y+z*z);

    /*Iterator<Type> it(*this);
    double len = 0;
    for (; it; it++)
    {
        len += *it * *it;
    }

    //for each
    double len = 0;
    for (Iterator<Type> elem:this)
    {
        len += *elem * *elem;
    }
    return sqrt(len);*/
}

template<typename Type>
bool Vector3D<Type>::is_zero() const
{
    return this->len() == 0;
}

template<typename Type>
bool Vector3D<Type>::is_unit() const
{
    return fabs(this->len() - 1) <= EPS;
}

template<typename Type>
Type Vector3D<Type>::getX() const
{
    return x;
}

template<typename Type>
Type Vector3D<Type>::getY() const
{
    return y;
}

template<typename Type>
Type Vector3D<Type>::getZ() const
{
    return z;
}

template<typename Type>
Iterator<Type> Vector3D<Type>::begin()
{
    //const Vector tmpVec(*this);
    return Iterator(Vector3D(*this));
}

template<typename Type>
Iterator<Type> Vector3D<Type>::end()
{
    //const Vector tmpVec(*this);
    return Iterator(Vector3D(*this), 3);
}

/*template<typename Type>
weak_ptr<Vector> Vector<Type>::operator *(Vector &vec)
{
    weak_ptr<Vector> wp = new weak_ptr(*this);
    return wp;
}*/

//cout
/*template<typename Type>
std::ostream& operator <<(std::ostream& out, const Vector3D<Type>& vec)
{
    if (vec.is_empty())
    {
        out << "Vector is empty.";
        return out;
    }

    out << '(' << vec.x;
    out << ", " << vec.y;
    out << ", " << vec.z;
    out << ')';

    return out;
}*/

template<typename Type>
ostream& operator <<(ostream& out, const Vector3D<Type>& vec)
{
    out << '(' << vec.getX() << ", " << vec.getY() << ", " << vec.getZ() << ')';


    return out;
}

/*template<typename Type>
ostream& operator <<(ostream& os, const Vector3D<Type>& vec)
{
    Iterator<Type> iter(vec);

    if (!iter)
    {
        os << "Vector is empty.";
        return os;
    }

    os << '(' << *iter;
    for (iter++; iter; iter++)
        os << ", " << *iter ;
    os << ')';

    return os;
}*/

#endif // VECTOR_H
