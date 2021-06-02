#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>

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

protected:
   virtual void mouseReleaseEvent(QMouseEvent *event);
   virtual void mousePressEvent(QMouseEvent *event);
   virtual void mouseMoveEvent(QMouseEvent *event);

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

    bool LMB_is_pressed = false;
    int previous_x = 0, previous_y = 0;
    //shared_ptr<QPainter> painter;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
