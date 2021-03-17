#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "canvas.h"
#include <QMainWindow>
#include <QKeyEvent>

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
   //virtual void keyPressEvent(QKeyEvent *event);

private slots:
    void on_load_model_clicked();

    void on_moveButton_clicked();

    void on_scaleButton_clicked();

    void on_rotateButton_x_clicked();

    void on_rotateButton_y_clicked();

    void on_rotateButton_z_clicked();

    void on_save_model_clicked();

private:
    Ui::MainWindow *ui;

    bool LMB_is_pressed = false;
    int previous_x, previous_y;

    Canvas *canvas;
};
#endif // MAINWINDOW_H
