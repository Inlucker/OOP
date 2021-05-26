#include "scenemanagercreator.h"

shared_ptr<SceneManager> SceneManagerCreator::getManager()
{
    static shared_ptr<SceneManager> myInstance(new SceneManager());

    return myInstance;
}

SceneManagerCreator::SceneManagerCreator()
{

}
