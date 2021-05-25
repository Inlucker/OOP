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
    void transform();
    /*vector<Point> getPoints();
    vector<Edge> getEdges();*/

private:
    vector<Point> points;
    vector<Edge> edges;
};

#endif // MODELELEMENTS_H