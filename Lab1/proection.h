#ifndef PROECTION_H
#define PROECTION_H

#include "points_arr_2d.h"
#include "edges_arr.h"
#include "model_funcs.h"

struct Proection
{
    Points_arr_2d points;
    Edges_arr edges;
};

Proection create_proection();

void free_proection(Proection &proection);

int get_proection(Proection &proection, const Model &model);

#endif // PROECTION_H
