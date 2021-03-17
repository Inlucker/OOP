#ifndef ACTIONS_H
#define ACTIONS_H

#include "model.h"
//#include "file_stream.h"
//#include "error_codes.h"

#define FILE_NAME_SIZE 200

enum action_type
{
    ROTATE,
    LOAD,
    MOVE,
    SCALE,
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

int load_model(Model &model, const Load &act);

#endif // ACTIONS_H
