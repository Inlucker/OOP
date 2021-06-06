#include <cabin.h>

#include <QString>

#include <QDebug>

Cabin::Cabin(QObject *parent) : QObject(parent)
{
    cur_floor = 1;
    //target = -1;
    //new_target = false;
    status = STAY_CLOSED;
    dir = STAY;
    crossing_floor_timer.setSingleShot(true);

    QObject::connect(&doors, SIGNAL(closedDoors()), this, SLOT(becomeClosed()));
    QObject::connect(this, SIGNAL(cabinStopped()), &doors, SLOT(startOpening()));

    QObject::connect(&crossing_floor_timer, SIGNAL(timeout()), this, SLOT(move()));

    QObject::connect(this, SIGNAL(becomeMoving()), this, SLOT(move()));

    /*QObject::connect(this, SIGNAL(startClosingDoors()), &doors, SLOT(startClosing()));
    QObject::connect(&doors, SIGNAL(closedDoors()), this, SLOT(move()));
    QObject::connect(&crossing_floor_timer, SIGNAL(timeout()), this, SLOT(move()));
    QObject::connect(this, SIGNAL(cabinStopped()), &doors, SLOT(startOpenning()));
    QObject::connect(this, SIGNAL(startMoving()), this, SLOT(move()));*/

    /*QObject::connect(this, SIGNAL(cabin_called()), &doors, SLOT(start_closing()));
    QObject::connect(this, SIGNAL(cabin_reached_target(int)), this, SLOT(cabin_stopping()));
    QObject::connect(this, SIGNAL(cabin_stopped(int)), &doors, SLOT(start_openning()));
    QObject::connect(&doors, SIGNAL(closed_doors()), this, SLOT(cabin_move()));
    QObject::connect(&crossing_floor_timer, SIGNAL(timeout()), this, SLOT(cabin_move()));*/
}

void Cabin::startMoving(int floor, direction new_dir)
{
    if (status == STAY_CLOSED)
    {
        status = START_MOVING;
        dir = new_dir;
        emit becomeMoving();
    }
}

void Cabin::move()
{
    if (status == START_MOVING || status == MOVING)
    {
        if (status == MOVING)
        {
            cur_floor += dir;
        }

        status = MOVING;
        emit cabinCrossedFloor(cur_floor, dir);
        crossing_floor_timer.start(CROSSING_FLOOR_TIME);
    }
}

void Cabin::becomeClosed()
{
    if (status == STOPED_ON_FLOOR)
    {
        status = STAY_CLOSED;
        qDebug() << "Cabin closed";
        //qDebug() << "Cabin waiting";
        emit cabinStayClosed(cur_floor);
    }
}

void Cabin::stopOnFloor()
{
    if (status == MOVING || status == STOPED_ON_FLOOR)
    {
        status = STOPED_ON_FLOOR;
        qDebug() << "Cabin stopped at floor " << cur_floor;
        emit cabinStopped();
    }
}

/*void Cabin::wait(direction new_dir)
{
    if (status == STOP)
    {
        status = WAIT_DOORS;
        dir = new_dir;
        if (doors.getDoorsStatus() != CLOSED)
            emit startClosingDoors(); //startClosing
        else
            emit startMoving(); //move
    }
}

void Cabin::move()
{
    if (status == WAIT_DOORS || status == MOVE)
    {
        if (status == MOVE)
        {
            cur_floor += dir;
            emit cabin_crossing_floor(cur_floor); //busy
        }

        status = MOVE;
        //if (dir != STAY)
        crossing_floor_timer.start(CROSSING_FLOOR_TIME);
    }
}

void Cabin::cabinStop(direction new_dir)
{
    if (status == MOVE)
    {
        status = STOP;
        crossing_floor_timer.stop();
        dir = new_dir;
        qDebug() << "Stopped at floor " << QString::number(cur_floor) << ".";
        emit cabinStopped();
    }
}*/

/*void Cabin::cabin_move()
{
  if (new_target && status == WAIT)
  {
    status = MOVE;

    if (cur_floor == target)
    {
      emit cabin_reached_target(cur_floor);
    }
    else
    {
      crossing_floor_timer.start(CROSSING_FLOOR);
    }

    return;
  }

  if (status == MOVE)
  {
    cur_floor += dir;

    if (cur_floor == target)
    {
      emit cabin_reached_target(cur_floor);
    }
    else
    {
      emit cabin_crossing_floor(cur_floor, dir);
      crossing_floor_timer.start(CROSSING_FLOOR);
    }
  }
}

void Cabin::cabin_stopping()
{
  if (status != MOVE)
    return;

  status = STOP;
  qDebug() << "Stopped at floor " << QString::number(cur_floor) << ".";
  emit cabin_stopped(cur_floor);
}

void Cabin::cabin_call(int floor, direction dir)
{
  if (status != STOP)
    return;

  new_target = true;
  status = WAIT;
  target = floor;

  dir = dir;
  emit cabin_called();
}*/
