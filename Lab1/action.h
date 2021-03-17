#ifndef ACTION_H
#define ACTION_H

#define FILE_NAME_SIZE 200

enum action_type
{
    LOAD,
    MOVE,
    SCALE,
    ROTATE,
    FREE,
    SAVE,
    DRAW
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

union Action
{
    Load create;
    Move move;
    Scale scale;
    Rotate rotate;
};

#endif // ACTION_H
