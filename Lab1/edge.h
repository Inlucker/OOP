#ifndef EDGE_H
#define EDGE_H

//typedef int edge[2];

#include "defines.h"
#include "file_stream.h"
#include "error_codes.h"

int load_edge(Edge &e, ifstream &file);//, int max_vertex);

int save_edge(const Edge& e, ofstream &file);

#endif // EDGE_H
