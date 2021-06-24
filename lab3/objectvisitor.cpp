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

ObjectVisitor::ObjectVisitor(shared_ptr<BaseDrawer> newDrawer, shared_ptr<Camera> newCamera)
{
    drawer = newDrawer;
    curCamera = newCamera;
}

void ObjectVisitor::visit(const Model &model)
{
    //shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();
    //shared_ptr<BaseDrawer> drawer = sceneMan->getDrawer();
    //cout << "Visited Model;" << endl;
    auto points = model.getElements()->getPoints();

    //shared_ptr<Camera> curCamera = sceneMan->getCamera().lock();
    Point cameraPosition = Point(curCamera->getPosition());
    Point cameraAngles = curCamera->getAngles();

    for (auto edge: model.getElements()->getEdges())
    {
        drawer->drawLine(getProection(points.at(edge.getFirst()), cameraPosition, cameraAngles), getProection(points.at(edge.getSecond()), cameraPosition, cameraAngles));
        //drawer->drawLine(getProection(points.at(edge.getFirst())), getProection(points.at(edge.getSecond())));
    }
}

void ObjectVisitor::visit(const Camera &camera)
{
    //cout << "Visited Camera;" << endl;
}

void ObjectVisitor::visit(const Composite &comp)
{
    //cout << "Visited compisite;" << endl;
}

Point ObjectVisitor::getProection(Point &_point, Point cameraPosition, Point angles)
{
    //shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();
    //shared_ptr<Camera> curCamera = sceneMan->getCamera().lock();

    Point proection(_point);
    //proection.transform(Point(curCamera->getPosition()), Point(1, 1, 1), Point(0, 0, 0));
    proection.transform(cameraPosition, Point(1, 1, 1), Point(0, 0, 0));

    //Point angles = curCamera->getAngles();

    proection.transform(Point(0, 0, 0), Point(1, 1, 1), Point(-angles.getX(), -angles.getY(), -angles.getZ()));

    return proection;
}

