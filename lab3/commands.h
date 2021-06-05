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

class LoadModel : public BaseCommand //AddModel
{
public:
    LoadModel() = delete;
    explicit LoadModel(string fileName);
    ~LoadModel() = default;
    virtual void execute() override;

private:
    string fileName;
};

class AddCamera : public BaseCommand
{
public:
    AddCamera() = delete;
    AddCamera(Point pos, Point angs);
    ~AddCamera() = default;
    virtual void execute() override;

private:
    Point position;
    Point angles;
};

//class DeleteModel : public BaseCommand
//class DeleteCamera : public BaseCommand
//

class UseCamera : public BaseCommand
{
public:
    UseCamera() = delete;
    UseCamera(size_t newId);
    ~UseCamera() = default;
    virtual void execute() override;

private:
    size_t id;
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
