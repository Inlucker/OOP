#include "commands.h"

#include <memory>

using namespace std;

#include "scenemanagercreator.h"
#include "scenemanager.h"

DrawScene::DrawScene()
{
    //man = SceneManagerCreator().getManager();
    //act = &SceneManager::drawScene;
}

void DrawScene::execute()
{
    shared_ptr<SceneManager> man = SceneManagerCreator().getManager();
    man->drawScene();
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
