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

    //canvas = new Canvas();
    canvas = shared_ptr<Canvas>(new Canvas());
    //ui->gridLayout->addWidget(canvas);
    ui->gridLayout->addWidget(&*canvas);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Object" << "Name");

    try
    {
        //SetDrawer
        SetDrawer setDrawerCmd(canvas->drawer);
        interface->execute(setDrawerCmd);

        //SetScene
        //shared_ptr<TestCanvas> testCanvas = make_shared<TestCanvas>(TestCanvas());
        //SetCanvas setCanvasCmd(testCanvas);
        SetCanvas setCanvasCmd(canvas->canvas);
        interface->execute(setCanvasCmd);

        //AddCamera addCameraCmd(Point(0, 0, 0), Point(0, 0, 0));
        //AddCamera addCameraCmd2(Point(0, 300, -300), Point(45, 45, 45));
        AddCamera addCameraCmd(Point(0, 0, 0), Point(0, 0, 0), "Robert");
        AddCamera addCameraCmd2(Point(0, 300, -300), Point(45, 45, 45), "Leo");
        //AddCamera addCameraCmd(Point(200, 200, 300), Point(45, 45, 35));
        interface->execute(addCameraCmd);
        interface->execute(addCameraCmd2);

        ui->tableWidget->setRowCount(2);

        QTableWidgetItem *obj_itm11 = new QTableWidgetItem("Camera");
        ui->tableWidget->setItem(0, 0, obj_itm11);
        QTableWidgetItem *obj_itm12 = new QTableWidgetItem("Robert");
        ui->tableWidget->setItem(0, 1, obj_itm12);

        QTableWidgetItem *obj_itm21 = new QTableWidgetItem("Camera");
        ui->tableWidget->setItem(1, 0, obj_itm21);
        QTableWidgetItem *obj_itm22 = new QTableWidgetItem("Leo");
        ui->tableWidget->setItem(1, 1, obj_itm22);

        //UseCamera useCamera(0);
        UseCameraName useCamera("Robert");
        interface->execute(useCamera);

        obj_itm11->setBackground(QBrush(Qt::green));
        obj_itm12->setBackground(QBrush(Qt::green));
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
    //delete canvas;
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
        SaveScene saveCmd;
        interface->execute(saveCmd);
        //cout << "Set" << endl;
        //previous_x = event->x();
        //previous_y = event->y();
        LMB_is_pressed = true;
    }
    if (event->button() == Qt::RightButton && !RMB_is_pressed && this->canvas->rect().contains(event->pos()))
    {
        SaveScene saveCmd;
        interface->execute(saveCmd);
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
                //TransformObject transformCmd(selectedRows[i].row(), Point(0, 0, 0), Point(1, 1, 1), Point(y, x, 0));
                string name = ui->tableWidget->item(selectedRows[i].row(), 1)->text().toStdString();
                TransformObjectName transformCmd(name, Point(0, 0, 0), Point(1, 1, 1), Point(y, x, 0));
                interface->execute(transformCmd);
            }

            /*TransformObject transformCmd(n, Point(0, 0, 0), Point(1, 1, 1), Point(y, x, 0));
            interface->execute(transformCmd);*/

            ClearCanvas clearCmd;
            interface->execute(clearCmd);
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
                //TransformObject transformCmd(selectedRows[i].row(), Point(-x, -y, 0), Point(1, 1, 1), Point(0, 0, 0));
                string name = ui->tableWidget->item(selectedRows[i].row(), 1)->text().toStdString();
                TransformObjectName transformCmd(name, Point(-x, -y, 0), Point(1, 1, 1), Point(0, 0, 0));
                interface->execute(transformCmd);
            }

            ClearCanvas clearCmd;
            interface->execute(clearCmd);
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
            //double kx = 1 + double(numDegrees.x()) / SCALE_SPEED;
            double ky = 1 + double(numDegrees.y()) / SCALE_SPEED;
            //cout <<  kx << endl;
            //cout <<  ky << endl;

            QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
            if (selectedRows.size() <= 0)
            {
                QMessageBox::information(this, "Error", "Выберите хотябы один объект из списка");
                return;
            }

            SaveScene saveCmd;
            interface->execute(saveCmd);
            for (int i = 0; i < selectedRows.size(); i++)
            {
                //TransformObject transformCmd(selectedRows[i].row(), Point(0, 0, 0), Point(ky, ky, ky), Point(0, 0, 0));
                string name = ui->tableWidget->item(selectedRows[i].row(), 1)->text().toStdString();
                TransformObjectName transformCmd(name, Point(0, 0, 0), Point(ky, ky, ky), Point(0, 0, 0));
                interface->execute(transformCmd);
            }

            ClearCanvas clearCmd;
            interface->execute(clearCmd);
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

void MainWindow::on_ClearSceneBtn_clicked()
{
    try
    {
        /*SaveScene saveCmd;
        interface->execute(saveCmd);*/

        ClearObjects clearObjectsCmd;
        interface->execute(clearObjectsCmd);

        //ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);

        ClearCanvas clearCmd;
        interface->execute(clearCmd);

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
        QString model_name = ui->lineEdit_model_name->text();
        //LoadModel loadCmd(ui->lineEdit_model->text().toStdString());
        LoadModel loadCmd(ui->lineEdit_model->text().toStdString(), model_name.toStdString());
        //LoadModel loadCmd("cube1.txt");
        //LoadModel loadCmd("12granSec.txt");
        interface->execute(loadCmd);

        ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
        QTableWidgetItem *obj_itm = new QTableWidgetItem("Model");
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, obj_itm);
        QTableWidgetItem *obj_itm2 = new QTableWidgetItem(model_name);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, obj_itm2);

        ClearCanvas clearCmd;
        interface->execute(clearCmd);
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

        SaveScene saveCmd;
        interface->execute(saveCmd);
        for (int i = 0; i < selectedRows.size(); i++)
        {
            //TransformObject transformCmd(selectedRows[i].row(), Point(0, 0, 0), Point(1, 1, 1), Point(x, y, z));
            string name = ui->tableWidget->item(selectedRows[i].row(), 1)->text().toStdString();
            TransformObjectName transformCmd(name, Point(0, 0, 0), Point(1, 1, 1), Point(x, y, z));
            interface->execute(transformCmd);
        }

        ClearCanvas clearCmd;
        interface->execute(clearCmd);
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

        SaveScene saveCmd;
        interface->execute(saveCmd);
        for (int i = 0; i < selectedRows.size(); i++)
        {
            //TransformObject transformCmd(selectedRows[i].row(), Point(x, y, z), Point(1, 1, 1), Point(0, 0, 0));
            string name = ui->tableWidget->item(selectedRows[i].row(), 1)->text().toStdString();
            TransformObjectName transformCmd(name, Point(x, y, z), Point(1, 1, 1), Point(0, 0, 0));
            interface->execute(transformCmd);
        }

        ClearCanvas clearCmd;
        interface->execute(clearCmd);
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

        SaveScene saveCmd;
        interface->execute(saveCmd);
        for (int i = 0; i < selectedRows.size(); i++)
        {
            //TransformObject transformCmd(selectedRows[i].row(), Point(0, 0, 0), Point(x, y, z), Point(0, 0, 0));
            string name = ui->tableWidget->item(selectedRows[i].row(), 1)->text().toStdString();
            TransformObjectName transformCmd(name, Point(0, 0, 0), Point(x, y, z), Point(0, 0, 0));
            interface->execute(transformCmd);
        }

        ClearCanvas clearCmd;
        interface->execute(clearCmd);
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
        bool isDouble;

        double x = ui->lineEdit_camera_x->text().toDouble(&isDouble);
        if (!isDouble)
        {
            QMessageBox::information(this, "Error", "Параметры преобразовнний должны быть вещественным числами");
            return;
        }

        double y = ui->lineEdit_camera_y->text().toDouble(&isDouble);
        if (!isDouble)
        {
            QMessageBox::information(this, "Error", "Параметры преобразовнний должны быть вещественным числами");
            return;
        }

        double z = ui->lineEdit_camera_z->text().toDouble(&isDouble);
        if (!isDouble)
        {
            QMessageBox::information(this, "Error", "Параметры преобразовнний должны быть вещественным числами");
            return;
        }

        double angle_x = ui->lineEdit_camera_x_2->text().toDouble(&isDouble);
        if (!isDouble)
        {
            QMessageBox::information(this, "Error", "Параметры преобразовнний должны быть вещественным числами");
            return;
        }

        double angle_y = ui->lineEdit_camera_y_2->text().toDouble(&isDouble);
        if (!isDouble)
        {
            QMessageBox::information(this, "Error", "Параметры преобразовнний должны быть вещественным числами");
            return;
        }

        double angle_z = ui->lineEdit_camera_z_2->text().toDouble(&isDouble);
        if (!isDouble)
        {
            QMessageBox::information(this, "Error", "Параметры преобразовнний должны быть вещественным числами");
            return;
        }

        QString camera_name = ui->lineEdit_camera_name->text();
        AddCamera addCameraCmd(Point(x, y, z), Point(angle_x, angle_y, angle_z), camera_name.toStdString());
        interface->execute(addCameraCmd);

        ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
        QTableWidgetItem *obj_itm = new QTableWidgetItem("Camera");
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, obj_itm);
        QTableWidgetItem *obj_itm2 = new QTableWidgetItem(camera_name);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, obj_itm2);

        /*DrawScene drawCmd;
        interface->execute(drawCmd);*/

        //canvas->update();
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
                //DeleteObject deleteObjectCmd(selectedRows[0].row());
                string name = ui->tableWidget->item(selectedRows[0].row(), 1)->text().toStdString();
                DeleteObjectName deleteObjectCmd(name);
                interface->execute(deleteObjectCmd);
                ui->tableWidget->removeRow(selectedRows[0].row());
                selectedRows = ui->tableWidget->selectionModel()->selectedRows();
            }
        }

        ClearCanvas clearCmd;
        interface->execute(clearCmd);
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
        string name = ui->tableWidget->item(selectedRows[0].row(), 1)->text().toStdString();
        //UseCamera useCameraCmd(selectedRows[0].row());
        UseCameraName useCameraCmd(name);
        interface->execute(useCameraCmd);

        for (int i = 0; i < ui->tableWidget->rowCount(); i++)
        {
            ui->tableWidget->item(i, 0)->setBackground(QBrush(Qt::white));
            ui->tableWidget->item(i, 1)->setBackground(QBrush(Qt::white));
        }
        ui->tableWidget->item(selectedRows[0].row(), 0)->setBackground(QBrush(Qt::green));
        ui->tableWidget->item(selectedRows[0].row(), 1)->setBackground(QBrush(Qt::green));

        ClearCanvas clearCmd;
        interface->execute(clearCmd);
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

void MainWindow::on_pushButton_clicked()
{
    try
    {
        ReturnScene returnCmd;
        interface->execute(returnCmd);

        ClearCanvas clearCmd;
        interface->execute(clearCmd);
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
    //updateTable();
}

#include "scenemanagercreator.h"
#include "scenemanager.h"

//Не нужно, просто тестирую
void MainWindow::updateTable()
{
    shared_ptr<SceneManager> sceneMan = SceneManagerCreator().getManager();
    shared_ptr<Object> comp = sceneMan->getScene()->getObjects();
    ui->tableWidget->setRowCount(comp->size());
    IteratorObject obj = comp->begin();
    int i = 0;
    while (obj != comp->end())
    {
        shared_ptr<Camera> tmpCam = dynamic_pointer_cast<Camera>(*obj);
        shared_ptr<Model> tmpMod = dynamic_pointer_cast<Model>(*obj);
        if (tmpCam)
        {
            QTableWidgetItem *obj_itm = new QTableWidgetItem("Camera");
            ui->tableWidget->setItem(i, 0, obj_itm);
        }
        if (tmpMod)
        {
            QTableWidgetItem *obj_itm = new QTableWidgetItem("Model");
            ui->tableWidget->setItem(i, 0, obj_itm);
        }
        i++;
        obj++;
    }
}
