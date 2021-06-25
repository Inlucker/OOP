#ifndef CAMERA_H
#define CAMERA_H

#include "object.h"

#include "point.h"
#include "objectvisitor.h"

//class ObjectVisitor;

class Camera : public Object
{
public:
    Camera();
    Camera(string new_name);
    Camera(const Point &pos, const Point &angs);
    Camera(string new_name, const Point &pos, const Point &angs);
    ~Camera() = default;

    virtual void transform(const Point moveK, const Point scaleK, const Point rotateK) override;
    virtual bool isVisible() const override;
    virtual void accept(shared_ptr<BaseVisitor> visitor) override;

    virtual shared_ptr<Object> clone() override;

private:
    void rotate(Point move);
    const Point &getPosition() const;
    const Point &getAngles() const;
    //friend ObjectVisitor;
    friend void ObjectVisitor::visit(const Model &model);

private:
    Point position;
    Point angles;
};

#endif // CAMERA_H
