#ifndef EDGES_ARR_H
#define EDGES_ARR_H

#include "edge.h"

//Edges_arr operations
Edges_arr create_edges_arr();

int allocate_edges_arr(Edges_arr &vertex);

void free_edges_arr(Edges_arr &points);

//Other funcs
int load_edges_arr(Edges_arr &edges, ifstream &file, int max_point_id);

int save_edge_arr(const Edges_arr &edges, ofstream &file);

#endif // EDGES_ARR_H
