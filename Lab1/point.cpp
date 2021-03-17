#include "point.h"

int load_point(Point &p, ifstream &stream)
{
    double x, y, z;
    int res = OK;
    res = read_file(x, stream);
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
