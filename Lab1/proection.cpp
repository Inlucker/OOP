#include "proection.h"

#include "error_codes.h"

Proection create_proection()
{
    Proection new_proection;
    new_proection.points = create_points_arr_2d();
    new_proection.edges = create_edges_arr();
    return new_proection;
}

void free_proection(Proection &proection)
{
    free_edges_arr(proection.edges);
    free_points_arr_2d(proection.points);
}

int get_proection(Proection &proection, const Model &model)
{
    //int res = OK;
    Proection new_proection = create_proection();
    int res = get_points_arr_2d(new_proection.points, model.points);
    if (!res)
        res = get_edges(new_proection.edges, model.edges);

    if (!res)
    {
        free_proection(proection);
        proection = new_proection;
    }

    return res;
}
