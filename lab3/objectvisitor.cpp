#include "objectvisitor.h"

#include "graphicsolution.h"
#include "object.h"
#include "model.h"
#include "camera.h"
#include "composite.h"
#include "errors.h"

#include "scenemanagercreator.h"
#include "scenemanager.h"

ObjectVisitor::ObjectVisitor()
{

}

void ObjectVisitor::visit(const Model &model)
{
    shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();
    shared_ptr<BaseDrawer> drawer = sceneMan->getDrawer();
    //cout << "Visited Model;" << endl;
    auto points = model.getElements()->getPoints();

    for (auto edge: model.getElements()->getEdges())
    {
        drawer->drawLine(getProection(points.at(edge.getFirst())), getProection(points.at(edge.getSecond())));
    }
}

void ObjectVisitor::visit(const Camera &camera)
{
    cout << "Visited Camera;" << endl;
}

void ObjectVisitor::visit(const Composite &comp)
{
    cout << "Visited compisite;" << endl;
}

Point ObjectVisitor::getProection(Point &_point)
{
    shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();
    shared_ptr<Camera> curCamera = sceneMan->getCamera().lock();

    Point proection(_point);
    proection.transform(Point(curCamera->getPosition()), Point(1, 1, 1), Point(0, 0, 0));

    Point angles = curCamera->getAngles();

    proection.transform(Point(0, 0, 0), Point(1, 1, 1), Point(-angles.getX(), -angles.getY(), -angles.getZ()));

    return proection;
}

