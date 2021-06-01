#include "commands.h"

#include <memory>

using namespace std;

#include "scenemanagercreator.h"
#include "scenemanager.h"

#include "loadmanagercreator.h"
#include "loadmanager.h"

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

CommandA::CommandA(double x, double y) : x(x), y(y)
{
    //man = SceneManagerCreator().getManager();
    //act = &SceneManager::drawScene;
}

void CommandA::execute()
{
    shared_ptr<SceneManager> man = SceneManagerCreator().getManager();
    man->drawScene();
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
