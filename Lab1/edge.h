#ifndef EDGE_H
#define EDGE_H

//typedef int edge[2];

#include "file_stream.h"
#include "error_codes.h"

struct Edge
{
    int p1;
    int p2;
};


int load_edge(Edge &e, ifstream &file);//, int max_vertex);

#endif // EDGE_H
