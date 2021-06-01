#include "objectvisitor.h"

#include "graphicsolution.h"

ObjectVisitor::ObjectVisitor()
{
    GraphicSolution solution;

    solution.registration(1, FactoryCreator::createQtFactory);

    shared_ptr<AbstractFactory> cr(solution.create(1));
    drawer = cr->createGraphics();
}

void ObjectVisitor::visit(const Model &model)
{
    cout << "Visited Model;" << endl;
}

void ObjectVisitor::visit(const Camera &camera)
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

