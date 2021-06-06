#include <door.h>

#include <QDebug>

Doors::Doors(QObject *parent) : QObject(parent)
{
    status = CLOSED;

    doors_stay_open_timer.setInterval(WAITING_TIME);
    doors_stay_open_timer.setSingleShot(true);
    doors_open_timer.setSingleShot(true);
    doors_close_timer.setSingleShot(true);

    QObject::connect(&doors_open_timer, SIGNAL(timeout()), this, SLOT(open()));
    QObject::connect(&doors_close_timer, SIGNAL(timeout()), this, SLOT(close()));
    QObject::connect(this, SIGNAL(openedDoors()), &doors_stay_open_timer, SLOT(start()));
    QObject::connect(&doors_stay_open_timer, SIGNAL(timeout()), this, SLOT(startClosing()));
}

void Doors::startOpening()
{
    if (status == CLOSED)
    {
        status = OPENNING;
        qDebug() << "Doors are opening...";
        doors_open_timer.start(DOORS_TIME); // timeout() -> open()
    }
    else if (status == CLOSING)
    {
        status = OPENNING;
        qDebug() << "Doors are opening...";
        int t = doors_close_timer.remainingTime();
        doors_close_timer.stop();
        doors_open_timer.start(DOORS_TIME - t); // timeout() -> open()
    }
}

void Doors::startClosing()
{
    if (status == OPENED)
    {
        status = CLOSING;
        qDebug() << "Doors are closing...";
        doors_close_timer.start(DOORS_TIME); // timeout() -> close()
    }
}

void Doors::open()
{
    if (status == OPENNING)
    {
        status = OPENED;
        qDebug() << "The doors are opened!\nWaiting for passengers...";
        emit openedDoors(); //start() -> timeout() -> startClosing()
    }
}

void Doors::close()
{
    if (status == CLOSING)
    {
        status = CLOSED;
        qDebug() << "The doors are closed.";
        emit closedDoors(); //move
    }
}
