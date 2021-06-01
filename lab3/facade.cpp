#include "facade.h"

Facade::Facade()
{
    //sceneManager = shared_ptr<SceneManager>(new SceneManager());
    //sceneManager = SceneManagerCreator().getManager();
}

void Facade::execute(BaseCommand &cmd)
{
    cmd.execute();
}
