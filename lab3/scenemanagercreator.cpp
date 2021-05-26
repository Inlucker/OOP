#include "scenemanagercreator.h"

#include "scenemanager.h"

shared_ptr<SceneManager> SceneManagerCreator::getManager()
{
    if (!manager)
        manager = createManager();

    return manager;
}

shared_ptr<SceneManager> SceneManagerCreator::createManager()
{
    static shared_ptr<SceneManager> created_man(new SceneManager());
    return created_man;
}
