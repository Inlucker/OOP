#include "entry_point.h"
//#include "model.h"

int entry_point(Model &model, action_type t, const Action &act)
{
    //static Model model = Init_model();
    //Model new_model = create_model();

    int res = OK;
    switch (t)
    {
    case LOAD:
    {
        Model new_model = create_model();
        free_model(model);
        res = load_model(new_model, act.load);
        model = new_model;
        break;
    }
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
