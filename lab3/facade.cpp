#include "facade.h"

Facade::Facade()
{
    sceneManager = shared_ptr<SceneManager>(new SceneManager());
}

void Facade::execute(BaseCommand &cmd)
{
    cmd.execute();
}
