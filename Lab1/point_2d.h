#ifndef POINT_2D_H
#define POINT_2D_H

#include "point.h"

struct Point_2d
{
    double x;
    double y;
};

void get_point_2d(Point_2d &point_2d, Point &point_3d);

#endif // POINT_2D_H
