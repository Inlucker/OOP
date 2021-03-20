#ifndef POINT_H
#define POINT_H

//#include "defines.h"
//#include "file_stream.h"
//#include "error_codes.h"

#include "action.h"
#include "file_stream.h"

//#include "error_codes.h"

struct Point
{
    double x;
    double y;
    double z;
};

int load_point(Point &p, Read_file &stream);

void move_point(Point &p, const Move &act);

void scale_point(Point &p, const Scale &act);

void rotate_point(Point &p, const Rotate &act);

int save_point(const Point& p, Write_file &file);

#endif // POINT_H
