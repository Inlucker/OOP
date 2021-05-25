#ifndef MODEL_H
#define MODEL_H

#include "object.h"

#include "modelelements.h"

class Model : public Object
{
public:
    Model() = default;
    ~Model() = default;
    virtual void transform() override;
    virtual bool isVisible() override;
private:
    ModelElements modelElements;
};

#endif // MODEL_H
