#ifndef POINTS_ARR_H
#define POINTS_ARR_H

//#include "point.h"

//#include "defines.h"
//#include "error_codes.h"
//#include "file_stream.h"

#include "file_stream.h"
#include "action.h"
#include "point.h"

struct Points_arr
{
    Point *mas = nullptr;
    int points_number = 0;
};

//Points_arr operations
Points_arr create_points_arr();

int allocate_points_arr(Points_arr &vertex);

void free_points_arr(Points_arr &points);

//Other funcs
int get_points_number(const Points_arr &points);

int load_points_arr(Points_arr &points, Read_file &file);

int move_points_arr(Points_arr &points, const Move &act);

int scale_points_arr(Points_arr &points, const Scale &act);

int rotate_point_arr(Points_arr &points, const Rotate &act);

int save_point_arr(const Points_arr &points, Write_file &file);

#endif // POINTS_ARR_H
