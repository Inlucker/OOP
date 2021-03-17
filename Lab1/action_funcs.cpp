#include "action_funcs.h"
//#include <fstream>

//using namespace std;

//int load_model(Model &model, ifstream &stream);

int load_model(Model &model, ifstream &stream)
{
    int res = load_points_arr(model.points, stream);

    if (!res)
        res = load_edges_arr(model.edges, stream);

    return res;
}

int load_model(Model &model, const Load &act)
{
    //IN_Stream stream;

    ifstream file(act.fileName);

    if (!file.is_open())
        return FILE_OPEN_ERROR;

    Model new_model;

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

int rotate_model(Model &model, const Rotate &act)
{
    return rotate_point_arr(model.points, act); //arr
}

int move_model(Model &model, const Move &act)
{
    return move_points_arr(model.points, act);
}