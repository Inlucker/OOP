#ifndef EDGE_H
#define EDGE_H

class Edge
{
public:
    Edge();
    Edge(const int new_p1, const int new_p2);

    ~Edge() = default;
private:
    int p1, p2;
};

#endif // EDGE_H
