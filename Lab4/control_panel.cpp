#include <control_panel.h>

#include <iostream>

#include <QDebug>

ControlPanel::ControlPanel(QObject *parent) : QObject(parent)
{
    cur_floor = 1;
    //cur_target = -1;
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
        //cur_target = floor;
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
        if (dir == UP || (dir == STAY && cur_floor > NUM_FLOORS/2))
        {
            for (int i = cur_floor; i <= NUM_FLOORS; i++)
                if (targets[i-1])
                {
                    emit addedTarget(i, UP);
                    return;
                }
            for (int i = cur_floor; i > 0; i--)
                if (targets[i-1])
                {
                    emit addedTarget(i, DOWN);
                    return;
                }
        }
        else //if (dir == DOWN)
        {
            for (int i = cur_floor; i > 0; i--)
                if (targets[i-1])
                {
                    emit addedTarget(i, DOWN);
                    return;
                }
            for (int i = cur_floor; i <= NUM_FLOORS; i++)
                if (targets[i-1])
                {
                    emit addedTarget(i, UP);
                    return;
                }
        }
    }
}
