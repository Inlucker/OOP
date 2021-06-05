#ifndef CAMERA_H
#define CAMERA_H

#include "object.h"
#include "basevisitor.h"

class ObjectDrawer;

class Camera : public Object
{
public:
    Camera() = default;
    Camera(const Point &pos, const Point &angs);
    ~Camera() = default;
    virtual void transform(const Point moveK, const Point scaleK, const Point rotateK) override;
    virtual bool isVisible() override;
    virtual void accept(shared_ptr<BaseVisitor> visitor) override;

private:
    //void move(Point move);
    void rotate(Point move);
    const Point &getPosition() const;
    const Point &getAngles() const;
    friend ObjectDrawer;

private:
    Point position;
    Point angles;
};

#endif // CAMERA_H
