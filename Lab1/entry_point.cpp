#include "entry_point.h"
//#include "model.h"

#include "action_funcs.h"
#include "error_codes.h"

int entry_point(Proection &proection, action_type t, const Action &act)
{
    static Model model = create_model();

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
    case PROECTION:
        res = get_proection(proection, model);
        break;
    case SAVE:
        res = save_model(model, act.load);
        break;
    default:
        res = ACTION_ERROR; //?
    }
    return res;
}
