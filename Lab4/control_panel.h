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

public slots:
    void getBusy(int floor, direction new_dir);
    void getFree();

private:
    int cur_floor;
    //int cur_target;
    QVector<bool> targets;
    panel_status status;
    direction dir;

private:
    void nextTarget();
};
