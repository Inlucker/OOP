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

    try
    {
        AddCamera addCameraCmd(Point(0, 0, 0), Point(0, 0, 0));
        AddCamera addCameraCmd2(Point(0, 300, -300), Point(45, 45, 45));
        //AddCamera addCameraCmd(Point(200, 200, 300), Point(45, 45, 35));
        interface->execute(addCameraCmd);
        interface->execute(addCameraCmd2);

        UseCamera useCamera(0);
        interface->execute(useCamera);
    }
    catch (BaseError &er)
    {
        QMessageBox::information(this, "Error", er.what());
    }
    catch (...)
    {
        QMessageBox::information(this, "Error", "Unexpected Error");
    }

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
        RMB_is_pressed = false;
    }
    /*try
    {
    }
    catch (BaseError &er)
    {
        QMessageBox::information(this, "Error", er.what());
    }
    catch (...)
    {
        QMessageBox::information(this, "Error", "Unexpected Error");
    }*/
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    previous_x = event->position().x();
    previous_y = event->position().y();
    if (event->button() == Qt::LeftButton && !LMB_is_pressed && this->canvas->rect().contains(event->pos()))
    {
        //cout << "Set" << endl;
        //previous_x = event->x();
        //previous_y = event->y();
        LMB_is_pressed = true;
    }
    if (event->button() == Qt::RightButton && !RMB_is_pressed && this->canvas->rect().contains(event->pos()))
    {
        //cout << "Set" << endl;
        //previous_x = event->x();
        //previous_y = event->y();
        RMB_is_pressed = true;
    }
}

#define ROTATE_SPEED 5
#define MOVE_SPEED 1

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    try
    {
        if (LMB_is_pressed)
        {
            double x = double(previous_x - event->position().x()) / ROTATE_SPEED;
            double y = double(previous_y - event->position().y()) / ROTATE_SPEED;

            //ui->Model_IDs->text().toInt()
            QString modelIds = ui->Model_IDs->text();
            int n = modelIds.toInt();
            TransformObject transformCmd(n, Point(0, 0, 0), Point(1, 1, 1), Point(y, x, 0));
            interface->execute(transformCmd);

            DrawScene drawCmd;
            interface->execute(drawCmd);

            /*canvas->update();

            previous_x = event->x();
            previous_y = event->y();*/
        }
        else if (RMB_is_pressed)
        {
            double x = double(previous_x - event->position().x()) / MOVE_SPEED;
            double y = double(previous_y - event->position().y()) / MOVE_SPEED;


            QString modelIds = ui->Model_IDs->text();
            int n = modelIds.toInt();
            TransformObject transformCmd(n, Point(-x, -y, 0), Point(1, 1, 1), Point(0, 0, 0));
            interface->execute(transformCmd);

            DrawScene drawCmd;
            interface->execute(drawCmd);

            /*canvas->update();

            previous_x = event->x();
            previous_y = event->y();*/
        }

        canvas->update();

        previous_x = event->position().x();
        previous_y = event->position().y();
    }
    catch (BaseError &er)
    {
        QMessageBox::information(this, "Error", er.what());
    }
    catch (...)
    {
        QMessageBox::information(this, "Error", "Unexpected Error");
    }
}

#define SCALE_SPEED 10

void MainWindow::wheelEvent(QWheelEvent *event)
{
    if (this->canvas->rect().contains(int(event->position().x()), int(event->position().y())))
    {
        try
        {
            QPoint numDegrees = event->angleDelta() / 120;
            cout <<  numDegrees.x() << endl;
            cout <<  numDegrees.y() << endl;
            double kx = 1 + double(numDegrees.x()) / SCALE_SPEED;
            double ky = 1 + double(numDegrees.y()) / SCALE_SPEED;
            cout <<  kx << endl;
            cout <<  ky << endl;

            TransformObject transformCmd(ui->Model_IDs->text().toInt(), Point(0, 0, 0), Point(ky, ky, ky), Point(0, 0, 0));
            interface->execute(transformCmd);

            DrawScene drawCmd;
            interface->execute(drawCmd);

            canvas->update();
        }
        catch (BaseError &er)
        {
            QMessageBox::information(this, "Error", er.what());
        }
        catch (...)
        {
            QMessageBox::information(this, "Error", "Unexpected Error");
        }
    }
}

void MainWindow::on_SetSceneBtn_clicked()
{
    try
    {
        SetDrawerScene setDrawerCmd(canvas->scene);
        interface->execute(setDrawerCmd);
    }
    catch (BaseError &er)
    {
        QMessageBox::information(this, "Error", er.what());
    }
    catch (...)
    {
        QMessageBox::information(this, "Error", "Unexpected Error");
    }
}

void MainWindow::on_DrawBtn_clicked()
{
    try
    {
        DrawScene drawCmd;
        interface->execute(drawCmd);
        canvas->update();
    }
    catch (BaseError &er)
    {
        QMessageBox::information(this, "Error", er.what());
    }
    catch (...)
    {
        QMessageBox::information(this, "Error", "Unexpected Error");
    }
}

void MainWindow::on_ClearSceneBtn_clicked()
{
    try
    {
        ClearObjects clearCmd;
        interface->execute(clearCmd);

        /*DrawScene drawCmd;
        interface->execute(drawCmd);*/

        canvas->clean();

        canvas->update();
    }
    catch (BaseError &er)
    {
        QMessageBox::information(this, "Error", er.what());
    }
    catch (...)
    {
        QMessageBox::information(this, "Error", "Unexpected Error");
    }
}

void MainWindow::on_AddModelBtn_clicked()
{
    try
    {
        LoadModel loadCmd("cube1.txt");
        //LoadModel loadCmd("12granSec.txt");
        interface->execute(loadCmd);

        DrawScene drawCmd;
        interface->execute(drawCmd);

        canvas->update();
    }
    catch (BaseError &er)
    {
        QMessageBox::information(this, "Error", er.what());
    }
    catch (...)
    {
        QMessageBox::information(this, "Error", "Unexpected Error");
    }
}

void MainWindow::on_RotateModelBtn_clicked()
{
    try
    {
        TransformObject transformCmd(0, Point(0, 0, 0), Point(1, 1, 1), Point(0, 45, 0));
        interface->execute(transformCmd);

        DrawScene drawCmd;
        interface->execute(drawCmd);

        canvas->update();
    }
    catch (BaseError &er)
    {
        QMessageBox::information(this, "Error", er.what());
    }
    catch (...)
    {
        QMessageBox::information(this, "Error", "Unexpected Error");
    }
}

void MainWindow::on_MoveModelBtn_clicked()
{
    try
    {
        TransformObject transformCmd(0, Point(100, 100, 100), Point(1, 1, 1), Point(0, 0, 0));
        interface->execute(transformCmd);

        DrawScene drawCmd;
        interface->execute(drawCmd);

        canvas->update();
    }
    catch (BaseError &er)
    {
        QMessageBox::information(this, "Error", er.what());
    }
    catch (...)
    {
        QMessageBox::information(this, "Error", "Unexpected Error");
    }
}

void MainWindow::on_ScaleModelBtn_clicked()
{
    try
    {
        TransformObject transformCmd(0, Point(0, 0, 0), Point(0.5, 0.5, 0.5), Point(0, 0, 0));
        interface->execute(transformCmd);

        DrawScene drawCmd;
        interface->execute(drawCmd);

        canvas->update();
    }
    catch (BaseError &er)
    {
        QMessageBox::information(this, "Error", er.what());
    }
    catch (...)
    {
        QMessageBox::information(this, "Error", "Unexpected Error");
    }
}

void MainWindow::on_AddCameraBtn_clicked()
{
    try
    {
        AddCamera addCameraCmd(Point(0, 0, 0), Point(0, 0, 0));
        interface->execute(addCameraCmd);

        DrawScene drawCmd;
        interface->execute(drawCmd);

        canvas->update();
    }
    catch (BaseError &er)
    {
        QMessageBox::information(this, "Error", er.what());
    }
    catch (...)
    {
        QMessageBox::information(this, "Error", "Unexpected Error");
    }
}

void MainWindow::on_DeleteObjBtn_clicked()
{
    try
    {
        DeleteObject deleteObjectCmd(ui->Model_IDs->text().toInt());
        interface->execute(deleteObjectCmd);

        DrawScene drawCmd;
        interface->execute(drawCmd);

        canvas->update();
    }
    catch (BaseError &er)
    {
        QMessageBox::information(this, "Error", er.what());
    }
    catch (...)
    {
        QMessageBox::information(this, "Error", "Unexpected Error");
    }
}

void MainWindow::on_SetCameraBtn_clicked()
{
    try
    {
        UseCamera useCameraCmd(ui->Model_IDs->text().toInt());
        interface->execute(useCameraCmd);

        DrawScene drawCmd;
        interface->execute(drawCmd);

        canvas->update();
    }
    catch (BaseError &er)
    {
        QMessageBox::information(this, "Error", er.what());
    }
    catch (...)
    {
        QMessageBox::information(this, "Error", "Unexpected Error");
    }
}
