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

void ModelElements::transform(const Point move, const Point scale, const Point rotate)
{
    /*for (auto point : points)
        point.transform(move, scale, rotate);*/
    for (size_t i = 0; i < points.size(); i++)
        points.at(i).transform(move, scale, rotate);
}

vector<Point> ModelElements::getPoints() const
{
    return points;
}

vector<Edge> ModelElements::getEdges() const
{
    return edges;
}
