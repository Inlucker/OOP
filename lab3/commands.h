#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <memory>

using namespace std;

#include "basecommand.h"
#include "basescene.h"
//#include "scenemanager.h"
//class scenemanager;

class DrawScene : public BaseCommand
{
    //using Action = void(SceneManager::*)();
public:
    //DrawScene() = delete;
    DrawScene();
    ~DrawScene() = default;
    virtual void execute() override;

private:
    //shared_ptr<SceneManager> man;
    //Action act;
};

class ClearScene : public BaseCommand
{
    //using Action = void(SceneManager::*)();

public:
    //CLearScene() = delete;
    ClearScene() = default;
    ~ClearScene() = default;
    virtual void execute() override;

private:
};

class LoadModel : public BaseCommand
{
public:
    LoadModel() = delete;
    LoadModel(string fileName);
    ~LoadModel() = default;
    virtual void execute() override;

private:
    string fileName;
};

class SetDrawerScene : public BaseCommand
{
public:
    SetDrawerScene() = delete;
    SetDrawerScene(shared_ptr<BaseScene> newScene);
    ~SetDrawerScene() = default;
    virtual void execute() override;

private:
    shared_ptr<BaseScene> scene;
};

#endif // COMMANDS_H
