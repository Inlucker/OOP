#include "edge.h"

Edge::Edge()
{
    p1 = 0;
    p2 = 0;
}

Edge::Edge(const int new_p1, const int new_p2)
{
    p1 = new_p1;
    p2 = new_p2;
}

int Edge::getFirst()
{
    return p1 - 1;
}

int Edge::getSecond()
{
    return p2 - 1;
}
