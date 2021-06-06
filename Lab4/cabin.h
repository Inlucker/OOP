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
  };

public:
    explicit Cabin(QObject *parent = nullptr);

signals:
    void cabinCrossedFloor(int floor, direction new_dir);
    void becomeMoving();
    void cabinStayClosed();
    void cabinStopped();

public slots:
    void startMoving(int floor, direction new_dir);
    void move();
    void becomeClosed();
    void stopOnFloor();

private:
    int cur_floor;
    cabin_status status;
    direction dir;
    Doors doors;
    QTimer crossing_floor_timer;
};
