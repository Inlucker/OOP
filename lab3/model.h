#ifndef MODEL_H
#define MODEL_H

#include "object.h"

class Model : public Object
{
public:
    Model() = default;
    ~Model() = default;
    virtual void transform() override;
    virtual bool isVisible() override;
};

#endif // MODEL_H
