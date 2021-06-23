#include "memento.h"

/*Memento::Memento()
{

}*/

Memento::Memento(Scene& o) : originator(o){}

void Memento::setOriginator(Scene o)
{
    originator = o;
}

Scene Memento::getOriginator()
{
    return originator;
}
