#include "camera.h"

void Camera::transform()
{
    cout << "Camera Transform method;" << endl;
}

bool Camera::isVisible()
{
    cout << "Camera isVisible method;" << endl;
    return false;
}

void Camera::accept(shared_ptr<BaseVisitor> visitor)
{
    visitor->visit(*this);
}
