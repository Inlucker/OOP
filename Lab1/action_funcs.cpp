#include "action_funcs.h"

//int load_model(Model &model, ifstream &stream);

int load_model(Model &model, ifstream &stream)
{
    int res = load_points_arr(model.points, stream);

    int points_max_id = get_points_number(model.points);
    if (!res)
        res = load_edges_arr(model.edges, stream, points_max_id);

    return res;
}

int load_model(Model &model, const Load &act)
{
    ifstream file(act.fileName);

    if (!file.is_open())
        return FILE_OPEN_ERROR;

    Model new_model= create_model();

    int res = load_model(new_model, file);

    if (file)
        file.close();

    if (!res)
    {
        free_model(model);
        model = new_model;
    }

    return res;
}

int move_model(Model &model, const Move &act)
{
    return move_points_arr(model.points, act);
}

int scale_model(Model &model, const Scale &act)
{
    return scale_points_arr(model.points, act);
}

int rotate_model(Model &model, const Rotate &act)
{
    return rotate_point_arr(model.points, act); //arr
}

/*int draw_model(const Draw &act)
{
    if (!act.model.points.mas)
        return MODEL_EMPTY;
}*/

int save_model(const Model &model, const Load &act)
{

    ofstream file(act.fileName);

    if (!file.is_open())
        return FILE_OPEN_ERROR;

    int res;

    res = save_point_arr(model.points, file);

    if (!res)
        res = save_edge_arr(model.edges, file);

    if (file)
        file.close();

    return res;

}
