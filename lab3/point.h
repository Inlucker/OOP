#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    Point(const double new_x, const double new_y, const double new_z);

    ~Point() = default;

    void transform();
private:
    void move();
    void scale();
    void turn();

    double x, y, z;
};

#endif // POINT_H
