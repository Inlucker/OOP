#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "object.h"

class Composite : public Object
{
private:
    VectorObject objectsVec;

public:
    Composite() = default;
    Composite(initializer_list<shared_ptr<Object>> args);

    virtual void transform() override;
    virtual bool isVisible() override;
    virtual void accept(shared_ptr<BaseVisitor> visitor) override;

    virtual bool add(shared_ptr<Object> comp) override;
    virtual bool remove(const IteratorObject& it) override;
    virtual bool isComposite() const override;
    virtual bool clear() override;
    virtual IteratorObject begin() const override;
    virtual IteratorObject end() const override;
};

#endif // COMPOSITE_H
