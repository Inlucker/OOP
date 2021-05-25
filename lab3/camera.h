#ifndef CAMERA_H
#define CAMERA_H

#include "object.h"
#include "basevisitor.h"

class Camera : public Object
{
public:
    Camera() = default;
    ~Camera() = default;
    virtual void transform() override;
    virtual bool isVisible() override;
    virtual void accept(shared_ptr<BaseVisitor> visitor) override;
};

#endif // CAMERA_H
