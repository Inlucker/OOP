#include "transformmanager.h"
#include "object.h"

TransformManager::TransformManager()
{

}

/*void TransformManager::MoveModel(Point move, int id)
{

}*/

void TransformManager::transformObject(shared_ptr<Object> object, const Point move, const Point scale, const Point rotate)
{
    object->transform(move, scale, rotate);
}
