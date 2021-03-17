#include "model.h"

/*Model create_model()
{
    Model new_model;
    return new_model;
}*/

void free_model(Model &model)
{
    free_edges_arr(model.edges);
    free_points_arr(model.points);
}
