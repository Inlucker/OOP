#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>

#include "facade.h"
#include "commands.h"
#include "canvas.h"
#include "errors.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
   virtual void mouseReleaseEvent(QMouseEvent *event);
   virtual void mousePressEvent(QMouseEvent *event);
   virtual void mouseMoveEvent(QMouseEvent *event);
   virtual void wheelEvent(QWheelEvent *event);

private slots:
    void on_ClearSceneBtn_clicked();

    void on_AddModelBtn_clicked();

    void on_RotateModelBtn_clicked();

    void on_MoveModelBtn_clicked();

    void on_ScaleModelBtn_clicked();

    void on_AddCameraBtn_clicked();

    void on_DeleteObjBtn_clicked();

    void on_SetCameraBtn_clicked();

    void on_pushButton_clicked();

private:
    void updateTable(); //Не нужно, просто тестирую

private:
    //Canvas *canvas;
    shared_ptr<Canvas> canvas;
    shared_ptr<Facade> interface;

    bool LMB_is_pressed = false;
    bool RMB_is_pressed = false;
    int previous_x = 0, previous_y = 0;
    //shared_ptr<QPainter> painter;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
