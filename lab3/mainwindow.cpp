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

    LoadModel loadCmd("cube.txt");
    interface->execute(loadCmd);

    DrawScene drawCmd;
    interface->execute(drawCmd);

    CommandA cmd1(1.2, 3.4);
    interface->execute(cmd1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    SetDrawerScene setDrawerCmd(canvas->scene);
    interface->execute(setDrawerCmd);
}

void MainWindow::on_pushButton_2_clicked()
{
    DrawScene drawCmd;
    interface->execute(drawCmd);
    canvas->update();
}
