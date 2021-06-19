#ifndef SCENE_H
#define SCENE_H

#include "composite.h"

class Scene
{
public:
    Scene();
    ~Scene() = default;

    /*void addObject(shared_ptr<Object> new_obj);
    void deleteObject(const size_t obj_id);*/
    //void addModel(shared_ptr<Object> new_model);
    //void deleteModel(const size_t model_id);
    //void addCamera(shared_ptr<Object> new_camera);
    //void deleteCamera(const size_t camera_id);
    void addObject(shared_ptr<Object> new_model);
    void deleteObject(const size_t obg_id);
    void clear();
    /*shared_ptr<Object> getModels();
    shared_ptr<Object> getModel(const size_t id);
    shared_ptr<Object> getCameras();
    shared_ptr<Object> getCamera(const size_t id);*/
    shared_ptr<Object> getObject(const size_t id);
    shared_ptr<Object> getObjects();
private:
    //objects;
    shared_ptr<Object> objects; //Объеденил модели и камеры
    //shared_ptr<Object> models;
    //shared_ptr<Object> cameras;
};

#endif // SCENE_H
