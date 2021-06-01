#include "point.h"

#include <cmath>

Point::Point()
{
    x = 0;
    y = 0;
    z = 0;
}

Point::Point(const double new_x, const double new_y, const double new_z)
{
    x = new_x;
    y = new_y;
    z = new_z;
}

void Point::transform(const Point moveK, const Point scaleK, const Point rotateK)
{
    move(moveK);
    scale(scaleK);
    rotate(rotateK);
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

double Point::getZ() const
{
    return z;
}

void Point::move(const Point move)
{
    x += move.getX();
    y += move.getY();
    z += move.getZ();
}

void Point::scale(const Point scale)
{
    this->x *= scale.getX();
    this->y *= scale.getY();
    this->z *= scale.getZ();
}


void Point::rotateX(const double angle)
{
    double radians = angle * M_PI / 180;
    double tmp_y = y;
    double tmp_z = z;
    y = tmp_y * cos(radians) + tmp_z * sin(radians);
    z  = -tmp_y * sin(radians) + tmp_z * cos(radians);
}

void Point::rotateY(const double angle)
{
    double radians = angle * M_PI / 180;
    double tmp_x = x;
    double tmp_z = z;
    x = tmp_x * cos(radians) + tmp_z * sin(radians);
    z = -tmp_x * sin(radians) + tmp_z * cos(radians);
}

void Point::rotateZ(const double angle)
{
    double radians = angle * M_PI / 180;
    double tmp_x = x;
    double tmp_y = y;
    x = tmp_x * cos(radians) - tmp_y * sin(radians);
    y = tmp_x * sin(radians) + tmp_y * cos(radians);
}

void Point::rotate(const Point rotate)
{
    rotateX(rotate.getX());
    rotateY(rotate.getY());
    rotateZ(rotate.getZ());
}

