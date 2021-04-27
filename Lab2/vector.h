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
    Vector(int elements_number, Type* mas);
    Vector(int elements_number, Type vec, ...);
    Vector(initializer_list<Type> args);

    explicit Vector(const Vector& vec); //copy //why explicit
    Vector<Type>& operator =(const Vector& vec);
    Vector(Vector<Type>&& vec); //Перенеос //explicit?
    Vector<Type>& operator =(Vector<Type>&& vec);

    ~Vector();

    bool is_empty() const;
    int size() const;

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

    //Math
    double len() const;
    bool is_zero() const;
    bool is_unit() const;
    Vector<Type> get_unit() const;
    Type operator *(const Vector<Type>& vec) const;
    double get_angle(const Vector<Type>& vec2) const;
    bool is_collinear(const Vector<Type>& vec) const;
    bool is_orthogonal(const Vector<Type>& vec) const;

    Vector<Type> operator +(const Type val) const;
    Vector<Type>& operator +=(const Type val);
    Vector<Type> operator +(const Vector<Type>& vec) const;
    Vector<Type>& operator +=(const Vector<Type>& vec);

    Vector<Type> operator -(const Type val) const;
    Vector<Type>& operator -=(const Type val);
    Vector<Type> operator -(const Vector<Type>& vec) const;
    Vector<Type>& operator -=(const Vector<Type>& vec);

    Vector<Type> operator *(const Type val);
    Vector<Type>& operator *=(const Type val);
    Vector<Type> operator /(const Type val);
    Vector<Type>& operator /=(const Type val);

    Vector<Type> operator &(const Vector<Type>& vec) const;
    Vector<Type>& operator &=(const Vector<Type>& vec);

    //template<typename Type2>
    //Vector<Type> operator *(const Vector<Type2>& vec) const;
    template<typename Type2>
    Vector<Type> operator *(const Vector<Type2>& vec) const
    {
        time_t t_time = time(NULL);
        if (is_empty() || vec.is_empty())
            throw EmptyError("vec1 or/and vec2 is empty", __FILE__, __LINE__, ctime(&t_time));
        if (size() != vec.size())
            throw DifSizeError("vec1 size != vec2 size", __FILE__, __LINE__, ctime(&t_time));

        Vector<Type> rez(elems_num);
        int i = 0;
        Iterator<Type> It1 = this->begin();
        for (Iterator<Type2> It2 = vec.begin(); It1 != this->end() || It2 != vec.end(); It1++, It2++)
        {
            rez[i++] = (*It1) * (*It2);
        }
        return rez;
    }

    //template<typename Type2>
    //Vector<Type>& operator *=(const Vector<Type2>& vec);
    template<typename Type2>
    Vector<Type>& operator *=(const Vector<Type2>& vec)
    {
        Vector<Type> mult_vec = *this * vec;
        *this = Vector<Type>(mult_vec);
        return *this;
    }

    bool is_null() const;

    friend class Iterator<Type>;

private:
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

        //for each
        for (auto &elem:*this)
            elem = 0;
    /*for (Iterator<Type> It = this->begin(); It != this->end(); ++It)
        *It = 0;*/
}

template<typename Type>
Vector<Type>::Vector(int elements_number, Type *mas)
{
    //check elems number?
    time_t t_time = time(NULL);
    if (elements_number < 0 || !mas)
        throw NegativeSizeError("elements_number < 0 or/and nullptr mas", __FILE__, __LINE__, ctime(&t_time));


    elems_num = elements_number;
    alloc_data();

    int i = 0;
    /*for (Iterator<Type> It = this->begin(); It != this->end(); ++It)
        *It = vec[i++];*/
    //for each
    for (auto &elem:*this)
        elem = mas[i++];
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
    //for each
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
    for (auto &elem : args)
    {
        *it = elem;
        it++;
    }
}

template<typename Type>
Vector<Type>::Vector(const Vector &vec)
{
    time_t t_time = time(NULL);
    if (vec.size() < 0)
        throw NegativeSizeError("vec elements_number < 0", __FILE__, __LINE__, ctime(&t_time));
    elems_num = vec.size(); // vec.elems_num как правильней?

    alloc_data();

    for (int i = 0; i < elems_num; i++)
        data_ptr[i] = vec[i]; //vec.get_elem(i); //vec.data_ptr[i] WHY THIS WORKS????????? Почему vec.data_ptr[i] работает именно внутри методов класса? Потому что они друзья?
    //cout << "HERE copy constructor" << endl;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator =(const Vector<Type> &vec)
{
    time_t t_time = time(NULL);
    //Не обязательно, потому что мы не допускаем создание векторов с отрицательным кол-вом элементов
    if (vec.size() < 0)
        throw NegativeSizeError("vec elements_number < 0", __FILE__, __LINE__, ctime(&t_time));
    elems_num = vec.size();

    alloc_data();

    for (int i = 0; i < elems_num; i++)
        data_ptr[i] = vec[i];
    //cout << "HERE copy operator =" << endl;
    return *this;
}

template<typename Type>
Vector<Type>::Vector(Vector<Type> &&vec)
{
    time_t t_time = time(NULL);
    if (vec.size() < 0)
        throw NegativeSizeError("vec elements_number < 0", __FILE__, __LINE__, ctime(&t_time));
    elems_num = vec.size();

    /*alloc_data();

    for (int i = 0; i < elems_num; i++)
        data_ptr[i] = vec[i];*/
    data_ptr = vec.data_ptr;
    //cout << "HERE transfer constructor" << endl; //Почему не печатается?
    //vec.data_ptr.reset(); // Не обязательно с умными указателями
}

template<typename Type>
Vector<Type> &Vector<Type>::operator =(Vector<Type> &&vec)
{
    time_t t_time = time(NULL);
    //Не обязательно, потому что мы не допускаем создание векторов с отрицательным кол-вом элементов
    if (vec.size() < 0)
        throw NegativeSizeError("vec elements_number < 0", __FILE__, __LINE__, ctime(&t_time));
    elems_num = vec.size();

    /*alloc_data();

    for (int i = 0; i < elems_num; i++)
        data_ptr[i] = vec[i];*/
    data_ptr = vec.data_ptr;
    //cout << "HERE transfer operator =" << endl;
    //vec.data_ptr.reset(); // Не обязательно с умными указателями
    return *this;
}

template<typename Type>
Vector<Type>::~Vector()
{
    //cout << "vector: ";
    if (data_ptr)
    {
        //cout << *this;
        data_ptr.reset();
    }
    //cout << " destroyed" << endl;
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
    time_t t_time = time(NULL);
    if (is_empty())
        throw EmptyError("vector is empty", __FILE__, __LINE__, ctime(&t_time));
    double len = 0;

    Vector<double> tmp_vec(*this);
    for (auto &elem:tmp_vec)
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
}

template<typename Type>
Vector<Type> Vector<Type>::get_unit() const
{
    time_t t_time = time(NULL);
    if (is_empty())
        throw EmptyError("vector is empty", __FILE__, __LINE__, ctime(&t_time));

    Vector<Type> unit_vector(*this);
    double length = len();
    for (auto &elem:unit_vector)
    {
        elem = elem / length;
    }
    return unit_vector;
}

template<typename Type>
Type Vector<Type>::operator *(const Vector<Type> &vec) const
{
    time_t t_time = time(NULL);
    if (is_empty() || vec.is_empty())
        throw EmptyError("vec1 or/and vec2 is empty", __FILE__, __LINE__, ctime(&t_time));
    if (size() != vec.size())
        throw DifSizeError("vec1 size != vec2 size", __FILE__, __LINE__, ctime(&t_time));

    double rez = 0;
    Iterator<Type> It1 = this->begin();
    for (Iterator<Type> It2 = vec.begin(); It1 != this->end() || It2 != vec.end(); It1++, It2++)
    {
        rez += (*It1) * (*It2);
    }
    return rez;
}

template<typename Type>
double Vector<Type>::get_angle(const Vector<Type> &vec) const
{
    time_t t_time = time(NULL);
    if (is_empty() || vec.is_empty())
        throw EmptyError("vec1 or/and vec2 is empty", __FILE__, __LINE__, ctime(&t_time));
    if (size() != vec.size())
        throw DifSizeError("vec1 size != vec2 size", __FILE__, __LINE__, ctime(&t_time));
    if (!this->len() || !vec.len())
        throw ZeroDivError("vec1 or/and vec2 len = 0", __FILE__, __LINE__, ctime(&t_time));

    double numerator = (*this) * vec;
    double denominator = (*this).len() * vec.len();
    double angle = numerator / denominator;
    angle = acos(angle) * 180 / M_PI;
    return angle;
}

template<typename Type>
double get_angle(const Vector<Type> &vec1, const Vector<Type> &vec2)
{
    return  vec1.get_angle(vec2);
}

template<typename Type>
bool Vector<Type>::is_collinear(const Vector<Type> &vec) const
{
    return get_angle(vec) < EPS;
}

template<typename Type>
bool is_collinear(const Vector<Type> &vec1, const Vector<Type> &vec2)
{
    return vec1.is_collinear(vec2);
}

template<typename Type>
bool Vector<Type>::is_orthogonal(const Vector<Type> &vec) const
{
    return abs(90 - get_angle(vec)) < EPS;
}

template<typename Type>
bool is_orthogonal(const Vector<Type> &vec1, const Vector<Type> &vec2)
{
    return vec1.is_orthogonal(vec2);
}

template<typename Type>
Vector<Type> Vector<Type>::operator +(const Type val) const
{
    time_t t_time = time(NULL);
    if (is_empty())
        throw EmptyError("vector is empty", __FILE__, __LINE__, ctime(&t_time));

    Vector<Type> rez(*this);
    for (auto &elem:rez)
        elem += val;
    return rez;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator +=(const Type val)
{
    time_t t_time = time(NULL);
    if (is_empty())
        throw EmptyError("vector is empty", __FILE__, __LINE__, ctime(&t_time));

    for (auto &elem:*this)
        elem += val;
    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::operator +(const Vector<Type> &vec) const
{
    time_t t_time = time(NULL);
    if (is_empty() || vec.is_empty())
        throw EmptyError("vec1 or/and vec2 is empty", __FILE__, __LINE__, ctime(&t_time));
    if (size() != vec.size())
        throw DifSizeError("vec1 size != vec2 size", __FILE__, __LINE__, ctime(&t_time));

    Vector<Type> rez(elems_num);
    int i = 0;
    Iterator<Type> It1 = this->begin();
    for (Iterator<Type> It2 = vec.begin(); It1 != this->end() || It2 != vec.end(); It1++, It2++)
    {
        rez[i++] = (*It1) + (*It2);
    }
    return rez;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator +=(const Vector<Type> &vec)
{
    Vector<Type> sum_vec = *this + vec;
    *this = Vector<Type>(sum_vec);
    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::operator -(const Type val) const
{
    time_t t_time = time(NULL);
    if (is_empty())
        throw EmptyError("vec is empty", __FILE__, __LINE__, ctime(&t_time));

    Vector<Type> rez(*this);
    for (auto &elem:rez)
        elem -= val;
    return rez;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator -=(const Type val)
{
    time_t t_time = time(NULL);
    if (is_empty())
        throw EmptyError("vec is empty", __FILE__, __LINE__, ctime(&t_time));

    for (auto &elem:*this)
        elem -= val;
    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::operator -(const Vector<Type> &vec) const
{
    time_t t_time = time(NULL);
    if (is_empty() || vec.is_empty())
        throw EmptyError("vec1 or/and vec2 is empty", __FILE__, __LINE__, ctime(&t_time));
    if (size() != vec.size())
        throw DifSizeError("vec1 size != vec2 size", __FILE__, __LINE__, ctime(&t_time));

    Vector<Type> rez(elems_num);
    int i = 0;
    Iterator<Type> It1 = this->begin();
    for (Iterator<Type> It2 = vec.begin(); It1 != this->end() || It2 != vec.end(); It1++, It2++)
    {
        rez[i++] = (*It1) - (*It2);
    }
    return rez;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator -=(const Vector<Type> &vec)
{
    Vector<Type> sum_vec = *this - vec;
    *this = Vector<Type>(sum_vec);
    return *this;
}


template<typename Type>
Vector<Type> Vector<Type>::operator *(const Type val)
{
    time_t t_time = time(NULL);
    if (is_empty())
        throw EmptyError("vec is empty", __FILE__, __LINE__, ctime(&t_time));

    Vector<Type> rez(*this);
    for (auto &elem:rez)
        elem = elem * val;
    return rez;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator *=(const Type val)
{
    Vector<Type> mul_vec = *this * val;
    *this = Vector<Type>(mul_vec);
    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::operator /(const Type val)
{
    time_t t_time = time(NULL);
    if (is_empty())
        throw EmptyError("vec is empty", __FILE__, __LINE__, ctime(&t_time));

    Vector<Type> rez(*this);
    for (auto &elem:rez)
        elem = elem / val;
    return rez;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator /=(const Type val)
{
    Vector<Type> div_vec = *this / val;
    *this = Vector<Type>(div_vec);
    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::operator &(const Vector<Type> &vec) const
{
    time_t t_time = time(NULL);
    if (is_empty() || vec.is_empty())
        throw EmptyError("vec1 or/and vec2 is empty", __FILE__, __LINE__, ctime(&t_time));
    if (size() != vec.size())
        throw DifSizeError("vec1 size != vec2 size", __FILE__, __LINE__, ctime(&t_time));
    if (size() != 2 && size() != 3)
        throw SizeError("vec is not 2D or 3D", __FILE__, __LINE__, ctime(&t_time));

    Type x = 0, y = 0, z = 0;
    if (elems_num == 3)
    {
        x = (*this)[1] * vec[2] - (*this)[2] * vec[1];
        y = (*this)[2] * vec[0] - (*this)[0] * vec[2];
        z = (*this)[0] * vec[1] - (*this)[1] * vec[0];
    }
    else if (elems_num == 2)
    {
        //x = (*this)[1] * 0 - 0 * vec[1];
        //y = 0 * vec[0] - (*this)[0] * 0;
        z = (*this)[0] * vec[1] - (*this)[1] * vec[0];
    }

    Vector<Type> rez{x, y, z};
    return rez;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator &=(const Vector<Type> &vec)
{
    Vector<Type> mult_vec = *this & vec;
    *this = Vector<Type>(mult_vec);
    return *this;
}

template<typename Type>
bool Vector<Type>::is_null() const
{
    return data_ptr == nullptr;
}

template<typename Type>
void Vector<Type>::alloc_data()
{
    data_ptr.reset();
    if (elems_num != 0)
    {
        shared_ptr<Type[]> new_ptr(new Type[elems_num]);

        time_t t_time = time(NULL);
        if (!new_ptr)
            throw MemoryError("allocationg data_ptr error", __FILE__, __LINE__, ctime(&t_time));

        data_ptr = new_ptr;
    }
}

//template<typename T> constexpr const T &as_const(T &t) noexcept { return t; }
//for (auto &v: as_const(container))

template<typename Type>
ostream& operator <<(ostream& os, const Vector<Type>& vec)
{
    //time_t t_time = time(NULL);
    /*if (vec.is_null())
        throw MemoryError("data_ptr = NULL", __FILE__, __LINE__, ctime(&t_time));*/

    if (vec.is_empty() || vec.is_null())
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
