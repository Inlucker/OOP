#include "commands.h"

DrawScene::DrawScene(shared_ptr<SceneManager> manager)
{
    man = manager;
    act = &SceneManager::drawScene;
}

void DrawScene::execute()
{
    ((*man).*act)();
}

CommandA::CommandA(double x, double y, shared_ptr<SceneManager> manager) : x(x), y(y)
{
    man = manager;
    act = &SceneManager::drawScene;
}

void CommandA::execute()
{
    ((*man).*act)();
}
