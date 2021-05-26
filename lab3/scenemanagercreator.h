#ifndef SCENEMANAGERCREATOR_H
#define SCENEMANAGERCREATOR_H

#include "scenemanager.h"

class SceneManagerCreator
{
public:
    static shared_ptr<SceneManager> getManager();
    ~SceneManagerCreator();

    SceneManagerCreator(const SceneManagerCreator&) = delete; //нет смысла?
    SceneManagerCreator& operator=(const SceneManagerCreator&) = delete; //нет смысла?

private:
    SceneManagerCreator();
};

#endif // SCENEMANAGERCREATOR_H
