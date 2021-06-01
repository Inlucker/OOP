#include "transformmanagercreator.h"

#include "transformmanager.h"

shared_ptr<TransformManager> TransformManagerCreator::getManager()
{
    if (!manager)
        manager = createManager();

    return manager;
}

shared_ptr<TransformManager> TransformManagerCreator::createManager()
{
    static shared_ptr<TransformManager> created_man(new TransformManager());
    return created_man;
}
