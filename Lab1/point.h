#ifndef POINT_H
#define POINT_H

#include "file_stream.h"
#include "error_codes.h"

struct Point
{
    double x;
    double y;
    double z;
};

int load_point(Point &p, ifstream &stream);

#endif // POINT_H
