#ifndef POINT_H
#define POINT_H

#include "file_stream.h"
#include "error_codes.h"
#include "defines.h"

int load_point(Point &p, ifstream &stream);

void move_point(Point &p, const Move &act);

void scale_point(Point &p, const Scale &act);

void rotate_point(Point &p, const Rotate &act);

#endif // POINT_H
