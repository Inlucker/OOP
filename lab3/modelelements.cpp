#include "modelelements.h"

/*ModelElements::ModelElements()
{

}*/

void ModelElements::addPoint(double new_x, double new_y, double new_z)
{
    points.push_back(Point(new_x, new_y, new_z));
}

void ModelElements::addEdge(int new_p1, int new_p2)
{
    edges.push_back(Edge(new_p1, new_p2));
}

void ModelElements::transform()
{
    for (auto point : points)
        point.transform();
}

vector<Point> ModelElements::getPoints() const
{
    return points;
}

vector<Edge> ModelElements::getEdges() const
{
    return edges;
}
