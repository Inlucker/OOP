#include "entry_point.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

#include <math.h>
#include "error_codes.h"

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

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        LMB_is_pressed = false;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && !LMB_is_pressed && this->canvas->rect().contains(event->pos()))
    {
        //cout << "Set" << endl;
        previous_x = event->position().x();
        previous_y = event->position().y();
        LMB_is_pressed = true;
    }
}

#define ROTATE_SPEED 100

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (LMB_is_pressed)
    {
        double x = double(previous_x - event->position().x()) / ROTATE_SPEED;
        double y = double(-previous_y + event->position().y()) / ROTATE_SPEED;

        Action act;

        act.rotate.x_angle = y;
        act.rotate.y_angle = x;
        act.rotate.z_angle = 0;

        entry_point(canvas->proection, ROTATE, act);
        entry_point(canvas->proection, PROECTION, act);
        canvas->update();
        previous_x = event->position().x();
        previous_y = event->position().y();
    }
}

/*void MainWindow::keyPressEvent(QKeyEvent *event)
{
        cout << event->key() << endl;
}*/

void MainWindow::on_load_model_clicked()
{
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    if (str == "")
        return;
    Action act;

    //-----------------------------------------------------
    /*act.load.file_name_size = str.length();
    act.load.fileName = new char[act.load.file_name_size];
    memmove(act.load.fileName, str.toStdString().c_str(), str.length());

    int res = entry_point(canvas->proection, LOAD, act);
    delete[] act.load.fileName;
    act.load.file_name_size = 0;*/
    //-----------------------------------------------------

    strcpy(act.load.fileName, str.toStdString().c_str());

    int res = entry_point(canvas->proection, LOAD, act);

    QString error = "";

    if (res == FILE_OPEN_ERROR)
        error = "Cannot open file";
    else if (res == FILE_ERROR)
        error = "Error format of data";
    else if (res == MEMORY_ALLOCATION_ERROR)
        error = "Memory error";
    if (error != "")
    {
        QMessageBox::information(this, "Error", error);
        return;
    }
    entry_point(canvas->proection, PROECTION, act);
    canvas->update();
    //std::cout << "UPDATED CANVAS" << std::endl;
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

        entry_point(canvas->proection, MOVE, act);
        entry_point(canvas->proection, PROECTION, act);
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

        entry_point(canvas->proection, SCALE, act);
        entry_point(canvas->proection, PROECTION, act);
        canvas->update();
    }
}

void MainWindow::on_rotateButton_x_clicked()
{
    bool isXFloat = false;
    float x = ui->rot_xEdit->text().toFloat(&isXFloat);
    //bool isYFloat = false;
    //float y = ui->rot_yEdit->text().toFloat(&isYFloat);
    //bool isZFloat = false;
    //float z = ui->rot_zEdit->text().toFloat(&isZFloat);


    //double *data = GetData(edits);

    /*if(LineEditError != NO_ER)
        return;*/

    //if (isXFloat && isYFloat && isZFloat)
    if (isXFloat)
    {
        Action act;

        act.rotate.x_angle = x * M_PI / 180;
        act.rotate.y_angle = 0; //y * M_PI / 180;
        act.rotate.z_angle = 0; //z * M_PI / 180;
        //std::cout << x << " " << y << " " << z << endl;

        entry_point(canvas->proection, ROTATE, act);
        entry_point(canvas->proection, PROECTION, act);
        canvas->update();
    }
}

void MainWindow::on_rotateButton_y_clicked()
{
    bool isYFloat = false;
    float y = ui->rot_yEdit->text().toFloat(&isYFloat);

    if (isYFloat)
    {
        Action act;

        act.rotate.x_angle = 0;
        act.rotate.y_angle = y * M_PI / 180;
        act.rotate.z_angle = 0;

        entry_point(canvas->proection, ROTATE, act);
        entry_point(canvas->proection, PROECTION, act);
        canvas->update();
    }
}

void MainWindow::on_rotateButton_z_clicked()
{
    bool isZFloat = false;
    float z = ui->rot_yEdit->text().toFloat(&isZFloat);

    if (isZFloat)
    {
        Action act;

        act.rotate.x_angle = 0;
        act.rotate.y_angle = 0;
        act.rotate.z_angle = z * M_PI / 180;

        entry_point(canvas->proection, ROTATE, act);
        entry_point(canvas->proection, PROECTION, act);
        canvas->update();
    }

}

void MainWindow::on_save_model_clicked()
{
    //setlocale (LC_ALL, "C");
    QString str = QFileDialog::getSaveFileName(0, "Save", "", "*.txt");

    if(str == "")
        return;

    Action act;
    //-----------------------------------------------------
    /*act.load.file_name_size = str.length();
    act.load.fileName = new char[act.load.file_name_size];
    memmove(act.load.fileName, str.toStdString().c_str(), str.length());

    int res = entry_point(canvas->proection, SAVE, act);
    delete[] act.load.fileName;
    act.load.file_name_size = 0;*/
    //-----------------------------------------------------

    strcpy(act.load.fileName, str.toStdString().c_str());

    int res = entry_point(canvas->proection, SAVE, act);
    QString error = "";

    if (res == FILE_NOT_FOUND)
        error = "Cannot open file";
    else if (res == FILE_ERROR)
        error = "Error format of data";

    if(error != "")
    {
        QMessageBox::information(this, "Error", error);
        return;
    }
}
