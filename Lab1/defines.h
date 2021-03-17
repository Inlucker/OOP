#ifndef DEFINES_H
#define DEFINES_H

#define FILE_NAME_SIZE 200

struct Point
{
    double x;
    double y;
    double z;
};

struct Points_arr
{
    Point *mas = nullptr;
    int points_number = 0;
};

struct Edge
{
    int p1;
    int p2;
};

struct Edges_arr
{
    Edge *mas = nullptr;
    int edges_number = 0;
};

struct Model
{
    Points_arr points;
    Edges_arr edges;
};

enum action_type
{
    LOAD,
    MOVE,
    SCALE,
    ROTATE,
    FREE,
    DRAW,
    SAVE
};

struct Load
{
    char fileName[FILE_NAME_SIZE];
};

struct Move
{
    double dx;
    double dy;
    double dz;
};

struct Scale
{
    double kx;
    double ky;
    double kz;
};

struct Rotate
{
    double x_angle;
    double y_angle;
    double z_angle;
};

/*struct Draw
{
    Model model;
};*/

union Action
{
    Load load;
    Move move;
    Scale scale;
    Rotate rotate;
    //Draw draw;
};

#endif // DEFINES_H
