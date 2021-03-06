#include "points_arr.h"
//#include "defines.h"

#include "error_codes.h"

Points_arr create_points_arr()
{
    Points_arr new_points_arr;
    new_points_arr.mas = nullptr;
    new_points_arr.points_number = 0;
    return new_points_arr;
}

int allocate_points_arr(Points_arr &points, const int points_number)
{
    if (points_number <= 0)
        return MEMORY_ALLOCATION_ERROR;
    points.mas = new Point [points_number];
    if (!(points.mas))
        return MEMORY_ALLOCATION_ERROR;
    points.points_number = points_number;
    return OK;
}

void free_points_arr(Points_arr &points)
{
    if (points.mas)
        delete[] points.mas;
    points.mas = nullptr;
    points.points_number = 0;
}

int get_points_number(const Points_arr &points)
{
    return points.points_number;
}

int load_points_arr(Points_arr &points, Read_file &file)
{
    int tmp;
    int res = read_file(tmp, file);
    if (res)
        return res;

    //HERE was MEM ERROR
    res = allocate_points_arr(points, tmp);
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

int save_point_arr(const Points_arr &points, Write_file &file)
{
    int buff_size = INT_MAX_SIZE + 2;
    //Обязательно динамически?
    char *buff = new char[buff_size];
    if (!buff)
        return MEMORY_ALLOCATION_ERROR;
    snprintf(buff, buff_size, "%d\n", points.points_number);
    int res = print_stream(file, buff);
    delete[] buff;

    for(int i = 0; i < points.points_number && !res; i++)
        res = save_point(points.mas[i], file);
    return res;
}
