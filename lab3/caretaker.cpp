#include "caretaker.h"
#include "errors.h"

/*Caretaker::Caretaker()
{

}*/

void Caretaker::addMemento(unique_ptr<Memento> memento)
{
    mementos.push_back(move(memento));
}

unique_ptr<Memento> Caretaker::getMemento()
{
    unique_ptr<Memento> last = move(mementos.back());
    if (!last)
    {
        time_t t_time = time(NULL);
        throw NoMementosError("No operations in list", __FILE__, __LINE__, ctime(&t_time));
    }
    mementos.pop_back();

    return last;
}
