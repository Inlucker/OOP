#ifndef MODEL_FUNCS_H
#define MODEL_FUNCS_H

#include "points_arr.h"
#include "edges_arr.h"

struct Model
{
    Points_arr points;
    Edges_arr edges;
};

Model create_model();

void free_model(Model &model);

#endif // MODEL_FUNCS_H
