#include "graphicsolution.h"

#include "qtfactory.h"
#include "errors.h"

/*unique_ptr<AbstractFactory> createQtFactory()
{
    //QtFactory* tmp = new QtFactory();
    //unique_ptr<AbstractFactory> rez = tmp->getAbstractFactoryPtr();
    //return rez;

    return unique_ptr<AbstractFactory>(new QtFactory()); //didn't work (fixed by public наследование)
}*/

unique_ptr<AbstractFactory> FactoryCreator::createQtFactory()
{
    unique_ptr<AbstractFactory> newQtFactory = unique_ptr<AbstractFactory>(new QtFactory());
    return newQtFactory;
}

/*GraphicSolution::GraphicSolution()
{

}*/

bool GraphicSolution::registration(size_t id, /*GraphicSolution::*/CreateFactory createfun)
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
        time_t t_time = time(NULL);
        throw GraphicsSolutionKeyError("Wrong id", __FILE__, __LINE__, ctime(&t_time));
    }

    return unique_ptr<AbstractFactory>((FactoryCreator().*it->second)()); //(FactoryCreator().*it->second)() is this OK? Or I should have ptr on FactoryCreator object?
}
