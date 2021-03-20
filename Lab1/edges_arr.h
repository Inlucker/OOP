#ifndef EDGES_ARR_H
#define EDGES_ARR_H

#include "edge.h"

struct Edges_arr
{
    Edge *mas = nullptr;
    int edges_number = 0;
};

//Edges_arr operations
Edges_arr create_edges_arr();

int allocate_edges_arr(Edges_arr &edges, const int edges_number);

void free_edges_arr(Edges_arr &edges);

//Other funcs
int load_edges_arr(Edges_arr &edges, Read_file &file, int max_point_id);

int save_edge_arr(const Edges_arr &edges, Write_file &file);

int get_edges(Edges_arr &edges_arr_2d, const Edges_arr &edges_arr_3d);

#endif // EDGES_ARR_H
