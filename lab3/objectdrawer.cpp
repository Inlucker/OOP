#include "objectdrawer.h"

#include "graphicsolution.h"
#include "model.h"

ObjectDrawer::ObjectDrawer()
{
    GraphicSolution solution;

    solution.registration(1, FactoryCreator::createQtFactory);

    shared_ptr<AbstractFactory> cr(solution.create(1));
    this->drawer = cr->createGraphics();
    //drawer.setScene();
}

void ObjectDrawer::visit(const Model &model)
{
    auto points = model.getElements()->getPoints();

    for (auto edge: model.getElements()->getEdges())
    {
        this->drawer->drawLine(points.at(edge.getFirst()), points.at(edge.getSecond()));
    }
    cout << "Visited Model;" << endl;
}

void ObjectDrawer::visit(const Camera &camera)
{
    cout << "Visited Camera;" << endl;
}

/*shared_ptr<BaseVisitor> ObjectVisitor::getBaseVisitorPtr() //Костыль?
{
    unique_ptr<BaseVisitor> u_ptr = unique_ptr<BaseVisitor>(this);
    shared_ptr<BaseVisitor> rez(move(u_ptr));
    return rez;
    //return shared_ptr<BaseVisitor>(this);
}*/

