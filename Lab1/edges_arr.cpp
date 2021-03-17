#include "edges_arr.h"

Edges_arr create_edges_arr()
{
    Edges_arr new_edges_arr;
    new_edges_arr.mas = nullptr;
    new_edges_arr.edges_number = 0;
    return new_edges_arr;
}

int allocate_edges_arr(Edges_arr &edges)
{
    edges.mas = new Edge [edges.edges_number];
    if (!(edges.mas))
        return MEMORY_ERROR;
    return OK;
}

void free_edges_arr(Edges_arr &edges)
{
    if (edges.mas)
        delete[] edges.mas;
    edges.mas = NULL;
    edges.edges_number = 0;
}

int load_edges_arr(Edges_arr &edges, ifstream &file)//, int max_vertex)
{
    int tmp;
    int res = read_file(tmp, file);
    if (res)
        return res;

    edges.edges_number = tmp;

    res = allocate_edges_arr(edges);
    if (res)
        return res;

    for (int i = 0; i < tmp && !res; i++)
    {
        res = load_edge(edges.mas[i], file);
    }

    if (res)
        free_edges_arr(edges);

    return res;
}
