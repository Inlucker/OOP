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

int load_edge(Edge &e, Read_file &file, int max_point_id);//, int max_vertex);

int save_edge(const Edge& e, Write_file &file);

void get_edge(Edge &edge_2d, const Edge &edge_3d);

#endif // EDGE_H
