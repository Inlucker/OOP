#include <lift.h>

Lift::Lift()
{

    QObject::connect(&control_panel, SIGNAL(addedTarget(int, direction)), &cabin, SLOT(startMoving(int, direction)));
    QObject::connect(&cabin, SIGNAL(cabinCrossedFloor(int, direction)), &control_panel, SLOT(getBusy(int, direction)));
    QObject::connect(&control_panel, SIGNAL(cabinAchievedTarget()), &cabin, SLOT(stopOnFloor()));
    QObject::connect(&cabin, SIGNAL(cabinStayClosed()), &control_panel, SLOT(getFree()));
}

void Lift::click(int floor)
{
    control_panel.addTarget(floor);
}
