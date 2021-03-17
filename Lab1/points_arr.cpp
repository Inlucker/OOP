#include "points_arr.h"
//#include "defines.h"

Points_arr create_points_arr()
{
    Points_arr new_points_arr;
    new_points_arr.mas = nullptr;
    new_points_arr.points_number = 0;
    return new_points_arr;
}

int allocate_points_arr(Points_arr &points)
{
    points.mas = new Point [points.points_number];
    if (!(points.mas))
        return MEMORY_ERROR;
    return OK;
}

void free_points_arr(Points_arr &points)
{
    if (points.mas)
        delete[] points.mas;
    points.mas = NULL;
    points.points_number = 0;
}

int get_points_number(Points_arr &points)
{
    return points.points_number;
}

int load_points_arr(Points_arr &points, ifstream &file)
{
    int tmp;
    int res = read_file(tmp, file);
    if (res)
        return res;
    points.points_number = tmp;

    res = allocate_points_arr(points);
    if (res)
        return res;

    for (int i = 0; i < tmp && !res; i++)
        res = load_point(points.mas[i], file);

    if (res)
        free_points_arr(points);

    return res;
}

int move_points_arr(Points_arr &points, const Move &act)
{
    if (!points.mas)
        return MODEL_EMPTY;

    //int res = OK;

    for (int i = 0; i < points.points_number; i++)
        move_point(points.mas[i], act);

    return OK;
}

int scale_points_arr(Points_arr &points, const Scale &act)
{
    if (!points.mas)
        return MODEL_EMPTY;

    for (int i = 0; i < points.points_number; i++)
        scale_point(points.mas[i], act);

    return OK;
}

int rotate_point_arr(Points_arr &points, const Rotate &act)
{
    if (!points.mas)
        return MODEL_EMPTY;

    for (int i = 0; i < points.points_number; i++)
        rotate_point(points.mas[i], act);

   return OK;
}

int save_point_arr(const Points_arr &points, ofstream &file)
{
    char buff[BUFF_SIZE];
    snprintf(buff, BUFF_SIZE, "%d\n", points.points_number);
    int ret = print_stream(file, buff);

    for(int i = 0; i < points.points_number && !ret; i++)
        ret = save_point(points.mas[i], file);
    return ret;
}
