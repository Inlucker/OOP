#include "entry_point.h"
//#include "model.h"

int entry_point(Model &model, action_type t, const Action &act)
{
    int res = OK;
    switch (t)
    {
    case LOAD:
        res = load_model(model, act.load);
        break;
    case MOVE:
        res = move_model(model, act.move);
        break;
    case SCALE:
        res = scale_model(model, act.scale);
        break;
    case ROTATE:
        res = rotate_model(model, act.rotate);
        break;
    case FREE:
        free_model(model);
        break;
    /*case DRAW:
        res = draw_model(act.draw);
        break;*/
    case SAVE:
        res = save_model(model, act.load);
        break;
    default:
        res = ACTION_ERROR; //?
    }
    return res;
}
