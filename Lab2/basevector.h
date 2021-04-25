#ifndef BASEVECTOR_H
#define BASEVECTOR_H

class BaseVector
{
public:
    BaseVector();
    explicit BaseVector(const BaseVector& copy_base);
    virtual ~BaseVector() = 0;

    //virtual bool is_empty() const = 0;
    virtual int size() const = 0;
    virtual bool is_zero() const = 0;
    virtual bool is_unit() const = 0;
    virtual double len() const = 0;

    //virtual void set_size(int size) = 0;
protected:
    int elems_num;
};

#endif // BASEVECTOR_H
