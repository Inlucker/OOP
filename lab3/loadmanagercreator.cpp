#include "loadmanagercreator.h"

#include "loadmanager.h"

shared_ptr<LoadManager> LoadManagerCreator::getManager()
{
    if (!manager)
        manager = createManager();

    return manager;
}

shared_ptr<LoadManager> LoadManagerCreator::createManager()
{
    static shared_ptr<LoadManager> created_man(new LoadManager());
    return created_man;
}
