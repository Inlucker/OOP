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
}

void Cabin::startMoving(direction new_dir)
{
    if (status == STAY_CLOSED)
    {
        status = START_MOVING;
        dir = new_dir;
        //emit becomeMoving();
        crossing_floor_timer.start(CROSSING_FLOOR_TIME);
    }
}

void Cabin::move()
{
    if (status == START_MOVING || status == MOVING)
    {
        /*if (status == MOVING)
        {
            cur_floor += dir;
        }*/
        cur_floor += dir;

        status = MOVING;
        emit cabinCrossedFloor(dir);
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
        emit cabinStayClosed();
    }
}

void Cabin::stopOnFloor()
{
    if (status == MOVING || status == STOPED_ON_FLOOR)
    {
        status = STOPED_ON_FLOOR;
        qDebug() << "Cabin stopped at floor" << cur_floor;
        emit cabinStopped();
    }
}
