#include "commands.h"
#include "scenemanagercreator.h"

DrawScene::DrawScene()
{
    man = SceneManagerCreator::getManager();
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
