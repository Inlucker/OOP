#ifndef GRAPHICSOLUTION_H
#define GRAPHICSOLUTION_H

#include <map>
#include <memory>

using namespace std;

#include "abstractfactory.h"

class FactoryCreator
{
public:
    unique_ptr<AbstractFactory> createQtFactory();
};

class GraphicSolution
{
public:
    typedef unique_ptr<AbstractFactory> (FactoryCreator::*CreateFactory)();
    GraphicSolution() = default;
    ~GraphicSolution() = default;

    bool registration(size_t id, CreateFactory createfun);
    //bool check(size_t id);

    unique_ptr<AbstractFactory> create(size_t id);
private:
    using CallBackMap = map<size_t, CreateFactory>;

    CallBackMap callbacks;
};

#endif // GRAPHICSOLUTION_H
