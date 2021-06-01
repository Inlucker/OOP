#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    Point(const double new_x, const double new_y, const double new_z);

    ~Point() = default;

    void transform(const Point moveK, const Point scaleK, const Point rotateK);

    double getX() const;
    double getY() const;
    double getZ() const;
private:
    void move(const Point move);
    void scale(const Point scale);
    void rotateX(const double angle);
    void rotateY(const double angle);
    void rotateZ(const double angle);
    void rotate(const Point rotate);

    double x, y, z;
};

#endif // POINT_H
