#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "object.h"

class Composite : public Object
{
public:
    Composite();
    Composite(string new_name);
    explicit Composite(int elements_number);
    Composite(initializer_list<shared_ptr<Object>> args);

    virtual void transform(const Point move, const Point scale, const Point rotate) override;
    virtual bool isVisible() const override;
    virtual void accept(shared_ptr<BaseVisitor> visitor) override;

    virtual shared_ptr<Object> clone() override;

    virtual bool add(shared_ptr<Object> comp) override;
    virtual bool remove(IteratorObject &it) override;
    virtual bool isComposite() const override;
    virtual bool clear() override;
    virtual int size() const override;
    /*virtual IteratorObject begin() const override;
    virtual IteratorObject end() const override;*/

    Iterator<Type> begin() noexcept override;
    Iterator<Type> end() noexcept override;
    ConstIterator<Type> cbegin() const noexcept override; //Added constIterator
    ConstIterator<Type> cend() const noexcept override;
    //ConstIterator<Type> begin() const noexcept;
    //ConstIterator<Type> end() const noexcept;

private:
    void alloc_data();

private:
    //VectorObject objectsVec;
    shared_ptr<Type[]> data_ptr;
    int elems_num;
};

#endif // COMPOSITE_H
