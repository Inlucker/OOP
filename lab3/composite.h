#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "object.h"

class Composite : public Object
{
public:
    Composite() = default;
    Composite(initializer_list<shared_ptr<Object>> args);

    virtual void transform(const Point move, const Point scale, const Point rotate) override;
    virtual bool isVisible() override;
    virtual void accept(shared_ptr<BaseVisitor> visitor) override;

    virtual bool add(shared_ptr<Object> comp) override;
    virtual bool remove(const IteratorObject& it) override;
    virtual bool isComposite() const override;
    virtual bool clear() override;
    virtual size_t size() override;
    virtual IteratorObject begin() const override;
    virtual IteratorObject end() const override;

private:
    VectorObject objectsVec;
};

#endif // COMPOSITE_H
