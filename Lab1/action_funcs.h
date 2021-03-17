#ifndef ACTION_FUNCS_H
#define ACTION_FUNCS_H

#include "model.h"
#include "action.h"
//#include "file_stream.h"
//#include "error_codes.h"

int load_model(Model &model, const Load &act);

int move_model(Model &model, const Move &act);

int rotate_model(Model &model, const Rotate &act);

#endif // ACTION_FUNCS_H
