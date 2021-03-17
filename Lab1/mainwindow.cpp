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
