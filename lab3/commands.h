#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <memory>

using namespace std;

#include "basecommand.h"
#include "basescene.h"
#include "point.h"
//#include "scenemanager.h"
//class scenemanager;

/*class MoveModel : public BaseCommand
{
public:
    MoveModel() = delete;
    MoveModel(const Point move, const int id);
    ~MoveModel() = default;
    virtual void execute() override;

private:
    int id;
    Point move;
};*/

class TransformModel : public BaseCommand
{
public:
    TransformModel() = delete;
    TransformModel(const int id, const Point move, const Point scale, const Point rotate);
    ~TransformModel() = default;
    virtual void execute() override;

private:
    int id;
    const Point move;
    const Point scale;
    const Point rotate;
};

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
