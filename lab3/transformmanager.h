#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include <memory>

using namespace std;

#include "basemanager.h"
#include "point.h"

class BaseModelLoader;
class Object;

class TransformManager : public BaseManager
{
public:
    TransformManager();
    ~TransformManager() = default;
    //void MoveModel(Point move, int id);
    void transformObject(shared_ptr<Object> object, const Point move, const Point scale, const Point rotate);
};

#endif // TRANSFORMMANAGER_H
