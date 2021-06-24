#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <memory>

using namespace std;

#include "basecommand.h"
#include "point.h"
#include "basedrawer.h"
#include "basecanvas.h"

class TransformObject : public BaseCommand
{
public:
    TransformObject() = delete;
    TransformObject(const int id, const Point move, const Point scale, const Point rotate);
    ~TransformObject() = default;
    virtual void execute() override;

private:
    int id;
    const Point move;
    const Point scale;
    const Point rotate;
};

class ClearCanvas : public BaseCommand
{
public:
    //DrawScene() = delete;
    ClearCanvas();
    ~ClearCanvas() = default;
    virtual void execute() override;
};

class DrawScene : public BaseCommand
{
public:
    //DrawScene() = delete;
    DrawScene();
    ~DrawScene() = default;
    virtual void execute() override;
};

class ClearObjects : public BaseCommand
{
public:
    ClearObjects();
    ~ClearObjects() = default;
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

class DeleteObject : public BaseCommand
{
public:
    DeleteObject() = delete;
    explicit DeleteObject(size_t newId);
    ~DeleteObject() = default;
    virtual void execute() override;

private:
    size_t id;
};

class UseCamera : public BaseCommand
{
public:
    UseCamera() = delete;
    explicit UseCamera(size_t newId);
    ~UseCamera() = default;
    virtual void execute() override;

private:
    size_t id;
    //long id;
};

class SetDrawer : public BaseCommand
{
public:
    SetDrawer() = delete;
    explicit SetDrawer(shared_ptr<BaseDrawer> newDrawer);
    ~SetDrawer() = default;
    virtual void execute() override;

private:
    shared_ptr<BaseDrawer> drawer;
};

class SetCanvas : public BaseCommand
{
public:
    SetCanvas() = delete;
    explicit SetCanvas(shared_ptr<BaseCanvas> newScene);
    ~SetCanvas() = default;
    virtual void execute() override;

private:
    shared_ptr<BaseCanvas> scene;
};

class SaveScene : public BaseCommand
{
public:
    SaveScene();
    ~SaveScene() = default;
    virtual void execute() override;
};

class ReturnScene : public BaseCommand
{
public:
    ReturnScene();
    ~ReturnScene() = default;
    virtual void execute() override;
};

#endif // COMMANDS_H
