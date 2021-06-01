#ifndef MODEL_H
#define MODEL_H

#include "object.h"

#include "modelelements.h"
#include "basevisitor.h"

class Model : public Object
{
public:
    //Model() = default;
    Model();
    Model(shared_ptr<ModelElements> modelElements);
    ~Model() = default;
    virtual void transform(const Point move, const Point scale, const Point rotate) override;
    virtual bool isVisible() override;
    virtual void accept(shared_ptr<BaseVisitor> visitor) override;

    const shared_ptr<ModelElements> getElements() const;
private:
    shared_ptr<ModelElements> modelElements;
};

#endif // MODEL_H
