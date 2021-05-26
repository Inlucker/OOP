#include "commands.h"
#include "scenemanagercreator.h"

DrawScene::DrawScene(shared_ptr<SceneManager> manager)
{
    man = manager;
    act = &SceneManager::drawScene;
}

void DrawScene::execute()
{
    ((*man).*act)();
}

CommandA::CommandA(double x, double y) : x(x), y(y)
{
    man = SceneManagerCreator::getManager();
    act = &SceneManager::drawScene;
}

void CommandA::execute()
{
    ((*man).*act)();
}
