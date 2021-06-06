#include <lift.h>

Lift::Lift()
{

    QObject::connect(&control_panel, SIGNAL(addedTarget(int, direction)), &cabin, SLOT(startMoving(int, direction)));
    QObject::connect(&cabin, SIGNAL(cabinCrossedFloor(int, direction)), &control_panel, SLOT(getBusy(int, direction)));
    QObject::connect(&control_panel, SIGNAL(cabinAchievedTarget()), &cabin, SLOT(stopOnFloor()));
    QObject::connect(&cabin, SIGNAL(cabinStayClosed(int)), &control_panel, SLOT(getFree(int)));

    /*QObject::connect(&control_panel, SIGNAL(startMoving(direction)), &cabin, SLOT(wait(direction)));
    QObject::connect(&cabin, SIGNAL(cabin_crossing_floor(int)), &control_panel, SLOT(getBusy(int)));
    QObject::connect(&control_panel, SIGNAL(stopCabin(direction)), &cabin, SLOT(cabinStop(direction)));
    QObject::connect(&control_panel, SIGNAL(move()), &cabin, SLOT(move()));*/

    /*QObject::connect(&control_panel, SIGNAL(addedTarget(int, direction)), &cabin, SLOT(cabin_call(int, direction)));
    QObject::connect(&cabin, SIGNAL(cabin_crossing_floor(int, direction)), &control_panel, SLOT(passed_floor(int)));
    QObject::connect(&cabin, SIGNAL(cabin_stopped(int)), &control_panel, SLOT(achieved_floor(int)));
    QObject::connect(&control_panel, SIGNAL(stop_cabin()), &cabin, SLOT(cabin_stopping()));*/
}

void Lift::click(int floor)
{
    control_panel.addTarget(floor);
}
