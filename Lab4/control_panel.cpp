#include <control_panel.h>

#include <iostream>

#include <QDebug>

ControlPanel::ControlPanel(QObject *parent) : QObject(parent)
{
    cur_floor = 1;
    //cur_target = -1;
    targets = QVector<bool>(NUM_FLOORS, false);
    status = WAITING_NEXT_TARGET;
    dir = STAY;

    QObject::connect(this, SIGNAL(addedTarget(direction)), this, SLOT(getDirection(direction)));
    QObject::connect(this, SIGNAL(stayOnFloor(direction)), this, SLOT(passFloor(direction)));

}

void ControlPanel::addTarget(int floor)
{
    //qDebug() << "Added target: floor №: " << floor;
    targets[floor - 1] = true;

    nextTarget();
}

void ControlPanel::getDirection(direction new_dir)
{
    if (status == WAITING_NEXT_TARGET)
    {
        status = SETTING_DIRECTION;
        //cur_target = floor;
        dir = new_dir;
    }
}

void ControlPanel::passFloor(direction new_dir)
{
    if (status == SETTING_DIRECTION || status == PASSING_FLOOR)
    {
        status = PASSING_FLOOR;
        cur_floor += new_dir;
        if (targets[cur_floor - 1])
        {
            targets[cur_floor - 1] = false;
            emit cabinAchievedTarget();
        }
        else
            qDebug() << "Passed floor" << cur_floor;
    }
}

void ControlPanel::findNextTarget()
{
    if (status == PASSING_FLOOR)
    status = WAITING_NEXT_TARGET;
    //cur_floor = floor;
    nextTarget();
}

void ControlPanel::nextTarget()
{
    if (targets[cur_floor - 1])
    {
        //emit addedTarget(STAY);
        emit stayOnFloor(STAY);
    }
    else if (status == WAITING_NEXT_TARGET)
    {
        if (dir == UP || (dir == STAY && cur_floor > NUM_FLOORS/2))
        {
            for (int i = cur_floor; i <= NUM_FLOORS; i++)
                if (targets[i-1])
                {
                    emit addedTarget(UP);
                    return;
                }
            for (int i = cur_floor; i > 0; i--)
                if (targets[i-1])
                {
                    emit addedTarget(DOWN);
                    return;
                }
        }
        else //if (dir == DOWN)
        {
            for (int i = cur_floor; i > 0; i--)
                if (targets[i-1])
                {
                    emit addedTarget(DOWN);
                    return;
                }
            for (int i = cur_floor; i <= NUM_FLOORS; i++)
                if (targets[i-1])
                {
                    emit addedTarget(UP);
                    return;
                }
        }
    }
}
