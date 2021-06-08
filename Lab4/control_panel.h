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
      WAITING_NEXT_TARGET,
      SETTING_DIRECTION,
      PASSING_FLOOR
  };

public:
    explicit ControlPanel(QObject *parent = nullptr);
    void addTarget(int floor);

signals:
    void addedTarget(direction new_dir);
    void cabinAchievedTarget();
    void stayOnFloor(direction new_dir);

public slots:
    void getDirection(direction new_dir);
    void passFloor(direction new_dir);
    void findNextTarget();

private:
    int cur_floor;
    //int cur_target;
    QVector<bool> targets;
    panel_status status;
    direction dir;

private:
    void nextTarget();
};
