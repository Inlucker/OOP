#ifndef ACTION_FUNCS_H
#define ACTION_FUNCS_H

//#include "model_funcs.h"
//#include "defines.h"

//#include "file_stream.h"
//#include "error_codes.h"

#include "model_funcs.h"
#include "action.h"

int load_model(Model &model, const Load &act);

int move_model(Model &model, const Move &act);

int scale_model(Model &model, const Scale &act);

int rotate_model(Model &model, const Rotate &act);

//int draw_model(const Draw &act);

int save_model(const Model &model, const Load &act);

#endif // ACTION_FUNCS_H
