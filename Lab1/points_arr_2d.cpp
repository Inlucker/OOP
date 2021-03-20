#include "points_arr_2d.h"

#include "error_codes.h"

Points_arr_2d create_points_arr_2d()
{
    Points_arr_2d new_points_arr_2d;
    new_points_arr_2d.mas = nullptr;
    new_points_arr_2d.points_number = 0;
    return new_points_arr_2d;
}

int allocate_points_arr_2d(Points_arr_2d &points, const int points_number)
{
    if (points_number <= 0)
        return MEMORY_ALLOCATION_ERROR;
    points.mas = new Point_2d [points_number];
    if (!(points.mas))
        return MEMORY_ALLOCATION_ERROR;
    points.points_number = points_number;
    return OK;
}

void free_points_arr_2d(Points_arr_2d &points)
{
    if (points.mas)
        delete[] points.mas;
    points.mas = nullptr;
    points.points_number = 0;
}

int get_points_arr_2d(Points_arr_2d &points_2d, const Points_arr &points_3d)
{
    int tmp = points_3d.points_number;

    int res = allocate_points_arr_2d(points_2d, tmp);
    if (res)
        return res;

    for (int i = 0; i < tmp; i++)
        get_point_2d(points_2d.mas[i], points_3d.mas[i]);

    if (res)
        free_points_arr_2d(points_2d);

    return res;
}
