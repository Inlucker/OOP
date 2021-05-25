#include "mainwindow.h"

#include <QApplication>

#include "facade.h"

//Composite tests
/*#include "model.h"
#include "camera.h"
#include "composite.h"*/

int main(int argc, char *argv[])
{
    Facade facade;
    //Composite tests
    /*shared_ptr<Object> fig1(new Model()), fig2(new Model), cam1(new Camera()), cam2(new Camera());
    shared_ptr<Object> composite1(new Composite{fig1, cam1, fig2, cam2});

    composite1->transform();
    cout << endl;
    composite1->isVisible();
    cout << endl;

    IteratorObject it = composite1->begin();

    composite1->remove(++it);
    composite1->transform();
    cout << endl;
    composite1->isVisible();
    cout << endl;

    shared_ptr<Object> composite2(new Composite{shared_ptr<Object>(new Model()), composite1});

    composite2->transform();
    cout << endl;
    composite2->isVisible();
    cout << endl;*/

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
