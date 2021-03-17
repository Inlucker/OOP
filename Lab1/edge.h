#ifndef EDGE_H
#define EDGE_H

//#include "defines.h"
//#include "file_stream.h"
//#include "error_codes.h"

#include "file_stream.h"

//#include "error_codes.h"

struct Edge
{
    int p1;
    int p2;
};

int load_edge(Edge &e, ifstream &file, int max_point_id);//, int max_vertex);

int save_edge(const Edge& e, ofstream &file);

#endif // EDGE_H
