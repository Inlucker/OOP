#include "point.h"

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

void Point::transform()
{
    move();
    scale();
    turn();
}

void Point::move()
{

}

void Point::scale()
{

}

void Point::turn()
{

}
