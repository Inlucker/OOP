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

/*MoveModel::MoveModel(const Point move, const int id) : move(move), id(id)
{

}

void MoveModel::execute()
{
    shared_ptr<TransformManager> transformMan = TransformManagerCreator().getManager();
    transformMan->MoveModel(move, id);
}*/

TransformModel::TransformModel(const int id, const Point move, const Point scale, const Point rotate) : id(id), move(move), scale(scale), rotate(rotate)
{

}

void TransformModel::execute()
{
    shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();

    shared_ptr<TransformManager> transformMan = TransformManagerCreator().getManager();
    transformMan->transformModel(sceneMan->getScene()->getModel(id), move, scale, rotate);

}

DrawScene::DrawScene()
{

}

void DrawScene::execute()
{
    shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();
    sceneMan->clearScene();
    sceneMan->drawScene();
}

void ClearScene::execute()
{
    shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();
    sceneMan->getScene()->getModels()->clear();
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

SetDrawerScene::SetDrawerScene(shared_ptr<BaseScene> newScene) : scene(newScene)
{

}

void SetDrawerScene::execute()
{
    shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();
    sceneMan->setDrawerScene(scene);
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

UseCamera::UseCamera(size_t newId)
{
    id = newId;
}

void UseCamera::execute()
{
    shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();
    shared_ptr<Object> newCurCam = sceneMan->getScene()->getCamera(id);
    sceneMan->useCamera(dynamic_pointer_cast<Camera>(newCurCam));
}
