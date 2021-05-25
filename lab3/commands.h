#ifndef COMMANDS_H
#define COMMANDS_H

#include "basecommand.h"
#include "scenemanager.h"

class DrawScene : public BaseCommand
{
    using Action = void(SceneManager::*)();
public:
    DrawScene() = delete;
    DrawScene(shared_ptr<SceneManager> manager);
    ~DrawScene() = default;
    virtual void execute() override;

private:
    shared_ptr<SceneManager> man;
    Action act;
};

class CommandA : public BaseCommand
{
    using Action = void(SceneManager::*)();

public:
    CommandA() = delete;
    CommandA(double x, double y, shared_ptr<SceneManager> manager);
    ~CommandA() = default;
    virtual void execute() override;

private:
    shared_ptr<SceneManager> man;
    Action act;
    double x;
    double y;
};

#endif // COMMANDS_H
