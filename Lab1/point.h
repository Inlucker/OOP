#ifndef POINT_H
#define POINT_H

#include "file_stream.h"
#include "error_codes.h"
#include "action.h"

struct Point
{
    double x;
    double y;
    double z;
};

int load_point(Point &p, ifstream &stream);

void move_point(Point &p, const Move &act);

#endif // POINT_H
