#include "objectdrawer.h"

#include "graphicsolution.h"
#include "object.h"
#include "model.h"
#include "camera.h"
#include "errors.h"


ObjectDrawer::ObjectDrawer()
{
    GraphicSolution solution;

    solution.registration(1, FactoryCreator::createQtFactory); //???

    shared_ptr<AbstractFactory> cr(solution.create(1));
    this->drawer = cr->createGraphics();

    curCamera = shared_ptr<Camera>(new Camera(Point(0, 0, 0), Point(0, 0, 0)));
    //drawer.setScene();
}

ObjectDrawer::ObjectDrawer(const weak_ptr<Camera> newCamera, const shared_ptr<BaseScene> scene)
{
    GraphicSolution solution;

    solution.registration(1, FactoryCreator::createQtFactory); //???

    shared_ptr<AbstractFactory> cr(solution.create(1));
    this->drawer = cr->createGraphics();
    this->drawer->setScene(scene);

    curCamera = newCamera.lock();
}

void ObjectDrawer::visit(const Model &model)
{
    cout << "Visited Model;" << endl;
    auto points = model.getElements()->getPoints();

    for (auto edge: model.getElements()->getEdges())
    {
        //this->drawer->drawLine(points.at(edge.getFirst()), points.at(edge.getSecond()));
        this->drawer->drawLine(getProection(points.at(edge.getFirst())), getProection(points.at(edge.getSecond())));
    }
}

void ObjectDrawer::visit(const Camera &camera)
{
    cout << "Visited Camera;" << endl;
}

void ObjectDrawer::visit(const Composite &comp)
{
    cout << "Visited compisite;" << endl;
}

Point ObjectDrawer::getProection(Point &_point)
{
    time_t t_time = time(NULL);
    if (curCamera.expired())
        throw NoCameraError("No active camera", __FILE__, __LINE__, ctime(&t_time));

    Point proection(_point);
    //Point move(-curCamera->getPosition().getX(), -curCamera->getPosition().getY(), 0);

    //proection.transform(move, Point(1, 1, 1), Point(0, 0, 0));
    //std::shared_ptr<Matrix<double>> reform_mtr(std::make_shared<MoveMatrix>(curCamera->get_position()));

    //projection.reform(reform_mtr);
    proection.transform(Point(curCamera.lock()->getPosition()), Point(1, 1, 1), Point(0, 0, 0));

    Point angles = curCamera.lock()->getAngles();//.deg_to_rad();

    /*reform_mtr = std::make_shared<RotateOxMatrix>(-angles.get_x());
    projection.reform(reform_mtr);

    reform_mtr = std::make_shared<RotateOyMatrix>(-angles.get_y());
    projection.reform(reform_mtr);

    reform_mtr = std::make_shared<RotateOzMatrix>(-angles.get_z());
    projection.reform(reform_mtr);*/

    proection.transform(Point(0, 0, 0), Point(1, 1, 1), Point(-angles.getX(), -angles.getY(), -angles.getZ()));

    return proection;
}

/*shared_ptr<BaseVisitor> ObjectVisitor::getBaseVisitorPtr() //Костыль?
{
    unique_ptr<BaseVisitor> u_ptr = unique_ptr<BaseVisitor>(this);
    shared_ptr<BaseVisitor> rez(move(u_ptr));
    return rez;
    //return shared_ptr<BaseVisitor>(this);
}*/

