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
    /*QObject::connect(this, SIGNAL(addedTarget(int)), this, SLOT(getBusy(int)));
    QObject::connect(this, SIGNAL(noTargets()), this, SLOT(getFree()));*/
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
            qDebug() << "Passed floor " << floor;
    }
}

void ControlPanel::getFree(int floor)
{
    status = FREE;
    cur_floor = floor;
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

/*void ControlPanel::addTarget(int floor)
{
    targets[floor - 1] = true;

    if ((cur_target == -1) || (dir == UP && floor > cur_target) || (dir == DOWN && floor < cur_target))
        cur_target = floor;

    if (status == FREE)
        emit addedTarget(floor);

    //find_new_target();
}*/

/*void ControlPanel::getBusy(int floor)
{
    if (status == FREE)
    {
        status = BUSY;
        if (cur_floor == cur_target)
            dir = STAY;
        else if (cur_floor > cur_target)
            dir = DOWN;
        else if (cur_floor < cur_target)
            dir = UP;
        emit startMoving(dir); //wait
    }
    else if (status == BUSY)
    {
        //status = BUSY;
        cur_floor = floor;
        if (targets[floor - 1])
        {
            targets[floor - 1] = false;

            if (cur_floor == cur_target)
                findNewTarget();

            emit stopCabin(dir);

            if (cur_target == -1)
                emit noTargets();
        }
        else
        {
            qDebug() << "Moving... floor:" << floor;
            //emit move();
        }
    }
}

void ControlPanel::getFree()
{
    if (status == BUSY)
    {
        status = FREE;
        //cur_floor = floor;
        //getClosestTarget(floor);
    }
}

void ControlPanel::findNewTarget()
{
    cur_target = -1;
    if (dir == UP)
    {
        for (int i = 1; i <= NUM_FLOORS; i++)
        {
            if (targets[i-1])
            {
                cur_target = i;
                break;
            }
        }
    }
    else
    {
        for (int i = NUM_FLOORS; i >= 1; i--)
        {
            if (targets[i-1])
            {
                cur_target = i;
                break;
            }
        }
    }
    if (cur_target == -1 || cur_floor == cur_target)
        dir = STAY;
    else if (cur_floor > cur_target)
        dir = DOWN;
    else if (cur_floor < cur_target)
        dir = UP;
}*/

/*void ControlPanel::find_new_target()
{
    int state = false;

    if (dir == UP)
    {
        for (int i = NUM_FLOORS; i >= 1 && !state; i--)
        {
            if (targets[i - 1])
            {
                state = true;
                cur_target = i;
            }
        }
        return;
    }

    for (int i = 1; i <= NUM_FLOORS && !state; i++)
    {
        if (targets[i - 1])
        {
            state = true;
            cur_target = i;
        }
    }
}

bool ControlPanel::getClosestTarget(int &floor)
{
    bool state = false;
    if (cur_target > cur_floor)
    {
        for (int i = cur_floor; i <= NUM_FLOORS && !state; i += 1)
        {
            if (targets[i - 1])
            {
                floor = i;
                state = true;
            }
        }
    }
    else
    {
        for (int i = cur_floor; i >= 1 && !state; i -= 1)
        {
            if (targets[i - 1])
            {
                floor = i;
                state = true;
            }
        }
    }
    return state;
}*/
