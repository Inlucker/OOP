#pragma once

#include <QObject>
#include <QVector>

#include <constants.h>

class ControlPanel : public QObject
{
  Q_OBJECT
  enum panel_status
  {
      /*FREE,
      BECOMING_BUSY,
      PASSING_FLOOR*/
      FREE,
      BUSY
  };

public:
    explicit ControlPanel(QObject *parent = nullptr);
    void addTarget(int floor);

signals:
    void addedTarget(int floor, direction new_dir);
    void cabinAchievedTarget();
    /*void addedTarget(int floor);
    void startMoving(direction cur_dir);
    void stopCabin(direction new_dir);
    void noTargets();
    void move();*/

public slots:
    void getBusy(int floor, direction new_dir);
    void getFree(int floor);
    /*void getBusy(int floor); //BUSY
    void getFree(); //FREE*/

private:
    int cur_floor;
    int cur_target;
    QVector<bool> targets;
    panel_status status;
    direction dir;

private:
    void nextTarget();
    //void findNewTarget();
    //bool getClosestTarget(int &floor);
    //void find_new_target();
};
