#include <control_panel.h>

#include <iostream>

#include <QDebug>

ControlPanel::ControlPanel(QObject *parent) : QObject(parent)
{
    cur_floor = 1;
    cur_target = -1;
    targets = QVector<bool>(NUM_FLOORS, false);
    status = FREE;
    dir = STAY;

    QObject::connect(this, SIGNAL(addedTarget(int, direction)), this, SLOT(getBusy(int, direction)));
}

void ControlPanel::addTarget(int floor)
{
    //qDebug() << "Added target: floor №: " << floor;
    targets[floor - 1] = true;

    nextTarget();
}

void ControlPanel::getBusy(int floor, direction new_dir)
{
    if (status == FREE)
    {
        status = BUSY;
        cur_target = floor;
        dir = new_dir;
    }
    else if (status == BUSY)
    {
        cur_floor = floor;
        if (targets[floor - 1])
        {
            targets[floor - 1] = false;
            emit cabinAchievedTarget();
        }
        else
            qDebug() << "Passed floor" << floor;
    }
}

void ControlPanel::getFree()
{
    status = FREE;
    //cur_floor = floor;
    nextTarget();
}

void ControlPanel::nextTarget()
{
    if (targets[cur_floor - 1])
    {
        emit addedTarget(cur_floor, STAY);
    }
    else if (status == FREE)
    {
        for (int i = 0; i < NUM_FLOORS; i++)
            if (targets[i])
            {
                if (i + 1 > cur_floor)
                    emit addedTarget(i + 1, UP);
                else
                    emit addedTarget(i + 1, DOWN);
                break;
            }
    }
}
