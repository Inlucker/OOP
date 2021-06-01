#ifndef MODELELEMENTS_H
#define MODELELEMENTS_H

#include <vector>

#include "point.h"
#include "edge.h"

using namespace std;

class ModelElements
{
public:
    ModelElements() = default;
    void addPoint(double new_x, double new_y, double new_z);
    void addEdge(int new_p1, int new_p2);
    //void addPoint(Point new_p);
    //void addEdge(Edge new_e);
    void transform(const Point move, const Point scale, const Point rotate);
    vector<Point> getPoints() const;
    vector<Edge> getEdges() const;

private:
    vector<Point> points;
    vector<Edge> edges;
};

#endif // MODELELEMENTS_H
