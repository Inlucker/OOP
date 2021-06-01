#include "transformmanager.h"
#include "object.h"

TransformManager::TransformManager()
{

}

/*void TransformManager::MoveModel(Point move, int id)
{

}*/

void TransformManager::transformModel(shared_ptr<Object> model, const Point move, const Point scale, const Point rotate)
{
    model->transform(move, scale, rotate);
}
