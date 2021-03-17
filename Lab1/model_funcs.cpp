#include "model_funcs.h"

Model create_model()
{
    Model new_model;
    new_model.points = create_points_arr();
    new_model.edges = create_edges_arr();
    return new_model;
}

void free_model(Model &model)
{
    free_edges_arr(model.edges);
    free_points_arr(model.points);
}
