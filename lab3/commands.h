#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>

using namespace std;

#include "basecommand.h"
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

class CommandA : public BaseCommand
{
    //using Action = void(SceneManager::*)();

public:
    CommandA() = delete;
    CommandA(double x, double y);
    ~CommandA() = default;
    virtual void execute() override;

private:
    //shared_ptr<SceneManager> man;
    //Action act;
    double x;
    double y;
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

#endif // COMMANDS_H
