#include "edges_arr.h"

#include "error_codes.h"
#include "defines.h"

Edges_arr create_edges_arr()
{
    Edges_arr new_edges_arr;
    new_edges_arr.mas = nullptr;
    new_edges_arr.edges_number = 0;
    return new_edges_arr;
}

int allocate_edges_arr(Edges_arr &edges, const int edges_number)
{
    edges.mas = new Edge [edges_number];
    if (!(edges.mas))
        return MEMORY_ERROR;
    edges.edges_number = edges_number;
    return OK;
}

void free_edges_arr(Edges_arr &edges)
{
    if (edges.mas)
        delete[] edges.mas;
    edges.mas = NULL;
    edges.edges_number = 0;
}

int load_edges_arr(Edges_arr &edges, Read_file &file, int max_point_id)
{
    int tmp;
    int res = read_file(tmp, file);
    if (res)
        return res;

    res = allocate_edges_arr(edges, tmp);
    if (res)
        return res;

    for (int i = 0; i < tmp && !res; i++)
        res = load_edge(edges.mas[i], file, max_point_id);

    if (res)
        free_edges_arr(edges);

    return res;
}

int save_edge_arr(const Edges_arr &edges, Write_file &file)
{
    char buff[BUFF_SIZE];
    snprintf(buff, BUFF_SIZE, "%d\n", edges.edges_number);
    int ret = print_stream(file, buff);

    for(int i = 0; i < edges.edges_number && !ret; i++)
        ret = save_edge(edges.mas[i], file);

    return ret;
}
