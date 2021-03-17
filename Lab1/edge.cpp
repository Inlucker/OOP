#include "edge.h"

int load_edge(Edge &e, ifstream &file)
{
    int id1;
    int id2;
    int res = read_file(id1, file);
    if (!res)
        res = read_file(id2, file);

    /*if(!(Check_number_vertex(x, 1, max_vertex) && Check_number_vertex(y, 1, max_vertex)))
        return FILE_ERROR;*/

    if (!res)
    {
        e.p1 = id1 - 1;
        e.p2 = id2 - 1;
    }

    return res;
}

int save_edge(const Edge& e, ofstream &file)
{
    char buff[BUFF_SIZE];
    snprintf(buff, BUFF_SIZE, "%d %d\n", e.p1 + 1, e.p2 + 1);
    return print_stream(file, buff);
}
