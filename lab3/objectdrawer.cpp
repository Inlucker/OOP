#include "objectdrawer.h"

#include "graphicsolution.h"

ObjectDrawer::ObjectDrawer()
{
    GraphicSolution solution;

    solution.registration(1, createQtFactory);

    shared_ptr<AbstractFactory> cr(solution.create(1));
    drawer = cr->createGraphics();
}

void ObjectDrawer::visit(const Model &model)
{
    cout << "Visited Model;" << endl;
}
