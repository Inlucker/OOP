#pragma once

#include <QObject>

#include "constants.h"
#include "control_panel.h"
#include "door.h"


class Cabin : public QObject
{
  Q_OBJECT
  enum cabin_status
  {
      STAY_CLOSED,
      STOPED_ON_FLOOR,
      START_MOVING,
      MOVING
      /*MOVE,
      WAIT_DOORS,
      STOP*/
  };

public:
    explicit Cabin(QObject *parent = nullptr);

signals:
    void cabinCrossedFloor(int floor, direction new_dir);
    void becomeMoving();
    void cabinStayClosed(int floor);
    void cabinStopped();
    /*void startClosingDoors();
    void cabin_crossing_floor(int floor);
    void cabinStopped();
    void startMoving();*/
    /*void cabin_called();
    void cabin_crossing_floor(int floor, direction d);
    void cabin_reached_target(int floor);
    void cabin_stopped(int floor);*/

public slots:
    void startMoving(int floor, direction new_dir);
    void move();
    void becomeClosed();
    void stopOnFloor();
    /*void wait(direction new_dir);
    void move();
    void cabinStop(direction new_dir);*/
    /*void cabin_move();
    void cabin_stopping();
    void cabin_call(int floor, direction dir);*/

private:
    int cur_floor;
    //int target;
    //bool new_target;
    cabin_status status;
    direction dir;
    Doors doors;
    QTimer crossing_floor_timer;
};
