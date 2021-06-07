#include <lift.h>

Lift::Lift()
{

    QObject::connect(&control_panel, SIGNAL(addedTarget(direction)), &cabin, SLOT(startMoving(direction)));
    //QObject::connect(&cabin, SIGNAL(cabinCrossedFloor(direction)), &control_panel, SLOT(getBusy(direction)));
    QObject::connect(&cabin, SIGNAL(cabinCrossedFloor(direction)), &control_panel, SLOT(passFloor(direction)));
    QObject::connect(&control_panel, SIGNAL(cabinAchievedTarget()), &cabin, SLOT(stopOnFloor()));
    QObject::connect(&cabin, SIGNAL(cabinStayClosed()), &control_panel, SLOT(getFree()));
}

void Lift::click(int floor)
{
    control_panel.addTarget(floor);
}
