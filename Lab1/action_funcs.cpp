#include "action_funcs.h"

#include "file_stream.h"
#include "error_codes.h"

//int load_model(Model &model, ifstream &stream);

int load_model(Model &model, Read_file &stream)
{
    int res = load_points_arr(model.points, stream);

    if (!res)
    {
        int points_max_id = get_points_number(model.points);
        res = load_edges_arr(model.edges, stream, points_max_id);
    }

    return res;
}

int load_model(Model &model, const Load &act)
{
    Read_file file;
    int res = open_file(file, act.fileName);
    if (res)
        return res;

    Model new_model = create_model();
    res = load_model(new_model, file);

    close_file(file);

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

    Write_file file;
    int res = open_file(file, act.fileName);
    if (res)
        return res;

    res = save_point_arr(model.points, file);

    if (!res)
        res = save_edge_arr(model.edges, file);

    res = close_file(file);

    return res;

}
