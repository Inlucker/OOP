#ifndef CAMERA_H
#define CAMERA_H

#include "object.h"

class Camera : public Object
{
public:
    Camera() = default;
    ~Camera() = default;
    virtual void transform() override;
    virtual bool isVisible() override;
};

#endif // CAMERA_H
