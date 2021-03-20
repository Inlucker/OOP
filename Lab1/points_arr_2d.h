#ifndef POINTS_ARR_2D_H
#define POINTS_ARR_2D_H

#include "point_2d.h"
#include "points_arr.h"

struct Points_arr_2d
{
    Point_2d *mas = nullptr;
    int points_number = 0;
};

//Points_arr_2d operations
Points_arr_2d create_points_arr_2d();

int allocate_points_arr_2d(Points_arr_2d &points, const int points_number);

void free_points_arr_2d(Points_arr_2d &points);

//Other funcs

int get_points_arr_2d(Points_arr_2d &points_2d, const Points_arr &points_3d);

#endif // POINTS_ARR_2D_H
