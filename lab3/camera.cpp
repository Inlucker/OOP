#include "camera.h"

Camera::Camera(const Point &pos, const Point &angs)
{
    position = pos;
    angles = angs;
}

void Camera::transform(const Point moveK, const Point scaleK, const Point rotateK)
{
    //move(moveK);
    //rotate(rotateK);
    position.transform(moveK, scaleK, rotateK, position);
}

bool Camera::isVisible()
{
    return false;
}

void Camera::accept(shared_ptr<BaseVisitor> visitor)
{
    if (isVisible())
        visitor->visit(*this);
}

void Camera::rotate(Point rotateK)
{
    angles.setX(position.getX()+rotateK.getX());
    angles.setY(position.getY()+rotateK.getY());
    angles.setZ(position.getZ()+rotateK.getZ());
}

const Point &Camera::getPosition() const
{
    return position;
}

const Point &Camera::getAngles() const
{
    return angles;
}

/*void Camera::move(Point moveK)
{
    position.setX(position.getX()+moveK.getX());
    position.setY(position.getY()+moveK.getY());
    position.setZ(position.getZ()+moveK.getZ());
}*/
