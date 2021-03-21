#ifndef ACTION_H
#define ACTION_H

#include "defines.h"

enum action_type
{
    LOAD,
    MOVE,
    SCALE,
    ROTATE,
    FREE,
    PROECTION,
    SAVE
};

struct Load
{
    //char fileName[FILE_NAME_SIZE];
    char *fileName;
    int file_name_size;
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
    Load load;
    Move move;
    Scale scale;
    Rotate rotate;
    //bool free;
};

#endif // ACTION_H
