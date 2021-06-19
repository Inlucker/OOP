#include "commands.h"

#include <memory>

using namespace std;

#include "errors.h"

#include "scenemanagercreator.h"
#include "scenemanager.h"

#include "loadmanagercreator.h"
#include "loadmanager.h"

#include "transformmanagercreator.h"
#include "transformmanager.h"

TransformObject::TransformObject(const int id, const Point move, const Point scale, const Point rotate) : id(id), move(move), scale(scale), rotate(rotate)
{

}

void TransformObject::execute()
{
    shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();

    shared_ptr<TransformManager> transformMan = TransformManagerCreator().getManager();
    transformMan->transformObject(sceneMan->getScene()->getObject(id), move, scale, rotate);

}

DrawScene::DrawScene()
{

}

void DrawScene::execute()
{
    shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();
    sceneMan->clearCanvas();
    sceneMan->drawScene();
}

ClearObjects::ClearObjects()
{

}

void ClearObjects::execute()
{
    shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();
    sceneMan->clearObjects();
    sceneMan->clearCanvas();
}

LoadModel::LoadModel(string fileName) : fileName(fileName)
{

}

void LoadModel::execute()
{
    shared_ptr<LoadManager> loadMan = LoadManagerCreator().getManager();
    shared_ptr<Model> newModel = loadMan->loadModel(fileName);
    shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();
    sceneMan->addModel(newModel);
}

AddCamera::AddCamera(Point pos, Point angs)
{
    position = pos;
    angles = angs;
}

void AddCamera::execute()
{
    shared_ptr<LoadManager> loadMan = LoadManagerCreator().getManager();
    shared_ptr<Camera> newCamera = shared_ptr<Camera>(new Camera(position, angles));
    shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();
    sceneMan->addCamera(newCamera);
}

DeleteObject::DeleteObject(size_t newId)
{
    id = newId;
}

void DeleteObject::execute()
{
    shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();
    sceneMan->deleteObject(id);
}

UseCamera::UseCamera(size_t newId)
{
    id = newId;
}

void UseCamera::execute()
{
    shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();
    shared_ptr<Object> newCurCam = sceneMan->getScene()->getObject(id);
    sceneMan->useCamera(dynamic_pointer_cast<Camera>(newCurCam));
}

SetCanvas::SetCanvas(shared_ptr<BaseCanvas> newScene) : scene(newScene)
{

}

void SetCanvas::execute()
{
    shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();
    sceneMan->setCanvas(scene);
}
