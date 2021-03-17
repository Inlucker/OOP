#include "entry_point.h"
#include "action_funcs.h"
//#include "model.h"

int entry_point(My_Scene &scene, const Action &act, action_type t)
{
    static Model model;// = Init_model();

    int res = OK;
    switch (t)
    {
    case LOAD:
        res = load_model(model, act.create);
        break;
        break;
    case MOVE:
        res = move_model(model, act.move);
        break;
    /*case SCALE:
        res = scale_model(model, act.scale);
        break;
    case ROTATE:
        res = rotate_model(model, act.rotate);
    case FREE:
        res = free_model(model);
        break;
    case SAVE:
        res = save_model(model, act.create);
        break;
    case DRAW:
        res = draw_model(scene, model);
        break;*/
    default:
        res = ACTION_ERROR; //?
    }
    return res;
}
