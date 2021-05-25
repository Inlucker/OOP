#include "graphicsolution.h"

#include "qtfactory.h"

/*GraphicSolution::GraphicSolution()
{

}*/

unique_ptr<AbstractFactory> createQtFactory()
{
    QtFactory* tmp = new QtFactory();
    unique_ptr<AbstractFactory> rez = tmp->getAbstractFactoryPtr();
    return rez;

    //return unique_ptr<AbstractFactory>(new QtFactory()); //doesn't work
}

bool GraphicSolution::registration(size_t id, GraphicSolution::CreateFactory createfun)
{
    return callbacks.insert(CallBackMap::value_type(id, createfun)).second;
}

bool GraphicSolution::check(size_t id)
{
    return callbacks.erase(id) == 1;
}

unique_ptr<AbstractFactory> GraphicSolution::create(size_t id)
{
    CallBackMap::const_iterator it = callbacks.find(id);

    if (it == callbacks.end())
    {
        //			throw IdError();
    }

    return unique_ptr<AbstractFactory>((it->second)());
}
