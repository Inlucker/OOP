#include "point.h"
#include <math.h>

#include "error_codes.h"

int load_point(Point &p, Read_file &stream)
{
    double x, y, z;
    int res = read_file(x, stream);
    if (!res)
        res = read_file(y, stream);
    if (!res)
        res = read_file(z, stream);

    if (!res)
    {
        p.x = x;
        p.y = y;
        p.z = z;
    }

    return res;
}

void move_point(Point &p, const Move &act)
{
    p.x += act.dx;
    p.y += act.dy;
    p.z += act.dz;
}

void scale_point(Point &p, const Scale &act)
{
    p.x = p.x * act.kx + 0 * (1 - act.kx);
    p.y = p.y * act.ky + 0 * (1 - act.ky);
    p.z = p.z * act.kz + 0 * (1 - act.kz);
}

void rotate_x(Point &p, double angle)
{
    //double x = p.x;
    double y = p.y;
    double z = p.z;
    p.y = y * cos(angle) + z * sin(angle);
    p.z  = -y * sin(angle) + z * cos(angle);
}

void rotate_y(Point &p, double angle)
{
    double x = p.x;
    //double y = p.y;
    double z = p.z;
    p.x = x * cos(angle) + z * sin(angle);
    p.z = -x * sin(angle) + z * cos(angle);
}

//error!
void rotate_z(Point &p, double angle)
{
    double x = p.x;
    double y = p.y;
    //double z = p.z;
    p.x = x * cos(angle) - y * sin(angle);
    p.y = x * sin(angle) + y * cos(angle);
}

void rotate_point(Point &p, const Rotate &act)
{
    rotate_x(p, act.x_angle);
    rotate_y(p, act.y_angle);
    rotate_z(p, act.z_angle);
}

int save_point(const Point& p, Write_file &file)
{
    int buff_size = DOUBLE_MAX_SIZE * 3 + 4;
    char *buff = new char[buff_size];
    snprintf(buff, buff_size, "%f %f %f\n", p.x, p.y, p.z);
    int res = print_stream(file, buff);
    delete[] buff;
    return res;
}
