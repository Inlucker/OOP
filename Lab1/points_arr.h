#ifndef POINTS_ARR_H
#define POINTS_ARR_H

#include "point.h"
//#include "error_codes.h"
//#include "file_stream.h"

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
int load_points_arr(Points_arr &points, ifstream &file);

#endif // POINTS_ARR_H
