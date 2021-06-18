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

        ui->tableWidget->setRowCount(2);
        ui->tableWidget->setColumnCount(1);
        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Object");


        /*QTableWidgetItem *id_itm = new QTableWidgetItem("0");
        ui->tableWidget->setItem(0, 0, id_itm);*/
        QTableWidgetItem *obj_itm = new QTableWidgetItem("Camera");
        obj_itm->setBackground(QBrush(Qt::green));
        cur_camera_id = 0;
        ui->tableWidget->setItem(0, 0, obj_itm);

        /*QTableWidgetItem *id_itm2 = new QTableWidgetItem("1");
        ui->tableWidget->setItem(1, 0, id_itm2);*/
        QTableWidgetItem *obj_itm2 = new QTableWidgetItem("Camera");
        ui->tableWidget->setItem(1, 0, obj_itm2);

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

            /*QString modelIds = ui->Model_IDs->text();
            int n = modelIds.toInt();*/

            QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
            if (selectedRows.size() <= 0)
            {
                QMessageBox::information(this, "Error", "Выберите хотябы один объект из списка");
                return;
            }
            for (int i = 0; i < selectedRows.size(); i++)
            {
                TransformObject transformCmd(selectedRows[i].row(), Point(0, 0, 0), Point(1, 1, 1), Point(y, x, 0));
                interface->execute(transformCmd);
            }

            /*TransformObject transformCmd(n, Point(0, 0, 0), Point(1, 1, 1), Point(y, x, 0));
            interface->execute(transformCmd);*/

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

            QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
            if (selectedRows.size() <= 0)
            {
                QMessageBox::information(this, "Error", "Выберите хотябы один объект из списка");
                return;
            }
            for (int i = 0; i < selectedRows.size(); i++)
            {
                TransformObject transformCmd(selectedRows[i].row(), Point(-x, -y, 0), Point(1, 1, 1), Point(0, 0, 0));
                interface->execute(transformCmd);
            }

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
            //cout <<  numDegrees.x() << endl;
            //cout <<  numDegrees.y() << endl;
            double kx = 1 + double(numDegrees.x()) / SCALE_SPEED;
            double ky = 1 + double(numDegrees.y()) / SCALE_SPEED;
            //cout <<  kx << endl;
            //cout <<  ky << endl;

            QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
            if (selectedRows.size() <= 0)
            {
                QMessageBox::information(this, "Error", "Выберите хотябы один объект из списка");
                return;
            }
            for (int i = 0; i < selectedRows.size(); i++)
            {
                TransformObject transformCmd(selectedRows[i].row(), Point(0, 0, 0), Point(ky, ky, ky), Point(0, 0, 0));
                interface->execute(transformCmd);
            }

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

        //ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);

        /*DrawScene drawCmd;
        interface->execute(drawCmd);*/

        //canvas->clean();

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

        ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
        QTableWidgetItem *obj_itm = new QTableWidgetItem("Model");
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, obj_itm);

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
        bool isDouble;

        double x = ui->lineEdit_x_3->text().toDouble(&isDouble);
        if (!isDouble)
        {
            QMessageBox::information(this, "Error", "Параметры преобразовнний должны быть вещественным числами");
            return;
        }

        double y = ui->lineEdit_y_3->text().toDouble(&isDouble);
        if (!isDouble)
        {
            QMessageBox::information(this, "Error", "Параметры преобразовнний должны быть вещественным числами");
            return;
        }

        double z = ui->lineEdit_z_3->text().toDouble(&isDouble);
        if (!isDouble)
        {
            QMessageBox::information(this, "Error", "Параметры преобразовнний должны быть вещественным числами");
            return;
        }

        QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
        if (selectedRows.size() <= 0)
        {
            QMessageBox::information(this, "Error", "Выберите хотябы один объект из списка");
            return;
        }
        for (int i = 0; i < selectedRows.size(); i++)
        {
            TransformObject transformCmd(selectedRows[i].row(), Point(0, 0, 0), Point(1, 1, 1), Point(x, y, z));
            interface->execute(transformCmd);
        }

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
        bool isDouble;

        double x = ui->lineEdit_x->text().toDouble(&isDouble);
        if (!isDouble)
        {
            QMessageBox::information(this, "Error", "Параметры преобразовнний должны быть вещественным числами");
            return;
        }

        double y = ui->lineEdit_y->text().toDouble(&isDouble);
        if (!isDouble)
        {
            QMessageBox::information(this, "Error", "Параметры преобразовнний должны быть вещественным числами");
            return;
        }

        double z = ui->lineEdit_z->text().toDouble(&isDouble);
        if (!isDouble)
        {
            QMessageBox::information(this, "Error", "Параметры преобразовнний должны быть вещественным числами");
            return;
        }

        QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
        if (selectedRows.size() <= 0)
        {
            QMessageBox::information(this, "Error", "Выберите хотябы один объект из списка");
            return;
        }
        for (int i = 0; i < selectedRows.size(); i++)
        {
            TransformObject transformCmd(selectedRows[i].row(), Point(x, y, z), Point(1, 1, 1), Point(0, 0, 0));
            interface->execute(transformCmd);
        }

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
        bool isDouble;

        double x = ui->lineEdit_x_2->text().toDouble(&isDouble);
        if (!isDouble)
        {
            QMessageBox::information(this, "Error", "Параметры преобразовнний должны быть вещественным числами");
            return;
        }

        double y = ui->lineEdit_y_2->text().toDouble(&isDouble);
        if (!isDouble)
        {
            QMessageBox::information(this, "Error", "Параметры преобразовнний должны быть вещественным числами");
            return;
        }

        double z = ui->lineEdit_z_2->text().toDouble(&isDouble);
        if (!isDouble)
        {
            QMessageBox::information(this, "Error", "Параметры преобразовнний должны быть вещественным числами");
            return;
        }

        QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
        if (selectedRows.size() <= 0)
        {
            QMessageBox::information(this, "Error", "Выберите хотябы один объект из списка");
            return;
        }
        for (int i = 0; i < selectedRows.size(); i++)
        {
            TransformObject transformCmd(selectedRows[i].row(), Point(0, 0, 0), Point(x, y, z), Point(0, 0, 0));
            interface->execute(transformCmd);
        }

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

        ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
        QTableWidgetItem *obj_itm = new QTableWidgetItem("Camera");
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, obj_itm);

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
        QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
        if (selectedRows.size() <= 0)
        {
            QMessageBox::information(this, "Error", "Выберите хотябы один объект из списка");
            return;
        }
        for (int i = 0; i < selectedRows.size(); i++)
        {
            while (!selectedRows.empty())
            {
                DeleteObject deleteObjectCmd(selectedRows[0].row());
                interface->execute(deleteObjectCmd);
                ui->tableWidget->removeRow(selectedRows[0].row());
                selectedRows = ui->tableWidget->selectionModel()->selectedRows();
            }
        }

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
        QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
        if (selectedRows.size() <= 0)
        {
            QMessageBox::information(this, "Error", "Выберите хотябы один объект из списка");
            return;
        }
        UseCamera useCameraCmd(selectedRows[0].row());
        interface->execute(useCameraCmd);

        ui->tableWidget->item(cur_camera_id, 0)->setBackground(QBrush(Qt::white));
        ui->tableWidget->item(selectedRows[0].row(), 0)->setBackground(QBrush(Qt::green));
        cur_camera_id = selectedRows[0].row();

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
