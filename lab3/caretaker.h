#ifndef CARETAKER_H
#define CARETAKER_H

#include <memory>
#include <list>

using namespace std;

#include "memento.h"

class Caretaker
{
public:
    void addMemento(unique_ptr<Memento> memento);
    unique_ptr<Memento> getMemento();

private:
    list<unique_ptr<Memento>> mementos;
};

#endif // CARETAKER_H
