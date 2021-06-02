#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    interface = make_shared<Facade>(Facade());

    this->setFixedHeight(this->height());
    this->setFixedWidth(this->width());

    canvas = new Canvas();
    ui->gridLayout->addWidget(canvas);

    //SetScene
    SetDrawerScene setDrawerCmd(canvas->scene);
    interface->execute(setDrawerCmd);

    /*LoadModel loadCmd("cube.txt");
    interface->execute(loadCmd);

    DrawScene drawCmd;
    interface->execute(drawCmd);*/

    //CLearScene clearCmd;
    //interface->execute(clearCmd);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete canvas;
}

void MainWindow::on_SetSceneBtn_clicked()
{
    SetDrawerScene setDrawerCmd(canvas->scene);
    interface->execute(setDrawerCmd);
}

void MainWindow::on_DrawBtn_clicked()
{
    DrawScene drawCmd;
    interface->execute(drawCmd);
    canvas->update();
}

void MainWindow::on_ClearSceneBtn_clicked()
{
    ClearScene clearCmd;
    interface->execute(clearCmd);

    /*DrawScene drawCmd;
    interface->execute(drawCmd);*/

    canvas->clean();

    canvas->update();
}

void MainWindow::on_AddModelBtn_clicked()
{
    //LoadModel loadCmd("cube.txt");
    LoadModel loadCmd("12granSec.txt");
    interface->execute(loadCmd);

    DrawScene drawCmd;
    interface->execute(drawCmd);

    canvas->update();
}

void MainWindow::on_RotateModelBtn_clicked()
{
    TransformModel transformCmd(0, Point(0, 0, 0), Point(1, 1, 1), Point(0, 45, 0));
    interface->execute(transformCmd);

    DrawScene drawCmd;
    interface->execute(drawCmd);

    canvas->update();
}

void MainWindow::on_MoveModelBtn_clicked()
{
    TransformModel transformCmd(0, Point(100, 100, 100), Point(1, 1, 1), Point(0, 0, 0));
    interface->execute(transformCmd);

    DrawScene drawCmd;
    interface->execute(drawCmd);

    canvas->update();
}

void MainWindow::on_ScaleModelBtn_clicked()
{
    TransformModel transformCmd(0, Point(0, 0, 0), Point(0.5, 0.5, 0.5), Point(0, 0, 0));
    interface->execute(transformCmd);

    DrawScene drawCmd;
    interface->execute(drawCmd);

    canvas->update();
}
