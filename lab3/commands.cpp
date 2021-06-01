#include "commands.h"

#include <memory>

using namespace std;

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
    transformMan->transformModel(sceneMan->getScene()->getModels(), move, scale, rotate);

}

DrawScene::DrawScene()
{
    //man = SceneManagerCreator().getManager();
    //act = &SceneManager::drawScene;
}

void DrawScene::execute()
{
    shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();
    sceneMan->drawScene();
    //SceneManagerCreator().getManager()->drawScene();
    //((*man).*act)();
}

void ClearScene::execute()
{
    shared_ptr<SceneManager> man = SceneManagerCreator().getManager();
    man->clearScene();
    //((*man).*act)();
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
