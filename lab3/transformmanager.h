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
    void transformModel(shared_ptr<Object> model, const Point move, const Point scale, const Point rotate);
};

#endif // TRANSFORMMANAGER_H
