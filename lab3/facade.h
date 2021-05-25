#ifndef FACADE_H
#define FACADE_H

#include "basecommand.h"

#include <memory>

using namespace std;

#include "scenemanager.h"

class Facade
{
public:
    Facade();
    virtual ~Facade() = default;
    void execute(BaseCommand &cmd);

private:
    shared_ptr<SceneManager> sceneManager;
};

#endif // FACADE_H
