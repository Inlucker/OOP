#include "entry_point.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedHeight(this->height());
    this->setFixedWidth(this->width());

    canvas = new Canvas();
    ui->gridLayout->addWidget(canvas);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_load_model_clicked()
{
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    if (str == "")
        return;
    Action act;
    strcpy(act.load.fileName, str.toStdString().c_str());

    int res = entry_point(canvas->model, LOAD, act);
    QString error = "";

    if (res == FILE_NOT_FOUND)
        error = "Cannot open file";
    else if (res == FILE_ERROR)
        error = "Error format of data";
    else if (res == MEMORY_ERROR)
        error = "Memory error";
    if (error != "")
    {
        QMessageBox::information(this, "Error", error);
        return;
    }
    //entry_point(act, DRAW);
    canvas->update();
}

void MainWindow::on_moveButton_clicked()
{
    bool isXFloat = false;
    float x = ui->dxEdit->text().toFloat(&isXFloat);
    bool isYFloat = false;
    float y = ui->dyEdit->text().toFloat(&isYFloat);
    bool isZFloat = false;
    float z = ui->dzEdit->text().toFloat(&isZFloat);

    if (isXFloat && isYFloat && isZFloat)
    {
        Action act;

        act.move.dx = x;
        act.move.dy = y;
        act.move.dz = z;

        entry_point(canvas->model, MOVE, act);
        canvas->update();
    }
}

void MainWindow::on_scaleButton_clicked()
{
    bool isXFloat = false;
    float x = ui->kxEdit->text().toFloat(&isXFloat);
    bool isYFloat = false;
    float y = ui->kyEdit->text().toFloat(&isYFloat);
    bool isZFloat = false;
    float z = ui->kzEdit->text().toFloat(&isZFloat);

    if (isXFloat && isYFloat && isZFloat)
    {
        Action act;

        act.scale.kx = x;
        act.scale.ky = y;
        act.scale.kz = z;

        entry_point(canvas->model, SCALE, act);
        canvas->update();
    }
}

void MainWindow::on_rotateButton_clicked()
{
    bool isXFloat = false;
    float x = ui->rot_xEdit->text().toFloat(&isXFloat);
    bool isYFloat = false;
    float y = ui->rot_yEdit->text().toFloat(&isYFloat);
    bool isZFloat = false;
    float z = ui->rot_zEdit->text().toFloat(&isZFloat);


    //double *data = GetData(edits);

    /*if(LineEditError != NO_ER)
        return;*/


    if (isXFloat && isYFloat && isZFloat)
    {
        Action act;

        act.rotate.x_angle = x * M_PI / 180;
        act.rotate.y_angle = y * M_PI / 180;
        act.rotate.z_angle = z * M_PI / 180;
        std::cout << x << " " << y << " " << z << endl;

        entry_point(canvas->model, ROTATE, act);
        //main_controller(scene, act, DRAW);
        canvas->update();
        //delete[] data;
    }
}
