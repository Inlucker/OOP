#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

#include "facade.h"
#include "commands.h"
#include "canvas.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_SetSceneBtn_clicked();

    void on_DrawBtn_clicked();

    void on_ClearSceneBtn_clicked();

    void on_AddModelBtn_clicked();

    void on_RotateModelBtn_clicked();

    void on_MoveModelBtn_clicked();

    void on_ScaleModelBtn_clicked();

private:
    Canvas *canvas;
    shared_ptr<Facade> interface;
    //shared_ptr<QPainter> painter;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
