#include "edge.h"

#include "error_codes.h"
#include "defines.h"

int load_edge(Edge &e, Read_file &file, int max_point_id)
{
    int id1;
    int id2;
    int res = read_file(id1, file);
    if (!res)
        res = read_file(id2, file);

    if (id1 > max_point_id || id2 > max_point_id)
        return FILE_ERROR;

    if (!res)
    {
        e.p1 = id1 - 1;
        e.p2 = id2 - 1;
    }

    return res;
}

int save_edge(const Edge& e, Write_file &file)
{
    int buff_size = INT_MAX_SIZE * 2 + 3;
    char *buff = new char[buff_size];
    snprintf(buff, buff_size, "%d %d\n", e.p1 + 1, e.p2 + 1);
    int res = print_stream(file, buff);
    delete[] buff;
    return res;
}

void get_edge(Edge &edge_2d, const Edge &edge_3d)
{
    edge_2d = edge_3d;
}
