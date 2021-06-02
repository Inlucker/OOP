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

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        LMB_is_pressed = false;
    }

    if (event->button() == Qt::RightButton)
    {
        RMB_is_pressed = true;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    previous_x = event->position().x();
    previous_y = event->position().y();
    if (event->button() == Qt::LeftButton && !LMB_is_pressed && this->canvas->rect().contains(event->pos()))
    {
        //cout << "Set" << endl;
        //previous_x = event->position().x();
        //previous_y = event->position().y();
        LMB_is_pressed = true;
    }
    if (event->button() == Qt::RightButton && !RMB_is_pressed && this->canvas->rect().contains(event->pos()))
    {
        //cout << "Set" << endl;
        //previous_x = event->position().x();
        //previous_y = event->position().y();
        RMB_is_pressed = true;
    }
}

#define ROTATE_SPEED 5
#define MOVE_SPEED 1

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (LMB_is_pressed)
    {
        double x = double(previous_x - event->position().x()) / ROTATE_SPEED;
        double y = double(previous_y - event->position().y()) / ROTATE_SPEED;


        TransformModel transformCmd(0, Point(0, 0, 0), Point(1, 1, 1), Point(y, x, 0));
        interface->execute(transformCmd);

        DrawScene drawCmd;
        interface->execute(drawCmd);

        /*canvas->update();

        previous_x = event->position().x();
        previous_y = event->position().y();*/
    }
    else if (RMB_is_pressed)
    {
        double x = double(previous_x - event->position().x()) / MOVE_SPEED;
        double y = double(previous_y - event->position().y()) / MOVE_SPEED;


        TransformModel transformCmd(0, Point(-x, -y, 0), Point(1, 1, 1), Point(0, 0, 0));
        interface->execute(transformCmd);

        DrawScene drawCmd;
        interface->execute(drawCmd);

        /*canvas->update();

        previous_x = event->position().x();
        previous_y = event->position().y();*/
    }

    canvas->update();

    previous_x = event->position().x();
    previous_y = event->position().y();
}


#define SCALE_SPEED 10

void MainWindow::wheelEvent(QWheelEvent *event)
{
    if (this->canvas->rect().contains(int(event->position().x()), int(event->position().y())))
    {
        QPoint numDegrees = event->angleDelta() / 120;
        cout <<  numDegrees.x() << endl;
        cout <<  numDegrees.y() << endl;
        double kx = 1 + double(numDegrees.x()) / SCALE_SPEED;
        double ky = 1 + double(numDegrees.y()) / SCALE_SPEED;
        cout <<  kx << endl;
        cout <<  ky << endl;

        TransformModel transformCmd(0, Point(0, 0, 0), Point(ky, ky, ky), Point(0, 0, 0));
        interface->execute(transformCmd);

        DrawScene drawCmd;
        interface->execute(drawCmd);

        canvas->update();
    }
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
