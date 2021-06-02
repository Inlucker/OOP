#include "modelelements.h"

/*ModelElements::ModelElements()
{

}*/

void ModelElements::addPoint(double new_x, double new_y, double new_z)
{
    points.push_back(Point(new_x, new_y, new_z));
    updateCenter();
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
        points.at(i).transform(move, scale, rotate, center);
    updateCenter();
}

vector<Point> ModelElements::getPoints() const
{
    return points;
}

vector<Edge> ModelElements::getEdges() const
{
    return edges;
}

void ModelElements::updateCenter()
{
    int i = 0;
    Point rez(0, 0, 0);
    for (auto point : points)
    {
        rez.setX(rez.getX() + point.getX());
        rez.setY(rez.getY() + point.getY());
        rez.setZ(rez.getZ() + point.getZ());
        i++;
    }
    rez.setX(rez.getX()/i);
    rez.setY(rez.getY()/i);
    rez.setZ(rez.getZ()/i);
    center = rez;
}
